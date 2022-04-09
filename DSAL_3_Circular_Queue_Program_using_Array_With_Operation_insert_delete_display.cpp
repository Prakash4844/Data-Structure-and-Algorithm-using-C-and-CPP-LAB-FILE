#include<iostream>
#define MAX 5

using namespace std;

class CirQueueUsingArray
{       
    private: 
        int front = -1, rear = -1;
        
    public:
        int queue[MAX] = {0};
        

        void insertElement(int x );
        void deleteElement();
        void displayCirQueue();
    
};

void CirQueueUsingArray::insertElement(int x )
{
    int element = x;
    if((rear+1)%MAX == front)
    {
        cout << "OverFlow: Circular Queue is Full!";
        return;
    }
    if(front == -1 && rear == -1)
    {
        front=0;
        rear=0;
        
    }
    else if(rear == MAX-1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX;
        
    }

    queue[rear] = element;
    cout << "Element Inserted!";
}

void CirQueueUsingArray::deleteElement()
{
    int val;

    if(front == -1 || front > rear)
    {
        cout << "UnderFlow: Circular Queue is empty!";
        return;
    }
    else
    {
        val = queue[front];

        if(front == rear)  
        {  
            front = -1;
            rear = -1; 
        } 
        else if(front == MAX-1)
        {   
            front = 0;   
        } 
        else
        {
            front = front + 1;
        }

        cout << "Element deleted";  
    }  
    
}

void CirQueueUsingArray::displayCirQueue()
{   
    int i=front;  
    if(front==-1)   
    {  
        cout<<"\n Circular Queue is empty..";  
    }  
    else  
    {  
        cout<<"\nElements in a circular Queue are :";  
        if(front<=rear)  
        {  
            while(i <= rear)
            {
                cout<< queue[i]<<" "; 
                i++; 
            }
            
        }
        else 
        {
            while(i<=MAX-1)
            {
                cout<< queue[i]<<" "; 
                i++;
            }
            while(i <= rear)
            {
                cout<< queue[i]<<" "; 
                i++; 
            }
            i=0;

        }  
    }  
}

int main()
{
    int choice = 0, insertElement = 0;

    CirQueueUsingArray Queue1;

    // cout << "Enter The no. of elements in Queue(<100): ";
    // cin >> n;

    while(choice != 4)  
    {  
        cout << "\n====Cirular Queue Operation====\n"; 
        cout << "\n1.insert\n2.Delete\n3.Display\n4.Exit\n"; 
        cout << "Chose one Option by their no.: ";

        cin >> choice; 
        
        if(choice == 1)
        {
            cout << "Enter The element to push ";
            cin >> insertElement ;
        }
        switch(choice)  
        {  
            case 1:  
            {   
                Queue1.insertElement(insertElement);  
                break;  
            }  
            case 2:  
            {  
                Queue1.deleteElement();  
                break;  
            }  
            case 3:  
            {  
                Queue1.displayCirQueue();  
                break;  
            }  
            case 4:   
            {  
                cout << "Exiting....";  
                break;   
            }  
            default:  
            {  
                cout << "Please Enter valid choice ";  
            }   
        };  
    }
    return 0;
}
