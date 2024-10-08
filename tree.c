//Rebecca Hanessian
//CS 4280
//P0

#include "node.h"
#include "tree.h"
#include <stdio.h>
/*
struct node *new_node(int x) {
  	struct node *val = (struct node *)calloc(1,sizeof(struct node));
  	printf("Allocating memory now at %p\n", val);
  	val->len = x;
  	val->p_left = val->p_right = NULL;
  	val->num = 0;
  	return val;
}

int findLastDigit(char* number){
	int digit = -1;
	while(*number &&*number != '\n')
	{
		if(! isdigit(*number))
			return -1;
		digit = *number - '0';
		number++;
	}
	return digit;
}

void insert(int key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) calloc(1,  sizeof( struct node ) );
        (*leaf)->len = key;
        (*leaf)->p_left = 0;    
        (*leaf)->p_right = 0;  
    }
    else if(key < (*leaf)->len)
    {
        insert( key, &(*leaf)->p_left );
    }
    else if(key > (*leaf)->len)
    {
        insert( key, &(*leaf)->p_right );
    }
}

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->len==x) {
    	printf("found length %d at %p\n", x, root);
        return root;
    } else if(x<root->len) {
        return search(root->p_left, x);
    } else {
        return search(root->p_right,x);
    }
}

struct node* buildTree(char** inputArray, int length){
	int i;
	struct node* tree = NULL;
	for(i = 0; i < length; i++){
		int lastDigit = (int)findLastDigit(inputArray[i]);
		struct node* finding = NULL;
		if (!tree) {
			tree = finding = new_node(lastDigit);
			printf("created tree at %p\n", tree);
		} else {
			finding = search(tree, lastDigit);
			if (finding == NULL) {
				insert(lastDigit, &tree);
				finding = search(tree, lastDigit);
				printf("inserted new node %p (tree=%p) for last digit %d\n", finding, tree, lastDigit);
			} else {
				printf("found node %p for last digit %d\n", finding, lastDigit);
			}
		}
		finding->value[finding->num++] = strdup(inputArray[i]);
		printf("adding number %s with last digit %d at %p, tree=%p\n", inputArray[i], lastDigit, finding, tree);
		if(tree==NULL) {
			printf("setting tree to %p\n", finding);
			tree = finding;
		}
		printf("\n");
	}
	return tree;
}

void printPostorder( struct node *root, int level, FILE* outfile)
{
	if( root != NULL){
		printPostorder(root->p_left, level+1, outfile);
		printPostorder(root->p_right, level+1, outfile);
		fprintf(outfile, "%d\n", root->len);
		int i;
		for (i = 0; i < root->num; i++){
			int j;
			for(j=0; j<level; j++){
				fprintf(outfile, "  ");
			}
			fprintf(outfile, "%s\n", root->value[i]);	
		}
	}
}

void printPreorder(struct node *root, int level, FILE* outfile)
{
	if( root != NULL) {
		fprintf(outfile, "%d\n", root->len);
		int i;
		for (i = 0; i < root->num; i++){
			int j;
			for(j=0; j<level; j++){
				fprintf(outfile, "  ");
			}
			fprintf(outfile, "%s\n", root->value[i]);	
		}
		printPreorder(root->p_left, level+1, outfile);
		printPreorder(root->p_right, level+1, outfile);
	}
}

void printInorder(struct node *root, int level, FILE* outfile)
{
    if( root != NULL ) {
        printInorder(root->p_left, level+1, outfile);
        fprintf(outfile, "%d\n", root->len);
        int i;
        for (i = 0; i < root->num; i++){
        	int j;
        	for(j=0; j<level; j++){
				fprintf(outfile, "  ");
			}
			fprintf(outfile, "%s\n", root->value[i]);	
		}
        printInorder(root->p_right, level+1, outfile);
    }
}
*/