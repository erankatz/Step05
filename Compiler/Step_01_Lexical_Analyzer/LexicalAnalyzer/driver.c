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
#include "../../HEADER_FILES/errormsg.h"
#include "../../BISON/BISON_01_For_First_Exercise/tiger.tab.h"

YYSTYPE yylval;

int yylex(void); /* prototype for the lexing function */

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
	default:			return "BAD_TOKEN";
	}
}

int main(int argc, char **argv)
{
	string fname;
	int tok;
	if (argc != 2)
	{
		fprintf(stderr,"usage: a.out filename\n");
		return 0;
	}
	
	fname=argv[1];
	EM_reset(fname);

	printf("\n\n");

	for(;;)
	{
		tok=yylex();
		if (tok==0) break;
		switch(tok) {
		case ID:
			printf("%s(%s) ",tokname(tok),yylval.sval);
			break;
		case STRING:
			printf("%s(%s) ",tokname(tok),yylval.sval);
			break;
		case INT:
			printf("%s(%d) ",tokname(tok),yylval.ival);
			break;
		case FLOAT:
			printf("%s(%f) ",tokname(tok),yylval.fval);
			break;
		case SEMICOLON:
			printf("%s\n\n",tokname(tok));
			break;
		default:
			printf("%s ",tokname(tok));
			break;
		}
	}

	printf("\n");
	
	return 0;
}

