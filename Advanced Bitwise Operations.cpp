#include<bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    struct Node* next;
    struct Node* prev;
};
 
// Inserts a node at the beginning of the doubly linked list
void push(struct Node** head_ref, char data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node -> data = data;
    new_node-> prev = NULL;
    new_node-> next = (*head_ref);
 
    if((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}
 
void print_register(struct Node* node)
{
    while(node!= NULL)
    {
        printf("%c",node->data);
        node = node->next;
    }
}
 
void left_shift(struct Node** head, char q[])
{
    struct Node* current = *head;
    char temp = (*head)->data;
 
    while(current->next != NULL)
    {
        current->data = (current)->next -> data;
        current = current->next;
    }
    if(current->next == NULL)
        {
            if(strcmp(q,"LS") == 0)
                current->data = '0';
            if(strcmp(q,"LR") == 0)
                current->data = temp;
        }
    //print_register(*head);
}
 
void right_shift(struct Node** head, char q[])
{
    struct Node* current = *head;
    char temp;
    
    // Going till the last node
    while((current)->next != NULL)
        (current) = (current)->next;
   
    temp = (current)->data;
 
    while((current)->prev != NULL)
    {
        current->data = (current)->prev -> data;
        current = current->prev;
    }
    if(current->prev == NULL)
        {
            if(strcmp(q,"RS") == 0)
                current->data = '0';
            if(strcmp(q,"RR") == 0)
                current->data = temp;
        }
    //print_register(*head);
}
 
void increment(struct Node** head)
{
    struct Node* current = (*head);
    while((current)->next != NULL)
        (current) = (current)->next;
 
    while(current!= NULL && (current)->data == '1')
    {
        (current)->data = '0';
        (current) = (current)->prev;
    }
    
    if(current != NULL)
        (current)->data = '1';
 
    //print_register(*head);
}
 
void decrement(struct Node** head)
{
    struct Node* current = (*head);
    while((current)->next != NULL)
        (current) = (current)->next;
 
    while(current!= NULL && current->data == '0')
    {
        (current)->data = '1';
        (current) = (current)->prev;
    }
    if(current != NULL)
        (current)->data = '0';
 
    //print_register(*head);
}
 
int main()
{
    char B[1000];
    static int T;
    struct Node* head = NULL;
 
    //Take the bit string and number of Queries as input
    scanf("%s", B);
    scanf("%d",&T);
 
    int len = strlen(B);
    
    //Insert the characters in the doubly linked list
    for(int i = len-1; i>=0; i--)
        push(&head, B[i]);
 
    //printf("Print the original list--> \n");
    //print_register(head);
     //printf("---------------\n");
 
    while(T--)
    {
 
        char q[4];
        scanf("%s", q);
 
        if(strcmp(q,"LS") == 0)
        {
            left_shift(&head, q);
        }
        else if (strcmp(q,"LR") == 0)
        {
            left_shift(&head,q);
        }
        else if(strcmp(q,"RS") == 0)
        {
            right_shift(&head,q);
        }
        else if(strcmp(q,"RR") == 0)
        {
            right_shift(&head,q);
        }
        else if(strcmp(q,"INC") == 0)
        {
            increment(&head);
        }
        else if(strcmp(q,"DEC") == 0)
        {
            decrement(&head);
        }
        else
        {
            return 0;
        }
    }
 
    //printf("Final list\n");
    print_register(head);
    return 0;
}