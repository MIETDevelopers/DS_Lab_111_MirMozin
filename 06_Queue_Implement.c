//Name: Mir Mozin
#include <stdio.h>
#include<stdlib.h>

void enqueue(int []);
void dequeue(int []);
void display(int []);

int size, rear = -1, front = -1;

int main(){
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    int *queue = (int*)malloc(size*sizeof(int));
    int choice=0;
    while (choice!=4){
        printf("Enter an option from the menu:\n");\
        printf("1 for Inserting element to the queue\n2 for Deleting element from the queue\n");
        printf("3 for Displaying elements\n4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            enqueue(queue);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            printf("Thanks!");
            exit(0);
        default:
            printf("Incorrect option!\n");
        }
    printf("\n");
    }
    free(queue);
}
void enqueue(int queue[]){
    int num;
    //Check if the queue is full
    if(rear==size-1)
        printf("Overflow!\n");
    else{ 
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else 
            rear=rear+1;
        printf("Enter an element: ");
        scanf("%d", &num);
        printf("\n");
        queue[rear] = num;
    }
}
void dequeue(int queue[]){
    //Check if the queue is empty
    if (front==-1 || front>rear)
        printf("Underflow!\n");
    else{ 
        printf("Item %d dequeued!\n", queue[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=front+1;
    }
} 
void display(int queue[]){
    if(front==-1)
        printf("Underflow!\n");
    else{
        printf("Queue elements: ");
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}