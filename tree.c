//Rebecca Hanessian
//CS 4280
//P0

#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <ctype.h>

// A function to create nodes
struct node *newNode(char* val) {
  	struct node *letter = (struct node *)calloc(1,sizeof(struct node));
  	printf("Allocating memory now at %p\n", letter);
  	letter->left = letter->right = NULL;
  	letter->value = val;
  	return letter;
}


// A function to add a node to the tree
void insert(char ch, struct node **leaf) {
    if( *leaf == 0 )
    {
        *leaf = (struct node*) calloc(1,  sizeof( struct node ) );
        (*leaf)->alpha = ch;
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(ch < (*leaf)->alpha)
    {
        insert( ch, &(*leaf)->left );
    }
    else if(ch > (*leaf)->alpha)
    {
        insert( ch, &(*leaf)->right );
    }
}

// A function to search the tree for existing nodes
struct node* search(struct node *root, char ch) {
    if (root == NULL || root->ch == key)
        printf("found node %c at %p\n",ch, root);
        return root;

    if (root->ch < ch)
        return search(root->right, ch);

    return search(root->left, ch);
}

// A main function to build tree
struct node* buildTree(FILE *inpt, int len){
	struct node* tree = NULL;
	char *buf = NULL;
	char *strbuf = NULL;
	int i, c = 0;
	char ch;
	
	buf = (char*) malloc(len);
	fread(buf, len - 1, 1, inpt);
	while (buf[i] != EOF) {
		for (i = 0; i < len; i++) {
			if (!isspace(buf[i])) {
				strbuf[c] = buf[i];
			} else {
				break;
			}
			
			ch = strbuf[0];
			if(search(tree, ch) = NULL) {
				insert(ch, &tree)
			}
		}
		
	}
	free(buf);
	
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

// A post order print function
void printPostorder( struct node *root, int level, FILE* outfile){
	if( root != NULL){
		printPostorder(root->p_left, level+1, outfile);
		printPostorder(root->p_right, level+1, outfile);
		fprintf(outfile, "%d\n", root->len);
		int i;
		for (i = 0; i < root->alph; i++){
			int j;
			for(j=0; j<level; j++){
				fprintf(outfile, "  ");
			}
			fprintf(outfile, "%s\n", root->value[i]);	
		}
	}
}

// A pre order print function
void printPreorder(struct node *root, int level, FILE* outfile){
	if( root != NULL) {
		fprintf(outfile, "%d\n", root->len);
		int i;
		for (i = 0; i < root->alph; i++){
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

// An in order print function
void printInorder(struct node *root, int level, FILE* outfile){
    if( root != NULL ) {
        printInorder(root->p_left, level+1, outfile);
        fprintf(outfile, "%d\n", root->len);
        int i;
        for (i = 0; i < root->alph; i++){
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