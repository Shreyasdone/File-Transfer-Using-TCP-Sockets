#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
typedef struct Employee {
    int emp_id;
    char name[100];
    struct Employee *left;
    struct Employee *right;
} Employee;

// Function to create a new employee node
Employee* createEmployee(int emp_id, char *name) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->emp_id = emp_id;
    strcpy(newEmployee->name, name);
    newEmployee->left = NULL;
    newEmployee->right = NULL;
    return newEmployee;
}

// Function to insert a new employee into the BST
Employee* insertEmployee(Employee* root, int emp_id, char *name) {
    if (root == NULL) {
        return createEmployee(emp_id, name);
    }
    if (emp_id < root->emp_id) {
        root->left = insertEmployee(root->left, emp_id, name);
    } else if (emp_id > root->emp_id) {
        root->right = insertEmployee(root->right, emp_id, name);
    }
    return root;
}

// Function to search for an employee by emp_id
Employee* searchEmployee(Employee* root, int emp_id) {
    if (root == NULL || root->emp_id == emp_id) {
        return root;
    }
    if (emp_id < root->emp_id) {
        return searchEmployee(root->left, emp_id);
    } else {
        return searchEmployee(root->right, emp_id);
    }
}

// Function to perform in-order traversal to print employees in ascending order
void inorderTraversal(Employee* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Employee ID: %d, Name: %s\n", root->emp_id, root->name);
        inorderTraversal(root->right);
    }
}

int main() {
    Employee* root = NULL;
    root = insertEmployee(root, 103, "Alice");
    root = insertEmployee(root, 101, "Bob");
    root = insertEmployee(root, 104, "Charlie");
    root = insertEmployee(root, 102, "David");

    printf("In-order traversal of the BST (sorted by emp_id):\n");
    inorderTraversal(root);

    int search_id = 104;
    Employee* emp = searchEmployee(root, search_id);
    if (emp != NULL) {
        printf("\nEmployee found: ID = %d, Name = %s\n", emp->emp_id, emp->name);
    } else {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }

    return 0;
}
