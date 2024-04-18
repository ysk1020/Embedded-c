/*
Use structures for store data of each 
student (name, rollNbr, marks of 5 subjects, total sum of marks). Roll number of
students - n must be less than 4. Program should print student name, roll number 
total sum
*/

#include <stdio.h>
typedef struct student{
    char name[50];
    int rollNo;
    char subject[5][50];
    float marks[5];
    float total_sum;
}Student;

void totalSum(Student *s){
    s->total_sum = 0;
    for(int i = 0; i < 5; i++){
        s->total_sum += s->marks[i];
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    Student *students = malloc(n *sizeof(int));
    
    for(int i = 0; i < n; i++){
        printf("\nEnter the name of student %d\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].rollNo);
        
        for(int j = 0; j<5; j++){
            printf("Subject name %d: ",j+1);
            scanf("%s", students[i].subject[j]);
            printf("Mark: ");
            scanf("%f", &students[i].marks[j]);
        }
        totalSum(&students[i]);
    }
    
    printf("\nDetails of all students:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll number: %d\n", students[i].rollNo);
        printf("Subject Marks:\n");
        for (int j = 0; j < 5; j++) {

            printf("%d. %s: %.2f\n", j + 1, students[i].subject[j], students[i].marks[j]);
        }
        printf("Total Marks: %.2f\n", students[i].total_sum);
        printf("\n");
    }
    return 0;
}
