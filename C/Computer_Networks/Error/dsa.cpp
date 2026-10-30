#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "employees.txt"

struct Employee {
    int id;
    char name[100];
    int age;
    char department[100];
    char phone[20];
    char email[100];
    float salary;
    char hire_date[20];
};

struct BTreeNode {
    struct Employee* employee;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

struct BTree {
    struct BTreeNode* root;
};

void insert(struct BTree* tree, struct Employee* employee);
void insertNode(struct BTreeNode** node, struct Employee* employee);
void display(struct BTree* tree);
void displayInOrder(struct BTreeNode* node);
struct Employee* search(struct BTree* tree, int id);
struct BTreeNode* searchNode(struct BTreeNode* node, int id);
void saveToFile(struct BTreeNode* node, FILE* file);
void loadFromFile(struct BTree* tree);

int main() {
    struct BTree tree = {NULL};
    int choice;
    loadFromFile(&tree);

    while (1) {
        printf("\n==============================\n");
        printf("      Mini Database System\n");
        printf("==============================\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            struct Employee emp;

            printf("\nEnter ID: ");
            scanf("%d", &emp.id);
            getchar();

            printf("Enter Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("Enter Age: ");
            scanf("%d", &emp.age);
            getchar();

            printf("Enter Department: ");
            fgets(emp.department, sizeof(emp.department), stdin);
            emp.department[strcspn(emp.department, "\n")] = '\0';

            printf("Enter Phone Number: ");
            fgets(emp.phone, sizeof(emp.phone), stdin);
            emp.phone[strcspn(emp.phone, "\n")] = '\0';

            printf("Enter Email: ");
            fgets(emp.email, sizeof(emp.email), stdin);
            emp.email[strcspn(emp.email, "\n")] = '\0';

            printf("Enter Salary: ");
            scanf("%f", &emp.salary);
            getchar();

            printf("Enter Hire Date (YYYY-MM-DD): ");
            fgets(emp.hire_date, sizeof(emp.hire_date), stdin);
            emp.hire_date[strcspn(emp.hire_date, "\n")] = '\0';

            insert(&tree, &emp);

            FILE* file = fopen(FILENAME, "a");
            if (file) {
                fprintf(file, "%d|%s|%d|%s|%s|%s|%.2f|%s\n", emp.id, emp.name, emp.age, emp.department,
                        emp.phone, emp.email, emp.salary, emp.hire_date);
                fclose(file);
            } else {
                printf("\nError saving record to file!\n");
            }

            printf("\nRecord inserted successfully!\n");
        }
        else if (choice == 2) {
            int searchID;
            printf("\nEnter ID to search: ");
            scanf("%d", &searchID);

            struct Employee* result = search(&tree, searchID);
            if (result != NULL) {
                printf("\nEmployee found with ID %d: %s\n", searchID, result->name);
            } else {
                printf("\nEmployee with ID %d not found!\n", searchID);
            }
        }
        else if (choice == 3) {
            printf("\nDisplaying all records:\n");
            display(&tree);
        }
        else if (choice == 4) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }
        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insert(struct BTree* tree, struct Employee* employee) {
    insertNode(&tree->root, employee);
}

void insertNode(struct BTreeNode** node, struct Employee* employee) {
    if (*node == NULL) {
        *node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        (*node)->employee = (struct Employee*)malloc(sizeof(struct Employee));
        memcpy((*node)->employee, employee, sizeof(struct Employee));
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    else if (employee->id < (*node)->employee->id) {
        insertNode(&(*node)->left, employee);
    } else {
        insertNode(&(*node)->right, employee);
    }
}

struct Employee* search(struct BTree* tree, int id) {
    struct BTreeNode* node = searchNode(tree->root, id);
    return node ? node->employee : NULL;
}

struct BTreeNode* searchNode(struct BTreeNode* node, int id) {
    if (node == NULL || node->employee->id == id) {
        return node;
    }

    if (id < node->employee->id) {
        return searchNode(node->left, id);
    }

    return searchNode(node->right, id);
}

void display(struct BTree* tree) {
    displayInOrder(tree->root);
}

void displayInOrder(struct BTreeNode* node) {
    if (node != NULL) {
        displayInOrder(node->left);
        struct Employee* emp = node->employee;
        printf("[ID: %d] Name: %s | Age: %d | Department: %s | Phone: %s | Email: %s | Salary: $%.2f | Hire Date: %s\n",
               emp->id, emp->name, emp->age, emp->department, emp->phone, emp->email, emp->salary, emp->hire_date);
        displayInOrder(node->right);
    }
}

void saveToFile(struct BTreeNode* node, FILE* file) {
    if (node != NULL) {
        saveToFile(node->left, file);
        struct Employee* emp = node->employee;
        fprintf(file, "%d|%s|%d|%s|%s|%s|%.2f|%s\n", emp->id, emp->name, emp->age, emp->department,
                emp.phone, emp.email, emp.salary, emp.hire_date);
        saveToFile(node->right, file);
    }
}

void loadFromFile(struct BTree* tree) {
    FILE* file = fopen(FILENAME, "r");
    if (file) {
        char line[500];
        while (fgets(line, sizeof(line), file)) {
            struct Employee emp;
            sscanf(line, "%d|%[^|]|%d|%[^|]|%[^|]|%[^|]|%f|%[^\n]", &emp.id, emp.name, &emp.age, emp.department,
                   emp.phone, emp.email, &emp.salary, emp.hire_date);
            insert(tree, &emp);
        }
        fclose(file);
    } else {
        printf("No records found in file or error opening file.\n");
    }
}
