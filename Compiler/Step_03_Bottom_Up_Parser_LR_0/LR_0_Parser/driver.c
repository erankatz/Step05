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
#include "Parser.h"

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

	if (Parse())
	{
		printf("\n\nLegal Expression\n\n");
	}
	else
	{
		printf("\n\nIllegal Expression\n\n");
	}
	
	return 0;
}

