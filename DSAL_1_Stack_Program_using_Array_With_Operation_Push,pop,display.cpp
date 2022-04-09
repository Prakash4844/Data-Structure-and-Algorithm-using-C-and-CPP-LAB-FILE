#include<iostream>
#define MAX 100

using namespace std;

class stackUsingArray
{       
    private: 
        int top;
        
    public:
        int stack[MAX] = {0};

        void push(int x, int n);
        void pop();
        void displayStack();
    
};

void stackUsingArray::push(int x, int n)
{
    int item = x;
    if(top == n)
    {
        cout << "OverFlow: Stack is Full!";
    }
    else
    {
        top= top+1;
        stack[top] = item;
        cout << "Element Pushed!";
    }
}

void stackUsingArray::pop()
{
    if(stack[top] == 0)
    {
        cout << "UnderFlow: Stack is empty!";
    }
    else
    {
        top = top-1;
        cout << "Element Poped ";
    }
}

void stackUsingArray::displayStack()
{   
    int i = 1;

    if(top==0)
    {
        cout << "Stack is empty!";
    }
    for(i = top; i>0; i--)
    {
        cout << stack[i]<<'\n';
    }
}

int main()
{
    int n= 0, choice = 0, pushElement = 0;

    stackUsingArray stack1;

    cout << "Enter The no. of elements in stack(<100): ";
    cin >> n;

    while(choice != 4)  
    {  
        cout << "\n====Stack Operation====\n"; 
        cout << "\n1.Push\n2.Pop\n3.Show\n4.Exit\n"; 
        cout << "Chose one Option by their no.: ";

        cin >> choice; 
        
        if(choice == 1)
        {
            cout << "Enter The no. to push ";
            cin >> pushElement ;
        }
        switch(choice)  
        {  
            case 1:  
            {   
                stack1.push(pushElement, n);  
                break;  
            }  
            case 2:  
            {  
                stack1.pop();  
                break;  
            }  
            case 3:  
            {  
                stack1.displayStack();  
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
