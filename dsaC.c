#include <stdlib.h>
int que[100];
int rear = -1, front = -1;
int size = 100;
struct Node
{
    int val;
    struct Node *next;
};

void insertfront_double_ended_q(int value , int size){
    if((front == 0 && rear == size -1) || (front  == (rear+1)%size)){
        printf("que is overflow ");
        return;
    }
    if(front == -1){
        front = 0 ;
        que[front] = value;
        return;
    }
    front  = (front - 1+ size)%size;
}
void delete_front_double_ended_q(){
    if (front == - 1){
        printf("que underflow ");
        return;
    }
    if(front == rear ){
        front = rear = -1;
        return;
    }
    front = (front+1)%size;
}
void insert_rear_double_ended_q(int value){
    if((front == 0 && rear == size-1) || ((rear+1) %size == front)){
        printf("the queue is overflow ");
        return;

    }
    if(front == -1){
        front = rear = 0;
        que[rear] = value;
        return;
    }
    rear = (rear+1)%size;
    que[rear] = value;
}
void delete_at_rear_double_ended(){
    
}
void insert_at_pos_csll( struct Node **head , int val , int pos){
    struct Node *newNode = createnode(val);
    if(*head == NULL){
        newNode->next = newNode;
        *head = newNode;
    }
    struct Node *temp = *head;
    
    if(pos == 1){
        do{
        temp = temp->next;
    }while(temp != *head);

        newNode->next = head;
        temp->next = newNode;
        *head = newNode;
        return;
    }
    int i = 1 ;
    for(i ; i < pos-1 &&temp->next !=*head ; i ++ ){
        temp = temp->next;
    }
    if(i != pos-1)
    newNode->next = temp->next;
    temp->next = newNode;
}
void delete_node_at_pos_csll(int pos){
    if(*head == NULL){
        printf("list is empty");
        return;
    }
    struct Node *temp = *head;
    if(pos == 1){
        struct Node *to_delete = *head;
        while(temp->next != *head){
            temp = temp->next; //last node 
        }
        (*head) = (*head)->next;
        temp->next= *head;
        free(to_delete);
        return;

    }
    struct Node *prev = NULL;
    int i = 1;
    for(i ; i < pos &&temp ->next!=*head ; i ++ ){
        prev = temp;
        temp = temp->next;
    }
    if(i != pos ){
        printf("invalid input ");
        return;

    }
    prev->next = temp->next;
    free(temp);
    return;

    
}
void insert_rear_simple_q(struct Node **head , int val ){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    if(newNode == NULL){
        printf("malloc allocation failed");
        return;
    }
    if(front == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = rear;
    rear = newNode;
}
void insert_sLL(struct Node **head , int val , int pos){
    struct Node *newNode = createNode(val);
    if(*head == NULL){
        
        *head = newNode;
        return;
    }
    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for(int i = 1 ; i < pos-1 && temp!= NULL ; i ++){
        temp = temp->next;
    }
    if(temp == NULL ){
        printf("invalid pos");
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void insert_csll(struct Node **head, int val , int pos){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node ));
    newNode->val = val;
    newNode->next = NULL; 
    if(*head == NULL){
        *head = newNode;
        (*head)->next = *head;
        return;
    }

}