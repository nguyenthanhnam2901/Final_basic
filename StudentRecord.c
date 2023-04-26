#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

int n;
student students[1003];

void input() {
    bool numberstudent = false;
    while(!numberstudent)
    {
        printf("Enter the number of students: ");
        printf("\n");
        scanf("%d", &n);
        if(n<0 || n>1000) 
        {
            printf("Invalid number of students. Please try again\n");
        }
        else
        {
            numberstudent = true;
        }
    }

    for(int i = 1; i <= n; ++i) {
        bool validID = false;
        while(!validID) {
            printf("Enter the information of student #%d\n", i);
            printf("ID: ");
            scanf("%s", students[i].id);
            printf("\n");
            // Check if the ID has already been entered
            bool duplicateID = false;
            for (int j = 1; j < i; ++j) {
                if (strcmp(students[j].id, students[i].id) == 0) {
                    duplicateID = true;
                    break;
                }
            }
            if (duplicateID) {
                printf("Duplicate ID. Please enter a different ID.\n");
            } else {
                validID = true;
            }
        }

        printf("Fullname, last name and first name, separated by a space: ");
        scanf("%s%s", students[i].fullName.lastName, students[i].fullName.firstName);
        printf("\n");

        // Validate birthdate input
        bool validBirthdate = false;
        while (!validBirthdate) {
            printf("Birthdate in the format date month year: ");
            scanf("%d%d%d", &students[i].birthDay.day, &students[i].birthDay.month, &students[i].birthDay.year);
            printf("\n");
            if (students[i].birthDay.day < 1 || students[i].birthDay.day > 31 || 
                students[i].birthDay.month < 1 || students[i].birthDay.month > 12 || 
                students[i].birthDay.year < 1) {
                printf("Invalid birthdate. Please try again.\n");
            } else {
                validBirthdate = true;
            }
        }

        // Validate grade input
        bool validGrade = false;
        while (!validGrade) {
            printf("Algebra, Calculus, BP grade, separated by a space: ");
            scanf("%f%f%f", &students[i].grade[0], &students[i].grade[1], &students[i].grade[2]);
            printf("\n");
            if (students[i].grade[0] < 0 || students[i].grade[0] > 20 || 
                students[i].grade[1] < 0 || students[i].grade[1] > 20 || 
                students[i].grade[2] < 0 || students[i].grade[2] > 20) {
                printf("Invalid grade. Please try again.\n");
            } else {
                validGrade = true;
            }
        }
    }
}


void printToFile() {
    FILE* fp = fopen("studentList.txt", "w");
    fprintf(fp, "ID\tFullname\tBirthdate\tAlgebra\tCalculus\tBP\tGPA\n");
    for (int i = 1; i <= n; ++i) {
        fprintf(fp, "%s\t%s %s\t%d/%d/%d\t%.2f\t%.2f\t%.2f\t%.2f\n", 
            students[i].id, 
            students[i].fullName.lastName, students[i].fullName.firstName,
            students[i].birthDay.day, students[i].birthDay.month, students[i].birthDay.year,
            students[i].grade[0], students[i].grade[1], students[i].grade[2], 
            gpa(students[i])
        );
    }
    fclose(fp);
}

int main() {
    input();

    /*
    printf("ID\tFullname\tBirthdate\tAlgebra\tCalculus\tBP\tGPA\n");
    for(int i = 1; i <= n; ++i) {
        printf("%s\t%s %s\t%d/%d/%d\t%.2f\t%.2f\t%.2f\t%.2f\n", 
            students[i].id, 
            students[i].fullName.lastName, students[i].fullName.firstName,
            students[i].birthDay.day, students[i].birthDay.month, students[i].birthDay.year,
            students[i].grade[0], students[i].grade[1], students[i].grade[2], 
            gpa(students[i])
        );
    }
    */
   
    printToFile();

    return 0;
}