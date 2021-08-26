//Name: Mir Mozin
#include<stdio.h>
#include<stdlib.h>

void insert();
void insertFirst();
void insertEnd();
void insertSpec();

void delete();
void deleteFirst();
void deleteEnd();
void deleteSpec();

void display();
void search();
int counter();

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;

int main(){
    int choice, option;
    while(choice!=6){
        printf("Current number of nodes: %d\n", counter());
        printf("Enter an option from the menu:\n1 for Insertion\n2 for Deletion\n3 for Displaying the list\n");
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
    int option;
    printf("Options:\n1 for Inserting at beginning\n2 for Inserting at end\n3 for Inserting at a specific location\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option){
    case 1:
        insertFirst();
        break;
    case 2:
        insertEnd();
        break;
    case 3:
        insertSpec();
        break;
    default:
        printf("Incorrect option!\n");
        break;
    }
}

void insertEnd(){
    NODE *new,*ptr;
    new=(NODE *)malloc(sizeof(NODE));
    if(new==NULL)
        printf("No space in RAM!\n");
    else{
        printf("Enter value for the node: ");
        scanf("%d", &new->data);
        new->next=NULL;
        if(head==NULL)
            head=new;
        else{
            ptr=head;
            while(ptr->next != NULL)
                ptr=ptr->next;
            ptr->next=new;
        }
    }
}

void insertFirst(){
    NODE *new;
    new=(NODE *)malloc(sizeof(NODE));
    if(new==NULL)
        printf("No space in RAM!\n");
    else{
        printf("Enter value for the node: " );
        scanf("%d",&new->data);
        new->next =NULL;
        if(head==NULL)
                head=new;
        else{
                new->next=head;
                head=new;
        }
    }   
}

void insertSpec(){
    NODE *ptr,*new;
    int i, pos;
    new=(NODE *)malloc(sizeof(NODE));
    if(new==NULL)
        printf("No space in RAM!\n");
    else{
        printf("Enter the position of the node: ");
        scanf("%d", &pos);
        printf("Enter value for the node: ");
        scanf("%d", &new->data);
        new->next=NULL;
        if(pos==0){
            new->next=head;
            head=new;
        }
        else{
            for(i=0, ptr=head; i<pos-1; i++){
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("Position not found!\n");
                    return;
                }
            }
            new->next =ptr->next ;
            ptr->next=new;
        }
    }
}

void display(){
    NODE *ptr;
    if(head==NULL)
        printf("Underflow!\n");
    else{
        ptr=head;
        printf("List elements: ");
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void delete(){
    int option;
    printf("Options:\n1 for Deleting from beginning\n2 for Deleting from end\n3 for Deleting from a specific location\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch(option){
        case 1: 
            deleteFirst();
            break;
        case 2:
            deleteEnd();
            break;
        case 3: 
            deleteSpec();
            break;
        default:
            printf("Incorrect option!\n");
            break;
    }
}

void deleteFirst(){
    NODE *ptr;
    if(ptr==NULL)
        printf("Underflow!\n");
    else{
        ptr=head;
        head=head->next ;
        printf("Node with data '%d' deleted!\n", ptr->data);
        free(ptr);
    }
}

void deleteSpec(){
    int i, pos;
    NODE *new,*ptr;
    if(head==NULL)
        printf("Underflow!\n");
    else{
        printf("Enter the position of the node: ");
        scanf("%d", &pos);
        if(pos==0){
            ptr=head;
            head=head->next;
            printf("Node with data '%d' deleted!\n", ptr->data);
            free(ptr);
        }
        else{
            ptr=head;
            for(i=0; i<pos; i++){
                new=ptr; 
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("Position not found!\n");
                    return;
                }
            }
            new->next =ptr->next ;
            printf("Node with data '%d' deleted!\n", ptr->data);
            free(ptr);
        }
    }
}

void deleteEnd(){
    NODE *new,*ptr;
    if(head==NULL)
        printf("Underflow!\n");
    else if(head->next ==NULL){
        ptr=head;
        head=NULL;
        printf("Node with data '%d' deleted!\n", ptr->data);
        free(ptr);
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            new=ptr;
            ptr=ptr->next;
        }
        new->next=NULL;
        printf("Node with data '%d' deleted!\n", ptr->data);
        free(ptr);
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