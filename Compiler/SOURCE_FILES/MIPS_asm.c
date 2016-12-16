/*************************/
/* FILE NAME: MIPS_asm.c */
/*************************/

/****************************************/
/* WARNING DISABLE: sprintf - I love it */
/****************************************/
#pragma warning (disable: 4996)

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "../HEADER_FILES/tree.h"
#include "../HEADER_FILES/frame.h"

/********************/
/* GLOBAL VARIABLES */
/********************/
FILE *fl=NULL;

/*******************************************/
/* MIPS_ASM_ALLOCATE_RECORD_IMPLEMENTATION */
/*******************************************/
/*****************************************************/
/*                                                   */
/*                       .                           */
/*                       .                           */
/*                       .                           */
/*          +-----------------------------+          */
/*          |                             |          */
/*          +-----------------------------+          */
/*          |                             |          */
/*          +-----------------------------+          */
/*          |                             |          */
/*          +-----------------------------+          */
/* ?? ----> |  NUMBER OF FIELDS IN RECORD | <---- ?? */
/*          +-----------------------------+          */
/*          | INITALIZED FIELD #0 VALUE   |          */
/*          +-----------------------------+          */
/*          | INITALIZED FIELD #1 VALUE   |          */
/*          +-----------------------------+          */
/*          |             .               |          */
/*          |             .               |          */
/*          |             .               |          */
/*          +-----------------------------+          */
/*          | INITALIZED FIELD #i VALUE   | <---- ?? */
/*          +-----------------------------+          */
/*                                                   */
/*****************************************************/
void MIPS_ASM_ALLOCATE_RECORD_IMPLEMENTATION(void)
{
	/*********************/
	/* [1] Function Name */
	/*********************/
	fprintf(fl,"Label_1_AllocateRecord:\n\n");
}

/******************************************/
/* MIPS_ASM_ALLOCATE_ARRAY_IMPLEMENTATION */
/******************************************/
/*******************************************/
/*                    .                    */
/*                    .                    */
/*                    .                    */
/*          +-------------------+          */
/*          |                   |          */
/*          +-------------------+          */
/*          |                   |          */
/*          +-------------------+          */
/* ?? ----> |  SIZE TO ALLOCATE | <---- ?? */
/*          +-------------------+          */
/*          | INITIALIZED VALUE | <---- ?? */
/*          +-------------------+          */
/*          |                   |          */
/*          +-------------------+          */
/*          |                   |          */
/*          +-------------------+          */
/*          |                   |          */
/*          +-------------------+          */
/*                                         */
/*******************************************/
void MIPS_ASM_ALLOCATE_ARRAY_IMPLEMENTATION(void)
{
	/*********************/
	/* [1] Function Name */
	/*********************/
	fprintf(fl,"Label_2_AllocateArray:\n\n");
}

void MIPS_ASM_PRINT_IMPLEMENTATION(void)
{
	/****************************/
	/* [1] Print function label */
	/****************************/
	fprintf(fl,"Label_3_PrintInt:\n\n");

	/**********************************************************/
	/* [2] Load argument to system call parameter register a0 */
	/**********************************************************/
	fprintf(fl,"\tlw $a0,0(%s)\n\n",Temp_look(Temp_name(),SP())); 

	/*****************************************/
	/* [3] print_int system call number is 1 */
	/*****************************************/
	fprintf(fl,"\tli $v0,%d\n\n",1); 

	/******************************/
	/* [4] Invoke the system call */
	/******************************/
	fprintf(fl,"\tsyscall\n\n"); 
	
	/*******************************************************/
	/* [5] Load space ascii as system call parameter to a0 */
	/*******************************************************/
	fprintf(fl,"\tli $a0,%d\n\n",(int)' '); 

	/*******************************************/
	/* [6] print_char system call number is 11 */
	/*******************************************/
	fprintf(fl,"\tli $v0,%d\n\n",11); 

	/******************************/
	/* [7] Invoke the system call */
	/******************************/
	fprintf(fl,"\tsyscall\n\n"); 

	/***************************/
	/* [9] Jump back to caller */
	/***************************/
	fprintf(fl,"\tjr $ra\n\n");
}

/********************************************/
/* MIPS_ASM_ACCESS_VIOLATION_IMPLEMENTATION */
/********************************************/
void MIPS_ASM_ACCESS_VIOLATION_IMPLEMENTATION(void)
{
	char *msg=NULL;

	/****************************/
	/* [1] Print function label */
	/****************************/
	fprintf(fl,"Label_4_Access_Violation:\n\n");

	for (msg="Access Violation";(*msg)!=0;msg++)
	{
		/************************************************/
		/* [2] Load char as system call parameter to a0 */
		/************************************************/
		fprintf(fl,"\tli $a0,%d\n\n",(int) (*msg)); 

		/*******************************************/
		/* [3] print_char system call number is 11 */
		/*******************************************/
		fprintf(fl,"\tli $v0,%d\n\n",11); 

		/******************************/
		/* [4] Invoke the system call */
		/******************************/
		fprintf(fl,"\tsyscall\n\n"); 
	}

	/*****************/
	/* [5] Then exit */
	/*****************/
	fprintf(fl,"\tli $v0,10\n\n");
	fprintf(fl,"\tsyscall\n\n");
}

/*****************/
/* ASM_MIPS_Init */
/*****************/
void MIPS_ASM_Init()
{
	/***************/
	/* Entry Point */
	/***************/
	fprintf(fl,"main:\n\n");
	fprintf(fl,"jal Label_0_main\n\n");
	fprintf(fl,"Label_0_main:\n\n");

	/**************************************************************************/
	/* Allocation of FP in case variables are defined in the outer most scope */
	/**************************************************************************/
	/******************************************************************************/
	/* NOTE: if you want more than 10 variables there - change the 40 accordingly */
	/******************************************************************************/
	fprintf(fl,"\taddi %s,%s,40\n\n", Temp_look(Temp_name(),FP()),Temp_look(Temp_name(),SP()));
}

void MIPS_ASM_External_Functions()
{
	/*******************/
	/* Allocation Code */
	/*******************/
	MIPS_ASM_ALLOCATE_RECORD_IMPLEMENTATION();
	MIPS_ASM_ALLOCATE_ARRAY_IMPLEMENTATION();

	/**************/
	/* Print Code */
	/**************/
	MIPS_ASM_PRINT_IMPLEMENTATION();

	/*************************/
	/* Access Violation Code */
	/*************************/
	MIPS_ASM_ACCESS_VIOLATION_IMPLEMENTATION();
}

/**********************/
/* ASM_MIPS_Terminate */
/**********************/
void MIPS_ASM_Terminate()
{
	fprintf(fl,"\tli $v0,10\n\n");
	fprintf(fl,"\tsyscall\n");
}

/***********************/
/* FUNCTION PROTOTYPES */
/***********************/
static Temp_temp MIPS_ASM_codeGeneration(T_exp IR_tree);

const char *Convert_IR_Binops_To_MIPS_ASM_Binops(T_binOp binop)
{
	switch (binop) {
	case (T_plus):	return "add";
	case (T_minus):	return "sub";
	case (T_mul):	return "mul";
	case (T_div):	return "div";
	case (T_and):	return "and";
	case (T_or):	return "or";
	default:		return "";
	}
}
Temp_temp MIPS_ASM_CodeGeneration_Seq(T_exp t)
{
	/**********************/
	/* [1] first left son */
	/**********************/
	(void) MIPS_ASM_codeGeneration(t->u.SEQ.left);

	/***********************************************/
	/* [2] then return the result of the right son */
	/***********************************************/
 	return MIPS_ASM_codeGeneration(t->u.SEQ.right);
}

Temp_temp MIPS_ASM_CodeGeneration_Mem(T_exp t)
{
	/********************************/
	/* [0] allocate a new temporary */
	/********************************/
	Temp_temp r = Temp_newtemp("");

	/************************************************/
	/* [1] compute memory address, and move it to s */
	/************************************************/
	Temp_temp s = MIPS_ASM_codeGeneration(t->u.MEM);

	/******************************************/
	/* [2] get memory contents from address s */
	/******************************************/
	fprintf(fl,"\tlw %s,0(%s)\n\n",Temp_look(Temp_name(),r),Temp_look(Temp_name(),s));

	/****************/
	/* [3] return r */
	/****************/
	return r;
}

Temp_temp MIPS_ASM_CodeGeneration_Call(T_exp t)
{
	int i=0;
	Temp_temp arg;
	int numParameters=0;
	T_expList expList=t->u.CALL.args;

	/***********************************************************/
	/* [1] save registers $t0-$t7 by pushing them on the stack */
	/***********************************************************/

	/***********************************/
	/* [2] pass all arguments on stack */
	/***********************************/
	/**********************************************************************************************/
	/* NOTE: we copycat visual c++ concept that sp points to the last occupied place on stack     */
	/*       therefore, whenever we want to push something on stack, we first decrement sp, then  */
	/*       write to MEM[sp]                                                                     */
	/**********************************************************************************************/
	for (;expList;expList=expList->tail)
	{
	}

	/***********************************************************************/
	/* [3] jump to function and remember the PC to know where to return to */
	/***********************************************************************/

	/******************************************/
	/* [4] pop outgoing parameters from stack */
	/******************************************/

	/****************************************/
	/* [4] pop registers $t0-$t7 from stack */
	/****************************************/

	/********************/
	/* [5] return value */
	/********************/
	return RV();
}

Temp_temp MIPS_ASM_CodeGeneration_Temp(T_exp t)
{
	/*******************/
	/* [1] clearly ... */
	/*******************/
	return t->u.TEMP;
}

Temp_temp MIPS_ASM_CodeGeneration_Jump(T_exp t)
{
	if (t->u.JUMP.type == T_JUMP_LABEL)
	{
		fprintf(fl,"\tj %s\n\n",Temp_labelstring(t->u.JUMP.u.label));
	}
	if (t->u.JUMP.type == T_JUMP_REGISTER)
	{
		fprintf(fl,"\tjr %s\n\n",Temp_look(Temp_name(),t->u.JUMP.u.temp));
	}

	return NULL;
}

Temp_temp MIPS_ASM_CodeGeneration_Move(T_exp t)
{
	if (t->u.MOVE.dst->kind == T_TEMP)
	{
		/***********************************/
		/* [1] move dst expression to temp */
		/***********************************/
		Temp_temp dst = MIPS_ASM_codeGeneration(t->u.MOVE.dst);

		/***********************************/
		/* [2] move src expression to temp */
		/***********************************/
		Temp_temp src = MIPS_ASM_codeGeneration(t->u.MOVE.src);

		/*********************************/
		/* [3] generate move instruction */
		/*********************************/
		fprintf(fl,"\taddi %s,%s,0\n\n",Temp_look(Temp_name(),dst),Temp_look(Temp_name(),src));
	}
	if (t->u.MOVE.dst->kind == T_MEM)
	{
		/***********************************/
		/* [1] move dst expression to temp */
		/***********************************/
		Temp_temp dst = MIPS_ASM_codeGeneration(t->u.MOVE.dst->u.MEM);

		/***********************************/
		/* [2] move src expression to temp */
		/***********************************/
		Temp_temp src = MIPS_ASM_codeGeneration(t->u.MOVE.src);

		/**********************************/
		/* [3] generate store instruction */
		/**********************************/
		fprintf(fl,"\tsw %s,0(%s)\n\n",Temp_look(Temp_name(),src),Temp_look(Temp_name(),dst));
	}

	return NULL;
}

Temp_temp MIPS_ASM_CodeGeneration_Binop(T_exp t)
{
	/***********************************************/
	/* [0] allocate a new temporary for the result */
	/***********************************************/
	Temp_temp t1 = Temp_newtemp("");

	/*****************************************/
	/* [1] move left operand to t2 temporary */
	/*****************************************/
	Temp_temp t2 = MIPS_ASM_codeGeneration(t->u.BINOP.left);

	/******************************************/
	/* [2] move right operand to t3 temporary */
	/******************************************/
	Temp_temp t3 = MIPS_ASM_codeGeneration(t->u.BINOP.right);

	/**********************************/
	/* [3] generate binop instruction */
	/**********************************/
	fprintf(
		fl,
		"\t%s %s,%s,%s\n\n",
		Convert_IR_Binops_To_MIPS_ASM_Binops(t->u.BINOP.op),
		Temp_look(Temp_name(),t1),
		Temp_look(Temp_name(),t2),
		Temp_look(Temp_name(),t3));

	/*********************/
	/* [4] return result */
	/*********************/
	return t1;
}

Temp_temp MIPS_ASM_CodeGeneration_Label(T_exp t)
{
	/*********************/
	/* [1] that's it ... */
	/*********************/
	fprintf(fl,"%s:\n\n",Temp_labelstring(t->u.LABEL));

	/**************/
	/* [2] return */
	/**************/
	return NULL;
}

Temp_temp MIPS_ASM_CodeGeneration_Const(T_exp t)
{
	Temp_temp r = Temp_newtemp("");

	/****************/
	/* [1] easy ... */
	/****************/
	fprintf(fl,"\tli %s,%d\n\n",Temp_look(Temp_name(),r),t->u.CONST);

	/**************/
	/* [2] return */
	/**************/
	return r;
}

Temp_temp MIPS_ASM_CodeGeneration_Cjump(T_exp t)
{
	Temp_temp operand1 = MIPS_ASM_codeGeneration(t->u.CJUMP.left);
	Temp_temp operand2 = MIPS_ASM_codeGeneration(t->u.CJUMP.right);

	string op1_name = Temp_look(Temp_name(),operand1);
	string op2_name = Temp_look(Temp_name(),operand2);

	string jumpToHereIfTrue = Temp_labelstring(t->u.CJUMP.jumpToHereIfTrue);
	string jumpToHereIfFalse = Temp_labelstring(t->u.CJUMP.jumpToHereIfFalse);

	switch (t->u.CJUMP.op) {
	case (T_eq):

		fprintf(fl,"\tbeq %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tbne %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;

	case (T_ne):

		fprintf(fl,"\tbne %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tbeq %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;

	case (T_lt):

		fprintf(fl,"\tblt %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tbge %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;

	case (T_gt):

		fprintf(fl,"\tbgt %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tble %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;

	case (T_le):

		fprintf(fl,"\tble %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tbgt %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;

	case (T_ge):

		fprintf(fl,"\tbge %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfTrue);
		fprintf(fl,"\tblt %s, %s, %s\n\n",op1_name,op2_name,jumpToHereIfFalse);
		break;
	}

	return NULL;
}

Temp_temp MIPS_ASM_CodeGeneration_Function(T_exp t)
{
	Temp_temp returned_value;

	/***************************/
	/* [0] print function name */
	/***************************/
	fprintf(fl,"%s:\n\n",Temp_labelstring(t->u.FUNCTION.name));

	/*************************/
	/* [1] generate prologue */
	/*************************/
	(void) MIPS_ASM_codeGeneration(t->u.FUNCTION.prologue);

	/******************************************/
	/* [2] generate code for body of function */
	/******************************************/
	returned_value = MIPS_ASM_codeGeneration(t->u.FUNCTION.body);

	/**************************************************/
	/* [3] check if function return value is not void */
	/**************************************************/
	if (returned_value != NULL)
	{
		/*******************************************/
		/* [4] move returned_value temporary to RV */
		/*******************************************/
		fprintf(fl,"\taddi %s,%s,0\n\n",Temp_look(Temp_name(),RV()),Temp_look(Temp_name(),returned_value));

		/*************************/
		/* [5] generate epilogue */
		/*************************/
		(void) MIPS_ASM_codeGeneration(t->u.FUNCTION.epilogue);

		/********************/
		/* [6] return value */
		/********************/
		return RV();
	}

	/**********************************************/
	/* [7] no return value - just do the epilogue */
	/**********************************************/
	if (returned_value == NULL)
	{
		/*************************/
		/* [8] generate epilogue */
		/*************************/
		(void) MIPS_ASM_codeGeneration(t->u.FUNCTION.epilogue);

		/*******************/
		/* [9] return NULL */
		/*******************/
		return NULL;
	}
}

Temp_temp MIPS_ASM_codeGeneration(T_exp IR_tree)
{
	if (IR_tree)
	{
		switch (IR_tree->kind)
		{
		case (T_SEQ):     return MIPS_ASM_CodeGeneration_Seq(     IR_tree);
		case (T_MEM):     return MIPS_ASM_CodeGeneration_Mem(     IR_tree);
		case (T_CALL):    return MIPS_ASM_CodeGeneration_Call(    IR_tree);
		case (T_TEMP):    return MIPS_ASM_CodeGeneration_Temp(    IR_tree);
		case (T_JUMP):    return MIPS_ASM_CodeGeneration_Jump(    IR_tree);
		case (T_MOVE):    return MIPS_ASM_CodeGeneration_Move(    IR_tree);
		case (T_BINOP):   return MIPS_ASM_CodeGeneration_Binop(   IR_tree);
		case (T_LABEL):   return MIPS_ASM_CodeGeneration_Label(   IR_tree);
		case (T_CJUMP):   return MIPS_ASM_CodeGeneration_Cjump(   IR_tree);
		case (T_CONST):   return MIPS_ASM_CodeGeneration_Const(   IR_tree);
		case (T_FUNCTION):return MIPS_ASM_CodeGeneration_Function(IR_tree);
		}
	}
}

/**************************/
/* IR_To_Pseudo_Assembley */
/**************************/
void IR_To_Pseudo_Assembley(T_exp IR_tree,const char *Pseudo_Assembley_Filename)
{
	/************************/
	/* [0] Open output file */
	/************************/
	fl=fopen(Pseudo_Assembley_Filename,"w+t");

	/********************/
	/* [1] Write header */
	/********************/
	MIPS_ASM_Init();

	/************************************/
	/* [2] Generate MIPS assembler code */
	/************************************/
	MIPS_ASM_codeGeneration(IR_tree);

	/**********************/
	/* [3] Write epilogue */
	/**********************/
	MIPS_ASM_Terminate();

	/*******************************************/
	/* [4] Implementation of external funtions */
	/*******************************************/
	MIPS_ASM_External_Functions();

	/*************************/
	/* [5] Close output file */
	/*************************/
	fclose(fl);
}
