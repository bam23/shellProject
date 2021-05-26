/*
 * os.c
 *
 *  Created on: Aug 10, 2011
 *      Author: Ben
 */

#define length 255

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data.h"


int main()
{
	char command[LENGTH];
	char variable1[LENGTH];
	char variable2[LENGTH];

startup();
input(command, variable1, variable2);	

//cinput(command, variable1, variable2);
  
return 0;
}


