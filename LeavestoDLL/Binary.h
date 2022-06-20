#pragma once
typedef int BType;
typedef struct bnode_s
{
	BType data;
	bnode_s* right, * left;
	
}bnode_t;


bnode_t* getBnode(BType data)
{
	bnode_t* root;
	root = (bnode_t*)malloc(sizeof(bnode_t));
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return root;
}
