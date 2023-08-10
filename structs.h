/* 

    Group_50
    ID: 2019B3A70489P    Name: Harsh Pandey
    ID: 2019B3A70470P    Name: Aryan Puwar
    ID: 2019B2A70898P    Name: Harshit Gupta
    ID: 2019B3A70819P    Name: Krish Vora
    ID: 2019B3A70562P    Name: Tejas Deshpande

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef enum {
    INTEGER , REAL ,BOOLEAN ,OF ,ARRAY ,START ,END ,DECLARE ,MODULE ,DRIVER ,
    PROGRAM ,GET_VALUE ,PRINT ,USE , WITH ,PARAMETERS ,TAKES ,
    INPUT ,RETURNS ,FOR ,IN ,SWITCH ,CASE ,BREAK ,DEFAULT ,WHILE ,ID, NUM ,RNUM, 
    AND ,TRUE ,FALSE, PLUS  ,MINUS ,MUL, DIV ,LT ,LE ,GE ,GT ,EQ ,NE ,DEF ,ENDDEF ,
    DRIVERDEF ,DRIVERENDDEF ,COLON ,RANGEOP ,SEMICOL ,COMMA ,ASSIGNOP ,SQBO ,SQBC ,
    BO ,BC ,COMMENTMARK, OR, IF, THEN, ELSE, ENDIF, PRINTANCESTOR, SUBRANGE, SIZE, HEXNUM
} Action;

union variant{                                                                                                                                                                                                                                                                                                                                                                                                                                 
    char *lex;                                                                                                                                                                                                                                                                                                                                                                                                                                 
    int valueInt;
    float valueFloat;
};

struct Token{
    Action tokenID;
    unsigned int lineNo;
    union variant lexeme;
} ;

typedef struct Token Token;

struct lookupTable{
    char name[100];
    Action value;
};

typedef struct lookupTable lookupTable;

typedef struct parseNode parseNode;

struct parseNode{
    // char *line_Num;
    char *val;
    
    // int x;
    union variant lexeme;
    parseNode *child;
    parseNode *sibling;
    parseNode *parent;
    parseNode *addr;
    parseNode *syn_list;
    parseNode *type;
    parseNode *branch;
};

typedef struct astNode astNode;
// struct astNode{
//     parseNode *head;
// }

struct symbol{
        char str[100];
    };

struct Node {
    char str[100];
    struct Node* next;
};

typedef struct  {
    char str[100];
}Str;

struct pair{
    int key;
    int ntCheck;
    parseNode *node;
}Pair;
typedef struct pair pair;
