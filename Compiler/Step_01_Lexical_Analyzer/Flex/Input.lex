%{
#include <string.h>
#include <math.h>
#include "../../HEADER_FILES/util.h"
#include "../../HEADER_FILES/errormsg.h"
#include "../../BISON/BISON_01_For_First_Exercise/tiger.tab.h"
int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%%
" "									{adjust(); continue;}
\n									{adjust(); EM_newline(); continue;}
","									{adjust(); return COMMA;}
";"									{adjust(); return SEMICOLON;}
for									{adjust(); return FOR;}
while								{adjust(); return WHILE;}
"("									{adjust(); return LPAREN;}
")"									{adjust(); return RPAREN;}
"["									{adjust(); return LBRACK;}
"]"									{adjust(); return RBRACK;}
"{"									{adjust(); return LBRACE;}
"}"									{adjust(); return RBRACE;}
"+"									{adjust(); return PLUS;}
"-"									{adjust(); return MINUS;}
"*"									{adjust(); return TIMES;}
"/"									{adjust(); return DIVIDE;}
"="									{adjust(); return EQ;}
":="								{adjust(); return ASSIGN;}
[0-9]+[0-9]*						{adjust(); yylval.ival=atoi(yytext); return INT;}
[a-zA-Z]+[0-9a-zA-Z]*				{adjust(); yylval.sval=String(yytext); return ID;}
.									{adjust(); EM_error(EM_tokPos,"illegal token");}
