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
	long file_sz;
	char *buffer = NULL;
	bool flag = true;
	FILE *input = tmpfile();
	
	//Parse arguments and take input
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
            return 1;
        }
        
        input = fopen("temptext.txt", "w+");
    	if(input == NULL) {
    		printf("Error writing to temp file.\n");
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
    buffer = (char*) malloc(file_sz +1);
    fread(buffer, file_sz, 1, input);
    buffer[file_sz] = '\0';
    
    while (a < strlen(buffer) && flag == true){
    	if(!isalpha(buffer[a]) && !isspace(buffer[a])) {
    		flag = false;
    		printf("Input not valid. Only alpha strings accepted.\n");
    		return 1;
    	} else {
    		flag = true;
    	}
    	a++;
    }
    free(buffer);
    

/*
	struct node* tree = buildTree(numbers, counter);
	FILE* pre = fopen("outP0.preorder","w");
	FILE* inord = fopen("outP0.inorder","w");
	FILE* post = fopen("outP0.postorder","w");
	printf("Preorder \n");
	printPreorder(tree, 0, pre);
	printf("Inorder \n");
	printInorder(tree, 0, inord);
	printf("Postorder \n");
	printPostorder(tree, 0, post);
	fclose(pre);
	fclose(inord);
	fclose(post);
*/
	fclose(input);
	return 0;

}
