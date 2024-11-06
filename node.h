#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPH_STRINGS 180

struct node {
    char *value[ALPH_STRINGS];
    char alpha;            
    struct node *left, *right;
}