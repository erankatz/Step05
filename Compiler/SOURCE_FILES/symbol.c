/************/
/* symbol.c */
/************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <string.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../HEADER_FILES/util.h"
#include "../HEADER_FILES/symbol.h"
#include "../HEADER_FILES/table.h"

struct S_symbol_ {string name; S_symbol next;};

static S_symbol mksymbol(string name, S_symbol next)
{
	S_symbol s = (S_symbol) checked_malloc(sizeof(*s));
	s->name=name; s->next=next;
	return s;
}

#define SIZE 109  /* should be prime */

static S_symbol hashtable[SIZE];

static unsigned int hash(char *s0)
{
	char *s;
	unsigned int h=0;
	
	for (s=s0; (*s); s++)
	{
		h = h*65599 + (*s);
	}
	
	return h;
}
 
static int streq(string a, string b)
{
 return !strcmp(a,b);
}

S_symbol S_Symbol(string name)
{
	int index= hash(name) % SIZE;
	S_symbol syms = hashtable[index], sym;
	
	for (sym=syms; sym; sym=sym->next)
	{
		if (streq(sym->name,name))
		{
			return sym;
		}
	}
	
	sym = mksymbol(name,syms);
	hashtable[index]=sym;
	return sym;
}
 
string S_name(S_symbol sym)
{
	return sym->name;
}

S_table S_empty(void) 
{
	return TAB_empty();
}

void S_enter(S_table t, S_symbol sym, void *value)
{
	TAB_enter(t,sym,value);
}

void *S_look(S_table t, S_symbol sym)
{
	return TAB_look(t,sym);
}

static struct S_symbol_ marksym = {"<mark>",0};

void S_beginScope(S_table t)
{
	S_enter(t,&marksym,NULL);
}

void S_endScope(S_table t)
{
	S_symbol s;

	do
	{
		s = (S_symbol) TAB_pop(t);
	}
	while (s != &marksym);
}
