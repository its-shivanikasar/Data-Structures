/*-----------------------------------------------------------------------------------------------------------------------------------------------------
            
                                          Program contains operations performed on linked list using C

-----------------------------------------------------------------------------------------------------------------------------------------*/

/*include header files */

#include <stdio.h>
#include <stdlib.h>

/*defining node strcture of linked List */
typedef struct node
{
    int data;
    struct node *next;
    
}node;


/*function to create a new node */
node* create_node()
{
    node *temp = (node*)malloc(1*sizeof(node));
    
    printf("\nEnter data : ");
    scanf("%d",&temp->data);
    temp->next =NULL;
    
    return temp;    
}


/*function to create new linked list */
node* create_LL()
{
    node *head=NULL,*temp=NULL;
    
    int ch=0;
    
    do
    {  
        if(head==NULL)
            head = create_node();
        else
        {
            temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
                
            temp->next = create_node();
        }   
        
        printf("\nDo you want to continue ?     (press 1 to continue, 0 to exit)");
        scanf("%d",&ch);
        
    }while(ch);

    printf("\n-------------------------------------------");
    printf("\n   Created Linked list successfully!!!   \n");
    printf("-------------------------------------------\n");
    
    return head;    
}

/*function to traverse a linked list */
void traverse_LL(node *head)
{
    printf("\n-------------------------------------------");
    printf("\n\nLinked list : ");
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d --> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
    printf("\n-------------------------------------------\n");
}


/*function to insert node at beginning of linked list */
node* insertAtBegin(node *head)
{
    node *temp = NULL;
    
    temp = create_node();
    
    temp->next = head;
    head = temp;
    
    printf("\n-------------------------------------------");
    printf("\nInserted node successfully at the beginning\n");
    printf("-------------------------------------------\n");
    
    return head;    
}

/*function to insert node at the end of linked list */
node* insertAtEnd(node *head)
{
    node *temp = NULL,*t=head;
    
    temp = create_node();
    
    while(t->next!=NULL)
        t = t->next;
        
    t->next = temp;
    
    printf("\n-------------------------------------------");
    printf("\n  Inserted node successfully at the end  \n");
    printf("-------------------------------------------\n");
    
    return head;    
}

/*function to insert node after given node in a linked list */
node* insertAfterNode(node *head)
{
    int data;
    node *temp = NULL,*t=head;
    
    printf("\n-------------------------------------------");
    printf("\nEnter node after which you want to insert new node : ");
    scanf("%d",&data);
    printf("-------------------------------------------\n");
    
    while(t->next!=NULL && t->data!=data)
        t = t->next;
        
    temp = create_node();
    
    temp->next = t->next;
    t->next = temp;
    
    printf("\n-------------------------------------------");
    printf("\nInserted node successfully after a given node\n");
    printf("-------------------------------------------\n");
    return head;    
}

/*function to delete first node from a linked list*/
node* deleteFromBegin(node *head)
{
    node *temp = head;
    printf("\n-------------------------------------------");
    printf("\n%d node deleted from a linked list\n",temp->data);
    printf("-------------------------------------------\n");

    head = head->next;
    free(temp);
    
    return head;
}

/*function to delete last node from a linked list*/
node* deleteFromEnd(node *head)
{
    node *temp = head,*temp_prev=NULL;
    
    while(temp->next!=NULL)
    {
        temp_prev = temp;
        temp = temp->next;
    }
    
    printf("\n-------------------------------------------");
    printf("\n%d node deleted from a linked list\n",temp->data);
    printf("-------------------------------------------\n");

    temp_prev->next = NULL;
    
    free(temp);
    
    return head;
}

/*function to delete a given node from linked list */
node* deleteNode(node *head)
{
    node *temp = head,*temp_prev=NULL;
    int data;
    
    printf("\n-------------------------------------------");
    printf("\n     Enter node to be delete : ");
    scanf("%d",&data);
    printf("-------------------------------------------\n");
    
    while((temp->next!=NULL) && (temp->data!=data))
    {
        temp_prev = temp;
        temp = temp->next;
    }
    
    temp_prev->next = temp->next;
    
    free(temp);
    
    printf("\n-------------------------------------------");
    printf("\n%d node deleted from a linked list\n",data);
    printf("-------------------------------------------\n");
    
    return head;
}

/*delete whole linked list*/
node* delete_LL(node *head)
{
    node *temp = NULL;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("\n-------------------------------------------");
    printf("\n       Deleted whole Linked List         \n");    
    printf("-------------------------------------------\n");
    
    return head;
}


/*  main method     */

int main()
{
    int ch;
    node *head=NULL;
    
    //menu
    do
    {
        printf("\n-------------------------------------------");
        printf("\n                  Menu                   \n");
        printf("-------------------------------------------\n");
        
        printf("\n 1. Create Linked List");
        printf("\n 2. Traverse Linked List");
        printf("\n 3. Insert node at beginning of Linked List");
        printf("\n 4. Insert node at end of Linked List");
        printf("\n 5. Insert new node after given node in  LL");
        printf("\n 6. Delete node at beginning of Linked List");
        printf("\n 7. Delete node at end of Linked List");
        printf("\n 8. Delete given node from Linked List");
        printf("\n 9. Delete whole Linked List");
        printf("\n10. Exit");
        
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: 
                    {
                        //create new Linked list
                         head = create_LL();
                         break;
                    }
                    
            case 2: {
                         //traverse linked list
                         traverse_LL(head);
                         break;
                    }

            case 3: {
                        //insert node at the beginning of linked list
                        head = insertAtBegin(head);
                        break;
                    }
                    
            case 4: {
                        //insert node at the end of linked list
                        head = insertAtEnd(head);
                        break;
                    }
                    
            case 5: {
                        //insert node after given node
                        head = insertAfterNode(head);
                        break;
                    }
                    
            case 6: {
                        //delete first node from linked list
                        head = deleteFromBegin(head);
                        break;
                    }
                    
            case 7: {
                        //delete last node from linked list
                        head = deleteFromEnd(head);
                        break;
                    }
                    
            case 8: {
                        //delete given node
                        head = deleteNode(head);
                        break;
                    }
            
            case 9: {
                        //delete whole linked list
                        head = delete_LL(head);
                        break;
                    }
                    
            case 10:{
                        //exit from code
                        printf("\nThankyou :) Visit Again!!!");
                        return 0;
                    }
                     
            default:{
                        //by default it will print
                        printf("\nI don't understood what you have entered :( ");
                    }
        }
        
    }while(1);
    
    return 0;
}

//end of code
