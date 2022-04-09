#include<iostream>
#define MAX 5

using namespace std;

class QueueUsingArray
{       
    private: 
        int front = -1, rear = -1;
        
    public:
        int queue[MAX] = {0};
        

        void insertElement(int x );
        void deleteElement();
        void displayQueue();
    
};

void QueueUsingArray::insertElement(int x )
{
    int element = x;
    if(rear == MAX-1)
    {
        cout << "OverFlow: Queue is Full!";
        return;
    }
    if(front == -1 && rear == -1)
    {
        front=0;
        rear=0;
        
    }
    else
    {
        rear = rear+1;
        
    }

    queue[rear] = element;
    cout << "Element Inserted!";
}

void QueueUsingArray::deleteElement()
{
    int val;

    if(front == -1 || front > rear)
    {
        cout << "UnderFlow: Queue is empty!";
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
        else
        {   
            front = front + 1;   
        } 

        cout << "Element deleted";  
    }  
    
}

void QueueUsingArray::displayQueue()
{   
    int i = 0; // = 1;

    if(rear == -1)
    {
        cout << "Queue is empty!";
    }
    else
    {
        cout<<"Queue elements: ";

        for(i=front;i<=rear;i++) 
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    int choice = 0, insertElement = 0;

    QueueUsingArray Queue1;

    // cout << "Enter The no. of elements in Queue(<100): ";
    // cin >> n;

    while(choice != 4)  
    {  
        cout << "\n====Queue Operation====\n"; 
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
                Queue1.displayQueue();  
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
