//
//  main.c
//  sykesmp4

#include <stdio.h>
#define NUM_GRADES 3

int main()
{
    int numberOfStudents;
    int grades[NUM_GRADES];
    int id[30] = {0};
    int average[30];
    char myName[20];
    int classTotal = 0;
    int totalGrades;
    int classAverage;
    int x, y;
    int sum;
    char c;
    

    printf ("Please enter your school name: ");
    scanf ("%20[^\n]", myName);
    while ( (c = getchar() != '\n') && c != EOF);
    
    printf ("\nWelcome to the %s Grade Calculator\n\n", myName);
    do
    {   printf ("Please enter the number of students (0-30): ");
        scanf ("%i", &numberOfStudents);
        while ((c = getchar() != '\n') && c != EOF);
        
        if (numberOfStudents < 0 || numberOfStudents > 30)
            printf("\n***Invalid number of students entered.***\n\n");
    } while (numberOfStudents < 0 || numberOfStudents > 30);
    
    for (x = 1; x <= numberOfStudents; x++)
    {
        do
        {
            printf ("\nEnter ID for student #%i (0-9999): ", x);
            scanf ("%i", &id[x]);
            while ((c = getchar() != '\n') && c != EOF);
            
            if (id[x] < 0 || id[x] > 9999)
                printf ("Bad ID number. Please re-enter.\n\n");
        } while (id[x] < 0 || id[x] > 9999);
        
            printf ("\nNow enter the 3 grades to be averaged\n\n");
        
        for (y = 0; y < NUM_GRADES; y++)
        {
            do
            {
                printf ("Enter grade #%i: ", y+1);
                scanf("%i", &grades[y]);
                while ((c = getchar() != '\n') && c != EOF);
                
                if (grades[y] < 0 || grades[y] > 100)
                    printf("***Invalid Entry. Grade must be from 0 to 100.\n***");
            } while (grades[y] < 0 || grades[y] > 100);
            sum = grades[0] + grades[1] + grades[2];
            average[x] = sum / 3;
        }
        
        classTotal = classTotal + sum;
        totalGrades = numberOfStudents * 3;
        classAverage = classTotal / totalGrades;
    }
    printf("\n\nClass report for %s\n\n", myName);
    
        printf("ID No.        Avg.          Grade\n");
    for (x = 1; x <= numberOfStudents; x++)
        if (average[x] >= 94 && average[x] <= 100)
            printf("%i            %i             A\n\n", id[x], average[x]);
        else if (average[x] >= 90 && average[x] <= 93)
            printf("%i            %i             A-\n\n", id[x], average[x]);
        else if (average[x] >= 87 && average[x] <= 89)
            printf("%i            %i             B+\n\n", id[x], average[x]);
        else if (average[x] >= 84 && average[x] <= 86)
            printf("%i            %i             B\n\n", id[x], average[x]);
        else if (average[x] >= 80 && average[x] <= 83)
            printf("%i            %i             B-\n\n", id[x], average[x]);
        else if (average[x] >= 77 && average[x] <= 79)
            printf("%i            %i             C+\n\n", id[x], average[x]);
        else if (average[x] >= 74 && average[x] <= 76)
            printf("%i            %i             C\n\n", id[x], average[x]);
        else if (average[x] >= 70 && average[x] <= 73)
            printf("%i            %i             C-\n\n", id[x], average[x]);
        else if (average[x] >= 67 && average[x] <= 69)
            printf("%i            %i             D+\n\n", id[x], average[x]);
        else if (average[x] >= 64 && average[x] <= 66)
            printf("%i            %i             D\n\n", id[x], average[x]);
        else if (average[x] < 64)
            printf("%i            %i             F\n\n", id[x], average[x]);
    
        
    
    printf("The average of the %i students is %i\n\n", numberOfStudents, classAverage);
    
    
    
    return 0;
}
