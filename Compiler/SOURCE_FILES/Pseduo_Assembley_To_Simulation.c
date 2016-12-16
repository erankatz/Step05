/**********/
/* main.c */
/**********/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../HEADER_FILES/util.h"
#include "../HEADER_FILES/temp.h"
#include "../HEADER_FILES/absyn.h"
#include "../HEADER_FILES/parse.h"
#include "../Header_FILES/frame.h"
#include "../HEADER_FILES/errormsg.h"

#define MAX_NAME_LENGTH_OF_TEMPORARY_OR_REGISTER 16
/********************/
/* GLOBAL VARIABLES */
/********************/
PSEUDO_MIPS_ASM_AST_expList AST=NULL;

/********************/
/* GLOBAL VARIABLES */
/********************/
FILE *fl;

/********************/
/* GLOBAL VARIABLES */
/********************/
int index=0;

string Temporary_Or_Register(PSEUDO_MIPS_ASM_AST_Var var)
{
	string temp_or_register = (string) malloc(MAX_NAME_LENGTH_OF_TEMPORARY_OR_REGISTER);
	char temp_buffer[MAX_NAME_LENGTH_OF_TEMPORARY_OR_REGISTER];

	if (var->type == TEMPORARY_VAR)
	{
		strcpy(temp_or_register,"Temp_");
		strcpy(temp_or_register+strlen("Temp_"),itoa(var->u.temp,temp_buffer,10));
	}
	if (var->type == REGISTER_VAR)
	{
		strcpy(temp_or_register,var->u.reg);
	}

	return temp_or_register;
}

void CodeGenerationExp_Add(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.add.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.add.var2);
	string temporary_or_register_3 = Temporary_Or_Register(exp->u.add.var3);

	fprintf(
		fl,
		"\t%s =(int *) (((int) %s) + ((int) %s));\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		temporary_or_register_3);
}
void CodeGenerationExp_Sub(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.sub.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.sub.var2);
	string temporary_or_register_3 = Temporary_Or_Register(exp->u.sub.var3);

	fprintf(
		fl,
		"\t%s =(int *) (((int) %s) - ((int) %s));\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		temporary_or_register_3);
}
void CodeGenerationExp_Mul(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.mul.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.mul.var2);
	string temporary_or_register_3 = Temporary_Or_Register(exp->u.mul.var3);

	fprintf(
		fl,
		"\t%s =(int *) (((int) %s) * ((int) %s));\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		temporary_or_register_3);
}
void CodeGenerationExp_Div(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.div.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.div.var2);
	string temporary_or_register_3 = Temporary_Or_Register(exp->u.div.var3);

	fprintf(
		fl,
		"\t%s =(int *) (((int) %s) / ((int) %s));\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		temporary_or_register_3);
}
void CodeGenerationExp_Beq(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.beq.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.beq.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) == ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.beq.label.name);
}
void CodeGenerationExp_Bne(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.bne.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.bne.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) != ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.bne.label.name);
}
void CodeGenerationExp_Bgt(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.bgt.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.bgt.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) > ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.bgt.label.name);
}
void CodeGenerationExp_Blt(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.blt.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.blt.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) < ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.blt.label.name);
}
void CodeGenerationExp_Bge(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.bge.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.bge.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) >= ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.bge.label.name);
}
void CodeGenerationExp_Ble(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.ble.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.ble.var2);

	fprintf(
		fl,
		"\tif (((int) (%s)) <= ((int) (%s)))\n\t{\n\t\tgoto %s;\n\t}\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.ble.label.name);
}
void CodeGenerationExp_Load(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.load.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.load.var2);

	fprintf(
		fl,
		"\t%s = (int *) *(%s + %d);\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.load.offset / F_wordSize);
}
void CodeGenerationExp_Move(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.move.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.move.var2);

	fprintf(
		fl,
		"\t%s = %s;\n\n",
		temporary_or_register_1,
		temporary_or_register_2);
}
void CodeGenerationExp_Label(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(
		fl,
		"%s:\n\n",
		exp->u.label.name);
}
void CodeGenerationExp_Store(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.move.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.move.var2);

	fprintf(
		fl,
		"\t*(%s) = (int) (%s+(%d));\n\n",
		temporary_or_register_2,
		temporary_or_register_1,
		exp->u.store.offset / F_wordSize);
}

void CodeGenerationExp_Jump_Label(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(
		fl,
		"\tgoto %s;\n\n",
		exp->u.jump_label.name);
}
void CodeGenerationExp_Jump_And_link(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(
		fl,
		"\t__asm\n\t{\n\t\tcall _here%d\n\t\t_here%d: pop eax\n\t\tadd eax,14\n\t\tmov ra,eax\n\t}\n\n",
		index,
		index);

	fprintf(
		fl,
		"\tgoto %s;\n\n",
		exp->u.jump_and_link);

	index++;
}
void CodeGenerationExp_Jump_Register(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(
		fl,
		"\t__asm\n\t{\n\t\tjmp %s\n\t}\n\n",
		exp->u.jump_register);
}

void CodeGenerationExp_Add_Immediate(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register_1 = Temporary_Or_Register(exp->u.load.var1);
	string temporary_or_register_2 = Temporary_Or_Register(exp->u.load.var2);

	fprintf(
		fl,
		"\t%s = (int *) ((int) %s + %d);\n\n",
		temporary_or_register_1,
		temporary_or_register_2,
		exp->u.add_immediate.value);
}
void CodeGenerationExp_Load_Immediate(PSEUDO_MIPS_ASM_AST_exp exp)
{
	string temporary_or_register = Temporary_Or_Register(exp->u.load_immediate.var);

	fprintf(
		fl,
		"\t%s = (int *) %d;\n\n",
		temporary_or_register,
		exp->u.load_immediate.value);
}

void CodeGenerationExp_Print_Int(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(fl,"\t%s\n\n","printf(\"\%d \",(int) a0);");
}
void CodeGenerationExp_Print_Char(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(fl,"\t%s\n\n","printf(\"\%c \",(char) a0);");
}
void CodeGenerationExp_Allocate(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(fl,"\t%s\n\n","v0 = (int *) malloc((int) a0);");
}
void CodeGenerationExp_Exit(PSEUDO_MIPS_ASM_AST_exp exp)
{
	fprintf(fl,"\t%s\n\n","exit(0);");
}

void CodeGenerationExp(PSEUDO_MIPS_ASM_AST_exp exp)
{
	switch (exp->type) {
	case (PSEUDO_MIPS_ASM_AST_ADD_EXP_TYPE):			CodeGenerationExp_Add(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_SUB_EXP_TYPE):			CodeGenerationExp_Sub(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_MUL_EXP_TYPE):			CodeGenerationExp_Mul(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_DIV_EXP_TYPE):			CodeGenerationExp_Div(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BEQ_EXP_TYPE):			CodeGenerationExp_Beq(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BNE_EXP_TYPE):			CodeGenerationExp_Bne(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BGT_EXP_TYPE):			CodeGenerationExp_Bgt(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BGE_EXP_TYPE):			CodeGenerationExp_Bge(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BLT_EXP_TYPE):			CodeGenerationExp_Blt(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_BLE_EXP_TYPE):			CodeGenerationExp_Ble(exp);            break;
	case (PSEUDO_MIPS_ASM_AST_LOAD_EXP_TYPE):			CodeGenerationExp_Load(exp);           break;
	case (PSEUDO_MIPS_ASM_AST_MOVE_EXP_TYPE):			CodeGenerationExp_Move(exp);           break;
	case (PSEUDO_MIPS_ASM_AST_LABEL_EXP_TYPE):			CodeGenerationExp_Label(exp);          break;
	case (PSEUDO_MIPS_ASM_AST_STORE_EXP_TYPE):			CodeGenerationExp_Store(exp);          break;
	case (PSEUDO_MIPS_ASM_AST_JUMP_LABEL_EXP_TYPE):		CodeGenerationExp_Jump_Label(exp);     break;
	case (PSEUDO_MIPS_ASM_AST_JUMP_AND_LINK_EXP_TYPE):	CodeGenerationExp_Jump_And_link(exp);  break;
	case (PSEUDO_MIPS_ASM_AST_JUMP_REGISTER_EXP_TYPE):	CodeGenerationExp_Jump_Register(exp);  break;
	case (PSEUDO_MIPS_ASM_AST_ADD_IMMEDIATE_EXP_TYPE):	CodeGenerationExp_Add_Immediate(exp);  break;
	case (PSEUDO_MIPS_ASM_AST_LOAD_IMMEDIATE_EXP_TYPE):	CodeGenerationExp_Load_Immediate(exp); break;
	case (PSEUDO_MIPS_ASM_AST_PRINT_INT_EXP_TYPE):		CodeGenerationExp_Print_Int(exp);      break;
	case (PSEUDO_MIPS_ASM_AST_PRINT_CHAR_EXP_TYPE):		CodeGenerationExp_Print_Char(exp);     break;
	case (PSEUDO_MIPS_ASM_AST_ALLOCATE_EXP_TYPE):		CodeGenerationExp_Allocate(exp);       break;
	case (PSEUDO_MIPS_ASM_AST_EXIT_EXP_TYPE):			CodeGenerationExp_Exit(exp);           break;
	}
}

void AST_To_Simulation(PSEUDO_MIPS_ASM_AST_expList AST)
{
	int i;

	PSEUDO_MIPS_ASM_AST_expList expList;

	/*************************************/
	/* [1] Open simulation.c for writing */
	/*************************************/
	fl=fopen("simulation.c","w+t");
	if (fl == NULL) return;

	/***********************/
	/* [2] Include headers */
	/***********************/
	fprintf(fl,"#include <stdio.h>\n\n");
	fprintf(fl,"#include <stdlib.h>\n\n");
	fprintf(fl,"#include <memory.h>\n\n");

	/**************************************/
	/* [3] Declare temporaries as (int *) */
	/**************************************/
	for (i=0;i<TEMP_numTemporariesAllocated();i++)
	{
		fprintf(fl,"int *Temp_%d;\n\n",i);
	}

	/**********************************************/
	/* [4] Declare dedicated registers as (int *) */
	/**********************************************/
	fprintf(fl,"int *sp;\n\n");
	fprintf(fl,"int *fp;\n\n");
	fprintf(fl,"int *ra;\n\n");
	fprintf(fl,"int *rv;\n\n");
	fprintf(fl,"int *a0;\n\n");
	fprintf(fl,"int *a1;\n\n");
	fprintf(fl,"int *a2;\n\n");
	fprintf(fl,"int *a3;\n\n");
	fprintf(fl,"int *v0;\n\n");
	fprintf(fl,"int *v1;\n\n");

	/**********************************************/
	/* [5] Declare dedicated registers as (int *) */
	/**********************************************/
	fprintf(fl,"int *t0;\n\n");
	fprintf(fl,"int *t1;\n\n");
	fprintf(fl,"int *t2;\n\n");
	fprintf(fl,"int *t3;\n\n");
	fprintf(fl,"int *t4;\n\n");
	fprintf(fl,"int *t5;\n\n");
	fprintf(fl,"int *t6;\n\n");
	fprintf(fl,"int *t7;\n\n");

	/****************************/
	/* [6] Function main starts */
	/****************************/
	fprintf(fl,"void main()\n\n");
 	fprintf(fl,"{\n\n");

	/**************************************************/
	/* [7] Declare dummy variables for easy debugging */
	/**************************************************/
	fprintf(fl,"\tint b1=1;\n");
	fprintf(fl,"\tint b2=2;\n");
	fprintf(fl,"\tint b3=3;\n");
	fprintf(fl,"\tint b4=4;\n");
	fprintf(fl,"\tint b5=5;\n");
	fprintf(fl,"\tint b6=6;\n");

	/**************************/
	/* [8] Initialize sp & fp */
	/**************************/
	fprintf(fl,"\tsp = &b3;\n");
	fprintf(fl,"\tfp = &b2;\n");

	/*****************************/
	/* [9] Generate C Simulation */
	/*****************************/
	for (expList=AST;expList;expList=expList->tail)
	{
		CodeGenerationExp(expList->head);
	}

	/***************************/
	/* [10] Function main ends */
	/***************************/
	fprintf(fl,"}\n\n");
	fclose(fl);
}

/**********************************/
/* Pseduo_Assembley_To_Simulation */
/**********************************/
void Pseudo_Assembley_To_Simulation(string Pseudo_Assembley_Filename)
{
	/**********************************/
	/* [1] Build Abstract Syntax Tree */
	/**********************************/
	AST=Pseudo_Assembley_To_AST(Pseudo_Assembley_Filename);

	/***************************/
	/* [2] AST To simulation.c */
	/***************************/
	AST_To_Simulation(AST);
}
