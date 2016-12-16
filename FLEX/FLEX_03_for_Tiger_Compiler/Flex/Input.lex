%{
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../../../Compiler/HEADER_FILES/util.h"
#include "../../../Compiler/HEADER_FILES/absyn.h"
#include "../../../Compiler/HEADER_FILES/errormsg.h"
#include "../../../BISON/BISON_03_for_Tiger_Compiler/Bison/tiger.tab.h"

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
\t									{adjust(); continue;}
\n									{adjust(); EM_newline(); continue;}
","									{adjust(); return COMMA;}
";"									{adjust(); return SEMICOLON;}
for									{adjust(); return FOR;}
nil									{adjust(); return NIL;}
to									{adjust(); return TO;}
do									{adjust(); return DO;}
of									{adjust(); return OF;}
array								{adjust(); return ARRAY;}
if									{adjust(); return IF;}
then								{adjust(); return THEN;}
while								{adjust(); return WHILE;}
type								{adjust(); return TYPE;}
var									{adjust(); return VAR;}
let									{adjust(); return LET;}
function							{adjust(); return FUNCTION;}
in									{adjust(); return IN;}
end									{adjust(); return END;}
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
"!="								{adjust(); return NEQ;}
"<"									{adjust(); return LT;}
"<="								{adjust(); return LE;}
">"									{adjust(); return GT;}
">="								{adjust(); return GE;}
":="								{adjust(); return ASSIGN;}
"->"								{adjust(); return ARROW;}
":"									{adjust(); return COLON;}
[0-9]+[0-9]*						{adjust(); yylval.gval.ival=atoi(yytext); return INT;}
[a-zA-Z]+[0-9a-zA-Z]*				{adjust(); yylval.gval.sval=String(yytext); return ID;}
\"[0-9a-zA-Z ]*\"					{adjust(); yylval.gval.sval=String(yytext); return STRING;}
[0-9]+"."[0-9]*						{adjust(); yylval.gval.fval=(float) atof(yytext); return FLOAT;}
"."[0-9]+							{adjust(); yylval.gval.fval=(float) atof(yytext); return FLOAT;}
@									{adjust(); EM_error(EM_tokPos,"illegal token");}
