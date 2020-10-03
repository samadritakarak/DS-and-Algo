# Binary Tree

## A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child. ##
&nbsp;
![Binary Tree](https://cdn.softwaretestinghelp.com/wp-content/qa/uploads/2019/08/pictorial-representation-of-a-binary-tree.png)
&nbsp;
### A Binary Tree node contains following parts:
1. Data
2. Pointer to left child
3. Pointer to right child

### Tree Vocabulary:
 The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves.

### Main applications of trees include:
1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making.

#### Simple Tree
```
     tree
      ----
       1    <-- root
     /   \
    2     3  
   /   
  4
```
```
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 

	// val is the key or the value that 
	// has to be added to the data part 
	Node(int val) 
	{ 
		data = val; 

		// Left and right child for node 
		// will be initialized to null 
		left = NULL; 
		right = NULL; 
	} 
}; 

int main() 
{ 

	/*create root*/
	struct Node* root = new Node(1); 
	/* following is the tree after above statement 

			1 
			/ \ 
			NULL NULL 
	*/

	root->left = new Node(2); 
	root->right = new Node(3); 
	/* 2 and 3 become left and right children of 1 
					1 
					/ \ 
				2	 3 
				/ \ / \ 
			NULL NULL NULL NULL 
	*/

	root->left->left = new Node(4); 
	/* 4 becomes left child of 2 
			1 
			/ \ 
			2	 3 
			/ \ / \ 
	4 NULL NULL NULL 
	/ \ 
	NULL NULL 
	*/

	return 0; 
} 
```

## Tree Traversals (Inorder, Preorder and Postorder)

### Inorder Traversal
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)

### Preorder Traversal
Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 

### Postorder Traversal
Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.

```
#include <iostream> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorder(node->left); 

	// then recur on right subtree 
	printPostorder(node->right); 

	// now deal with the node 
	cout << node->data << " "; 
} 

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	printInorder(node->left); 

	/* then print the data of node */
	cout << node->data << " "; 

	/* now recur on right child */
	printInorder(node->right); 
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first print data of node */
	cout << node->data << " "; 

	/* then recur on left sutree */
	printPreorder(node->left); 

	/* now recur on right subtree */
	printPreorder(node->right); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root); 

	return 0; 
} 
```

#### Output
```
Preorder traversal of binary tree is
1 2 4 5 3 
Inorder traversal of binary tree is
4 2 5 1 3 
Postorder traversal of binary tree is
4 5 2 3 1
```
