#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết đơn
struct Node {
    int data;
    struct Node* next;
};

// Hàm tạo một nút mới với dữ liệu đã cho
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn một nút vào đầu danh sách
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Hàm duyệt và in ra các phần tử của danh sách
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm tìm kiếm một giá trị trong danh sách
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Tìm thấy
        }
        current = current->next;
    }
    return 0; // Không tìm thấy
}

// Hàm xóa một nút từ danh sách
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Xóa nút đầu tiên nếu là nút cần xóa
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Tìm nút cần xóa và nút trước nó
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Nếu không tìm thấy nút cần xóa
    if (temp == NULL) {
        printf("Không tìm thấy nút cần xóa!\n");
        return;
    }

    // Xóa nút khỏi danh sách
    prev->next = temp->next;
    free(temp);
}

// Hàm main
int main() {
    struct Node* head = NULL; // Khởi tạo danh sách rỗng

    // Thêm các nút vào danh sách
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // In ra các phần tử của danh sách
    printf("Danh sách sau khi thêm:\n");
    traverseList(head);

    // Tìm kiếm một giá trị trong danh sách
    int key = 10;
    if (search(head, key)) {
        printf("%d có trong danh sách.\n", key);
    } else {
        printf("%d không có trong danh sách.\n", key);
    }

    // Xóa một nút từ danh sách
    deleteNode(&head, 10);

    // In ra danh sách sau khi xóa
    printf("Danh sách sau khi xóa:\n");
    traverseList(head);

    return 0;
}
