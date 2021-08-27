//Name: Mir Mozin
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next ;
};
typedef struct node NODE;
NODE *front = NULL, *rear = NULL;

void insert(int);
int delete();
void show();

void main(){
    int  num, ch;
    while(ch!=4){
        printf("Enter an option from the menu:\n1 for Insertion\n2 for Deletion\n");      
        printf("3 for Displaying the queue\n4 for Exit\n");  
        printf("Enter your choice: ");
        scanf("%d", &ch) ;
        switch(ch){
            case 1:
                printf("Enter an element: ") ;
                scanf("%d", &num) ;
                insert(num);
                break ;
            case 2:
                printf("Item: %d removed!\n", delete());
                break ;
            case 3:
                show();
                break ;
        }
        printf("\n");
    }
}

void insert(int num){
    NODE *new=(NODE*)malloc(sizeof(NODE));
    if(new==NULL)
        printf("No space in RAM!\n");
    else{
        new->data = num;
        new->next = NULL;
        if(front==NULL)
            front=rear=new;
        else{
            rear->next = new;
            rear=new;
        }
    }
}

void show(){
    NODE *ptr;
    if(front==NULL)
        printf("Underflow!\n") ;
    else{
        printf("Queue elements: ") ;
        ptr=front ;
        while(ptr!=NULL){
            printf("%d ",ptr->data) ;
            ptr=ptr->next ;
        }
        printf("\n");
    }
}

int delete(){
    int  min;
    NODE *ptr, *ptr1, *temp, *temp1 ;
    if(front==NULL)
        printf("Undeflow!\n");
    else{
        temp=temp1=front;
        ptr=ptr1=NULL;
        min=front->data;
        while(temp!=NULL){
            if(temp->data<min){
                min=temp->data;
                ptr1=ptr;
                temp1=temp;
                }
            ptr=temp;
            temp=temp->next;
        }
        if(temp1==front){
            front=front->next;
            if(front==NULL)
                rear=NULL;
            }
        else if(temp1==rear){
            rear=ptr1;
            rear->next=NULL;
            }
        else
            ptr1->next=temp1->next;
        free(temp1);
        return min;
    }
}