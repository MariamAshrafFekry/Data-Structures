#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;
template <class T>
class BSTNode
{     // A generic node with 2 pointers
private:
	T key;
	BSTNode<T>* left;
	BSTNode<T>* right;
public:
	BSTNode<T>() { left = right = NULL; }
	BSTNode<T>(T& el, BSTNode* l = NULL, BSTNode* r = NULL){key = el; left = l; right = r;}
	BSTNode<T>* getLeft()  { return left; }
	BSTNode<T>* getRight() { return right; }
	void setLeft(BSTNode<T>* l)   { left = l; }
	void setRight(BSTNode<T>* r)  { right = r; }
	T& getKey()                   { return key; }
};
template <class T>
class BSTFCI {      // Generic binary search tree
protected:
	BSTNode<T>* root;
	bool isBalanced(BSTNode<T> *root)
	{
		int LS;
		int RS;
		if (root == NULL)
			return true;
		LS = height(root->getLeft());
		RS = height(root->getRight());
		if (abs(LS - RS) <= 1 && isBalanced(root->getLeft()) && isBalanced(root->getRight()))
			return true;
		return false;
	}
	//void 
public:
	BSTFCI<T>()   { root = NULL; }
	BSTNode<T>*getnode(){ return root; }
	void clear()   { root = NULL; }
	bool isEmpty() { return root == NULL; }
	T* search(T& el);
	void insert(T el);
	void breadthFirst(void(*visit) (T&));
	bool isbalanced();
	int height(BSTNode<T>*n);
};
template <class T>
void BSTFCI<T>::insert(T el) {
	BSTNode<T>* p = root, *prev = NULL;
	while (p != NULL) {         // Move till correct position
		prev = p;
		if (p->getKey() < el)
			p = p->getRight();
		else p = p->getLeft();
	}
	if (root == NULL)           // If no tree, this is first node
		root = new BSTNode<T>(el);
	else if (prev->getKey() < el)   // Insert right
		prev->setRight(new BSTNode<T>(el));
	else                            // Insert left
		prev->setLeft(new BSTNode<T>(el));
}
template <class T>
T* BSTFCI<T>::search(T& el)
{
	BSTNode<T>* p = root;
	while (p != NULL)          // there is a node
	if (el == p->getKey())  // Found it
		return &p->getKey(); // return data  
	else if (el < p->getKey())    // move left
		p = p->getLeft();
	else p = p->getRight();     // move right
	return NULL;               // NOT found
}
template <class T>
void BSTFCI<T>::breadthFirst(void(*visit) (T&))
{
	queue<BSTNode<T>* > q;
	BSTNode<T>* p = root;
	if (p != NULL)
	{
		q.push(p);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			//cout << (p->getKey()) << "  ";
			visit(p->getKey());
			if (p->getLeft() != NULL)
				q.push(p->getLeft());
			if (p->getRight() != NULL)
				q.push(p->getRight());
		}
		cout << endl;
	}
}
template<class T>
void printKey(T& key)
{
	cout << key << " ";
}
template<class T>
void times2(T& key)
{
	key *= 2;
}

template<class T>
int BSTFCI<T>::height(BSTNode<T>* node)
{
	if (node == NULL)
		return 0;
	return 1 + max(height(node->getLeft()), height(node->getRight()));
}

template<class T>
bool BSTFCI<T>::isbalanced()
{
	return isBalanced(root);
}
int main()
{
	BSTFCI <int>* ba = new BSTFCI<int>();
	ba->insert(1);
	ba->insert(2);
	ba->insert(3);
	ba->insert(4);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl<<endl;
	else
		cout << "Tree not Balanced " << endl << endl;
//-------------------------------------------------------------
	ba = new BSTFCI<int>();
	ba->insert(3);
	ba->insert(1);
	ba->insert(4);
	ba->insert(2);
	ba->insert(5);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl<<endl;
	else
		cout << "Tree not Balanced " << endl << endl;
	//-------------------------------------------------------------
 ba = new BSTFCI<int>();
	ba->insert(5);
	ba->insert(4);
	ba->insert(3);
	ba->insert(2);
	ba->insert(1);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl << endl;
	else
		cout << "Tree not Balanced " << endl << endl;
	//-------------------------------------------------------------
    ba = new BSTFCI<int>();
	ba->insert(7); 
	ba->insert(4);
	ba->insert(15);
	ba->insert(3);
	ba->insert(11);
	ba->insert(25);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl<<endl;
	else
		cout << "Tree not Balanced " << endl<<endl;
	//-------------------------------------------------------------
	ba = new BSTFCI<int>();
	ba->insert(7);
	ba->insert(4);
	ba->insert(15);
	ba->insert(3);
	ba->insert(11);
	ba->insert(25);
	ba->insert(2);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl << endl;
	else
		cout << "Tree not Balanced " << endl << endl;
	//-------------------------------------------------------------
	ba = new BSTFCI<int>();
	ba->insert(5);
	ba->insert(3);
	ba->insert(7);
	ba->insert(1);
	ba->insert(2);
	ba->insert(9);
	ba->insert(10);
	ba->breadthFirst(printKey);
	if (ba->isbalanced())
		cout << "Tree balanced" << endl << endl;
	else
		cout << "Tree not Balanced " << endl << endl;

	system("pause");
	return 0;
}

/*#include<bits\stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
class binarytree
{
private:
	node*root;
	bool balanced(node *n)
	{
		int LS;
		int RS;
		if (n == NULL)
			return true;
		LS = node_height(n->left);
		RS = node_height(n->right);
		if (abs(LS - RS) <= 1 && balanced(n->left) && balanced(n->right))
			return true;
		return false;
	}
public:
	binarytree()
	{
		root = NULL;
	}
	node* getnode()
	{
		return root;
	}
	void insert(int x)
	{
		node*current = root;
		node* n = new node();
		n->data = x;
		n->left = NULL;
		n->right = NULL;

		if (root == NULL)
		{
			root = new node();
			root = n;
			return;
		}
		while (true)
		{
			if (x >= current->data)
			{
				if (current->right != NULL)
				{
					current = current->right;
				}
				else
				{
					current->right = n;
					return;
				}
			}
			else if (x < current->data)
			{
				if (current->left != NULL)
				{
					current = current->left;
				}
				else
				{
					current->left = n;
					return;
				}
			}
		}
	}
	bool search(int x)
	{
		if (root == NULL)
			return false;
		else
		{
			node*current = root;
			while (true)
			{
				if (x > current->data)
				{
					if (current->right != NULL)
					{
						current = current->right;

					}
					else if (current->right == NULL)
						return false;
				}

				else if (x < current->data)
				{
					if (current->left != NULL)
					{
						current = current->left;

					}
					else if (current->left == NULL)
						return false;
				}
				else return true;
			}
		}
	}
	int node_height(node* node)
	{
		if (node == NULL)
			return 0;
		return (max(node_height(node->left) + 1, node_height(node->right) + 1));
	}
	bool isBalanced()
	{
		return balanced(root);
	}
	void inorder(node*n)
	{
		if (n != NULL)
		{
			inorder(n->left);
			std::cout << n->data << "   ";
			inorder(n->right);
		}
	}
	void binarytree::breadthFirst()
	{
		queue<node*>q;
		node* p = root;
		if (p != NULL)
		{
			q.push(p);
			while (!q.empty())
			{
				p = q.front();
				q.pop();
				cout << (p->data) << "   ";
				if (p->left != NULL)
					q.push(p->left);
				if (p->right != NULL)
					q.push(p->right);
			}
			cout << endl;
		}
	}
};

int main()
{
	binarytree x, y, z, w, v;
	x.insert(7);
	x.insert(4);
	x.insert(3);
	x.insert(15);
	x.insert(11);
	x.insert(25);
	if (x.isBalanced())
		cout << "The Tree is balanced" << endl << endl;
	else
		cout << "The Tree is not Balanced " << endl << endl;
	x.inorder(x.getnode());
	cout << endl;
	cout << "breadthFirst : "; x.breadthFirst();
	cout << "\n--------------------------------------------" << endl;
//----------------------------------------------------------------------
	y.insert(5);
	y.insert(3);
	y.insert(2);
	y.insert(1);
	y.insert(7);
	y.insert(9);
	y.insert(10);
	if (y.isBalanced())
		cout << "The Tree is balanced" << endl << endl;
	else
		cout << "The Tree is not Balanced " << endl << endl;
	y.inorder(y.getnode());
	cout << endl;
	cout << "breadthFirst : ";
	y.breadthFirst();
	cout << "\n--------------------------------------------" << endl;
//------------------------------------------------------------------------
	z.insert(1);
	z.insert(2);
	z.insert(3);
	z.insert(4);
	if (z.isBalanced())
		cout << "The Tree is balanced" << endl << endl;
	else
		cout << "The Tree is not Balanced " << endl << endl;
	z.inorder(z.getnode());
	cout << endl;
	cout << "breadthFirst : ";
	z.breadthFirst();
	cout << "\n--------------------------------------------" << endl;
//-----------------------------------------------------------------
	w.insert(5);
	w.insert(4);
	w.insert(3);
	w.insert(2);
	w.insert(1);
	if (w.isBalanced())
		cout << "The Tree is balanced" << endl << endl;
	else
		cout << "The Tree is not Balanced " << endl << endl;
	w.inorder(w.getnode());
	cout << endl;
	cout << "breadthFirst : ";
	w.breadthFirst();
	cout << "\n--------------------------------------------" << endl;
//--------------------------------------------------------------------
	v.insert(6);
	v.insert(4);
	v.insert(7);
	v.insert(3);
	v.insert(5);
	v.insert(8);
	v.insert(1);
	cout << endl;
	if (v.isBalanced())
		cout << "The Tree is balanced" << endl << endl;
	else
		cout << "The Tree is not Balanced " << endl << endl;
	v.inorder(v.getnode());
	cout << endl;
	cout << "breadthFirst : ";
	v.breadthFirst();
	cout << "\n--------------------------------------------" << endl;
//-----------------------------------------------------------------
	system("pause");
	return 0;
}
*/