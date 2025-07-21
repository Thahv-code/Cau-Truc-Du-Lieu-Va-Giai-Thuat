//
// Created by Thanh on 11/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==== Struct cho Course ====
typedef struct {
    int id;
    char title[100];
    int credit;
} Course;

// ==== Node danh sách đơn (đang học) ====
typedef struct SNode {
    Course course;
    struct SNode *next;
} SNode;

// ==== Node danh sách đôi (đã hoàn thành) ====
typedef struct DNode {
    Course course;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// ==== HEAD pointer ====
SNode *headSingle = NULL;
DNode *headDouble = NULL;
DNode *tailDouble = NULL;

// ==== Thêm khóa học vào danh sách đơn ====
void addCourse() {
    Course c;
    printf("Enter course ID: ");
    scanf("%d", &c.id);
    getchar();
    printf("Enter course title: ");
    fgets(c.title, sizeof(c.title), stdin);
    c.title[strcspn(c.title, "\n")] = '\0';
    printf("Enter credit: ");
    scanf("%d", &c.credit);

    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->course = c;
    newNode->next = headSingle;
    headSingle = newNode;

    printf("✅ Course added successfully!\n");
}

// ==== Hiển thị danh sách khóa học đang học ====
void displayCourses() {
    SNode *temp = headSingle;
    printf("\n--- Current Courses ---\n");
    while (temp) {
        printf("ID: %d | Title: %s | Credit: %d\n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next;
    }
}

// ==== Xóa khóa học theo ID ====
void deleteCourse() {
    int id;
    printf("Enter course ID to delete: ");
    scanf("%d", &id);

    SNode *temp = headSingle, *prev = NULL;
    while (temp) {
        if (temp->course.id == id) {
            if (prev == NULL)
                headSingle = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("✅ Course deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("❌ Course not found.\n");
}

// ==== Cập nhật khóa học ====
void updateCourse() {
    int id;
    printf("Enter course ID to update: ");
    scanf("%d", &id);
    getchar();

    SNode *temp = headSingle;
    while (temp) {
        if (temp->course.id == id) {
            printf("New title: ");
            fgets(temp->course.title, sizeof(temp->course.title), stdin);
            temp->course.title[strcspn(temp->course.title, "\n")] = '\0';
            printf("New credit: ");
            scanf("%d", &temp->course.credit);
            printf("✅ Course updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("❌ Course not found.\n");
}

// ==== Đánh dấu đã hoàn thành ====
void markCompleted() {
    int id;
    printf("Enter course ID to mark as completed: ");
    scanf("%d", &id);

    SNode *temp = headSingle, *prev = NULL;
    while (temp) {
        if (temp->course.id == id) {
            // Xóa khỏi danh sách đơn
            if (prev == NULL)
                headSingle = temp->next;
            else
                prev->next = temp->next;

            // Thêm vào danh sách đôi
            DNode *newNode = (DNode *)malloc(sizeof(DNode));
            newNode->course = temp->course;
            newNode->prev = tailDouble;
            newNode->next = NULL;

            if (tailDouble)
                tailDouble->next = newNode;
            else
                headDouble = newNode;
            tailDouble = newNode;

            free(temp);
            printf("✅ Course marked as completed.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("❌ Course not found.\n");
}

// ==== Sắp xếp theo tín chỉ (đơn giản: bubble sort) ====
void sortCoursesByCredit() {
    if (!headSingle) return;
    int swapped;
    SNode *ptr1;
    SNode *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = headSingle;
        while (ptr1->next != lptr) {
            if (ptr1->course.credit > ptr1->next->course.credit) {
                Course temp = ptr1->course;
                ptr1->course = ptr1->next->course;
                ptr1->next->course = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("✅ Courses sorted by credit.\n");
}

// ==== Tìm kiếm khóa học theo tên ====
void searchCourseByName() {
    char keyword[100];
    getchar();
    printf("Enter course title to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    SNode *temp = headSingle;
    int found = 0;
    while (temp) {
        if (strstr(temp->course.title, keyword)) {
            printf("Found - ID: %d | Title: %s | Credit: %d\n", temp->course.id, temp->course.title, temp->course.credit);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("❌ No matching course found.\n");
}

// ==== Giải phóng bộ nhớ ====
void freeAll() {
    SNode *temp1;
    while (headSingle) {
        temp1 = headSingle;
        headSingle = headSingle->next;
        free(temp1);
    }

    DNode *temp2;
    while (headDouble) {
        temp2 = headDouble;
        headDouble = headDouble->next;
        free(temp2);
    }
}

// ==== Menu chính ====
int main() {
    int choice;
    do {
        printf("\n==== Course Manager ====\n");
        printf("1. Add Course\n");
        printf("2. Display Courses\n");
        printf("3. Delete Course\n");
        printf("4. Update Course\n");
        printf("5. Mark Course as Completed\n");
        printf("6. Sort Courses by Credit\n");
        printf("7. Search Course by Name\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCourse(); break;
            case 2: displayCourses(); break;
            case 3: deleteCourse(); break;
            case 4: updateCourse(); break;
            case 5: markCompleted(); break;
            case 6: sortCoursesByCredit(); break;
            case 7: searchCourseByName(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("❌ Invalid choice!\n");
        }
    } while (choice != 8);

    freeAll();
    return 0;
}
