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
    while (temp!= NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void delet(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next->next == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = temp->next->next;
    }
}
node* reverse(node* &head)
{
    node *temp = head;
    node *prev = NULL;
    node* nextp;
    while (temp!= NULL)
    {
        nextp=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextp;
    }
    while(prev!=NULL){
    cout<<prev->data<<"->";
    prev=prev->next;
    }
    return prev;
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    display(head);
    // cout << endl;
    // delet(head,2);
    // delet(head,4);
    // delet(head,3);
    reverse(head);
    // node *nhead = reverse(head);
    // display(nhead);
    return 0;
}
