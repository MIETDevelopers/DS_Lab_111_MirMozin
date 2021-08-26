//Name: Mir Mozin
#include <stdio.h>  
#include <stdlib.h>  

void push();  
void pop();  
void display();  

struct node{  
    int data;  
    struct node *next;  
};
typedef struct node NODE;
NODE *top=0;  
  
void main(){  
    int choice=0;     
    while(choice!=4){  
        printf("Enter an option from the menu:\n1 for Push\n2 for Pop\n");  
        printf("3 for Display\n4 for Exit\n");  
        printf("Enter your choice: ");        
        scanf("%d", &choice);  
        switch(choice){  
            case 1:    
                push();  
                break;   
            case 2:  
                pop();  
                break; 
            case 3: 
                display();  
                break;
            case 4:
                printf("Thanks!");  
                exit(0);
            default:
                printf("Incorrect option!\n");
                break;
        }  
    printf("\n");
    }     
}  

void push (){  
    NODE *new = (NODE*)malloc(sizeof(NODE));   
    if(new == NULL) 
        printf("No space in RAM!\n");
    else{  
        printf("Enter the value: ");  
        scanf("%d", &new->data);  
        if(top==NULL){          
            new->next = NULL;  
            top=new;  
        }   
        else{   
            new->next = top;  
            top=new;      
        }  
        printf("Item '%d' pushed!\n", new->data);  
    }  
}  
  
void pop(){   
    NODE *ptr;  
    if (top==NULL)
        printf("Underflow!\n");  
    else{  
        ptr = top;  
        top = top->next;  
        printf("Item '%d' popped!\n", ptr->data);
        free(ptr);            
    }  
}

void display(){    
    NODE *ptr;  
    ptr=top;  
    if(ptr==NULL)
        printf("Underflow!\n");
    else{  
        printf("Stack elements: ");  
        while(ptr!=NULL){  
            printf("%d ", ptr->data);  
            ptr = ptr->next;  
        }  
        printf("\n");
    }  
}