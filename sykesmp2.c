/*------------------------------------------------------------------------------
Program file: sykesmp2.c
Author:       Matthew Sykes
Date:         Feb 16, 2020
Assignment:   Program #2
Objective:    This program calculates the miles per gallon for three tanks of 
		      gas after the user inputs the gallons used and the miles driven 
			  for each tank, as well as calculating the average miles per gallon
			  for all three tanks combined.   	
------------------------------------------------------------------------------*/



#include <stdio.h>
int main()
{
	/* Variable declaration                                             */
	/* Initialize variables: x, totalGallons, totalMiles, tanksUsed     */
	/* x = Loop index                                                   */
	/* totalMiles and totalGallons = Accumulators for miles and gallons */
	/* mpg = Miles Per Gallon, totalMpg = Total Miles Per Gallon        */
	/* c = Clear input buffer                                           */
	/* ---------------------------------------------------------------- */
	
    int   x = 1, tanksUsed = 3;
    float gallons, miles, mpg;
    float totalGallons = 0, totalMiles = 0, totalMpg;
    char  c;
    
   
    /* Welcome message and user input instructions                      */
    /* ---------------------------------------------------------------- */
    
	printf("Welcome to the Sykes Mileage Analysis\n\n");
    
    printf("This program will calculate the miles per gallon for you for three\n"
           "tanks of gas after you have entered the gallons used and miles driven.\n\n");
		    
    /* Loop statement                                                   */
	/* ---------------------------------------------------------------- */
	
	/* Prompt user to enter gallons used and miles driven               */
	/* ---------------------------------------------------------------- */
		      
    for(x = 1; x <= tanksUsed; x++)
    {
    	printf("Enter the number of gallons used for tank #%i: ", x);
        scanf("%f", &gallons);
        while ( (c = getchar() != '\n') && c != EOF);
        
        printf("Enter the number of miles driven: ");
        scanf("%f", &miles);
        while ( (c = getchar() != '\n') && c != EOF);
              
 		/* Calculate mpg for each tank and accumulate totals for miles   
           and gallons for final calculation                             */
		/* ------------------------------------------------------------- */
		        	
        mpg = miles / gallons;
        printf("**The miles per gallon for this tank is: %.1f\n\n", mpg);
        
        totalGallons = totalGallons + gallons;
        totalMiles = totalMiles + miles;
  } /* End for loop */
    
    /* Output final total */
    /* ------------------ */
    
	totalMpg = totalMiles / totalGallons;
    printf("Your overall miles per gallon for three tanks is %.1f\n", totalMpg);
    
    /* Output farewell greeting */
    /* ------------------------ */
    
    printf("\nThank you for using the Sykes Mileage Analysis program.\n");
    
    getchar();
    return 0;
    
} /* end main */

