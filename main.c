#include <stdio.h>
#include <stdbool.h>
#include "parsexec.h"

static char input[100] = "look around";

static bool getInput(void); 

int main() {
	printf("Welcome to a Little Cave Adventure game I made.\n");
	while (parseAndExecute(input) && getInput());
	printf("Bye!\n");

	return 0;
}

static bool getInput(void){
	printf("\nEnter command --> ");
	return fgets(input, sizeof input, stdin) != NULL;
}	
