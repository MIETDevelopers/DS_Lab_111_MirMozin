//Name: Mir Mozin
#include<stdio.h>   
#include<stdlib.h>  

struct node{  
    int data;   
    struct node *next;  
}; 
typedef struct node NODE;
NODE *front = NULL, *rear = NULL;   

void enqueue();  
void dequeue();  
void display(); 

void main (){  
    int choice;   
    while(choice!=4){
        printf("Enter an option from the menu:\n1 for Insertion\n2 for Deletion\n");      
        printf("3 for Displaying the queue\n4 for Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch(choice){  
            case 1:  
                enqueue();  
                break;  
            case 2:  
                dequeue();  
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

void enqueue(){  
    NODE *ptr;
    ptr=(NODE *)malloc(sizeof(NODE));  
    if(ptr == NULL){  
        printf("No space in RAM!\n");  
        return;  
    }  
    else{   
        printf("Enter the value: ");  
        scanf("%d", &ptr->data);
        if(front==NULL){  
            front = rear = ptr;
            front->next = NULL;  
            rear->next = NULL;  
        }  
        else{  
            rear->next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    printf("Item '%d' inserted!\n", ptr->data);
    }  
}     

void dequeue(){  
    NODE *ptr = front;  
    if(front == NULL){  
        printf("Underflow!\n");  
        return;  
    }  
    else{   
        front = front->next;  
        printf("Item '%d' dequeued!\n", ptr->data);
        free(ptr);  
    }  
}  

void display(){  
    NODE *ptr = front;   
    if(front == NULL) 
        printf("Underflow!\n");  
    else{ 
        printf("Queue elements: ");  
        while(ptr!=NULL){  
            printf("%d ", ptr->data);  
            ptr = ptr->next;  
        }  
        printf("\n");
    }  
}  
