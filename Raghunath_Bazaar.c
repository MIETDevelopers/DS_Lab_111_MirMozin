//Name: Mir Mozin
#include <stdio.h>
#include <stdlib.h>

struct node{
    int item, cost;
    char shop[20];
    struct node * next;
};
typedef struct node NODE;
NODE * head, *ptr1;

void insert();
void cheapest();
void display();

int main(){
    int choice=0;
    while(choice!=4){
        printf("Enter an option from the menu:\n1 for Inserting a record\n2 for Finding cheapest item\n");
        printf("3 for Displaying records\n4 for Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            insert();
            break;
        case 2:
            cheapest();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thanks!\n");
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
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter the name of the shop: ");
    scanf("%s", &temp->shop);
PROCESS:
    printf("Types:\n1 for Walnuts\n2 for Raisins\nItem: ");
    scanf("%d", &temp->item);
    if(temp->item==1 || temp->item==2){
        printf("Enter the price of the item: ");
        scanf("%d", &temp->cost);
        if(head==NULL || temp->cost<=head->cost){
            temp->next=head;
            head=temp;
        }
        else{
            ptr1=head;
            while (ptr1->next!=NULL && ptr1->next->cost < temp->cost){
                ptr1=ptr1->next;
            }
            temp->next = ptr1->next;
            ptr1->next = temp;
        }
        return;
    }
    else{
        printf("Incorrect type!\n");
        goto PROCESS;
    }
}

void cheapest(){
    NODE * temp = head;
    int type;
    if(head==NULL)
        printf("Record empty!\n");
    else{
        while (temp!=NULL){
            if(temp=head){
                printf("Shop with cheapest item details:\n");
                printf("Shop name: %s shop\n", temp->shop);
                type=temp->item;
                switch (type){
                case 1:
                    printf("Item type: Walnuts\n");
                    break;
                case 2: 
                    printf("Item type: Raisins\n");
                    break;
                }
                printf("Item rate: %drs\n", temp->cost);
            }
            temp=temp->next;
            return;
        }
    }
}

void display(){
    NODE * temp = head;
    int type;
    if(head==NULL)
        printf("Record empty!\n");
    else{
        while(temp!=NULL){
            printf("Shop name: %s shop\n", temp->shop);
            type=temp->item;
            switch (type){
            case 1:
                printf("Item type: Walnuts\n");
                break;
            case 2:
                printf("Item type: Raisins\n");
                break;
            }
            printf("Item rate: %drs\n", temp->cost);
            temp=temp->next;
            printf("\n");
        }
        return;
    }
}
