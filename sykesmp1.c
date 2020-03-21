/*------------------------------------------------------------------------------
Program file: sykesmp1.c
Author:       Matthew Sykes
Date:         Jan 28, 2020
Assignment:   Program #1
Objective:    This program computes the salary for individual employees and 
              totals the sum of all salaries.  Individual salaries are the 
              product of hours and rate.  Total salary is the sum of all
              individual salaries.
------------------------------------------------------------------------------*/


#include <stdio.h>
int main()

{
	/* Variable Declaration */
	/* -------------------- */
	
    float hours1, hours2;
    float rate1, rate2;
    float salary1, salary2, totalSalary;
    
   
    /* Hours worked and rate of pay for Employee #1 and Employee #2 */
    /* ------------------------------------------------------------ */

    hours1      = 35.50;
    hours2      = 24.25;

    rate1       = 15.50;
    rate2       = 10.75;
    
   
    /* Individual Salary equals product of hours and rate for each employee */
    /* Total Salary equals sum of all individual salaries                   */
    /* -------------------------------------------------------------------- */

    salary1     = hours1 * rate1;
    salary2     = hours2 * rate2;
    totalSalary = salary1 + salary2;
    
    
    /* Display results of Individual Salary and Total Salary */
    /* ----------------------------------------------------- */


    printf("                Sykes Payroll Report \n");
    printf("                --------------------\n\n");

    printf("Employee #1 worked %.2f hours for salary: $ %.2f\n" ,hours1, 
			salary1);
    printf("Employee #2 worked %.2f hours for salary: $ %.2f\n\n" ,hours2, 
			salary2);
    printf("                             Total Salary: $ %.2f\n",totalSalary);


    getchar();

    return 0;

} /* end main */

