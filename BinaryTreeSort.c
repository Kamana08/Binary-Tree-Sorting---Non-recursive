/*******************************************************************************************
* File Name          : Kamana_assign2_nonrecursive.c
* Description        : Prog8130 - Assignment 2: Binary Tree
*					   This program uses binary tree to hold and print a list of words
*					   in a sorted order.
* Author:            : Kamana Sharma(8697409)
* Date:              : June 21,2021
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure defining a binary tree node.  Lower sorted values will go the the left, higher to the right.
struct nodeData {
	char name[30];				// character string of the data being stored in the node
	struct nodeData* left;		// pointer to the next node in the tree that is less than current node OR NULL if empty
	struct nodeData* right;		// pointer to the next node in the tree that is greater than current node OR NULL if empty
};

struct nodeData* head = NULL;	// head of the binary tree

//function definitions
void printBinaryTree(void);
void printTree(struct nodeData* currentNode);		//function to print the binary tree
void addToBinaryTree(const char* newString);		//function to insert in a binary tree

// data to be stored in tree.  In this case there is just a character string but this could have contained more
// replace inputData used for test put it in here and is created from Prog8130AssignDataCreator.exe 

 const char* inputData[12] = {
		{ "smuwl"},
		{ "fycqu"},
		{ "susfj"},
		{ "rxuam"},
		{ "shouj"},
		{ "mvhsd"},
		{ "pdwtj"},
		{ "entrc"},
		{ "jtsvt"},
		{ "ascur"},
		{ "pydgy"},
		{ "xeiks"}
};

// The correct sorted order using a binary tree is:
//      ascur
//      entrc
//      fycqu
//      jtsvt
//      mvhsd
//      pdwtj
//      pydgy
//      rxuam
//      shouj
//      smuwl
//      susfj
//      xeiks


	
 int main()
 {
	 int i;

	 // put all the data into the binary tree
	 for (i = 0; i < 12; i++)
		 addToBinaryTree(inputData[i]);

	 // print the entire tree.  It should come out in alphabetical order because of the way it was stored in the tree
	 printBinaryTree();
	 return 0;
 }


 // FUNCTION      : addToBinaryTree
//
// DESCRIPTION   :
//   This function will store the data in newNode into a binary tree according to alphabetical order
//
// PARAMETERS    :
//   newString - the string that is to be stored in the binary tree in alphabetica order
//
// RETURNS       :
//   Nothing
void addToBinaryTree(const char* newString)
{
	struct nodeData* newNode;		//a newNode that will act as a current node
	struct nodeData* tempPtr;		//a node used for traversing
	
	// add code to put items into binary tree in alphabetical order here
	// consider using strcmp library function to decide if a name is greater or less than
	
	if (head == NULL)				//if head is null, it means binary tree is empty so it'll insert currentnode at head
	{
			newNode = (struct nodeData*)malloc(sizeof(struct nodeData));
			if (newNode != NULL)
			{
				strcpy_s(newNode->name, newString);			//copying the data into currentNode
				newNode->left = NULL;						//setting left of node to NULL
				newNode->right = NULL;						//setting right of node to NULL
				head = newNode;								//setting head as newNode
			}
	}

	else                                                   //if head is not null
	
	{	
		tempPtr = (struct nodeData*)malloc(sizeof(struct nodeData));  //a temporary node is created 
		tempPtr = head;												 //setting temp node as head
		while (tempPtr != NULL)										//untill tempnode is not null
		{
			
			if (strcmp(newString, tempPtr->name)>0)					//it'll compare the data . if greater
			{
				if (tempPtr->right != NULL)
				{
					tempPtr = tempPtr->right;						//traversing to right of the binary tree
					//continue;
				}

				else                                               //if temp right is null
				{
					newNode = (struct nodeData*)malloc(sizeof(struct nodeData));    //a new node is created 
					tempPtr->right = newNode;										//assigning temp->right as a newnode
					
					if (newNode != NULL)
					{
						strcpy_s(newNode->name, newString);                        //copying the data into currentNode
						newNode->left = NULL;									   //setting newNode left as null
						newNode->right = NULL;										//setting newNode right as null
						//tempPtr = newNode;
						
					}
					break;
				}
				
			}

			else if (strcmp(newString, tempPtr->name) < 0)							//if data is less than temp data
			{
				if (tempPtr->left != NULL)											//traversing to left side of binary tree
				{
					tempPtr = tempPtr->left;
					//continue;
				}
				else                                                              //if temp left is null it means we have reached to the end of tree
				{
					newNode = (struct nodeData*)malloc(sizeof(struct nodeData));  //creating a newNode
					tempPtr->left = newNode;
					if (newNode != NULL)
					{	
						//tempPtr->left = tempPtr;
						strcpy_s(newNode->name, newString);                      //copying data into newnode
						newNode->left = NULL;								    //setting newNode left as null
						newNode->right = NULL;									//setting newNode right as null
						//tempPtr = newNode;
					}
					break;
				}
				

			}
		}

	}
	return;

}
// FUNCTION      : printBinaryTree
	//
	// DESCRIPTION   :
	//   This function will print the entire binary tree out.  You can choose to print
	//   it using recursion but more marks will be awarded if you do it non recursively.
	//
	// PARAMETERS    :
	//   None
	//
	// RETURNS       :
	//   Nothing

void printBinaryTree(void)           //function to print binary tree
{
	// add code to print data in order starting at the "head" pointer
	printTree(head);
}

void printTree(struct nodeData* currentNode)  
{
	if (currentNode == NULL)					//if current node is null, it means end of tree
		return;
	printTree(currentNode->left);              
	printf("%s \n", currentNode->name);
	printTree(currentNode->right);
	return;
}








