#include "head.h"

int keyword(char *);

int lexical(FILE *fp){
   
    char ch;
    char word[30];
    int i;
    
    printf("\tLexical Analyzer\n");
    printf("--------------------------------------\n\n");
    while((ch = fgetc(fp)) != EOF){
        if(isalpha(ch)){
            i=0;
            word[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                    (isalpha(ch) || ch == '_')){
               
                word[i++] = ch;
            }
            word[i] = '\0';

            if(keyword(word)){
                printf("%-15s  :  %-15s\n",word,"Keyword");
            }
            else{
                printf("%-15s  :  %-15s\n",word,"Identifier");
            }
        }
        else if(isdigit(ch)){
            i=0;
            word[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                    isdigit(ch)){
               
                word[i++] = ch;
            }
            word[i] = '\0';
            printf("%-15s  :  %-15s\n",word,"Constants");
        }
        else if(!isspace(ch)){
            seperators_and_operators(ch,fp);
        }
        
    }
    return SUCCESS;
}

int keyword(char *word){
    char *keywords[] = { "int","float","char","double","break","continue","short",
        "void","do","while","if","else","default","auto","extern","typedef","struct",
        "union","enum","case","goto","for","long","static","signed","sizeof","volatile",
        "unsigned","switch","return"
    };
    int len = sizeof(keywords) / sizeof(keywords[0]);

    for(int i=0; i<len ;i++){
        if(strcmp(word,keywords[i]) == 0){
            return FAILURE;
        }
    }
    return SUCCESS;
}
void seperators_and_operators(char ch,FILE *fp){
    char next;

    switch(ch){
        case '{':
        printf("%-15s  :  %-15s\n","{","Open Braces");
        break;

        case '}':
        printf("%-15s  :  %-15s\n","}","Closed Braces");
        break;

        case '(':
        printf("%-15s  :  %-15s\n","(","Open Parenthesis");
        break;

        case ')':
        printf("%-15s  :  %-15s\n",")","Closed Parenthesis");
        break;

        case '[':
        printf("%-15s  :  %-15s\n","[","Open Bracket");
        break;

        case ']':
        printf("%-15s  :  %-15s\n","]","Closed Bracket");
        break;

        case ';':
        printf("%-15s  :  %-15s\n",";","Semicolon");
        break;

        case ',':
        printf("%-15s  :  %-15s\n",",","Comma");
        break;

        case '.':
        printf("%-15s  :  %-15s\n",".","Dot Operator");
        break;

        case '#':
        printf("%-15s  :  %-15s\n","#","Preprocessor Directive Symbol");
        break;

        case '*':
        printf("%-15s  :  %-15s\n","*","Arithmetic Operator");
        break;

        case '/':
        printf("%-15s  :  %-15s\n","/","Arithmetic Operator");
        break;

        case '%':
        printf("%-15s  :  %-15s\n","%","Modulus Operator");
        break;

        case '?':
        printf("%-15s  :  %-15s\n","?","Conditional Operator");
        break;

        case ':':
        printf("%-15s  :  %-15s\n",":","Conditional Operator");
        break;

        case '=':
        next = fgetc(fp);
        if(next == '='){
            printf("%-15s  :  %-15s\n","==","Relational Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","=","Assignment Operator");
        }
        ungetc(next,fp);
        break;

        case '+':
        next = fgetc(fp);
        if(next == '+'){
            printf("%-15s  :  %-15s\n","++","Increment Operator");
        }
        else if(next == '='){
            printf("%-15s  :  %-15s\n","+=","Assignment Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","+","Arithmetic Operator");
        }
        ungetc(next,fp);
        break;

        case '-':
        next = fgetc(fp);
        if(next == '-'){
            printf("%-15s  :  %-15s\n","--","Decrement Operator");
        }
        else if(next == '='){
            printf("%-15s  :  %-15s\n","-=","Assignment Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","-","Arithmetic Operator");
        }
        ungetc(next,fp);
        break;

        case '<':
        next = fgetc(fp);
        if(next == '<'){
            printf("%-15s  :  %-15s\n","<=","Relational Operator");
        }
        else if(next == '<'){
            printf("%-15s  :  %-15s\n","<<","Left Shift Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","<","Relational Operator");
        }
        ungetc(next,fp);
        break;

        case '>':
        next = fgetc(fp);
        if(next == '>'){
            printf("%-15s  :  %-15s\n",">>","Right Shift Operator");
        }
        else if(next == '='){
            printf("%-15s  :  %-15s\n",">=","Relational Operator");
        }
        else{
            printf("%-15s  :  %-15s\n",">","Relational Operator");
        }
        ungetc(next,fp);
        break;

        case '!':
        next = fgetc(fp);
        if(next == '='){
            printf("%-15s  :  %-15s\n","!=","Relational Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","!","Logical NOT Operator");
        }
        ungetc(next,fp);
        break;

        case '|':
        next = fgetc(fp);
        if(next == '|'){
            printf("%-15s  :  %-15s\n","||","Logical OR Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","|","Bitwise Operator");
        }
        ungetc(next,fp);
        break;

        case '&':
        next = fgetc(fp);
        if(next == '&'){
            printf("%-15s  :  %-15s\n","&&","Logical AND Operator");
        }
        else{
            printf("%-15s  :  %-15s\n","&","Bitwise Operator");
        }
        ungetc(next,fp);
        break;

        case '^':
        printf("%-15s  :  %-15s\n","^","Bitwise XOR Operator");
        break;

        case '~':
        printf("%-15s  :  %-15s\n","~","Bitwise NOT Operator");
        break;

        default:
        break;
    }
}

