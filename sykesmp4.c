/*------------------------------------------------------------------------------
Program file: sykesmp4.c
Author:       Matthew Sykes
Date:         Mar 22, 2020
Assignment:   Program #4
Objective:    This program allows the user to enter up to 30 students as well
              as entering three grades per student.  The program will then take
              the information and generate a grade report which will provide
              the user with the average grade and letter grade of each student
              and will also calculate the average grade for all students
              combined.
------------------------------------------------------------------------------*/
#include <stdio.h>
/* Declare symbolic constant*/
#define NUM_GRADES 3

int main()

/* Declare and initialize variables*/
{
    int numberOfStudents;               /* user can enter up to 30 student */
    int grades[NUM_GRADES];             /* holds 3 integer grades */
    int id[30] = {0};                   /* holds up to 30 student ids */
    int average[30];                    /* stores averages rounded up */
    char myName[20];                    /* stores up to 20 characters for school name */
    int classTotal = 0;                 /* accumulated grades for all students */
    int totalGrades;                    /* total number of grade scores entered */
    int classAverage;                   /* average of grade scores for all students entered */
    int x, y;                           /* loop control variables */
    int sum;                            /* sum of grades for each student */
    char c;                             /* buffer clearing */
    
    /* prompt user to enter name of school*/
    printf ("Please enter your school name: ");
    scanf ("%20[^\n]", myName);
    while ( (c = getchar() != '\n') && c != EOF);
    
    /* Welcome message */
    printf ("\nWelcome to the %s Grade Calculator\n\n", myName);
    
    /* trap loop to validate number of students */
    do
    {   printf ("Please enter the number of students (0-30): ");
        scanf ("%i", &numberOfStudents);
        while ((c = getchar() != '\n') && c != EOF);
        
        if (numberOfStudents < 0 || numberOfStudents > 30)
            printf("\n***Invalid number of students entered.***\n\n");
    } while (numberOfStudents < 0 || numberOfStudents > 30); /* end do loop */
    
    /* loop runs until number of students user entered is met */
    for (x = 1; x <= numberOfStudents; x++)
    {
        /* trap loop to validate student id */
        do
        {
            printf ("\nEnter ID for student #%i (0-9999): ", x);
            scanf ("%d", &id[x]);
            while ((c = getchar() != '\n') && c != EOF);
            
            if (id[x] < 0 || id[x] > 9999)
                printf ("Bad ID number. Please re-enter.\n\n");
        } while (id[x] < 0 || id[x] > 9999); /* end do loop */
        
        printf ("\nNow enter the 3 grades to be averaged\n\n");
        
        /* loop with symbolic constant */
        for (y = 0; y < NUM_GRADES; y++)
        {
            /* trap loop to validate grades */
            do
            {
                printf ("Enter grade #%i: ", y+1);
                scanf("%i", &grades[y]);
                while ((c = getchar() != '\n') && c != EOF);
                
                if (grades[y] < 0 || grades[y] > 100)
                    printf("***Invalid Entry. Grade must be from 0 to 100.\n***");
            } while (grades[y] < 0 || grades[y] > 100); /* end do loop */
            
            /* calculations for sum of grades and average per student */
            sum = grades[0] + grades[1] + grades[2];
            average[x] = sum / 3;
        } /* end for loop*/
        
        /* calculations for class average */
        classTotal = classTotal + sum;
        totalGrades = numberOfStudents * 3;
        classAverage = classTotal / totalGrades;
    } /* end for loop */
    
    /* output grade report */
    printf("\n\nClass report for %s\n\n", myName);
    
    printf("ID No.        Avg.          Grade\n");
    
    /* loop to output info stored in arrays */
    for (x = 1; x <= numberOfStudents; x++)
        
        /* if else statements to ouptut letter grade */
        if (average[x] >= 94 && average[x] <= 100)
            printf("%04d          %i             A\n\n", id[x], average[x]);
        else if (average[x] >= 90 && average[x] <= 93)
            printf("%04d          %i             A-\n\n", id[x], average[x]);
        else if (average[x] >= 87 && average[x] <= 89)
            printf("%04d          %i             B+\n\n", id[x], average[x]);
        else if (average[x] >= 84 && average[x] <= 86)
            printf("%04d          %i             B\n\n", id[x], average[x]);
        else if (average[x] >= 80 && average[x] <= 83)
            printf("%04d          %i             B-\n\n", id[x], average[x]);
        else if (average[x] >= 77 && average[x] <= 79)
            printf("%04d          %i             C+\n\n", id[x], average[x]);
        else if (average[x] >= 74 && average[x] <= 76)
            printf("%04d          %i             C\n\n", id[x], average[x]);
        else if (average[x] >= 70 && average[x] <= 73)
            printf("%04d          %i             C-\n\n", id[x], average[x]);
        else if (average[x] >= 67 && average[x] <= 69)
            printf("%04d          %i             D+\n\n", id[x], average[x]);
        else if (average[x] >= 64 && average[x] <= 66)
            printf("%04d          %i             D\n\n", id[x], average[x]);
        else if (average[x] < 64)
            printf("%04d          %i             F\n\n", id[x], average[x]);
    
        
    /* output class average */
    printf("The average of the %i students is %i\n\n", numberOfStudents, classAverage);
    
    
    
    return 0;
} /* end main */
