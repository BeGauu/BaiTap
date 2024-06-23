#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ð?nh nghia c?u trúc tam giác
typedef struct {
    double sides[3];
    double perimeter;
    double area;
} Triangle;

// Ham kiem tra tinh hop le cua tam giac
int isValidTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Ham tinh dien tich cua tam giac
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Ham nhap tam giac tu nguoi dung
Triangle inputTriangle() {
    Triangle triangle;
    double a, b, c;

    do {
        printf("Nhap canh thu nhat: ");
        scanf("%lf", &a);
        printf("Nhap canh thu hai: ");
        scanf("%lf", &b);
        printf("Nhap canh thu ba: ");
        scanf("%lf", &c);

        if (!isValidTriangle(a, b, c)) {
            printf("Ba canh nhap vao khong the tao thanh tam giac, hay nhap lai.\n");
        }
    } while (!isValidTriangle(a, b, c));

    triangle.sides[0] = a;
    triangle.sides[1] = b;
    triangle.sides[2] = c;
    triangle.perimeter = a + b + c;
    triangle.area = calculateArea(a, b, c);

    return triangle;
}

// Ham xuat thong tin cua tam giac
void printTriangle(Triangle triangle) {
    printf("Tam giac: [%.2lf, %.2lf, %.2lf]\n", triangle.sides[0], triangle.sides[1], triangle.sides[2]);
    printf("Chu vi: %.2lf\n", triangle.perimeter);
    printf("Dien tich: %.2lf\n", triangle.area);
}


// BST da luu tru theo dien tich
typedef struct TreeNode {
    Triangle triangle;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* bst_root = NULL;

// Ham them mot tam giac vào BST theo dien tich
void insertIntoBST(TreeNode** root, Triangle triangle) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->triangle = triangle;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
    } else {
        TreeNode* current = *root;
        while (1) {
            if (triangle.area < current->triangle.area) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Ham in-order traversal cua BST da in ra thong tin cac tam giac theo dien tich
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printTriangle(root->triangle);
        inOrderTraversal(root->right);
    }
}

// Ham giai phong bo nho cho BST
void freeBST(TreeNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// Ham main da thuc hien nhap, tinh toan và xuat thong tin cac tam giac
int main() {
    Triangle triangles_list[100];  // Gia su toi da 100 tam giác
    int list_size = 0;
    Triangle triangles_stack[100];
    int stack_top = -1;
    Triangle triangles_queue[100];
    int queue_front = 0, queue_rear = -1;
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Nhap tam giac moi\n");
        printf("2. Xuat thong tin tam giac tu List\n");
        printf("3. Xuat thong tin tam giac tu Stack\n");
        printf("4. Xuat thong tin tam giác tu Queue\n");
        printf("5. Xuat thong tin tam giac tu BST theo dien tich\n");
        printf("6. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Nhap tam giac moi và luu vao List, Stack, Queue, BST
                if (list_size < 100) {
                    Triangle new_triangle = inputTriangle();
                    triangles_list[list_size++] = new_triangle;
                    // Them vao Stack
                    if (stack_top < 99) {
                        triangles_stack[++stack_top] = new_triangle;
                    }
                    // Them vao Queue
                    if (queue_rear < 99) {
                        triangles_queue[++queue_rear] = new_triangle;
                    }
                    // Them vao BST
                    insertIntoBST(&bst_root, new_triangle);
                    printf("Da them tam giac vao cac cau truc du lieu.\n");
                } else {
                    printf("Danh sach tam giac day, không the them moi.\n");
                }
                break;
            case 2:
                // Xuat thong tin tam giac tu List
                printf("\nThong tin tam giac tu List:\n");
                for (int i = 0; i < list_size; ++i) {
                    printTriangle(triangles_list[i]);
                }
                break;
            case 3:
                // Xuat thong tin tam giac tu Stack
                printf("\nThong tin tam giac tu Stack (LIFO):\n");
                for (int i = stack_top; i >= 0; --i) {
                    printTriangle(triangles_stack[i]);
                }
                break;
            case 4:
                // Xuat thong tin tam giac tu Queue
                printf("\nThong tin tam giac tu Queue (FIFO):\n");
                for (int i = queue_front; i <= queue_rear; ++i) {
                    printTriangle(triangles_queue[i]);
                }
                break;
            case 5:
                // Xuat thong tin tam giac tu BST theo dien tich
                printf("\nThong tin tam giac tu BST theo dien tich:\n");
                inOrderTraversal(bst_root);
                break;
            case 6:
                // Thoat
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon không hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    // Giai phong bo nho cho BST
    freeBST(bst_root);

    return 0;
}
