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
	char *strings[ALPH_STRINGS];
	int counter = 0;
	
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
    buffer = (char*) malloc(file_sz +1);
    fread(buffer, file_sz, 1, input);
    buffer[file_sz] = '\0';
    int l = strlen(buffer);
    
    while (a < l && flag == true) {
    	if(!isalpha(buffer[a]) && !isspace(buffer[a]) && !islower(buffer[a])) {
    		flag = false;
    		printf("Input not valid. Only alpha strings accepted.\n");
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
    struct node* tree = buildTree(input, l);
/*    
	//Print three traversals to out files
	char filename[128];
	if (argv[1]) {
		filename[] = argv[1]
	} else {
		filename[] = "out";
	}
	FILE* pre = fopen(("%s.preorder", filename), "w");
	FILE* inord = fopen(("%s.inorder", filename), "w");
	FILE* post = fopen(("%s.postorder", filename), "w");
	
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
