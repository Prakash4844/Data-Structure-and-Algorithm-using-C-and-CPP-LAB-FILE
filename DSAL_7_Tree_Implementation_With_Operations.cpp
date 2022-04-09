#include <iostream>

using namespace std;


struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL)
    {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf){

	if(key < leaf->value)
    {
		if(leaf->left != NULL)
        {
			insert(key, leaf->left);
		}
        else
        {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
    else if(key >= leaf->value)
    {
		if(leaf->right != NULL)
        {
			insert(key, leaf->right);
		}
        else
        {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
    cout<<"Element Inserted!\n";
}

void btree::insert(int key){
	if(root != NULL)
    {
		insert(key, root);
	}
    else
    {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value)
        {
			return leaf;
		}
		if(key < leaf->value)
        {
			return search(key, leaf->left);
		}
        else
        {
			return search(key, leaf->right);
		}
	}
    else
    {
		return NULL;
	}
}

node *btree::search(int key)
{
	return search(key, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::inorder_print()
{
    cout<<"InOrder = ";
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf)
{
    
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print()
{
    cout<<"PostOrder = ";
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf)
{
    
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print()
{
    cout<<"PreOrder = ";
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf)
{
    
	if(leaf != NULL)
    {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main()
{
    int choice, val;
	//btree tree;
	btree *tree = new btree();

    while(1)
    {	
        cout<<"\n=========Opertaions on Binary Tree=============\n";
        cout<<"\n\t1.Insert element\n";
        cout<<"\t2.PreOrder print\n";
        cout<<"\t3.PostOrder Print\n";
        cout<<"\t4.Inorder Print\n";
        cout<<"\t5.Exit\n";
        cout<<" Enter you Choice: \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Value to Be inserted: ";
                cin>> val;

                tree->insert(val);
                cout<<"Value " <<val <<" inserted.\n";
                break;
            case 2:
                tree->preorder_print();
                break;
            case 3:
                tree->postorder_print();
                break;
            case 4:
                tree->inorder_print();
                break;
            case 5:
                exit(0);
            default:
                cout<<"invalid Choice!\n";
        }
    }
	delete tree;

}