//Name: Mir Mozin
#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void view();

int item, restart, arr[6], HIGH = 6, max = -1;

//Main function
void main(){
    int option;
PROCESS: //Goto function label
    printf("Enter an option from the menu:\n1 for Push\n2 for Pop\n3 for View\n4 for Exit\n");
    scanf("%d", &option);
    switch (option){
    case 1:
        push();
        break;
    case 2: 
        pop();
        break;
    case 3: 
        view(); 
        break;
    case 4:
        printf("Thanks!");     
        exit(0);
        break;
    default:
        printf("Incorrect option!\n");
        break;
    }
    goto PROCESS;   
}

void push(){
    if(max==HIGH-1)
        printf("Overflow!\n");
    else{
        printf("Enter a value to push: ");
        scanf("%d", &item);
        max +=1;
        arr[max] = item;
    }
}

void pop(){
    if(max==-1)
        printf("Underflow!\n");
    else{
        item = arr[max];
        max -=1;
        printf("Item: %d deleted from Stack!\n", item);
    }
    view();
}

void view(){
    if(max==-1)
        printf("Underflow!\n");
    else{
        printf("Stack elements are: ");
        for(int i=max; i>=0; i--)
            printf("%d ", arr[i]);
        printf("\n");
    }
CHOICE:
    printf("Press '1' to continue\nPress '2' to exit\n");
    scanf("%d", &restart);
    if(restart==1){
        printf("\n");
    }
    else if(restart==2){
        printf("Thanks!");
        exit(0);
    }
    else{
        printf("Incorrect option!\n");
        goto CHOICE;
    }
}