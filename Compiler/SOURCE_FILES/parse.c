/***********/
/* parse.c */
/***********/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../HEADER_FILES/parse.h"
#include "../HEADER_FILES/symbol.h"
#include "../HEADER_FILES/util.h"
#include "../HEADER_FILES/absyn.h"
#include "../HEADER_FILES/errormsg.h"
#include "../HEADER_FILES/PSEUDO_MIPS_ASM_AST_errormsg.h"

/************************/
/* Tiger_Program_To_AST */
/************************/
A_exp Tiger_Program_To_AST(string Tiger_Program_Filename)
{
	EM_reset(Tiger_Program_Filename);
	if (yyparse() == 0)
	{
		/******************/
		/* parsing worked */
		/******************/
		return absyn_root;
	}
	else
	{
		return NULL;
	}
}

/***************************/
/* Pseudo_Assembley_To_AST */
/***************************/
PSEUDO_MIPS_ASM_AST_expList Pseudo_Assembley_To_AST(string Pseudo_Assembley_Filename)
{
	PSEUDO_MIPS_ASM_AST_EM_reset(Pseudo_Assembley_Filename);
 	if (zzparse() == 0)
	{
		/******************/
		/* parsing worked */
		/******************/
		return PSEUDO_MIPS_ASM_AST_root;
	}
	else
	{
		return NULL;
	}
}
