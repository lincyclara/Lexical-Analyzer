/*
NAME : LINCY K
DATE : 27/12/2025
DESCRIPTION : The Lexical Analyzer Project is a C-based program that reads C source code from a file and breaks it into meaningful tokens, 
              classifying them as keywords, identifiers, constants, operators, and separators. It accurately handles single and multi-character
              operators such as ++, --, +=, ==, !=, &&, ||, <<, >> using a lookahead mechanism, and distinguishes between user-defined identifiers
              and reserved keywords. The analyzer also categorizes various separators ({ } ( ) [ ] ; , . #) and recognizes arithmetic, relational,
              logical, and bitwise operators. This project demonstrates an understanding of compiler design fundamentals, including lexical analysis,
              tokenization, and pattern recognition, and showcases skills in C programming, file handling, and string manipulation.
*/

#include "head.h"

int main(int argc,char *argv[])
{
    if(argc < 2){
        printf("Use this format:\n");
        printf("./a.out <filename>\n");
        return FAILURE;
    }
    FILE *fp;

    fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("File empty\n");
        return FAILURE;
    }

    lexical(fp);

    fclose(fp);

    return SUCCESS;
}