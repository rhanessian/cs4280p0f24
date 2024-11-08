//Rebecca Hanessian
//CS 4280
//P0

#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char *argv[]){
	int a = 0, c;
	int file_sz;
	char *buffer = NULL;
	bool flag = true;
	FILE *input = tmpfile();
	
	//Parse arguments and take input; write input to temp file
	if (argc > 2) 
    {
        printf( "usage: %s filename", argv[0] );
        return 1;
    }
    else if (argc == 1){
    	printf("Begin inputting strings separated by spaces or lines and end with ctrl-D:\n");
    	input = fopen("temptext.txt", "w+");
    	if(input == NULL) {
    		printf("Error writing to temp file.\n");
    		fclose(input);
    		return 1;
    	}
    	
    	while ((c = fgetc(stdin)) != EOF)
    	{
        	fputc(c, input);
    	}	
    }
    else 
    {
    	char tempstring[128];
		sprintf(tempstring, "%s.4280fs24", argv[1]);
        FILE *file = fopen(tempstring, "r");

        if (file == NULL)
        {
            printf( "File could not be opened.\n" );
            fclose(input);
            return 1;
        }
        
        input = fopen("temptext.txt", "w+");
    	if(input == NULL) {
    		printf("Error writing to temp file.\n");
    		fclose(input);
    		return 1;
    	}
    	
    	while ((c = fgetc(file)) != EOF)
    	{
        	fputc(c, input);
    	}
    }
    
    //Create a char array to validate input
    fseek(input, 0, SEEK_END);
    file_sz = ftell(input);
    rewind(input);
    
    buffer = (char*) malloc(file_sz + 1);
    if(buffer == NULL) {
    	perror("Failed to write file into buffer\n");
    	fclose(input);
    	return 1;
    }
    
    size_t bytesRead = fread(buffer, sizeof(char), file_sz, input);
    if(bytesRead != file_sz) {
    	perror("Error reading file into buffer\n");
    	fclose(input);
    	free(buffer);
    	return 1;
    }
    
    buffer[file_sz] = '\0';
    int l = strlen(buffer);
  
    while (a < (l-1) && flag == true) {
    	if(!isalpha(buffer[a]) && !isspace(buffer[a]) && !islower(buffer[a])) {
    		flag = false;
    		printf("Input not valid. Only lowercase alpha strings accepted.\n");
    		fclose(input);
    		free(buffer);
    		return 1;
    	} else {
    		flag = true;
    	}
    	a++;
    }
    free(buffer);
    
    
    //Create binary search tree from input
    struct node* tree = buildTree(input);
    
	//Print three traversals to out files
	char filename[100];
	if (argv[1]) {
		strcpy(filename, argv[1]);
	} else {
		strcpy(filename, "out");
	}
	
	char prefileext[] = ".preorder";
	char infileext[] = ".inorder";
	char postfileext[] = ".postorder";
	
	char prefile[100];
	char infile[100];
	char postfile[100];
	
	strcpy(prefile, filename);
	strcpy(infile, filename);
	strcpy(postfile, filename);
	
	strcat(prefile, prefileext);
	strcat(infile, infileext);
	strcat(postfile, postfileext);
	
	FILE* pre = fopen(prefile, "w");
	FILE* inord = fopen(infile, "w");
	FILE* post = fopen(postfile, "w");
	
	printf("Preorder \n");
	printPreorder(tree, 0, pre);
	printf("Inorder \n");
	printInorder(tree, 0, inord);
	printf("Postorder \n");
	printPostorder(tree, 0, post);
	
	fclose(pre);
	fclose(inord);
	fclose(post);

	if (input != stdin) {
		fclose(input);
	}
	return 0;

}
