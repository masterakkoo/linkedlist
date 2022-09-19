using namespace std;
#include <iostream>
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

    

void insert(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
bool checkcycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
void makecycle(node* &head,int p)
{
    int count=0;
    node* temp=head;
   while (temp->next!=NULL)
   {
    temp=temp->next;
   }
   node* n=head;
   while(count!=p)
   {
    n=n->next;
    count++;
   }
   temp->next=n;
}
void removecycle(node* &head)
{
   node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
           
    }while (slow != fast);
     fast=head;
    while(slow->next!=fast->next)
    {
       fast= fast->next;
       slow=slow->next;
    }
    slow->next=NULL;
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    display(head);
    cout<<endl;
     cout<<checkcycle(head);
     cout<<endl;
    makecycle(head,3);
     cout<<checkcycle(head);
     cout<<endl;
     removecycle(head);
    display(head);
    return 0;
}