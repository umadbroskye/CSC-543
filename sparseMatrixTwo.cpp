#include <iostream>
#include <vector>

struct node {
public:
    int row;
    int column;
    int value;
    node* next;

    node(int r, int c, int v) : row(r), column(c), value(v), next(nullptr) {}
};

void alternatePrint(node* start, int count) { //Alternative way to print. Created to be "cleaner" version. Faster if the linked list is small. 
    std::vector<std::vector<int>> printMatrix(3, std::vector<int>(count, 0));

    node* ptr = start;
    for (int i = 0; i < count; i++) {
        printMatrix[0][i] = ptr->row;
        printMatrix[1][i] = ptr->column;
        printMatrix[2][i] = ptr->value;
        ptr = ptr->next;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count; j++) {
            std::cout << printMatrix[i][j];
        }
        std::cout << std::endl;
    }
    
}

void printList(node* start)
{
    node* ptr = start;
    while (ptr)
    {
        std::cout << ptr->row;
        ptr = ptr->next;
    }
    std::cout << std::endl;

    ptr = start;
    while (ptr)
    {
        std::cout << ptr->column;
        ptr = ptr->next;
    }
    std::cout << std::endl;
    ptr = start;

    while (ptr)
    {
        std::cout << ptr->value;
        ptr = ptr->next;
    }
    std::cout << std::endl;

}

int main()
{
    int rows = 0;
    int columns = 0;

    std::cout << "Enter the number of rows and columns seperated by a space : "; //User input for everything to get full credit
    if (scanf_s("%d%d", &rows, &columns) != 2 || rows <= 0 || columns <= 0) {
        std::cout << "Invalid input for rows or columns. Exiting." << std::endl;
        return 1;
    }
    std::vector<std::vector<int>> sparseMatrix(rows, std::vector<int>(columns, 0));

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {
            std::cout << "Enter the contents of matrix[" << i << "][" << j << "]: ";
            if (scanf_s("%d", &sparseMatrix[i][j]) != 1) {
                std::cout << "Invalid input for matrix element. Exiting." << std::endl;
                return 1;
            }
        }
    }

    node* head = nullptr;
    node* tail = nullptr;

    //int printCount = 0;

    int n = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (sparseMatrix[i][j] != 0) {

                node* newNode = new node(i, j, sparseMatrix[i][j]);

                if (!head) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = newNode;
                }

                //printCount++;
            }
        }
    }

    //alternatePrint(head, printCount);
    printList(head);
}
