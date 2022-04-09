#include<iostream>
#include<vector>
using namespace std;

class node
{
	public:
		int v;
		node *next;
		node()
        {
			next = NULL;
		}
};

class LinkedList
{
	node *head;
	public:
		
		LinkedList()
        {
			head = NULL;
		}
		
		void insert_at_beginning(int v)
        {
			node *temp = new node();
			temp->v = v;
			temp->next = head;
			head = temp;
		}
		
		void insert_at_end(int v)
        {
			node *temp = new node();
			temp->v = v;
			if (head == NULL)
            {
				head = temp;
			}
			else{
				node *ptr = head;
				
				while (ptr->next != NULL)
                {
					ptr = ptr->next;
				} 
				ptr->next = temp;
			}
		}
		
		void insert_at_given_position(int v, int p)
        {
			node *temp = new node();
			temp->v = v;
			if (p == 0)
            {
				temp->next = head;
				head = temp;
			}
			else
            {
				node *ptr = head;
				
				while(p>1) {
					ptr = ptr->next;
					--p;
				}
				
				temp->next = ptr->next;
				ptr->next = temp;
			}
		}
		
		void delete_at_beginning()
        {
			if (head == NULL)
            {
				cout<<"List is Empty"<<"\n";
			}
			else{
				cout<<"Element Deleted: "<<head->v<<"\n";
				
				node *temp = head;
				
				head = head->next;
				
				delete(temp);
			}
		}
		
		void delete_at_end()
        {
			if (head == NULL)
            {
				cout<<"List is Empty"<<"\n";
			}
			else if (head->next == NULL)
            {
				
				cout<<"Element Deleted: "<<head->v<<"\n";
				delete(head);
				head = NULL;
			}
			else
            {
				
				node *temp = head;
				
				while (temp->next->next != NULL) {
					temp = temp->next;
				}
				
				cout<<"Element Deleted: "<<temp->next->v<<"\n";
				// delete last node
				delete(temp->next);
				
				temp->next = NULL;
			}					
		
		}
		
		void delete_at_given_position(int p)
        {
			if (head == NULL)
            {
				// if list is empty do nothing
				cout<<"List is Empty"<<"\n";
			}
			else
            {
				node *temp, *ptr;
				if (p == 0) 
                {
					
					cout<<"Element Deleted: "<<head->v<<"\n";
					ptr = head;
					head = head->next;
					delete(ptr);
				}
				else
                {
					
					temp = ptr = head;
					while(p>0){
						--p;
						temp = ptr;
						ptr = ptr->next;
					}
					cout<<"Element Deleted: "<<ptr->v<<"\n";
					
					temp->next = ptr->next;
					
					free(ptr);
				}
			}
		
		}
		
		void display()
        {
			if (head == NULL)
            {
				cout<<"List is empty"<<"\n";
			}
			else
            {
				node *temp = head;
				cout<<"Linked List: ";
				while (temp != NULL)
                {
					cout<<temp->v<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<"\n";
			}
		}	
			
};


int main() 
{
	
	cout<<"1 to Insert at the beginning";
	cout<<"\n2 to Insert at the end";
	cout<<"\n3 to Insert at mid";
	cout<<"\n4 to Delete from beginning";
	cout<<"\n5 to Delete from the end";
	cout<<"\n6 to Delete from mid";
	cout<<"\n7 to Display";
	cout<<"\n0 to Exit";
	
	int choice,v,p;
	LinkedList ll;
	do {
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter Element: ";
				cin>>v;
				ll.insert_at_beginning(v);
				break;
				
			case 2:
				cout<<"Enter Element: ";
				cin>>v;
				ll.insert_at_end(v);
				break;
				
			case 3:
				cout<<"Enter Element: ";
				cin>>v;
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.insert_at_given_position(v,p);
				break;
				
			case 4:
				ll.delete_at_beginning();
				break;
				
			case 5:
				ll.delete_at_end();
				break;
				
			case 6:
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.delete_at_given_position(p);
				break;
				
			case 7:
				ll.display();
				break;
				
		}
	} while (choice != 0);
	
}