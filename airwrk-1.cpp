#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void displayList(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void merger(node* head1, node* head2, node* &res)
{
    if(head1->data < head2->data)
    {
        res = head1;
        head1 = head1->next;
    }
    else
    {
        res = head2;
        head2 = head2->next;
    }
    node* a;
    a = res;

    while(head1 && head2)
    {
        if(head1->data<head2->data)
        {
            a->next = head1;
            head1 = head1->next;
        }
        else
        {
            a->next = head2;
            head2 = head2->next;
        }
        a = a->next;
    }

    if(head1!=NULL)
    {
        a->next = head1;
    }
    else
    {
        a->next = head2;
    }
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* res = NULL;
    int n1, n2, x, i;
    cout<<"Enter length of 1st list: ";
    cin>>n1;
    cout<<"Enter length of 2nd list: ";
    cin>>n2;
    if(n1!=0) cout<<"First linked list"<<endl;
    for(i=n1; i>=1; i--)
    {
        cin>>x;
        insertAtTail(head1, x);
    }
    if(n2!=0) cout<<"Second linked list"<<endl;
    for(i=n2; i>=1; i--)
    {
        cin>>x;
        insertAtTail(head2, x);
    }
    if(n1==0)
    {
        displayList(head2);
        return 0;
    }
    else if(n2==0)
    {
        displayList(head1);
        return 0;
    }
    else
    {
        merger(head1, head2, res);
    }
    displayList(res);
}
