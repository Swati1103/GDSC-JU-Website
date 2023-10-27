#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*tail;

void CreateList(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==0){
        head=newnode;
        tail=newnode;
        tail->next=head;
    }else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}

void InsertAtBeg(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==0){
        tail=newnode;
        head=newnode;
        tail->next=head;
    }
    else{
        tail->next=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void countList(){
    temp=head;
    int count=0;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    count++;
    printf("\n%d",count);
}

void InsertAtPosition(int data){
    int i=1,position=3;
    temp=head;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
}

void InsertAtEnd(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==0){
        tail=newnode;
        head=newnode;
        tail->next=head;
    }
    else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}

void DeleteFromBeg(){
    temp=head;
    tail->next=head->next;
    head=head->next;
    free(temp);
}

void DeleteFromEnd(){
    struct node *prev,*current;
    prev=head;
    current=head;
    temp=tail;
    while(current->next!=tail->next){
        prev=current;
        current=current->next;
    }
    prev->next=head;
    tail=prev;      
    free(temp);
}

void DeleteFromPosition(){
    struct node *prevnode,*currentnode,*nextnode;
    currentnode=head;
    prevnode=head;
    nextnode=head;
    int i=1,position=4;
    while(i<position){
      prevnode=currentnode;
      currentnode=currentnode->next;
      nextnode=currentnode->next;
      i++;
    }
    prevnode->next=nextnode;
    free(currentnode);
}

void ReverseList(){
    struct node *prevnode,*currentnode,*nextnode;
    currentnode=tail->next;
    
    if(tail==0){
        printf("List is Empty");
    }
    else{
         while(currentnode!=tail){
            prevnode=currentnode;
            currentnode=nextnode;
            nextnode=currentnode->next;
            currentnode->next=prevnode;
         }
         nextnode->next=tail;
         tail=nextnode;
    }
}

void printList(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("List is Invalid");
    }
    else{
        while(temp->next!=head){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main(){
    CreateList(325);
    CreateList(67367); 
    CreateList(76368);
    CreateList(6326728);
    CreateList(256325);
    CreateList(126712778);
    InsertAtEnd(123456);
    InsertAtBeg(934164);
    InsertAtPosition(96933);
    DeleteFromBeg();
    DeleteFromEnd();
    DeleteFromPosition();
    ReverseList();
    printList();
    countList();
}
