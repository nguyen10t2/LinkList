#include <iostream>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push_back(struct Node** head,int data){
    if(*head == NULL){
        *head = create(data);
        return;
    }
    while((*head)->next != NULL){
        *head = (*head)->next;
    }
    (*head)->next = create(data);
}
void push_front(struct Node** head,int data){
    struct Node* newNode = create(data);
    newNode->next = *head;
    *head = newNode;
}
//Chen 1 Node vao vi tri index cho truoc
void insert(struct Node** head,int data,int index){
    if(*head == NULL){
        *head = create(data);
    }
    if(index == 0){
        push_front(head, data);
    }
    struct Node* local = *head;
    //local tim vi tri truoc o can chen
    while(--index){
        local = local->next;
        if(index != 0 && local->next == NULL) break;
    }
    struct Node* newNode = create(data);
    newNode->next = local->next;
    local->next = newNode;
}
void del(struct Node** head,int index){
    if(*head == NULL){
        free(head);
        return;
    }
    //dung 2 con tro prev va temp di canh nhau de duyet den index can xoa
    struct Node* prev = NULL;
    struct Node* temp = *head;
    int i = 0;
    while(temp != NULL && i < index){
        prev = temp;
        temp = temp->next;
        ++i;
    }
    if(i != index) return;
    //TH dac biet xoa node dau tien
    if(prev == NULL){
        *head = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void pop_back(struct Node** head){
    struct Node* temp = *head;
    if(temp->next == NULL){
        free(temp);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct Node* rubbish = temp->next;
    temp->next = NULL;
    free(rubbish);
}
void pop_front(struct Node** head){
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void call(struct Node* head){
    while(head != NULL){
        std::cout<<head->data<<"->";
        head = head->next;
    }
    std::cout<<"NULL";
}
int main(){
    struct Node* head = NULL;
    push_back(&head, 3);  //3->null
    push_back(&head, 7);  //3->5->null
    push_front(&head,5);  //5->3->5->null
    insert(&head, 6, 2);  //5->3->6->5->null
    del(&head, 1);        //5->6->5->null
    pop_back(&head);      //5->6->null
    pop_front(&head);     //6->null
    call(head);
}
