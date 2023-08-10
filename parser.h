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
#include <stdbool.h>
#include "lexer.c"

int keyfromstring(char *key);
int keyfromstringNT(char *key);
void printList(struct Node* n);
void printProdTable();
void readProductionRules();
bool checkInFFSet( Str* buff, char* str, int k);
void calcFirst( int k, char *curr, struct Node* parent);
bool checkInFFSet( Str* buff, char* str, int k);
void addToFFSet( Str* buff, char* str, int k);
void calcFirstSets();
void printSets(int first);
void calcFollowFirst(int k, char *curr, struct Node* parent);
void calcFollowFirstParseTable(int k, char *curr, struct Node* parent);
void calcFollow(int k, char *curr);
void calcFollowParseTable(int k, char *curr);
void calcFollowSets();
void printNonTerminalSet(int nonTerminalFlag);
void fillParseTableRow(int k, char *curr, struct Node* parent);
void fillParseTable();
void storeElements();
void printParseTable();
pair top();
void push(int key,int ntCheck,parseNode *node);
void pop();
parseNode* insertNode(parseNode** parent,  parseNode *addrs[],char *val[1000], int count);
void printParseTree(parseNode *root);
void parseInputSourceCode(char *testcaseFile);
