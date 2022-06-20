#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Binary.h"
#include "DLL.h"

void InOrder(bnode_t* root, node_t**List, node_t** Temp)
{
	if (root != NULL)
	{
		InOrder(root->left, List, Temp);
		if (root->left == NULL && root->right == NULL)
		{
			if (*List == NULL)
			{
				*List = addBeginning(*List, root->data);
				*Temp = *List;
				 
			}
			else
			{

				AddAfter(*Temp, root->data);
				*Temp = (*Temp)->next;
			}
			
		}
		InOrder(root->right, List, Temp);
	}
}
bnode_t* ModifyTree(bnode_t** root, node_t* DLL, bnode_t* temp, int *flag)
{
	 //outer DLL
	
		
		if (temp != NULL)
		{
			if (temp != NULL)
			{
				ModifyTree(root, DLL, temp->left, flag);

			}
			
			 if (DLL->data == temp->data)
				{
					free(temp);
					temp = NULL;
					DLL = DLL->next;
					temp = *root;
					*flag = 0;
				}

			 if (*flag == 0)
			 {
				 ModifyTree(root, DLL, temp->left, flag);

			 }
			
			 ModifyTree(root, DLL, temp->right,flag);
	

	    }
	
	if (DLL == NULL)
	{
		return *root;
	}

}
node_t* convertToDLL(bnode_t** root)
{
	node_t* DLL = NULL;
	node_t* Temp = NULL;
	 
	InOrder(*root, &DLL, &Temp);
	bnode_t* temp = *root;
	int flag = 1;
	*root = ModifyTree(root, DLL, temp, &flag);
	return DLL;
}

int main(void)
{

	bnode_t* root = getBnode(1);
	root->right = getBnode(3);
	root->left = getBnode(2);
	root->left->left= getBnode(4);
	root->left->right= getBnode(5);
	root->right->right= getBnode(7);
	root->right->left= getBnode(6);
	
	convertToDLL(&root);

	return 0;
}