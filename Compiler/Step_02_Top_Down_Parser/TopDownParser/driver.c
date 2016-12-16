/***********************/
/* FILE NAME: driver.c */
/***********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../../HEADER_FILES/util.h"
#include "../../HEADER_FILES//errormsg.h"
#include "../../BISON/BISON_01_For_First_Exercise/tiger.tab.h"

/********/
/* EXIT */
/********/
extern int exit(int);

int tok=0;

int status=1;

YYSTYPE yylval;

int yylex(void); /* prototype for the lexing function */

string toknames[] =
{
	"INT",
	"FLOAT",
	"STRING",
	"ID",
	"COMMA",
	"COLON",
	"SEMICOLON",
	"LPAREN",
	"RPAREN",
	"LBRACK",
	"RBRACK",
	"LBRACE",
	"RBRACE",
	"DOT",
	"PLUS",
	"MINUS",
	"TIMES",
	"DIVIDE",
	"EQ",
	"NEQ",
	"LT",
	"LE",
	"GT",
	"GE",
	"AND",
	"OR",
	"ASSIGN",
	"ARRAY",
	"IF",
	"THEN",
	"ELSE",
	"WHILE",
	"FOR",
	"TO",
	"DO",
	"LET",
	"IN",
	"END",
	"OF",
	"BREAK",
	"NIL",
	"FUNCTION",
	"VAR",
	"TYPE",
};

string tokname(int tok)
{
	switch (tok) {
	case (FLOAT):		return "FLOAT";
	case (STRING):		return "STRING";
	case (ID):			return "ID";
	case (COMMA):		return "COMMA";
	case (INT):			return "INT";
	case (COLON):		return "COLON";
	case (SEMICOLON):	return "SEMICOLON";
	case (LPAREN):		return "LPAREN";
	case (RPAREN):		return "RPAREN";
	case (LBRACK):		return "LBRACK";
	case (RBRACK):		return "RBRACK";
	case (LBRACE):		return "LBRACE";
	case (RBRACE):		return "RBRACE";
	case (DOT):			return "DOT";
	case (PLUS):		return "PLUS";
	case (MINUS):		return "MINUS";
	case (TIMES):		return "TIMES";
	case (DIVIDE):		return "DIVIDE";
	case (EQ):			return "EQ";
	case (NEQ):			return "NEQ";
	case (LT):			return "LT";
	case (LE):			return "LE";
	case (GT):			return "GT";
	case (GE):			return "GE";
	case (AND):			return "AND";
	case (OR):			return "OR";
	case (ASSIGN):		return "ASSIGN";
	case (ARRAY):		return "ARRAY";
	case (IF):			return "IF";
	case (THEN):		return "THEN";
	case (ELSE):		return "ELSE";
	case (WHILE):		return "WHILE";
	case (FOR):			return "FOR";
	case (TO):			return "TO";
	case (DO):			return "DO";
	case (LET):			return "LET";
	case (IN):			return "IN";
	case (END):			return "END";
	case (OF):			return "OF";
	case (BREAK):		return "BREAK";
	case (NIL):			return "NIL";
	case (FUNCTION):	return "FUNCTION";
	case (VAR):			return "VAR";
	case (TYPE):		return "TYPE";
	case (0):			return "END_OF_FILE";
	default:			return "BAD_TOKEN";
	}
}

void Eat(int expectedToken)
{
	if (tok == expectedToken)
	{
		tok=yylex();
	}
	else
	{
		status = 0;

		printf("Error in position %d\n\n",EM_tokPos);
		printf("Should be %s instead of %s\n\n",
			tokname(expectedToken),
			tokname(tok));
		exit(0);
	}
}


void S()
{
	switch (tok) {

	case (LPAREN):
		
		// S ---> (S)S
		Eat(LPAREN);
		S();
		Eat(RPAREN);
		S();
		break;

	case (LBRACK):
		
		// S ---> [S]S
		Eat(LBRACK);
		S();
		Eat(RBRACK);
		S();
		break;

	case (LBRACE):
		
		// S ---> {S}S
		Eat(LBRACE);
		S();
		Eat(RBRACE);
		S();
		break;
	}
}

void E();

void E_tag()
{
	switch (tok) {
	case (TIMES):
		// E' ---> * E E'
		Eat(TIMES);
		E();
		E_tag();
		break;

	case (DIVIDE):
		// E' ---> / E E'
		Eat(DIVIDE);
		E();
		E_tag();
		break;

	case (PLUS):
		// E' ---> + E E'
		Eat(PLUS);
		E();
		E_tag();
		break;

	case (MINUS):
		// E' ---> - E E'
		Eat(MINUS);
		E();
		E_tag();
		break;
	}
}


void E()
{
	switch (tok) {

	case (LPAREN):
		
		// E ---> (E)E'
		Eat(LPAREN);
		E();
		Eat(RPAREN);
		E_tag();
		break;

	case (INT):
		
		// E ---> INT
		Eat(INT);
		E_tag();
		break;

	default:

		printf("Error in position %d\n\n",EM_tokPos);
		printf("unexpected %s\n\n",tokname(tok));
		exit(0);
	}
}

void A();

void X()
{
	switch (tok) {
	case (INT):

		Eat(INT);
		A();
	}
}

void A()
{
	Eat(INT);
	X();
}

void G()
{
	switch (tok) {

	case (LPAREN):
		
		// G ---> (G)
		Eat(LPAREN);
		A();
		Eat(RPAREN);
		break;

	default:

		printf("Error in position %d\n\n",EM_tokPos);
		printf("unexpected %s\n\n",tokname(tok));
		exit(0);
	}
}

int main(int argc, char **argv)
{
	string fname;

	if (argc != 2)
	{
		fprintf(stderr,"usage: a.out filename\n");
		return 0;
	}
	
	fname=argv[1];
	EM_reset(fname);

	printf("\n\n");

	tok=yylex();

	G();
	// S();
	//E();

	Eat(0);

	if (status == 0)
	{
		printf("ERROR");
	}
	else
	{
		printf("GOOD!");
	}

	printf("\n\n");
	
	return 0;
}

