/*------------------------------------------------------------------------------
Program file: sykesmp3.c
Author:       Matthew Sykes
Date:         Mar 1, 2020
Assignment:   Program #3
Objective:    This program calculates the total cost and the average cost of 
			  as many lunches purchased as the user wants to enter.  The program
			  will analyze a minimum of two lunches and will only analyze 
			  purchases between $0.01 and $20.00.  If the user inputs fewer than
			  two lunches or a purchase of less than $0.01 or more than $20.00 
			  the user will be faced with an error message and instructions on
			  how to proceed.  The program then analyzes the average cost of 
			  lunches purchased and provides the user with a message regarding
			  the amount of money they are spending on lunch.   	
------------------------------------------------------------------------------*/

#include <stdio.h>
int main ()

{	
	/* Declare and initialize variables */
	/* lunchPurchased = Amount of lunches purchased, counter = Loop index---- */
	/* lunchValue = Cost of lunch purchased, totalValue = Cost of all lunches */
	/* avgCost = Average cost of lunches purchased, c = Buffer clearing------ */
	
	int lunchPurchased, counter = 1;
	float lunchValue, totalValue = 0, avgCost;
	char c;
	
	/* Welcome message and user input instructions                           */
    /* --------------------------------------------------------------------- */
    
    printf ("Welcome to the Sykes Lunches Analyzer.\n\n");
    printf ("This program calculates the average of as many lunches as you\n");
 	printf ("wish to enter.\n\n");
	
	/* Loop statement.  Trap loop will the program in the loop until the 
	   amount of lunches input by the user has been reached and the program
	   will exit the loop.	                                                 */
 	/* Prompt user to enter the cost of the lunches to be analyzed           */
 	/* If user enters fewer than 2 lunches an error message will display and 
	   will instruct the user input at least 2 lunches                       */
	/* --------------------------------------------------------------------- */
	
	do {	    
		printf ("\nEnter the number of lunches to process: ");
		scanf ("%i", &lunchPurchased);
		while ( (c = getchar() != '\n') && c != EOF);	
	
		if (lunchPurchased < 2 )
			
			printf ("\n***Please enter at least two lunches to be analyzed***\n");
		
		} while (lunchPurchased < 2); /* End do loop */
	
	/* Loop Index */
	/* ---------- */
		
	for (counter; counter <= lunchPurchased; counter++)		
	{
 		do
	 	{	
			printf ("Enter lunch value #%i: ", counter);
			scanf ("%f", &lunchValue);
			while ( (c = getchar() != '\n') && c != EOF);
	
	/* If user enters a value less than $0.01 or greater than $20.00 an error
	   message will display and will ask the user to enter a value greater 
	   than $0.01 and less than $20.00.  An invalid amount will not be 
	   included in the the total cost of all lunches purchased               */
	/* --------------------------------------------------------------------- */		
						
 		  	if (lunchValue < 0.01 || lunchValue > 20.00)
			
					printf ("***Please enter an amount between $0.01 and $20.00***\n");
					
	 	} while (lunchValue < 0.01 || lunchValue > 20.00); /* End Do Loop */
	
	/* Calculations for total cost of all lunches and average cost of all 
	   lunches																 */
    /* --------------------------------------------------------------------  */
    
    totalValue = lunchValue + totalValue;
    avgCost = totalValue / lunchPurchased;
			
		}  /* End for loop */
   
   /* Output final totals */
   /* ------------------- */
   
   /* If statements to analyze avg cost and output message based on amount spent */
   /* -------------------------------------------------------------------------  */
   
		printf ("\nYour total for %i lunches is $%.2f\n", lunchPurchased, totalValue);
		printf ("The average of the %i lunches entered is $%.2f\n\n", lunchPurchased, avgCost);
		                                                                    
		if (avgCost <= 7.00)
		
			printf ("You are very economical.");
		
		else if (avgCost >= 7.01 && avgCost <= 9.99)
		
			printf ("You are spending a reasonable amount on your lunches.");
		
		else if (avgCost >= 10.01 && avgCost <= 14.99)
		
			printf ("You are spending a little too much for your lunches.");
		
		else if (avgCost >= 15.00)
		
			printf ("You are spending an excessive amount for your lunches.");
		
	getchar ();
	return (0);
	
} /* End main */
