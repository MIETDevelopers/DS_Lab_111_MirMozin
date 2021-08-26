//Name: Mir Mozin
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next, * prev;
};
typedef struct node NODE;
NODE * head = NULL;

void insert();
void insertFirst(NODE *);
void insertEnd(NODE *);
void insertSpec(NODE *);

void delete();
void deleteFirst();
void deleteSpec();

int counter();
void search();
void display();

int main(){
    int choice=0;
    while(choice!=5){
        printf("Current number of nodes: %d\n", counter());
        printf("Enter an option from the menu:\n1 for Insertion\n2 for Deletion\n3 for Displaying\n");
        printf("4 for Search\n5 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                insert();
                break;
            case 2: 
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Thanks!");
                exit(0);
            default:
                printf("Incorrect option!\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

void insert(){
    NODE *new; int option;
    new=(NODE *)malloc(sizeof(NODE));
    if(new==NULL)
        printf("No space in RAM!\n");
    else{
        printf("Options:\n1 for Inserting at beginning\n2 for Inserting at end\n3 for Inserting at a specific location\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            insertFirst(new);
            break;
        case 2:
            insertEnd(new);
            break;
        case 3:
            insertSpec(new);
            break;
        default:
            printf("Incorrect option!\n");
            break;
        }
    }
}

void insertFirst(NODE * new){
    printf("Enter value for the node: " );
    scanf("%d", &new->data);
    new->prev = NULL;
    if(head == NULL){
        new->next=NULL;
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }
}

void insertEnd(NODE * new){
    NODE *ptr=head;
    printf("Enter value for the node: " );
    scanf("%d", &new->data);
    new->next=NULL;
    if(head == NULL){
        new->prev=NULL;
        head = new;
    }
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new;
        new->prev=ptr;
   }
}

void insertSpec(NODE * new){
    NODE *ptr = head;
    int pos;
    printf("Enter the position where you want to enter the node: ");
    scanf("%d", &pos);
    printf("Enter value for the node: ");
    scanf("%d", &new->data) ;
    new->next=NULL;
    if(pos==0){
        new->next = head;
        head = new;
    }
    else{
        for(int i=0; i<pos-1;i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Node not found!\n");
                return;
            }
        }
        new->next = ptr->next ;
        ptr->next = new;
    }
}

void delete(){
    if(head==NULL)
        printf("Underflow!\n");
    else{
        int option;
        printf("Options:\n1 for Deleting from beginning\n2 for Deleting from a specific location\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1: 
                deleteFirst();
                break;
            case 2: 
                deleteSpec();
                break;
            default:
                printf("Incorrect option!\n");
                break;
        }
    }
}

void deleteFirst(){
    NODE *ptr = head;
    if(ptr->prev==ptr->next)
        head = NULL;
    else{
        head=ptr-> next;
        head->prev=NULL;
    printf("Node with data '%d' deleted!\n", ptr->data);
    free(ptr);
   }
}

void deleteSpec(){
    int pos;
    NODE *temp, *ptr = head;
    if(head==NULL){
        printf("Underflow!\n");
        return;
    }
    else{
        printf("Enter the position of the node which you want to delete: ");
        scanf("%d", &pos);
        if(pos==0)
            head = head->next;
        else{
            for(int i=0; i<pos; i++){   
                temp = ptr; 
                ptr = ptr->next;
                if(ptr==NULL){
                    printf("Node not found!\n");
                    return;
                }
            }
            temp->next = ptr->next;
        }
        printf("Node with data '%d' deleted!\n", ptr->data);
        free(ptr);
    }
}

int counter(){
    NODE *ptr;
    int flag=0;
    if(head==NULL)
        return 0;
    else{
        for(ptr=head; ptr!=NULL; ptr=ptr->next)
            flag++;
        return flag;
    }
}

void search(){
    NODE *ptr = head;
    int item, flag=0, count=0;
    if(ptr==NULL)
        printf("Underflow!\n");
    else{
        printf("Enter the value you want to search: ");
        scanf("%d", &item);
        for(int i=0; ptr!=NULL; i++){
            if(ptr->data==item){
                printf("Value '%d' found in the list at position '%d'!\n", item, count);
                return;
            }
            else
                flag=1;
            ptr = ptr->next;
            count++;
        }
        if(flag==1)
            printf("Value '%d' not found in the list!\n", item);       
    }
}

void display(){
    NODE *ptr;
    if(head==NULL)
        printf("Underflow!\n");
    else{
        ptr=head;
        printf("List from start: ");
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}