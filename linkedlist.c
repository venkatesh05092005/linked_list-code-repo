#include<stdio.h>
#include<stdlib.h>

struct Node {
    //createing node structer with data and self referential
    int data;
    struct Node *next;  // a pointer that can pointer another structer
}ListNode;


struct Node *head=NULL;


void addAtIndex(struct Node **h,int val,int index) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
   
    if(index == 0) {
        newNode->next = *h;
        *h = newNode;
        return;
    }
    struct Node* temp = *h;
    for(int i = 0; temp != NULL && i < index-1; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Index %d is out of range!\n", index);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void addAtBe(struct Node **head,int val) {
    //creating a newnode and data:val,link:NULL
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    //pointing to the newnode to head and head is newnode, 
    newNode->next = *head;
    *head = newNode;
}
void addAtEnd(struct Node **head,int val) {

    // creating a newnode of data:val and link: NULL
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {  // If the list is empty
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while(temp->next !=NULL) {  //traversl to last node
        temp = temp->next;
    }
    temp->next = newNode; //assign newnode to last node
}
void display(struct Node *head) {

    // current node will traversel all the elements
    struct Node *curr = head;
    while(curr!=NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL \n ");
}

 void alloperations() {
     printf("\nSelect your operation:\n\n");
     printf("1.insertation at Beginnig\n");
     printf("2.insertation at end\n");
     printf("3.insertation at index\n");
     printf("4.deletion at Beginnig\n");
     printf("5.deletion at end\n");
     printf("6.deletion at index\n");
     printf("7.Display LinkedList\n");
     printf("8.Search Element\n");
     printf("9.Free and Exit\n");
     printf("Enter: ");
 }

 void delAtBe(struct Node **head) {
    if(*head == NULL) {
        printf("List is empmty!\n");
        return;
    }
     struct Node *temp = *head;
     (*head) = (*head)->next;
     free(temp);
 }
 void delAtEnd(struct Node **head) {
      if (*head == NULL) {  // empty list
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) {  // only one node
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    // stop at second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);     // delete last node
    temp->next = NULL;    // mark new end
 }

 void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;         // store current node
        head = head->next;   // move to next node
        free(temp);          // free current node
    }
}

void delAtIndex(struct Node **h,int idx) {
    if(*h== NULL) {  
        printf("List is empty!\n");
        return;
    }

    if((*h)->next == NULL) {  // only one node
        free(*h);
        *h = NULL;
        return;
    }
    if (idx == 0) { // delete at beginning
    struct Node *temp = *h;
    *h = (*h)->next;
    free(temp);
    return;
}


    struct Node *temp = *h;
    for (int i = 0; temp->next != NULL && i < idx - 1;i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index %d out of range!\n", idx);
        return;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}
int search(struct Node* head,int tar) {
    struct Node *temp = head;
    int c =0;
    while(temp!= NULL) {
        if(temp->data == tar) {
            return c;
        } else {
            temp = temp->next;
            c++;
        }
    }
    return -1;
}

void debugPrint(struct Node* head) {
    int i = 0;
    for (struct Node* t = head; t != NULL; t = t->next, i++) {
        printf("[%d]=%d ", i, t->data);
    }
    puts("");
}

int main() {
     printf("\n\t--------Welcome to LinkedList Application---------\t\n");
    int ch,val;
    while (1)
    {   
        alloperations();
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter your element: ");
            scanf("%d", &val);
            addAtBe(&head, val);
            printf("After inserting element into LL: \t");
            display(head);
        }else if(ch ==2) {
              printf("Enter your element: ");
            scanf("%d", &val);
            addAtEnd(&head, val);
             printf("After inserting element into LL: \t");
            display(head);
        } else if(ch == 3) {
            int idx;
            printf("Enter your Index to insert into LL: ");
            scanf("%d", &idx);
            printf("\nEnter your element: ");
            scanf("%d", &val);
            addAtIndex(&head, val, idx);
             printf("After inserting element into LL: \t");
            display(head);
        }else if(ch == 4) {
            delAtBe(&head);
            printf("After deleting your elements:  \t");
            display(head);
        } else if(ch == 5) {
            delAtEnd(&head);
            printf("After deleting your elements:  \t");
            display(head);
        } else if(ch == 6) {
            int ind;
            printf("Enter your index to delete: ");
            scanf("%d", &ind);
            delAtIndex(&head, ind);
            printf("After deleting your elements:  \t");
            display(head);
        }
        else if(ch ==9) {
            freeList(head);
            printf("\n\t----------End of LinkedList Application--------\t\n");
            break;
        }else if(ch == 7) {
            display(head);
        }else if(ch==8) {
            printf("Enter to Find your element in LL: ");
            scanf("%d",&val);
            int tar = search(head, val);
            if(tar !=-1) {
                printf("Found at Index: %d \n", tar);
                debugPrint(head);
            }
            else {
                printf("Not Found In LL\n");
            }
        }
        else {
            printf("Entered Invalid option\n");
        }
    }
    return 0;
}

