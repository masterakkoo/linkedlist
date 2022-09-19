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
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

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
int length(node *head)
{
    int p = 0;
    node *temp = head;
    while (temp!= NULL)
    {
        temp=temp->next;
        p++;
    }
    return p;
}
void append(node *&head, int p)
{
    int l = length(head);
    int count = 1;
    node *tail = head;
    node *ntail;
    node *nhead;
    while (tail->next != NULL)
    {
        if (count == l - p)
        {
            ntail = tail;
            
        }
        if (count == l - p + 1)
        {
            nhead = tail;
        }
        tail = tail->next;
        count++;
    }
    ntail->next = NULL;
    tail->next = head;
    head = nhead; 
}
int main()
{
    node *head = NULL;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insertathead(head, 1);
    display(head);
    cout << endl;
    append(head, 3);
    display(head);
    return 0;
}