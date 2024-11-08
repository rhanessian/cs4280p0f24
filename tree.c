//Rebecca Hanessian
//CS 4280
//P0

#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <ctype.h>

// A function to create nodes
struct node *newNode(char val) {
  	struct node *letter = (struct node *)calloc(1,sizeof(struct node));
  	printf("Allocating memory now at %p\n", letter);
  	letter->left = letter->right = NULL;
  	letter->alpha = val;
  	letter->strn = 0;
  	return letter;
}


// A function to add a node to the tree
/*void insert(char ch, struct node **leaf) {
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
*/
struct node* insert(char ch, struct node* treeNode) {
	if (treeNode == NULL){
		return newNode(ch);
	}
	if (ch < treeNode->alpha) {
		treeNode->left = insert(ch, treeNode->left);
	} else if (ch > treeNode->alpha) {
		treeNode->right = insert(ch, treeNode->right);
	}
	return treeNode;
}

// A function to search the tree for existing nodes
struct node* search(struct node *root, char chr) {
    if (root == NULL || root->alpha == chr) {
        return root;
	}
    if (root->alpha < chr) {
        return search(root->right, chr);
	}
    return search(root->left, chr);
}

// A main function to build tree
struct node* buildTree(FILE *inpt){
	struct node* tree = NULL;
	char *buf = NULL;
	int i, c = 0;
	char ch;
	int fl_sz;
	
	fseek(inpt, 0, SEEK_END);
	fl_sz = ftell(inpt);
    rewind(inpt);
    
    buf = (char*) malloc(fl_sz);
    if(buf == NULL) {
    	perror("Failed to write file into buffer\n");
    	fclose(inpt);
    }
    
    size_t bytesRead = fread(buf, sizeof(char), fl_sz, inpt);
    if(bytesRead != fl_sz) {
    	perror("Error reading file into buffer\n");
    	fclose(inpt);
    	free(buf);
    }
    
    buf[fl_sz] = '\0';
    int len = strlen(buf);
    char *strbuf = NULL;
    strbuf = (char*) malloc(len);
    
	for (i = 0; i < len; i++) {
		if (!isspace(buf[i])) {
			strbuf[c] = buf[i];
			c++;
			continue;
		} else {
			ch = strbuf[0];
			struct node* finding = NULL;
			if (!tree) {
				tree = finding = newNode(ch);
				printf("Created tree at %p\n", tree);
			} else {
				finding = search(tree, ch);
				if (finding == NULL) {
					insert(ch, tree);
					finding = search(tree, ch);
					printf("Inserted new node %p (tree = %p) for char %c\n", finding, tree, ch);
				} else {
					printf("Found node %p for char %c\n", finding, ch);
				}
			}
			finding->value[finding->strn++] = strdup(strbuf);
			printf("Adding string %s with char %c at %p, tree = %p\n", strbuf, ch, finding, tree);
			if(tree == NULL) {
				printf("Setting tree to %p\n", finding);
			}
			printf("\n");
			int a;
			for (a = 0; a < len; a++){
				strbuf[a] = '\0';
			}
			c = 0;
		}
	}
	free(buf);
	free(strbuf);
	fclose(inpt);
	return tree;
}

// A post order print function
void printPostorder( struct node *root, int level, FILE* outfile){
	if( root != NULL){
		printPostorder(root->left, level+1, outfile);
		printPostorder(root->right, level+1, outfile);
		fprintf(outfile, "%*c%c:", level*2, ' ', root->alpha);
		int i;
		for (i = 0; i < root->strn; i++){
			fprintf(outfile, " %s ", root->value[i]);	
		}
		fprintf(outfile, "\n");
	}
}

// A pre order print function
void printPreorder(struct node *root, int level, FILE* outfile){
	if( root != NULL){
		fprintf(outfile, "%*c%c:", level*2, ' ', root->alpha);
		int i;
		for (i = 0; i < root->strn; i++){
			fprintf(outfile, " %s ", root->value[i]);	
		}
		fprintf(outfile, "\n");
		printPreorder(root->left, level+1, outfile);
		printPreorder(root->right, level+1, outfile);
	}
}

// An in order print function
void printInorder(struct node *root, int level, FILE* outfile){
    if( root != NULL ) {
        printInorder(root->left, level+1, outfile);
        fprintf(outfile, "%*c%c: ", level*2, ' ', root->alpha);
        int i;
        for (i = 0; i < root->strn; i++){
			fprintf(outfile, " %s", root->value[i]);	
		}
		fprintf(outfile, "\n");
        printInorder(root->right, level+1, outfile);
    }
}
