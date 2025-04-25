#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
typedef struct {
    char name[50];
    char roll_number[15];
    char course[50];
    char semester[10];
    float cgpa;
} Student;

// Function to display a welcome screen
void display_welcome_screen() {
    printf("========================================\n");
    printf("   Welcome to Student Management System \n");
    printf("========================================\n");
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to add a new student
void add_student(Student students[], int *num_students) {
    if (*num_students < MAX_STUDENTS) {
        printf("Enter student name: ");
        fgets(students[*num_students].name, sizeof(students[*num_students].name), stdin);
        students[*num_students].name[strcspn(students[*num_students].name, "\n")] = '\0'; // Remove newline

        printf("Enter roll number: ");
        fgets(students[*num_students].roll_number, sizeof(students[*num_students].roll_number), stdin);
        students[*num_students].roll_number[strcspn(students[*num_students].roll_number, "\n")] = '\0';

        printf("Enter course: ");
        fgets(students[*num_students].course, sizeof(students[*num_students].course), stdin);
        students[*num_students].course[strcspn(students[*num_students].course, "\n")] = '\0';

        printf("Enter semester: ");
        fgets(students[*num_students].semester, sizeof(students[*num_students].semester), stdin);
        students[*num_students].semester[strcspn(students[*num_students].semester, "\n")] = '\0';

        printf("Enter CGPA: ");
        scanf("%f", &students[*num_students].cgpa);
        getchar(); // Consume leftover newline

        (*num_students)++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

// Function to display all students
void display_students(Student students[], int num_students) {
    if (num_students == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("List of Students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %s\n", students[i].roll_number);
        printf("Course: %s\n", students[i].course);
        printf("Semester: %s\n", students[i].semester);
        printf("CGPA: %.2f\n\n", students[i].cgpa);
    }
}

// Function to search for a student by roll number
void search_student(Student students[], int num_students) {
    char roll_number[15];
    printf("Enter roll number to search: ");
    fgets(roll_number, sizeof(roll_number), stdin);
    roll_number[strcspn(roll_number, "\n")] = '\0';

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].roll_number, roll_number) == 0) {
            printf("Student found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %s\n", students[i].semester);
            printf("CGPA: %.2f\n", students[i].cgpa);
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to delete a student by roll number
void delete_student(Student students[], int *num_students) {
    char roll_number[15];
    printf("Enter roll number to delete: ");
    fgets(roll_number, sizeof(roll_number), stdin);
    roll_number[strcspn(roll_number, "\n")] = '\0';

    for (int i = 0; i < *num_students; i++) {
        if (strcmp(students[i].roll_number, roll_number) == 0) {
            for (int j = i; j < *num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            (*num_students)--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;

    // Display the welcome screen
    display_welcome_screen();

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                display_students(students, num_students);
                break;
            case 3:
                search_student(students, num_students);
                break;
            case 4:
                delete_student(students, &num_students);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
