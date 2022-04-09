#include<iostream>
using namespace std;

template<typename T>class Node
{
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
        template<typename U>friend class LinkedList;
    public:
        Node()
        {
            this->next = NULL;
            this->prev = NULL;
        }
};

template<typename T>class LinkedList
{
    private:
        Node<T>* head;
    public:
        LinkedList()
        {
            this->head = NULL;
        }

        void add(T item)
        {
            Node<T>* node = new Node<T>[1];
            node->data = item;
            if(head == NULL)
            {
                head = node;
                cout<<"new node added(firstnode) !"<<endl;
                return;
            }
            Node<T>* temp = head;
            Node<T>* prev;
            while(temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            temp->next = node;
            temp->prev = prev;
            cout<<"new node added at back!"<<endl;
        }

        void addFront(T item)
        {
            Node<T>* node = new Node<T>[1];
            node->data = item;
            if(head == NULL)
            {
                head = node;
                cout<<"new node added(firstnode) !"<<endl;
                return;
            }
            head->prev = node;
            node->next = head;
            head = node;
            cout<<"new node added at front !"<<endl;
        }

        void add(int index, T item)
        {
            if(index > length() || index < 0)
            {
                cout<<"index out of bound !"<<endl;
                return;
            }
            Node<T>* node = new Node<T>[1];
            node->data = item;
            int count = 0;
            Node<T>* temp = head;
            while(temp != NULL && count < index)
            {
                if(count == index-1)
                {
                    if(temp->next != NULL)
                    {
                        node->next = temp->next;
                    }
                    temp->next = node;
                    node->prev = temp;
                    cout<<"new node added at index "<<index<<" !"<<endl;
                    break;
                }
                count++;
                temp = temp->next;
            }
            
        }
        int length(){
            int len = 0;
            Node<int>* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            return len;
        }

        void displayAll()
        {
            if(head == NULL)
            {
                cout<<"linked list is empty"<<endl;
                return;
            }
            cout<<endl<<"----link list items------"<<endl;
            Node<T>* temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<" | ";
                temp = temp->next;
            }
            cout<<endl<<"--------------------------"<<endl;
        }
        void remove(int index)
        {
            if(head == NULL)
            {
                cout<<"linked list is empty !"<<endl;
                return;
            }
            if(index >= length() || index < 0)
            {
                cout<<"index out of bound !"<<endl;
                return;
            }
            if(index == 0)
            {
                //removeFront();
                cout<<"item removed at index "<<index<<endl;
                return;
            }
            int count = 0;
            Node<T>* temp = head;
            while(temp != NULL)
            {
                if(count == index - 1)
                {
                    temp->next = temp->next->next;
                    cout<<"item removed at index "<<index<<endl;
                    break;
                }
                count++;
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList<int> list;
    int ch, item, index;
    bool quit = false;
    do{
        cout<<"==========Doubly LinkedList==========="<<endl;
        cout<<"select one of the option :"<<endl;
        cout<<"1: insert back"<<endl;
        cout<<"2: insert front"<<endl;
        cout<<"3: insert at index"<<endl;
        cout<<"4: display items"<<endl;
        cout<<"5: delete at index"<<endl;
        cout<<"6: exit"<<endl;
        cin>>ch;
        
        switch (ch)
        {
        case 1:
            cout<<"enter item to insert:"<<endl;
            cin>>item;
            list.add(item);
            break;
        case 2:
            cout<<"enter item to insert:"<<endl;
            cin>>item;
            list.addFront(item);
            break;
        case 3:
            cout<<"enter item to insert:"<<endl;
            cin>>item;
            cout<<"enter index:"<<endl;
            cin>>index;
            list.add(index, item);
            break;
        case 4:
            list.displayAll();
            break;
        case 5:
            cout<<"enter index:"<<endl;
            cin>>index;
            list.remove(index);
            break;
        case 6:
            quit = true;
            break;
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
    }while(!quit);
    return 0;
}