
#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

//the structer of each node in the tree
template <typename T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

//the class for Binary Search Tree (BST)
template <typename T>
class BST
{
public:
	BST() { root = nullptr; } //constructor
	void insert(T x) { insert(root, x); } //insert x into the tree

	void displayTree() const { displayTree(root, 0); }

	T largestElement() const;
	//returns the value (data) of the largest element of the  BST tree  (non-recursively)
	//assume that the tree is not empty

	int leaves() const { return leaves(root); }
	//returns the # of leaves in the tree
	

	int leaves(TreeNode<T>* treeroot) const;
	//return the number of leaves in the subtree with root treeroot
	//recursive function


	T sum() const { return sum(root);}
	//return the sum of all the nodes in the tree
	//assume that data is numeric and the tree is not empty
	
	T sum(TreeNode<T>* treeroot) const;
	//return the sum of all the nodes in the subtree with root treeroot
	//assume that data is numeric
	//recursive function

	~BST() { destroyTree(root); }  //destructor

private:
	TreeNode<T>* root;
	void insert(TreeNode<T>*& treeroot, T x);
	//insert x into the subtree with root treeroot 

	void destroyTree(TreeNode<T>* treeroot) //deallocate the memory for the subtree treeroot
	{
		if (treeroot) //not empty
		{
			destroyTree(treeroot->left); //delete the left
			destroyTree(treeroot->right);
			delete treeroot; //after deleting the children, delete the root
		}
	};
	void displayTree(TreeNode<T>* treeroot, int level) const;
};

//functions already implemented
template <typename T>
void BST<T>::displayTree(TreeNode<T >* treeroot, int level) const
{
	if (treeroot != nullptr)
	{
		displayTree(treeroot->right, level + 1);
		cout << setw(level * 6) << ' '
			<< setw(6) << treeroot->data << endl;
		displayTree(treeroot->left, level + 1);
	}
}

template <typename T>
void BST<T>::insert(TreeNode<T>*& treeroot, T x)
{
	if (treeroot == nullptr)  //reached the end of the search
	{
		TreeNode<T>* newnode = new TreeNode<T>;
		newnode->data = x;
		newnode->left = nullptr;
		newnode->right = nullptr;
		treeroot = newnode;
	}
	else
	{
		if (x == treeroot->data)
			return;
		if (x < treeroot->data)
			insert(treeroot->left, x);
		else
			insert(treeroot->right, x);
	}
}

//implement the functions below

template <typename T>
T BST<T>::largestElement() const 
{
	int data = 0; //initialize return value
	TreeNode<T>* walker = root; //intitialize walker
	while (walker->right != nullptr) {
		walker = walker->right; //finds largest element in the tree
	}
	data = walker->data; //sets data to that value to return it
	return data;
}

template <typename T>
int BST<T>::leaves(TreeNode<T>* treeroot) const 
{ 
	if (treeroot == nullptr) //if the tree is empty, or if the node is a leaf (base case)
		return 0; 
	if (treeroot->left == nullptr && treeroot->right == nullptr) { //Tests if node is a leaf
		//cout << treeroot->data << " "; //Testing
		return 1 + leaves(treeroot->left); //if so, adds 1 to counter and applies recursion
	}
	return leaves(treeroot->left) + leaves(treeroot->right); //recursion to test the other nodes
}

template <typename T>
T BST<T>::sum(TreeNode<T>* treeroot) const
{
	if (treeroot == nullptr) //if there is no value to add, don't (base case)
		return 0;
	return treeroot->data + sum(treeroot->left) + sum(treeroot->right); //recursion with element just added
}

#endif


