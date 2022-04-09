#include<iostream>
using namespace std;

struct Node
{
    int data;
 	Node *next;
}*tail;

class Circular_LinkedList
{
public:
    void Insert_at_Front(int n);
    void Insert_at_End(int n);
    void Delete_at_Front();
    void Display();
};

int main()
{
    int val = 0;
    int choice;
    
    Circular_LinkedList object;
    
    tail=NULL;

    while(1)
    {	
        cout<<"\n=========Enter Value to Be inserted=============\n";
        cout<<"\n\t1.Insert at Front\n";
        cout<<"\t2.Insert at End\n";
        cout<<"\t3.Delete at Front\n";
        cout<<"\t4.Display Nodes\n";
        cout<<"\t5.Exit\n";
        cout<<" Enter you Choice: \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Value to Be inserted: ";
                cin>> val;

                object.Insert_at_Front(val);
                cout<<"Value " <<val <<" inserted at Front.\n";
                break;
            case 2:
                cout<<"Enter Value to Be inserted: ";
                cin>> val;

                object.Insert_at_End(val);
                cout<<"Value " <<val <<" inserted at End.\n";
                break;
            case 3:
                object.Delete_at_Front();
                cout<<"Value " <<val <<" Deleted at Front.\n";
                break;
            case 4:
                object.Display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"invalid Choice!\n";
        }
    }
return 0;
}

void Circular_LinkedList::Insert_at_Front(int n)
{
 	Node *temp;
    temp=new Node;
    temp->data=n;
    temp->next=NULL;
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
    }
}
    
void Circular_LinkedList::Insert_at_End(int n)
{
  	Node *temp;
    temp=new Node;
    temp->data=n;
    temp->next=NULL;

    if(tail==NULL)
    {
        temp->next=temp;
        tail=temp;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

void Circular_LinkedList::Display()
{
  	Node *front;
    front=tail->next;

    if(tail==NULL)
    {
        cout<<"Empty List: \n";
    }

    cout<<"\tNodes are:\t";

    while(front!=tail)
    {
        cout<<front->data<<" --> ";
        front=front->next;
    }

	if(front==tail)
	{
        cout<<front->data;
	}

    delete front;
    cout<<endl;
}

void Circular_LinkedList::Delete_at_Front()
{
  	Node *temp=new Node;
    temp=tail->next;
    if(tail==NULL)
    {
        cout<<"Empty List\n";
        return;
	}
    if(temp==tail)
    {
        delete temp;

    }
    else
    {
        tail->next=temp->next;
        delete temp;
    }
}