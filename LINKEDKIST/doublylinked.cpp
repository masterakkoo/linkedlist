using namespace std;
#include <iostream>
class node
{
public:
    int data;
    node *next;
    node *previous;
    node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
    }
};
void insertathead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
    {
        head->previous = n;
    }

    head = n;
}
void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
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
void deleteathead(node* &head)
{
    node* temp=head;
    temp->next->previous=NULL;
    delete temp;
}
void delet(node *&head, int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    int count=1;
    node *temp = head;
    while (count!=pos)
    {
        temp = temp->next;
        count++;
    }
    temp->previous->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
    }
    delete temp;
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insertathead(head, 5);
    display(head);
    cout << endl;
    delet(head, 1);
    display(head);

    return 0;
}