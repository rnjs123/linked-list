#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
struct Node {
    int data;
    struct Node* next;
};

// 새로운 노드를 생성하는 함수
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트의 마지막에 노드를 추가하는 함수
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 리스트를 출력하는 함수
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 메인 함수
int main() {
    struct Node* head = NULL; // 초기 리스트는 빈 상태

    // 노드 추가
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // 리스트 출력
    printf("Linked List: ");
    printList(head);

    return 0;
}
