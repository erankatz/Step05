/***********************/
/* FILE NAME: Parser.c */
/***********************/

/*****************/
/* INCLUDE FILES */
/*****************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../../HEADER_FILES/util.h"
#include "../../HEADER_FILES/errormsg.h"
#include "../../BISON/BISON_01_For_First_Exercise/tiger.tab.h"
#include "Parser.h"
#include "Stack.h"

/********************/
/* GLOBAL VARIABLES */
/********************/
Stack s;
int tok=0;
int status=1;
int readToken=1;
string entry=NULL;
YYSTYPE yylval;

int yylex(void); /* prototype for the lexing function */

/*****/
/* E */
/*****/
#define NUM_VARIABLES 1

/******************************/
/* (, ), INT(x), +, -, *, / $ */
/******************************/
#define NUM_TOKENS 7

#define NUM_DERIVIATION_RULES 7
char *RULES[NUM_DERIVIATION_RULES]=
{
	"S->E$",
	"E->E+E",
	"E->E-E",
	"E->E*E",
	"E->E/E",
	"E->y",
	"E->(E)"
};

char LEFT_SIDE_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	'S',
	'E',
	'E',
	'E',
	'E',
	'E',
	'E',
};

int LENGTH_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	2,/* S->E$  */
	3,/* E->E+E */
	3,/* E->E-E */
	3,/* E->E*E */
	3,/* E->E/E */
	1,/* E->y   */
	3 /* E->(E) */
};

#define NUM_STATES 14
string table[NUM_STATES][NUM_VARIABLES+NUM_TOKENS+1]=
{
	/*			(		)		y		+		-		*		/		$		E		*/
	/*----------------------------------------------------------------------------------*/
	/*	0	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g1",
	/*----------------------------------------------------------------------------------*/
	/*	1	*/	"",		"",		"",		"s2",	"s3",	"s4",	"s5",	"a",	"",
	/*----------------------------------------------------------------------------------*/
	/*	2	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g10",
	/*----------------------------------------------------------------------------------*/
	/*	3	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g11",
	/*----------------------------------------------------------------------------------*/
	/*	4	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g12",
	/*----------------------------------------------------------------------------------*/
	/*	5	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g13",
	/*----------------------------------------------------------------------------------*/
	/*	6	*/	"s6",	"",		"s8",	"",		"",		"",		"",		"",		"g7",
	/*----------------------------------------------------------------------------------*/
	/*	7	*/	"",		"s9",	"",		"s2",	"s3",	"s4",	"s5",	"",		"",
	/*----------------------------------------------------------------------------------*/
	/*	8	*/	"r5",	"r5",	"r5",	"r5",	"r5",	"r5",	"r5",	"r5",	"",
	/*----------------------------------------------------------------------------------*/
	/*	9	*/	"r6",	"r6",	"r6",	"r6",	"r6",	"r6",	"r6",	"r6",	"",
	/*----------------------------------------------------------------------------------*/
	/*	10	*/	"r1",	"r1",	"r1",	"r1",	"r1",	"r1",	"r1",	"r1",	"",
	/*----------------------------------------------------------------------------------*/
	/*	11	*/	"r2",	"r2",	"r2",	"r2",	"r2",	"r2",	"r4",	"r2",	"",
	/*----------------------------------------------------------------------------------*/
	/*	12	*/	"r3",	"r3",	"r3",	"r3",	"r3",	"r3",	"r3",	"r3",	"",
	/*----------------------------------------------------------------------------------*/
	/*	13	*/	"r4",	"r4",	"r4",	"r4",	"r4",	"r4",	"r4",	"r4",	"",
	/*----------------------------------------------------------------------------------*/
};

int ConvertTokenToIndex(int token)
{
	switch (token) {
	case (LPAREN): return 0;
	case (RPAREN): return 1;
	case (INT):    return 2;
	case (PLUS):   return 3;
	case (MINUS):  return 4;
	case (TIMES):  return 5;
	case (DIVIDE): return 6;
	case (0):      return 7;
	default:       return -1;
	}
}

int ConvertCharToIndex(char c)
{
	switch (c) {
	case ('('): return  0;
	case (')'): return  1;
	case ('y'): return  2;
	case ('+'): return  3;
	case ('-'): return  4;
	case ('*'): return  5;
	case ('/'): return  6;
	case ('$'): return  7;
	case ('E'): return  8;
	case ('T'): return  9;
	case ('F'): return 10;
	default:    return -1;
	}
}

char ConvertTokenToChar(int token)
{
	switch (token) {
	case (LPAREN): return '(';
	case (RPAREN): return ')';
	case (INT):    return 'y';
	case (PLUS):   return '+';
	case (MINUS):  return '-';
	case (TIMES):  return '*';
	case (DIVIDE): return '/';
	case (0):      return '$';
	default:       return  0 ;
	}
}

void Shift(void)
{
	int state=0;

	/**********************/
	/* Compute Next State */
	/**********************/
	state=atoi(entry+1);

	/********/
	/* Push */
	/********/
	Push(&s,state,ConvertTokenToChar(tok));
	
	/*******************/
	/* Read next token */
	/*******************/
	tok=yylex();
}

void Reduce(int rule_number)
{
	int i=0;
	int state=0;

	/**********************************************************/
	/* Pop the stack the length of the right side of the rule */
	/**********************************************************/
	for (i=0;i<LENGTH_DERIVIATION_RULES[rule_number];i++)
	{
		Pop(&s);
	}

	/**********************/
	/* Compute Next State */
	/**********************/
	entry=table[Top(&s)->state][ConvertCharToIndex(LEFT_SIDE_DERIVIATION_RULES[rule_number])];

	/******************************************/
	/* Only goto states are possible here ... */
	/******************************************/
	assert((*entry) == 'g');
	state=atoi(entry+1);

	/************************************/
	/* Push left side variable on stack */
	/************************************/
	Push(&s,state,LEFT_SIDE_DERIVIATION_RULES[rule_number]);
}

int Parse()
{
	char wait_for_transition=0;

	/**************/
	/* Init Stack */
	/**************/
	s.c=0;
	s.state=0;
	s.next=NULL;

	/*******************/
	/* print the stack */
	/*******************/
	PrintStack(&s);

	/***********************/
	/* Get the first token */
	/***********************/
	tok=yylex();
	
	while (1) {

		/***********************/
		/* extract table entry */
		/***********************/
		entry=table[Top(&s)->state][ConvertTokenToIndex(tok)];
		
		switch (*entry) {
		
		case ('s'):

			// Shift
			Shift();
			PrintStack(&s);
			break;

		case ('r'):

			// Reduce
			Reduce(atoi(entry+1));
			PrintStack(&s);
			break;

		case ('a'):
			
			// Accept
			return 1;

		case (0):

			// Error
			return 0;
		}
	}

	return 0;
}
