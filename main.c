//
//  main.c
//  sykesmp4

#include <stdio.h>
#define NUM_GRADES 3

int main()
{
    int numberOfStudents;
    int grades[NUM_GRADES];
    int id[30];
    int average[30];
    char myName[20];
    int classTotal = 0;
    int totalGrades;
    int classAverage;
    int x, y;
    int sum = 0;
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
            printf("\n***Invalid Entry***\n\n");
    } while (numberOfStudents < 0 || numberOfStudents > 30);
    
    for (x = 1; x <= numberOfStudents; x++)
    {
        do
        {
            printf ("\nEnter ID for student #%i (0-9999): ", x);
            scanf ("%i", &id[x]);
            while ((c = getchar() != '\n') && c != EOF);
            
            if (id[x] < 0 || id[x] > 9999)
                printf ("***Invalid Entry***\n\n");
        } while (id[x] < 0 || id[x] > 9999);
    
        for (y = 0; y < NUM_GRADES; y++)
        {
            do
            {
                printf ("Enter grade #%i: ", y+1);
                scanf("%i", &grades[x]);
                while ((c = getchar() != '\n') && c != EOF);
                
                if (grades[x] < 0 || grades[x] > 100)
                    printf("***Invalid Entry***\n\n");
            } while (grades[x] < 0 || grades[x] > 100);
                
            
                classTotal = classTotal + grades[x];
                totalGrades = NUM_GRADES * numberOfStudents;
                classAverage = classTotal / totalGrades;
        }
        
        
    }
    printf("\n\nClass report for %s\n\n", myName);
    
        printf("ID No.      Grade\n");
    for (x = 1; x <= numberOfStudents; x++)
        printf(" %i           %i      %i\n\n", id[x], grades[x], sum);
    
    printf("The class average of the %i students is %i\n\n", numberOfStudents, classAverage);
    
    
    return 0;
}

