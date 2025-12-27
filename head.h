#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef enum
{
    Keywords, 
    Identifiers,
    Constants,
    Operators,
    Separators
    
}Tokentype;

typedef struct
{
    Tokentype type;
    char lexical[50];

}Tokens;


int lexical(FILE *fp);
int Keyword(char );
void seperators_and_operators(char ch,FILE *fp);

#endif