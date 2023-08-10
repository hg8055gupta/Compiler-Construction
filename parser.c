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
#include "parser.h"
#include "ast.c"
// hardcoded for now
#define lineNum 146

typedef struct
{
    char *key;
    int val;
} terminalPair;
Str firstSetsWithEpsilon[lineNum];

static char *TMappings[] = {
    "$",
    "epsilon",
    "T_DECLARE",
    "T_MODULE",
    "T_ID",
    "T_SEMICOL",
    "T_DRIVERDEF",
    "T_DRIVER",
    "T_PROGRAM",
    "T_DRIVERENDDEF",
    "T_DEF",
    "T_ENDDEF",
    "T_TAKES",
    "T_INPUT",
    "T_SQBO",
    "T_SQBC",
    "T_RETURNS",
    "T_COLON",
    "T_COMMA",
    "T_INTEGER",
    "T_REAL",
    "T_BOOLEAN",
    "T_ARRAY",
    "T_OF",
    "T_RANGEOP",
    "T_START",
    "T_END",
    "T_GET_VALUE",
    "T_BO",
    "T_BC",
    "T_PRINT",
    "T_NUM",
    "T_RNUM",
    "T_TRUE",
    "T_FALSE",
    "T_ASSIGNOP",
    "T_PLUS",
    "T_MINUS",
    "T_USE",
    "T_WITH",
    "T_PARAMETERS",
    "T_MUL",
    "T_DIV",
    "T_AND",
    "T_OR",
    "T_LT",
    "T_LE",
    "T_GT",
    "T_GE",
    "T_EQ",
    "T_NE",
    "T_SWITCH",
    "T_CASE",
    "T_BREAK",
    "T_DEFAULT",
    "T_FOR",
    "T_IN",
    "T_WHILE",
    "T_COMMA"};

static terminalPair lookuptable[] = {
    {"$", 1},
    {"epsilon", 2},
    {"T_DECLARE", 3},
    {"T_MODULE", 4},
    {"T_ID", 5},
    {"T_SEMICOL", 6},
    {"T_DRIVERDEF", 7},
    {"T_DRIVER", 8},
    {"T_PROGRAM", 9},
    {"T_DRIVERENDDEF", 10},
    {"T_DEF", 11},
    {"T_ENDDEF", 12},
    {"T_TAKES", 13},
    {"T_INPUT", 14},
    {"T_SQBO", 15},
    {"T_SQBC", 16},
    {"T_RETURNS", 17},
    {"T_COLON", 18},
    {"T_COMMA", 19},
    {"T_INTEGER", 20},
    {"T_REAL", 21},
    {"T_BOOLEAN", 22},
    {"T_ARRAY", 23},
    {"T_OF", 24},
    {"T_RANGEOP", 25},
    {"T_START", 26},
    {"T_END", 27},
    {"T_GET_VALUE", 28},
    {"T_BO", 29},
    {"T_BC", 30},
    {"T_PRINT", 31},
    {"T_NUM", 32},
    {"T_RNUM", 33},
    {"T_TRUE", 34},
    {"T_FALSE", 35},
    {"T_ASSIGNOP", 36},
    {"T_PLUS", 37},
    {"T_MINUS", 38},
    {"T_USE", 39},
    {"T_WITH", 40},
    {"T_PARAMETERS", 41},
    // { "T_ID" , 42},
    {"T_MUL", 42},
    {"T_DIV", 43},
    {"T_AND", 44},
    {"T_OR", 45},
    {"T_LT", 46},
    {"T_LE", 47},
    {"T_GT", 48},
    {"T_GE", 49},
    {"T_EQ", 50},
    {"T_NE", 51},
    {"T_SWITCH", 52},
    {"T_CASE", 53},
    {"T_BREAK", 54},
    {"T_DEFAULT", 55},
    {"T_FOR", 56},
    {"T_IN", 57},
    {"T_WHILE", 58},
    {"T_COMMA", 59}};

#define NKEYS (sizeof(lookuptable) / sizeof(terminalPair))

static char *NTMappings[] = {
    "N_program",
    "N_moduleDeclarations",
    "N_moduleDeclaration",
    "N_otherModules",
    "N_driverModule",
    "N_module",
    "N_ret",
    "N_input_plist",
    "N_n1",
    "N_output_plist",
    "N_n2",
    "N_dataType",
    "N_range_arrays",
    "N_type",
    "N_moduleDef",
    "N_statements",
    "N_statement",
    "N_ioStmt",
    "N_var_print",
    "N_p1",
    "N_boolConstt",
    "N_id_num_rnum",
    "N_array_element_for_print",
    "N_simpleStmt",
    "N_assignmentStmt",
    "N_whichStmt",
    "N_lvalueIDStmt",
    "N_lvalueARRStmt",
    "N_index_arr",
    "N_new_index",
    "N_sign",
    "N_moduleReuseStmt",
    "N_actual_para_list",
    "N_optional",
    "N_idList",
    "N_n3",
    "N_expression",
    "N_u",
    "N_new_NT",
    "N_var_id_num",
    "N_unary_op",
    "N_arithmeticOrBooleanExpr",
    "N_n7",
    "N_anyTerm",
    "N_n8",
    "N_arithmeticExpr",
    "N_n4",
    "N_term",
    "N_n5",
    "N_factor",
    "N_n_11",
    "N_arrExpr",
    "N_arr_n4",
    "N_arrTerm",
    "N_arr_n5",
    "N_arrFactor",
    "N_element_index_with_expressions",
    "N_n_10",
    "N_op1",
    "N_op2",
    "N_logicalOp",
    "N_relationalOp",
    "N_declareStmt",
    "N_condionalStmt",
    "N_caseStmts",
    "N_n9",
    "N_value",
    "N_default",
    "N_iterativeStmt",
    "N_range_for_loop",
    "N_index_for_loop",
    "N_new_index_for_loop",
    "N_sign_for_loop",
    "N_append_para_list",
    "N_K"};

static terminalPair lookuptableNT[] = {
    {"N_program", 1},
    {"N_moduleDeclarations", 2},
    {"N_moduleDeclaration", 3},
    {"N_otherModules", 4},
    {"N_driverModule", 5},
    {"N_module", 6},
    {"N_ret", 7},
    {"N_input_plist", 8},
    {"N_n1", 9},
    {"N_output_plist", 10},
    {"N_n2", 11},
    {"N_dataType", 12},
    {"N_range_arrays", 13},
    {"N_type", 14},
    {"N_moduleDef", 15},
    {"N_statements", 16},
    {"N_statement", 17},
    {"N_ioStmt", 18},
    {"N_var_print", 19},
    {"N_p1", 20},
    {"N_boolConstt", 21},
    {"N_id_num_rnum", 22},
    {"N_array_element_for_print", 23},
    {"N_simpleStmt", 24},
    {"N_assignmentStmt", 25},
    {"N_whichStmt", 26},
    {"N_lvalueIDStmt", 27},
    {"N_lvalueARRStmt", 28},
    {"N_index_arr", 29},
    {"N_new_index", 30},
    {"N_sign", 31},
    {"N_moduleReuseStmt", 32},
    {"N_actual_para_list", 33},
    {"N_optional", 34},
    {"N_idList", 35},
    {"N_n3", 36},
    {"N_expression", 37},
    {"N_u", 38},
    {"N_new_NT", 39},
    {"N_var_id_num", 40},
    {"N_unary_op", 41},
    {"N_arithmeticOrBooleanExpr", 42},
    {"N_n7", 43},
    {"N_anyTerm", 44},
    {"N_n8", 45},
    {"N_arithmeticExpr", 46},
    {"N_n4", 47},
    {"N_term", 48},
    {"N_n5", 49},
    {"N_factor", 50},
    {"N_n_11", 51},
    {"N_arrExpr", 52},
    {"N_arr_n4", 53},
    {"N_arrTerm", 54},
    {"N_arr_n5", 55},
    {"N_arrFactor", 56},
    {"N_element_index_with_expressions", 57},
    {"N_n_10", 58},
    {"N_op1", 59},
    {"N_op2", 60},
    {"N_logicalOp", 61},
    {"N_relationalOp", 62},
    {"N_declareStmt", 63},
    {"N_condionalStmt", 64},
    {"N_caseStmts", 65},
    {"N_n9", 66},
    {"N_value", 67},
    {"N_default", 68},
    {"N_iterativeStmt", 69},
    {"N_range_for_loop", 70},
    {"N_index_for_loop", 71},
    {"N_new_index_for_loop", 72},
    {"N_sign_for_loop", 73},
    {"N_append_para_list", 74},
    {"N_K", 75}};

#define NTKEYS (sizeof(lookuptableNT) / sizeof(terminalPair))
void printParseTable();

int keyfromstring(char *key)
{
    int i;
    for (i = 0; i < NKEYS; i++)
    {
        terminalPair *sym = &lookuptable[i];
        if (strcmp(sym->key, key) == 0)
            return sym->val;
    }
    return -1;
}
int keyfromstringNT(char *key)
{
    int i;
    for (i = 0; i < NTKEYS; i++)
    {
        terminalPair *sym = &lookuptableNT[i];
        if (strcmp(sym->key, key) == 0)
            return sym->val;
    }
    return -1;
}

// This function prints contents of linked list starting
// from the given node
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %s ", n->str);
        n = n->next;
    }
}

// j for calcFirstSets
int firstSetCol = 0;
int followSetCol = 0;
Str parseTable[lineNum][100];
Str terminalSet[100];
Str nonTerminalSet[lineNum];
int parseTableRow = 1;
int parseTableCol = 1;
int terminalSetCounter = 0;
int nonTerminalSetCounter = 0;
struct Node prodTable[200];

void printProdTable()
{
    for (int i = 0; i < lineNum; i++)
    {
        printList(&prodTable[i]);
        printf("%c", '\n');
    }
}

bool prodTableFilled = false;
void readProductionRules()
{
    //============== resetting globals ============
    terminalSetCounter=0;
    nonTerminalSetCounter=0;
    firstSetCol = 0;
    followSetCol = 0;
    parseTableRow = 1;
    parseTableCol = 1;
    //=============================================

    // printf("===!!!===\n");
    if(prodTableFilled) return;
    // for(int i=0;i<200;i++){
    //     printList(&prodTable[i]);
    //     printf("\n");
    // }
    
    // printf("########################################################3\n");

    //=====================Read from file and store in buffer===================//

    // open the file
    FILE *grammarFilePointer = fopen("grammar.txt", "r");

    // Return if could not open file
    if (grammarFilePointer == NULL)
        return;

    struct Node *tempoHead = &prodTable[0];
    int row = 0;
    int k = 0;
    
    while (1)
    {

        if (feof(grammarFilePointer))
        {
            // printf("break");
            break;
        }
        // Taking input single character at a time

        char c = fgetc(grammarFilePointer);
        if(c=='~') break;
        printf("%c", c);
        if (c == ' ')
        {
            k = 0;
            tempoHead->next = (struct Node *)malloc(sizeof(struct Node));
            // printf("tempohead = %s\n",tempoHead->str);
            tempoHead = tempoHead->next;
        }
        else if (c == '\n')
        {
            struct Node *n = &prodTable[row];
            // printf("%s\n",n->str);
            row++;
            tempoHead = &prodTable[row];
            k = 0;
        }
        else
        {   
            
            tempoHead->str[k] = c;
            // struct Node *n = &prodTable[row];
            // printf("%c",n->str[k]);
            k++;
        }
    };

    fclose(grammarFilePointer);
    // printf("!########################################################!\n");
    // for(int i=1;i<200;i++){
    //     struct Node *n = &prodTable[i];
    
    //     printList(&prodTable[i]);
    //     printf("\n");
    // }
    
    prodTableFilled=true;
    printProdTable();
    printf("!########################################################!2\n");
}




bool checkInFFSet(Str *buff, char *str, int k);
Str firstSets[lineNum][100];
Str followSets[lineNum][100];

void calcFirst(int k, char *curr, struct Node *parent)
{

    for (int i = 0; i < lineNum; i++)
    {
        struct Node *tempHead = &prodTable[i];

        if (!strcmp(curr, tempHead->str))
        {
            // both strings match

            if (tempHead->next->str[0] == 'N')
            {

                calcFirst(k, tempHead->next->str, tempHead);
            }
            else if (tempHead->next->str[0] == 'T')
            {
                if (!checkInFFSet(firstSets[k], tempHead->next->str, firstSetCol))
                {
                    strcpy(firstSets[k][firstSetCol].str, tempHead->next->str);
                    firstSetCol++;
                }
            }

            else if (tempHead->next->str[0] == 'e')
            {

                if (parent == NULL)
                {
                    if (!checkInFFSet(firstSets[k], tempHead->next->str, firstSetCol))
                    {
                        strcpy(firstSets[k][firstSetCol].str, tempHead->next->str);
                        firstSetCol++;
                    }
                }
                else
                {
                    struct Node *tempNode = parent->next;

                    while (strcmp(tempNode->str, tempHead->str))
                    {
                        tempNode = tempNode->next;
                    }

                    if (tempNode->next == NULL)
                    {
                        if (!checkInFFSet(firstSets[k], tempNode->str, firstSetCol))
                        {
                            strcpy(firstSets[k][firstSetCol].str, tempNode->str);
                            firstSetCol++;
                        }
                    }
                    else
                        calcFirst(k, tempNode->next->str, parent);
                }
            }
        }
    }
}

Str firstDoneBuff[lineNum];

bool checkInFFSet(Str *buff, char *str, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (!strcmp(buff[i].str, str))
            return true;
    }
    return false;
}

void addToFFSet(Str *buff, char *str, int k)
{
    strcpy(buff[k].str, str);
}

bool firstSetsCalculated=false;
void calcFirstSets()
{
    if(firstSetsCalculated) return;
    int k = 0;

    for (int i = 0; i < lineNum; i++)
    {

        struct Node *tempHead = &prodTable[i];

        if (!checkInFFSet(firstDoneBuff, tempHead->str, k))
        {

            strcpy(firstSets[k][firstSetCol].str, tempHead->str);
            firstSetCol++;

            calcFirst(k, tempHead->str, NULL);

            // printf("%c",'\n');
            addToFFSet(firstDoneBuff, tempHead->str, k);
            firstSetCol = 0;
            k++;
        }
    }
    firstSetsCalculated=true;
}

void printSets(int first)
{

    if (first)
    {
        for (int i = 0; i < lineNum; i++)
        {
            if (!strcmp(firstSets[i][0].str, ""))
            {
                // printf("hi");
                break;
            }
            for (int j = 0; j < 100; j++)
            {
                if (!strcmp(firstSets[i][j].str, ""))
                {
                    break;
                }
                printf("%s ", firstSets[i][j].str);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < lineNum; i++)
        {
            if (!strcmp(followSets[i][0].str, ""))
            {
                // printf("hi");
                break;
            }
            for (int j = 0; j < 100; j++)
            {
                if (!strcmp(followSets[i][j].str, ""))
                {
                    // printf("hi");
                    break;
                }
                printf("%s ", followSets[i][j].str);
            }
            printf("\n");
        }
    }
}
void calcFollowFirstParseTable(int k, char *curr, struct Node *parent);
void calcFollowParseTable(int k, char *curr);

Str followDoneBuff[lineNum];

void calcFollow(int k, char *curr);

void calcFollowFirst(int k, char *curr, struct Node *parent)
{

    for (int i = 0; i < lineNum; i++)
    {
        struct Node *tempHead = &prodTable[i];

        if (!strcmp(curr, tempHead->str))
        {
            // both strings match

            if (tempHead->next->str[0] == 'N')
            {

                calcFollowFirst(k, tempHead->next->str, tempHead);
            }
            else if (tempHead->next->str[0] == 'T')
            {
                if (!checkInFFSet(followSets[k], tempHead->next->str, followSetCol))
                {
                    strcpy(followSets[k][followSetCol].str, tempHead->next->str);
                    followSetCol++;
                }
                // printf("%s ", tempHead->next->str);
            }

            else if (tempHead->next->str[0] == 'e')
            {

                if (parent == NULL)
                {
                    calcFollow(k, tempHead->str);
                    // printf("%s",tempHead->next->str);
                }
                else
                {
                    struct Node *tempNode = parent->next;

                    while (strcmp(tempNode->str, tempHead->str))
                    {
                        tempNode = tempNode->next;
                    }

                    if (tempNode->next == NULL)
                    {
                        if (!checkInFFSet(followSets[k], tempNode->str, followSetCol))
                        {
                            strcpy(followSets[k][followSetCol].str, tempNode->str);
                            followSetCol++;
                        }
                        // printf("%s ", tempNode->str);
                    }
                    else
                        calcFollowFirst(k, tempNode->next->str, parent);
                }
            }
        }
    }
}

void calcFollowFirstParseTable(int k, char *curr, struct Node *parent)
{

    for (int i = 0; i < lineNum; i++)
    {
        struct Node *tempHead = &prodTable[i];

        if (!strcmp(curr, tempHead->str))
        {
            // both strings match

            if (tempHead->next->str[0] == 'N')
            {

                calcFollowFirstParseTable(k, tempHead->next->str, tempHead);
            }
            else if (tempHead->next->str[0] == 'T')
            {

                int val = keyfromstring(tempHead->next->str);
                char buf[4];
                sprintf(buf, "%d", k);
                // printf("%s", buf);
                strcpy(parseTable[parseTableRow][val].str, buf);
                // strcpy( parseTable[k][val].str , prodTable[val].);
                // printf("%s ",tempHead->next->str);
            }

            else if (tempHead->next->str[0] == 'e')
            {

                if (parent == NULL)
                {
                    calcFollowParseTable(k, tempHead->str);
                    // printf("%s",tempHead->next->str);
                }
                else
                {
                    struct Node *tempNode = parent->next;

                    // while(strcmp(tempNode->str,tempHead->str)){
                    //     tempNode = tempNode->next;
                    // }

                    if (tempNode == NULL)
                    {
                        calcFollowParseTable(k, parseTable[parseTableRow][0].str);
                    }
                    else
                    {
                        // printf("%s @!\n", tempNode->str);
                        calcFollowFirstParseTable(k, tempNode->str, tempNode);
                        // printf("hi");
                    }
                }
            }
        }
    }
}

void calcFollow(int k, char *curr)
{

    if (!strcmp(curr, "N_program"))
    {
        if (!checkInFFSet(followSets[k], "$", followSetCol))
        {
            strcpy(followSets[k][followSetCol].str, "$");
            followSetCol++;
        }
        // printf("%c ", '$');
        return;
    }

    for (int i = 0; i < lineNum; i++)
    {

        struct Node *lhs = &prodTable[i];
        struct Node *tempHead = lhs;

        while (1)
        {

            if (tempHead->next == NULL)
                break;

            tempHead = tempHead->next;

            if (!strcmp(curr, tempHead->str))
            {

                if (tempHead->next && strcmp(tempHead->next->str, ""))
                {

                    if (tempHead->next->str[0] == 'T')
                    {
                        if (!checkInFFSet(followSets[k], tempHead->next->str, followSetCol))
                        {
                            strcpy(followSets[k][followSetCol].str, tempHead->next->str);
                            followSetCol++;
                        }
                        // printf("%s ", tempHead->next->str);
                    }
                    else
                        calcFollowFirst(k, tempHead->next->str, NULL);
                }
                else if (!strcmp(curr, tempHead->str))
                {
                    // printf("lhs: %s ", lhs->str);

                    if (strcmp(lhs->str, tempHead->str))
                        calcFollow(k, lhs->str);
                }
            }
        }
    }
}

void calcFollowParseTable(int k, char *curr)
{

    if (!strcmp(curr, "N_program"))
    {
        char buf[4];
        sprintf(buf, "%d", k);
        strcpy(parseTable[parseTableRow][1].str, buf);
        return;
    }

    for (int i = 0; i < lineNum; i++)
    {

        struct Node *lhs = &prodTable[i];
        struct Node *tempHead = lhs;

        while (1)
        {
            if (tempHead->next == NULL)
                break;
            tempHead = tempHead->next;

            if (!strcmp(curr, tempHead->str))
            {
                if (tempHead->next && strcmp(tempHead->next->str, ""))
                {

                    if (tempHead->next->str[0] == 'T')
                    {
                        int val = keyfromstring(tempHead->next->str);
                        char buf[4];
                        sprintf(buf, "%d", k);
                        strcpy(parseTable[parseTableRow][val].str, buf);
                    }
                    else
                        calcFollowFirstParseTable(k, tempHead->next->str, NULL);
                }
                else if (!strcmp(curr, tempHead->str))
                {
                    if (strcmp(lhs->str, tempHead->str))
                        calcFollowParseTable(k, lhs->str);
                }
            }
        }
    }
}

void calcFollowSets()
{

    int k = 0;

    for (int i = 0; i < lineNum; i++)
    {

        struct Node *tempHead = &prodTable[i];

        if (!checkInFFSet(followDoneBuff, tempHead->str, k))
        {
            strcpy(followSets[k][followSetCol].str, tempHead->str);
            followSetCol++;
            // printf("%s : ", tempHead->str);
            calcFollow(k, tempHead->str);
            // printf("%c", '\n');
            addToFFSet(followDoneBuff, tempHead->str, k);
            followSetCol = 0;
            k++;
        }
    }
}

void printNonTerminalSet(int nonTerminalFlag)
{

    if (nonTerminalFlag)
    {
        for (int i = 0; i < lineNum; i++)
        {
            if (!strcmp(nonTerminalSet[i].str, ""))
            {
                break;
            }
            printf("%s \n", nonTerminalSet[i].str);
        }
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (!strcmp(terminalSet[i].str, ""))
            {
                break;
            }
            printf("%s \n", terminalSet[i].str);
        }
    }
    return;
}

void fillParseTableRow(int k, char *curr, struct Node *parent)
{
    struct Node *tempHead = &prodTable[k - 1];
    if (tempHead->next->str[0] == 'N')
    {
        calcFollowFirstParseTable(k, tempHead->next->str, tempHead);
    }
    else if (tempHead->next->str[0] == 'T')
    {
        int val = keyfromstring(tempHead->next->str);
        char buf[4];
        sprintf(buf, "%d", k);
        strcpy(parseTable[parseTableRow][val].str, buf);
    }

    else if (tempHead->next->str[0] == 'e')
    {
        calcFollowParseTable(k, tempHead->str);
    }
}

void fillParseTable()
{
    for (int i = 1; i <= 100; i++)
    {
        strcpy(parseTable[0][i].str, terminalSet[i - 1].str);
    }

    Str temp;
    strcpy(temp.str, nonTerminalSet[0].str);

    for (int i = 1; i <= lineNum; i++)
    {
        struct Node *n = &prodTable[i - 1];
        if (strcmp(temp.str, n->str))
        {
            parseTableRow++;
            strcpy(temp.str, n->str);
        }
        strcpy(parseTable[parseTableRow][0].str, n->str);
        fillParseTableRow(i, n->str, NULL);
    }
}

bool elementsStored = false;
void storeElements()
{
    if(elementsStored) return;
    strcpy(terminalSet[0].str, "$");
    terminalSetCounter++;   
    for (int i = 0; i < lineNum; i++)
    { 
        struct Node *n = &prodTable[i];
        while (n != NULL)
        {
            if (n->str[0] == 'N')
            {
                if (!checkInFFSet(nonTerminalSet, n->str, nonTerminalSetCounter + 1))
                {
                    strcpy(nonTerminalSet[nonTerminalSetCounter].str, n->str);
                    nonTerminalSetCounter++;
                }
            }
            else
            {

                if (!checkInFFSet(terminalSet, n->str, terminalSetCounter + 1))
                {
                    strcpy(terminalSet[terminalSetCounter].str, n->str);
                    terminalSetCounter++;
                }
            }
            n = n->next;
        }
    }
    elementsStored=true;
}

void printParseTable()
{
    FILE *fp = fopen("parseTable.txt", "w");
    for (int i = 0; i < lineNum; i++)
    {
        if (i != 0 && (!strcmp(parseTable[i][0].str, "")))
        {
            printf("hi");
            break;
        }
        for (int j = 0; j < 100; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(fp, "**,");
                printf("**,");
                continue;
            }
            printf(" %s ", parseTable[i][j].str);
            fprintf(fp, "%s", parseTable[i][j].str);
            fprintf(fp, ",");
        }
        fprintf(fp, "\n");
        printf("\n");
    }

    fclose(fp);
}

// =============================================================================================================
int cur = 0;
typedef struct
{
    pair st[500];
} Stack;

Stack stk;
pair top()
{
    return stk.st[cur];
}

void push(int key, int ntCheck, parseNode *node)
{
    cur++;
    stk.st[cur].key = key;
    stk.st[cur].ntCheck = ntCheck;
    stk.st[cur].node = node;
}

void pop()
{
    cur--;
}
int count1=0;
parseNode *insertNode(parseNode **parent, parseNode *addrs[], char *val[1000], int count)
{
    parseNode *temp = (parseNode *)malloc(1 * sizeof(parseNode));
    temp->val = val[0];
    // temp->line_Num = val[0];
    temp->parent = (*parent);
    temp->child = NULL;
    temp->sibling = NULL;
    (*parent)->child = temp;
    addrs[0] = temp;
    count1++;
    for (int i = 1; i < count; i++) //// <
    {
        parseNode *temp1 = (parseNode *)malloc(1 * sizeof(parseNode));
        temp1->val = val[i];
        count1++;
        // temp1->line_Num = val[i];
        // printf("mkbhd %s %s \n", temp->val, temp->line_Num );

        temp1->parent = (*parent);
        temp1->child = NULL;
        temp1->sibling = NULL;
        temp->sibling = temp1;
        addrs[i]=temp1;
        temp = temp1;
    }
    return (*parent)->child;
}

void printStack()
{
    int n = cur;
    for (; n > 0; n--)
    {
        pair p = stk.st[n];
        if (p.ntCheck)
            printf("| %s |\n", NTMappings[p.key - 1]);
        else
            printf("| %s |\n", TMappings[p.key - 1]);
    }
}

#define MAX_SIZE_MODULE 100

typedef struct {
    char data[MAX_SIZE_MODULE][100];
    int top;
} Stack_moduleName;

void init_moduleName(Stack_moduleName *s) {
    s->top = -1;
}

int is_empty_moduleName(Stack_moduleName *s) {
    return s->top == -1;
}

int is_full_moduleName(Stack_moduleName *s) {
    return s->top == MAX_SIZE_MODULE - 1;
}

char *peek_moduleName(Stack_moduleName *s) {
    if (is_empty_moduleName(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

void push_moduleName(Stack_moduleName *s, char *str) {
    if (is_full_moduleName(s)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    strcpy(s->data[s->top], str);
}

char *pop_moduleName(Stack_moduleName *s) {
    if (is_empty_moduleName(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    char *str = s->data[s->top];
    s->top--;
    return str;
}

struct Pair_startEnd {
   char *first;
   char *second;
};

struct Pair_startEnd pairs[100];

void update_pairs(struct Pair_startEnd pairs[], int size_startEnd, char *start, char *end) {
    for (int i = 0; i < size_startEnd; i++) {
        if (strcmp(pairs[i].first, start) == 0) {
            pairs[i].second = end;
        }
    }
}

char *find_end(struct Pair_startEnd pairs[], int size_startEnd, char *start) {
    for (int i = 0; i < size_startEnd; i++) {
        if (strcmp(pairs[i].first, start) == 0) {
            return pairs[i].second;
        }
    }
    return NULL;
}


int cur_startEnd = 0;

typedef struct node_startLine {
    char *data;
    struct node_startLine *next;
} Node_startLine;

Node_startLine *head_startLine = NULL;

void push_startLine(char *str) {
    Node_startLine *new_node = malloc(sizeof(Node_startLine));
    new_node->data = strdup(str);
    new_node->next = head_startLine;
    head_startLine = new_node;
}

char *pop_startLine() {
    if (head_startLine == NULL) {
        return NULL;
    }
    char *str = head_startLine->data;
    Node_startLine *temp = head_startLine;
    head_startLine = head_startLine->next;
    free(temp);
    return str;
}

char *peak_startLine() {
    if (head_startLine == NULL) {
        return NULL;
    }
    return head_startLine->data;
}



typedef struct node_arrayRange {
    char *data;
    struct node_arrayRange *next;
} Node_arrayRange;

Node_arrayRange *head_arrayRange = NULL;

void push_arrayRange(char *str) {
    Node_arrayRange *new_node = malloc(sizeof(Node_arrayRange));
    new_node->data = strdup(str);
    new_node->next = head_arrayRange;
    head_arrayRange = new_node;
}

char *pop_arrayRange() {
    if (head_arrayRange == NULL) {
        return NULL;
    }
    char *str = head_arrayRange->data;
    Node_arrayRange *temp = head_arrayRange;
    head_arrayRange = head_arrayRange->next;
    free(temp);
    return str;
}

char *peak_arrayRange() {
    if (head_arrayRange == NULL) {
        return NULL;
    }
    return head_arrayRange->data;
}


typedef struct sym_pair {
    int first;
    int second;
} sym_pair;

typedef struct symTable {
    char *varName;
    char *modNameScope;
    char *lineNumScope;
    char *type;
    char *isArray;
    char *statDyn;
    char *arrayRange;
    int width;
    int offset;
    int nestingLevel;
    struct symTable *next;
} symTable;

struct Sym_Stack {
    symTable *top;
};

// Initialize the stack
void initialize_sym(struct Sym_Stack *stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int is_empty_sym(struct Sym_Stack *stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push_sym(struct Sym_Stack *stack, symTable *element) {
    element->next = stack->top;
    stack->top = element;
}

// Pop an element from the stack
symTable* pop_sym(struct Sym_Stack *stack) {
    if (is_empty_sym(stack)) {
        printf("Error: Sym_Stack underflow\n");
        exit(1);
    }
    symTable *element = stack->top;
    stack->top = stack->top->next;
    return element;
}

// Get the top element of the stack without removing it
symTable* peek_sym(struct Sym_Stack *stack) {
    if (is_empty_sym(stack)) {
        printf("Error: Sym_Stack is empty\n");
        exit(1);
    }
    return stack->top;
}

// Create a new element for the stack
symTable* create_element(char *varName, char *modNameScope, char *lineNumScope, char *type,
                         char *isArray, char *statDyn, char *arrayRange, int width,
                         int offset, int nestingLevel) {
    symTable *element = (symTable*) malloc(sizeof(symTable));
    element->varName = strdup(varName);
    element->modNameScope = strdup(modNameScope);
    element->lineNumScope = strdup(lineNumScope);
    element->type = strdup(type);
    element->isArray = strdup(isArray);
    element->statDyn = strdup(statDyn);
    element->arrayRange = strdup(arrayRange);
    element->width = width;
    element->offset = offset;
    element->nestingLevel = nestingLevel;
    element->next = NULL;
    return element;
}

int accept_module=0;
int accept_symbols = 0;
int nesting_level = 0;
struct Sym_Stack sym_stack;
struct Sym_Stack final_sym_stack;
Stack_moduleName s_moduleName;
char* sym_types[] = {"T_INTEGER", "T_REAL", "T_BOOLEAN","T_SEMICOL"};
int is_array = 0;

int find_sym_type(char* str) {
    int i;
    int num_types = sizeof(sym_types) / sizeof(sym_types[0]);

    // Loop through the array of symbol types
    for (i = 0; i < num_types; i++) {
        // Compare the input string to each symbol type
        if (strcmp(str, sym_types[i]) == 0) {
            // If we find a match, return 1
            return 1;
        }
    }

    // If we didn't find a match, return 0
    return 0;
}
int flagger = 0;

int integerWidth = 2;
int realWidth = 4;
int booleanWidth = 1;

int stringToInt(char* str) {
    int result = 0;
    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int offsetCalc = 0;


void createSymTable(parseNode *curr, parseNode *par)
{
    
    if (curr == NULL)
        return;
    
    

    if (!strcmp(curr->val, ""))
        return;

    if (curr->child != NULL)
        createSymTable(curr->child, curr);
    
    if (par != NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){

                if(!strcmp(curr->val,"T_NUM")){
                    push_arrayRange(curr->lexeme.lex);
                }

                if(!strcmp(curr->val,"T_MODULE")){
                    accept_module=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_module){
                    push_moduleName(&s_moduleName, curr->lexeme.lex);
                    accept_module=0;
                }

                if(!strcmp(curr->val,"T_START")){
                    // pairs[cur_startEnd].first = strdup(curr->line_Num);
                    cur_startEnd++;
                    // push_startLine(curr->line_Num);
                    nesting_level++;
                }

                if(!strcmp(curr->val,"T_END")){
                    // update_pairs(pairs, 100, peak_startLine(), curr->line_Num);
                    nesting_level--;
                    pop_startLine();
                    pop_moduleName(&s_moduleName); 
                }

                if(!strcmp(curr->val,"T_DECLARE")){
                    accept_symbols=1;
                    is_array=0;
                }

                if(!strcmp(curr->val,"T_ARRAY")){
                    is_array=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_symbols){
                    symTable *element2 = create_element(curr->lexeme.lex, "module2", "", "float", "no", "dynamic", "", 10, 20, 1);

                    push_sym(&sym_stack, element2);
                    
                    // printf("Top element:\nvarName: %s\nmodNameScope: %s\nlineNumScope: (%d, %d)\ntype: %s\nisArray: %d\nstatDyn: %s\narrayRange: %s\nwidth: %d\noffset: %d\nnestingLevel: %d\n",
                    //     peek_sym(&sym_stack)->varName, peek_sym(&sym_stack)->modNameScope, peek_sym(&sym_stack)->lineNumScope.first, peek_sym(&sym_stack)->lineNumScope.second,
                    //     peek_sym(&sym_stack)->type, peek_sym(&sym_stack)->isArray, peek_sym(&sym_stack)->statDyn, peek_sym(&sym_stack)->arrayRange,
                    //     peek_sym(&sym_stack)->width, peek_sym(&sym_stack)->offset, peek_sym(&sym_stack)->nestingLevel);
                }

                if(find_sym_type(curr->val)){
                    accept_symbols = 0;
                    while(!is_empty_sym(&sym_stack)){
                       symTable* element = pop_sym(&sym_stack);
                        element->modNameScope = strdup(peek_moduleName(&s_moduleName));

                        // element->lineNumScope = strdup(peak_startLine());
                        char* peak_start = peak_startLine();

                        if(peak_start)
                            element->lineNumScope = strdup(peak_start);


                        if(!strcmp(curr->lexeme.lex,";")){
                            element->type = strdup("module");
                        }
                        else
                            element->type = strdup(curr->lexeme.lex);

                        if(is_array){
                            char* rangeEnd = pop_arrayRange();
                            char* rangeStart = pop_arrayRange();
                            char* separator = "..";

                            // Calculate the total length of the concatenated string
                            int totalLength = strlen(rangeStart) + strlen(separator) + strlen(rangeEnd);

                            // Allocate memory for the concatenated string
                            char* concatenatedString = (char*) malloc(totalLength + 1);

                            // Copy the first string into the concatenated string
                            strcpy(concatenatedString, rangeStart);

                            // Append the separator and the second string to the concatenated string
                            strcat(concatenatedString, separator);
                            strcat(concatenatedString, rangeEnd);

                            element->arrayRange = strdup(concatenatedString);
                            
                            element->isArray = strdup("yes");


                            int start = stringToInt(rangeStart);
                            int end = stringToInt(rangeEnd);

    // Calculate the difference
                            int diff = end - start + 1;

                            if(!strcmp(element->type, "integer")){
                                element->width = 2 * diff + 1 ;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1 * diff + 1 ;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4 * diff + 1 ;

                            }


                        }
                        else{

                            element->isArray = strdup("no");

                            if(!strcmp(element->type, "integer")){
                                element->width = 2;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4;

                            }
                        }

                        // element->statDyn = strdup(statDyn);
                        // element->arrayRange = strdup(arrayRange);
                        // element->width = width;
                        // element->offset = offset;
                        element->nestingLevel = nesting_level;
                        // element->next = NULL;

                        push_sym(&final_sym_stack, element);

                        // if(element->width == 0){
                        //     printf("varName: %s, type: %s, isArray: %s, nestingLevel: %d, moduleName: %s, arrayRange: %s, lineNumScope %s,  width %s -\n",element->varName,element->type,element->isArray,element->nestingLevel,element->modNameScope,element->arrayRange,element->lineNumScope, "0");


                        // }else{
                            element->offset = offsetCalc;
                            printf("varName: %s, type: %s, isArray: %s, nestingLevel: %d, moduleName: %s, arrayRange: %s, lineNumScope %s 5 - 20,  width %d offset %d \n",element->varName,element->type,element->isArray,element->nestingLevel,element->modNameScope,element->arrayRange,element->lineNumScope, element->width, element -> offset);
                            offsetCalc += element->width;
                        // }
                    }
                }
                
                // printf("|-%s(%s) %s-|\n", curr->val, curr->lexeme.lex, par->val);
            
            }
            // else
            //     printf("|-%s %s-|\n", curr->val, par->val);

        }
    }

    if (par == NULL && curr->child == NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){

                if(!strcmp(curr->val,"T_NUM")){
                    push_arrayRange(curr->lexeme.lex);
                }

                if(!strcmp(curr->val,"T_MODULE")){
                    accept_module=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_module){
                    push_moduleName(&s_moduleName, curr->lexeme.lex);
                    accept_module=0;
                }

                if(!strcmp(curr->val,"T_START")){
                    // pairs[cur_startEnd].first = strdup(curr->line_Num);
                    cur_startEnd++;
                    // push_startLine(curr->line_Num);
                    nesting_level++;
                }

                if(!strcmp(curr->val,"T_END")){
                    
                    // update_pairs(pairs, 100, peak_startLine(), curr->line_Num);
                    // printf("yooooo \n");
                    nesting_level--; ///!!!!
                    pop_startLine();
                    pop_moduleName(&s_moduleName); 
                }

                if(!strcmp(curr->val,"T_DECLARE")){
                    accept_symbols=1;
                    is_array=0;
                }

                if(!strcmp(curr->val,"T_ARRAY")){
                    is_array=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_symbols){
                    symTable *element2 = create_element(curr->lexeme.lex, "module2", "", "float", "no", "dynamic", "", 10, 20, 1);
                    push_sym(&sym_stack, element2);
                    
                }
                
                if(find_sym_type(curr->val)){
                    
                    accept_symbols = 0;
                    while(!is_empty_sym(&sym_stack)){
                        symTable* element = pop_sym(&sym_stack);
    
                        element->modNameScope = strdup(peek_moduleName(&s_moduleName));
                        
                        // element->lineNumScope = strdup(peak_startLine());
                        char* peak_start = peak_startLine();

                        if(peak_start)
                            element->lineNumScope = strdup(peak_start);

                        if(!strcmp(curr->lexeme.lex,";")){
                            element->type = strdup("module");
                        }
                        else
                            element->type = strdup(curr->lexeme.lex);
                        
                        if(is_array){
                            char* rangeEnd = pop_arrayRange();
                            char* rangeStart = pop_arrayRange();
                            char* separator = "..";

                            // Calculate the total length of the concatenated string
                            int totalLength = strlen(rangeStart) + strlen(separator) + strlen(rangeEnd);

                            // Allocate memory for the concatenated string
                            char* concatenatedString = (char*) malloc(totalLength + 1);

                            // Copy the first string into the concatenated string
                            strcpy(concatenatedString, rangeStart);

                            // Append the separator and the second string to the concatenated string
                            strcat(concatenatedString, separator);
                            strcat(concatenatedString, rangeEnd);

                            element->arrayRange = strdup(concatenatedString);

                            element->isArray = strdup("yes");

                            int start = stringToInt(rangeStart);
                            int end = stringToInt(rangeEnd);

    // Calculate the difference
                            int diff = end - start + 1;

                            if(!strcmp(element->type, "integer")){
                                element->width = 2 * diff + 1 ;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1 * diff + 1 ;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4 * diff + 1 ;

                            }

                        }
                        else{
                            element->isArray = strdup("no");

                            if(!strcmp(element->type, "integer")){
                                element->width = 2;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4;


                                
                            }




                        }

                        // element->statDyn = strdup(statDyn);
                        // element->arrayRange = strdup(arrayRange);
                        // element->width = width;
                        // element->offset = offset;
                        element->nestingLevel = nesting_level;
                        // element->next = NULL;

                        push_sym(&final_sym_stack, element);
                            element->offset = offsetCalc;
                            printf("varName: %s, type: %s, isArray: %s, nestingLevel: %d, moduleName: %s, arrayRange: %s, lineNumScope %s 5 - 20,  width %d offset %d \n",element->varName,element->type,element->isArray,element->nestingLevel,element->modNameScope,element->arrayRange,element->lineNumScope, element->width, element -> offset);
                            offsetCalc += element->width;                    }
                }

                // printf("|-%s(%s)-|\n", curr->val, curr->lexeme.lex);
                
            }
            // else
            //     printf("|-%s-|\n", curr->val);
        }
    }
    
    if (curr->sibling != NULL)
    {
        
        createSymTable(curr->sibling, NULL);
        
    }
}


//=================================//



void printInOrder(parseNode *curr, parseNode *par)
{

    if (curr == NULL)
        return;

    if (!strcmp(curr->val, ""))
        return;

    if (curr->child != NULL)
        printInOrder(curr->child, curr);

    if (par != NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){
                
                printf("|-%s(%s) %s-|\n", curr->val, curr->lexeme.lex, par->val);
            
            }
            else
                printf("|-%s %s-|\n", curr->val, par->val);

        }
    }

    if (par == NULL && curr->child == NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){
                
                printf("|-%s(%s)-|\n", curr->val, curr->lexeme.lex);
                
            }
            else
                printf("|-%s-|\n", curr->val);
        }
    }

    if (curr->sibling != NULL)
    {
        printInOrder(curr->sibling, NULL);
    }
}

void printParseTree(parseNode *root)
{
    printf("%s\n", root->val);
    parseNode *queue = root;
    parseNode *tail = queue;
    int curr = 1;

    while (queue)
    {
        parseNode *temp = queue->child;
        if (!(temp->child))
            printf("%s ", temp->val);
        if (temp->child)
        {
            tail->sibling = temp;
            tail = tail->sibling;
        }
        while (temp->sibling)
        {
            temp = temp->sibling;
            if (!(temp->child))
                printf("%s ", temp->val);
            if (temp->child)
            {
                tail->sibling = temp;
                tail = tail->sibling;
            }
        }
        queue = queue->sibling;
        printf("\n");
    }
}

parseNode *parseTree; // global parsetree

bool checkFirstSetsWithEpsilon(char *symb)
{
    for (int i = 0; i < lineNo; i++)
    {
        if (!strcmp(firstSetsWithEpsilon[i].str, ""))
            break;

        if (!strcmp(firstSetsWithEpsilon[i].str, symb))
        {
            return true;
        }
    }
    return false;
}

void parseInputSourceCode(char *testcaseFile)
{
    FILE *lexerFP = lexerMain(testcaseFile);
    cur=0;
    pair ins;
    int key = keyfromstring("$");
    push(key, 0, NULL);
    parseNode *head = (parseNode *)malloc(1 * sizeof(parseNode));
    head->val = "N_program";
    // head->line_Num = strdup("0"); ///// IGNOREEEEEEEE
    parseTree = head;
    key = keyfromstringNT("N_program");
    push(key, 1, head);
    parseNode *latest = (parseNode *)malloc(1 * sizeof(parseNode));
    latest = head;
    Token tk = getNextToken(lexerFP,false);
    while (1)
    {
        pair topu = top();
        // printf("Topu key: %d, cur:%d\n",topu.key,cur);
        char symb[100];
        int j;
        if (topu.ntCheck)
        {
            strcpy(symb, NTMappings[topu.key - 1]);
            j = keyfromstringNT(symb);
        }
        else
        {
            strcpy(symb, TMappings[topu.key - 1]);
            j = keyfromstring(symb);
        }
        // printf("%s\n",symb);
        // printf("\n");
        // printStack();
        // if(tk.tokenID!=-1) printf("%s\n",en[tk.tokenID]);

        if (tk.tokenID == -1)
        {
            int flag = 0;
            if (cur > 2)
            {
                while (1)
                {
                    if (checkFirstSetsWithEpsilon(symb))
                    {
                        // char *symbsInRule1[1000]={"epsilon"};
                        // insertNode(&latest,symbsInRule1,1);
                        topu = top();
                        pop();
                        if (topu.ntCheck)
                        {
                            strcpy(symb, NTMappings[topu.key - 1]);
                            j = keyfromstringNT(symb);
                        }
                        else
                        {

                            //     strcpy(symb,TMappings[topu.key-1]);
                            //     j=keyfromstring(symb);
                            break;
                        }
                    }
                    else
                    {
                        printf("Error: Input ended before stack and top terminal doesn't derive epsilon. Syntactically incorrect.\n");
                        break;
                    }
                }
            }
            else if (cur == 2)
            {
                // printf("%d yo %s yo\n", cur, symb);

                if (checkFirstSetsWithEpsilon(symb))
                {
                    pop();
                    latest = topu.node;
                    while (latest != NULL && strcmp(latest->val, symb) != 0)
                        latest = latest->sibling;
                    // printf("heheh %s\n",latest->val);
                    char *symbsInRule1[1000] = {"epsilon"};
                    parseNode *addrs[1];
                    insertNode(&latest, addrs, symbsInRule1, 1);
                    printf("successfully parsed.\n");
                    break;
                }
            }
            else
            {
                printf("Successfully parsed.\n");
                break;
            }
            if (flag)
                break;
        }
        char tkn[20];
        strcpy(tkn, en[tk.tokenID]);
        char prefix[1000] = "T_";
        strcat(prefix, tkn);
        strcpy(tkn, prefix);
        // printf("Terminal is %s %d\n",tkn,cur);
        int i = keyfromstring(tkn);
        if (cur == 1)
        {
            printf("Error : stack empty\n");
            break;
        }
        // printf("topu: %d cur=%d\n",topu.key,cur);
        // printf("non terminal is %s\n",symb);
        // int j=keyfromstringNT(symb);
        // printf("parsetable[%d][%d] %s\n",j,i,parseTable[j][i].str);
        latest = topu.node;
        while (latest != NULL && strcmp(latest->val, symb) != 0)
            latest = latest->sibling;

        if (keyfromstring(symb) == -1)
        { // NON TERMINAL IN STACK

            if (strcmp(parseTable[j][i].str, "") != 0)
            { // HAS PROD RULE
                pop();
                char *prod = parseTable[j][i].str;
                int produ = atoi(prod);
                struct Node *rule = &prodTable[--produ];
                // printf("rule is %d from %s\n",produ+1,rule->str);
                rule = rule->next;
                char *symbsInRule[1000];

                int p = 0;
                while (rule)
                {
                    symbsInRule[p++] = rule->str;
                    rule = rule->next;
                }
                
                parseNode *addrs[p];
                insertNode(&latest, addrs, symbsInRule, p);

                p--;
                for (; p >= 0; p--)
                {
                    
                    if (!strcmp(symbsInRule[p], "epsilon"))
                    {
                        continue;
                    }

                    if (symbsInRule[p][0] == 'T')
                    {
                        int key1 = keyfromstring(symbsInRule[p]);
                        push(key1, 0, addrs[p]);
                    }
                    else
                    {
                        int key1 = keyfromstringNT(symbsInRule[p]);
                        // printf("pushed %s\n",symbsInRule[p]);
                        if (key1 != -1)
                            push(key1, 1, addrs[p]);
                    }
                }
                // tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : No production rule for token %s at line %d.\n", en[tk.tokenID], tk.lineNo);
               
                int ntNo = keyfromstringNT(symb);
                int flag = 0;
                for (int i = 0; i < 100; i++)
                {
                    // printf("%d %s , follow %s compared %s\n",ntNo, symb, followSets[ntNo][i].str, tkn );
                    if (!strcmp(followSets[ntNo][i].str, tkn))
                    {
                        // printf("flagged here?/n");
                        pop();
                        printf("Non terminal %s removed since token %s exists in its synchronous set.\n", symb, tkn);
                        flag = 1;
                    }
                }
                if (flag){
                    
                    continue;
                }
                else
                {
                    printf("Terminal %s removed since it does not exit in the synchronous set of non terminal %s.\n", tkn, symb);
                    tk = getNextToken(lexerFP,false);
                    // printf("%s yooo\n", en[tk.tokenID]);
                }
            }
        }
        else
        {
            
            if (!strcmp(symb, tkn))
            {
                latest=topu.node;
 
                latest->lexeme.lex = malloc(strlen(tk.lexeme.lex) + 1);
                strcpy(latest->lexeme.lex, tk.lexeme.lex);
                char lineNoStr[20];
                sprintf(lineNoStr, "%u", tk.lineNo);
                // latest->lineNo = malloc(strlen(lineNoStr) + 1);
                // strcpy(latest->lineNo, lineNoStr);
                printf("lexeme: %s \n",latest->lexeme.lex);
                
                pop();
                printf("heelo\n");
                tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : Terminal Mismatch at line %d at token %s\n", tk.lineNo, en[tk.tokenID]);
                pop();
            }
        }
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    // printInOrder(head,NULL);

    // createSymTable(head, NULL);
    //  printf("here eeeeee\n");
    fclose(lexerFP);
    // printf("%s parsetree\n",parseTree->val);
    astProgram(parseTree);
    printf("=========================================================================\n");
    printAST(parseTree,NULL);
    return;
}




bool epDerivationsFilled = false;
void fillEpsilonDerivations()
{
    if(epDerivationsFilled) return;
    int k = 0;
    for (int i = 0; i < lineNum; i++)
    {
        if (!strcmp(firstSets[i][0].str, ""))
        {
            break;
        }
        for (int j = 0; j < 100; j++)
        {
            if (!strcmp(firstSets[i][j].str, ""))
            {
                break;
            }

            if (!strcmp(firstSets[i][j].str, "epsilon"))
            {
                strcpy(firstSetsWithEpsilon[k].str, firstSets[i][0].str);
                k++;
            }
        }
    }
    epDerivationsFilled =true;
}

// int main()
// {
//     readProductionRules();
//     storeElements();
//     calcFirstSets();
//     fillParseTable();
//     fillEpsilonDerivations();
//     // for(int i = 0; i <= lineNum; i++){
//     //   printf("\"%s\",\n",parseTable[i][0].str);
//     // }
//     printParseTable();
//     // printf("hi");

//     // printProdTable();

//     // calcFollowSets();
//     // printf("\n------------------------------------\n");
//     // printSets(0);
//     printf("\n------------------------------------\n");
//     parseInputSourceCode("mynewfile.txt");
//     // printf("\n------------------------------------\n");
//     // printNonTerminalSet(1);
//     // printf("\n------------------------------------\n");
//     // printNonTerminalSet(0);

//     return 0;
// }



void parseInputSourceCode_Sym2(char *testcaseFile)
{
    FILE *lexerFP = lexerMain(testcaseFile);
    cur=0;
    pair ins;
    int key = keyfromstring("$");
    push(key, 0, NULL);
    parseNode *head = (parseNode *)malloc(1 * sizeof(parseNode));
    head->val = "N_program";
    // head->line_Num = strdup("0"); ///// IGNOREEEEEEEE
    parseTree = head;
    key = keyfromstringNT("N_program");
    push(key, 1, head);
    parseNode *latest = (parseNode *)malloc(1 * sizeof(parseNode));
    latest = head;
    Token tk = getNextToken(lexerFP,false);
    while (1)
    {
        pair topu = top();
        // printf("Topu key: %d, cur:%d\n",topu.key,cur);
        char symb[100];
        int j;
        if (topu.ntCheck)
        {
            strcpy(symb, NTMappings[topu.key - 1]);
            j = keyfromstringNT(symb);
        }
        else
        {
            strcpy(symb, TMappings[topu.key - 1]);
            j = keyfromstring(symb);
        }
        // printf("%s\n",symb);
        // printf("\n");
        // printStack();
        // if(tk.tokenID!=-1) printf("%s\n",en[tk.tokenID]);

        if (tk.tokenID == -1)
        {
            int flag = 0;
            if (cur > 2)
            {
                while (1)
                {
                    if (checkFirstSetsWithEpsilon(symb))
                    {
                        // char *symbsInRule1[1000]={"epsilon"};
                        // insertNode(&latest,symbsInRule1,1);
                        topu = top();
                        pop();
                        if (topu.ntCheck)
                        {
                            strcpy(symb, NTMappings[topu.key - 1]);
                            j = keyfromstringNT(symb);
                        }
                        else
                        {

                            //     strcpy(symb,TMappings[topu.key-1]);
                            //     j=keyfromstring(symb);
                            break;
                        }
                    }
                    else
                    {
                        printf("Error: Input ended before stack and top terminal doesn't derive epsilon. Syntactically incorrect.\n");
                        break;
                    }
                }
            }
            else if (cur == 2)
            {
                // printf("%d yo %s yo\n", cur, symb);

                if (checkFirstSetsWithEpsilon(symb))
                {
                    pop();
                    latest = topu.node;
                    while (latest != NULL && strcmp(latest->val, symb) != 0)
                        latest = latest->sibling;
                    // printf("heheh %s\n",latest->val);
                    char *symbsInRule1[1000] = {"epsilon"};
                    parseNode *addrs[1];
                    insertNode(&latest, addrs, symbsInRule1, 1);
                    printf("successfully parsed.\n");
                    break;
                }
            }
            else
            {
                printf("Successfully parsed.\n");
                break;
            }
            if (flag)
                break;
        }
        char tkn[20];
        strcpy(tkn, en[tk.tokenID]);
        char prefix[1000] = "T_";
        strcat(prefix, tkn);
        strcpy(tkn, prefix);
        // printf("Terminal is %s %d\n",tkn,cur);
        int i = keyfromstring(tkn);
        if (cur == 1)
        {
            printf("Error : stack empty\n");
            break;
        }
        // printf("topu: %d cur=%d\n",topu.key,cur);
        // printf("non terminal is %s\n",symb);
        // int j=keyfromstringNT(symb);
        // printf("parsetable[%d][%d] %s\n",j,i,parseTable[j][i].str);
        latest = topu.node;
        while (latest != NULL && strcmp(latest->val, symb) != 0)
            latest = latest->sibling;

        if (keyfromstring(symb) == -1)
        { // NON TERMINAL IN STACK

            if (strcmp(parseTable[j][i].str, "") != 0)
            { // HAS PROD RULE
                pop();
                char *prod = parseTable[j][i].str;
                int produ = atoi(prod);
                struct Node *rule = &prodTable[--produ];
                // printf("rule is %d from %s\n",produ+1,rule->str);
                rule = rule->next;
                char *symbsInRule[1000];

                int p = 0;
                while (rule)
                {
                    symbsInRule[p++] = rule->str;
                    rule = rule->next;
                }
                
                parseNode *addrs[p];
                insertNode(&latest, addrs, symbsInRule, p);

                p--;
                for (; p >= 0; p--)
                {
                    
                    if (!strcmp(symbsInRule[p], "epsilon"))
                    {
                        continue;
                    }

                    if (symbsInRule[p][0] == 'T')
                    {
                        int key1 = keyfromstring(symbsInRule[p]);
                        push(key1, 0, addrs[p]);
                    }
                    else
                    {
                        int key1 = keyfromstringNT(symbsInRule[p]);
                        // printf("pushed %s\n",symbsInRule[p]);
                        if (key1 != -1)
                            push(key1, 1, addrs[p]);
                    }
                }
                // tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : No production rule for token %s at line %d.\n", en[tk.tokenID], tk.lineNo);
               
                int ntNo = keyfromstringNT(symb);
                int flag = 0;
                for (int i = 0; i < 100; i++)
                {
                    // printf("%d %s , follow %s compared %s\n",ntNo, symb, followSets[ntNo][i].str, tkn );
                    if (!strcmp(followSets[ntNo][i].str, tkn))
                    {
                        // printf("flagged here?/n");
                        pop();
                        printf("Non terminal %s removed since token %s exists in its synchronous set.\n", symb, tkn);
                        flag = 1;
                    }
                }
                if (flag){
                    
                    continue;
                }
                else
                {
                    printf("Terminal %s removed since it does not exit in the synchronous set of non terminal %s.\n", tkn, symb);
                    tk = getNextToken(lexerFP,false);
                    // printf("%s yooo\n", en[tk.tokenID]);
                }
            }
        }
        else
        {
            
            if (!strcmp(symb, tkn))
            {
                latest=topu.node;
 
                latest->lexeme.lex = malloc(strlen(tk.lexeme.lex) + 1);
                strcpy(latest->lexeme.lex, tk.lexeme.lex);
                char lineNoStr[20];
                sprintf(lineNoStr, "%u", tk.lineNo);
                // latest->lineNo = malloc(strlen(lineNoStr) + 1);
                // strcpy(latest->lineNo, lineNoStr);
                printf("lexeme: %s \n",latest->lexeme.lex);
                
                pop();
                printf("heelo\n");
                tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : Terminal Mismatch at line %d at token %s\n", tk.lineNo, en[tk.tokenID]);
                pop();
            }
        }
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    // printInOrder(head,NULL);

    createSymTable(head, NULL);
    //  printf("here eeeeee\n");
    fclose(lexerFP);
    // printf("%s parsetree\n",parseTree->val);
    // astProgram(parseTree);
    // printf("=========================================================================\n");
    // printAST(parseTree,NULL);
    return;
}


void createSymTable_Sym2(parseNode *curr, parseNode *par)
{
    
    if (curr == NULL)
        return;
    
    

    if (!strcmp(curr->val, ""))
        return;

    if (curr->child != NULL)
        createSymTable(curr->child, curr);
    
    if (par != NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){

                if(!strcmp(curr->val,"T_NUM")){
                    push_arrayRange(curr->lexeme.lex);
                }

                if(!strcmp(curr->val,"T_MODULE")){
                    accept_module=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_module){
                    push_moduleName(&s_moduleName, curr->lexeme.lex);
                    accept_module=0;
                }

                if(!strcmp(curr->val,"T_START")){
                    // pairs[cur_startEnd].first = strdup(curr->line_Num);
                    cur_startEnd++;
                    // push_startLine(curr->line_Num);
                    nesting_level++;
                }

                if(!strcmp(curr->val,"T_END")){
                    // update_pairs(pairs, 100, peak_startLine(), curr->line_Num);
                    nesting_level--;
                    pop_startLine();
                    pop_moduleName(&s_moduleName); 
                }

                if(!strcmp(curr->val,"T_DECLARE")){
                    accept_symbols=1;
                    is_array=0;
                }

                if(!strcmp(curr->val,"T_ARRAY")){
                    is_array=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_symbols){
                    symTable *element2 = create_element(curr->lexeme.lex, "module2", "", "float", "no", "dynamic", "", 10, 20, 1);

                    push_sym(&sym_stack, element2);
                    
                    // printf("Top element:\nvarName: %s\nmodNameScope: %s\nlineNumScope: (%d, %d)\ntype: %s\nisArray: %d\nstatDyn: %s\narrayRange: %s\nwidth: %d\noffset: %d\nnestingLevel: %d\n",
                    //     peek_sym(&sym_stack)->varName, peek_sym(&sym_stack)->modNameScope, peek_sym(&sym_stack)->lineNumScope.first, peek_sym(&sym_stack)->lineNumScope.second,
                    //     peek_sym(&sym_stack)->type, peek_sym(&sym_stack)->isArray, peek_sym(&sym_stack)->statDyn, peek_sym(&sym_stack)->arrayRange,
                    //     peek_sym(&sym_stack)->width, peek_sym(&sym_stack)->offset, peek_sym(&sym_stack)->nestingLevel);
                }

                if(find_sym_type(curr->val)){
                    accept_symbols = 0;
                    while(!is_empty_sym(&sym_stack)){
                       symTable* element = pop_sym(&sym_stack);
                        element->modNameScope = strdup(peek_moduleName(&s_moduleName));

                        // element->lineNumScope = strdup(peak_startLine());
                        char* peak_start = peak_startLine();

                        if(peak_start)
                            element->lineNumScope = strdup(peak_start);


                        if(!strcmp(curr->lexeme.lex,";")){
                            element->type = strdup("module");
                        }
                        else
                            element->type = strdup(curr->lexeme.lex);

                        if(is_array){
                            char* rangeEnd = pop_arrayRange();
                            char* rangeStart = pop_arrayRange();
                            char* separator = "..";

                            // Calculate the total length of the concatenated string
                            int totalLength = strlen(rangeStart) + strlen(separator) + strlen(rangeEnd);

                            // Allocate memory for the concatenated string
                            char* concatenatedString = (char*) malloc(totalLength + 1);

                            // Copy the first string into the concatenated string
                            strcpy(concatenatedString, rangeStart);

                            // Append the separator and the second string to the concatenated string
                            strcat(concatenatedString, separator);
                            strcat(concatenatedString, rangeEnd);

                            element->arrayRange = strdup(concatenatedString);
                            
                            element->isArray = strdup("yes");


                            int start = stringToInt(rangeStart);
                            int end = stringToInt(rangeEnd);

    // Calculate the difference
                            int diff = end - start + 1;

                            if(!strcmp(element->type, "integer")){
                                element->width = 2 * diff + 1 ;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1 * diff + 1 ;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4 * diff + 1 ;

                            }


                        }
                        else{

                            element->isArray = strdup("no");

                            if(!strcmp(element->type, "integer")){
                                element->width = 2;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4;

                            }
                        }

                        // element->statDyn = strdup(statDyn);
                        // element->arrayRange = strdup(arrayRange);
                        // element->width = width;
                        // element->offset = offset;
                        element->nestingLevel = nesting_level;
                        // element->next = NULL;

                        push_sym(&final_sym_stack, element);

                        // if(element->width == 0){
                        //     printf("varName: %s, type: %s, isArray: %s, nestingLevel: %d, moduleName: %s, arrayRange: %s, lineNumScope %s,  width %s -\n",element->varName,element->type,element->isArray,element->nestingLevel,element->modNameScope,element->arrayRange,element->lineNumScope, "0");


                        // }else{
                            element->offset = offsetCalc;
                            printf("varName: %s, width %d \n",element->varName, element->width);
                            offsetCalc += element->width;
                        // }
                    }
                }
                
                // printf("|-%s(%s) %s-|\n", curr->val, curr->lexeme.lex, par->val);
            
            }
            // else
            //     printf("|-%s %s-|\n", curr->val, par->val);

        }
    }

    if (par == NULL && curr->child == NULL)
    {
        if (strcmp(curr->val, "")){
            if(curr->val[0]=='T'){

                if(!strcmp(curr->val,"T_NUM")){
                    push_arrayRange(curr->lexeme.lex);
                }

                if(!strcmp(curr->val,"T_MODULE")){
                    accept_module=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_module){
                    push_moduleName(&s_moduleName, curr->lexeme.lex);
                    accept_module=0;
                }

                if(!strcmp(curr->val,"T_START")){
                    // pairs[cur_startEnd].first = strdup(curr->line_Num);
                    cur_startEnd++;
                    // push_startLine(curr->line_Num);
                    nesting_level++;
                }

                if(!strcmp(curr->val,"T_END")){
                    
                    // update_pairs(pairs, 100, peak_startLine(), curr->line_Num);
                    // printf("yooooo \n");
                    nesting_level--; ///!!!!
                    pop_startLine();
                    pop_moduleName(&s_moduleName); 
                }

                if(!strcmp(curr->val,"T_DECLARE")){
                    accept_symbols=1;
                    is_array=0;
                }

                if(!strcmp(curr->val,"T_ARRAY")){
                    is_array=1;
                }

                if(!strcmp(curr->val,"T_ID") && accept_symbols){
                    symTable *element2 = create_element(curr->lexeme.lex, "module2", "", "float", "no", "dynamic", "", 10, 20, 1);
                    push_sym(&sym_stack, element2);
                    
                }
                
                if(find_sym_type(curr->val)){
                    
                    accept_symbols = 0;
                    while(!is_empty_sym(&sym_stack)){
                        symTable* element = pop_sym(&sym_stack);
    
                        element->modNameScope = strdup(peek_moduleName(&s_moduleName));
                        
                        // element->lineNumScope = strdup(peak_startLine());
                        char* peak_start = peak_startLine();

                        if(peak_start)
                            element->lineNumScope = strdup(peak_start);

                        if(!strcmp(curr->lexeme.lex,";")){
                            element->type = strdup("module");
                        }
                        else
                            element->type = strdup(curr->lexeme.lex);
                        
                        if(is_array){
                            char* rangeEnd = pop_arrayRange();
                            char* rangeStart = pop_arrayRange();
                            char* separator = "..";

                            // Calculate the total length of the concatenated string
                            int totalLength = strlen(rangeStart) + strlen(separator) + strlen(rangeEnd);

                            // Allocate memory for the concatenated string
                            char* concatenatedString = (char*) malloc(totalLength + 1);

                            // Copy the first string into the concatenated string
                            strcpy(concatenatedString, rangeStart);

                            // Append the separator and the second string to the concatenated string
                            strcat(concatenatedString, separator);
                            strcat(concatenatedString, rangeEnd);

                            element->arrayRange = strdup(concatenatedString);

                            element->isArray = strdup("yes");

                            int start = stringToInt(rangeStart);
                            int end = stringToInt(rangeEnd);

    // Calculate the difference
                            int diff = end - start + 1;

                            if(!strcmp(element->type, "integer")){
                                element->width = 2 * diff + 1 ;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1 * diff + 1 ;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4 * diff + 1 ;

                            }

                        }
                        else{
                            element->isArray = strdup("no");

                            if(!strcmp(element->type, "integer")){
                                element->width = 2;


                            }
                            if (!strcmp(element->type, "boolean")){
                                element->width = 1;


                            }

                            if (!strcmp(element->type, "real")){
                                element->width = 4;


                                
                            }




                        }

                        // element->statDyn = strdup(statDyn);
                        // element->arrayRange = strdup(arrayRange);
                        // element->width = width;
                        // element->offset = offset;
                        element->nestingLevel = nesting_level;
                        // element->next = NULL;

                        push_sym(&final_sym_stack, element);
                            element->offset = offsetCalc;
                            printf("varName: %s, width %d \n",element->varName, element->width);
                            offsetCalc += element->width;                    }
                }

                // printf("|-%s(%s)-|\n", curr->val, curr->lexeme.lex);
                
            }
            // else
            //     printf("|-%s-|\n", curr->val);
        }
    }
    
    if (curr->sibling != NULL)
    {
        
        createSymTable(curr->sibling, NULL);
        
    }
}

void parseInputSourceCode_Sym3(char *testcaseFile)
{
    FILE *lexerFP = lexerMain(testcaseFile);
    cur=0;
    pair ins;
    int key = keyfromstring("$");
    push(key, 0, NULL);
    parseNode *head = (parseNode *)malloc(1 * sizeof(parseNode));
    head->val = "N_program";
    // head->line_Num = strdup("0"); ///// IGNOREEEEEEEE
    parseTree = head;
    key = keyfromstringNT("N_program");
    push(key, 1, head);
    parseNode *latest = (parseNode *)malloc(1 * sizeof(parseNode));
    latest = head;
    Token tk = getNextToken(lexerFP,false);
    while (1)
    {
        pair topu = top();
        // printf("Topu key: %d, cur:%d\n",topu.key,cur);
        char symb[100];
        int j;
        if (topu.ntCheck)
        {
            strcpy(symb, NTMappings[topu.key - 1]);
            j = keyfromstringNT(symb);
        }
        else
        {
            strcpy(symb, TMappings[topu.key - 1]);
            j = keyfromstring(symb);
        }
        // printf("%s\n",symb);
        // printf("\n");
        // printStack();
        // if(tk.tokenID!=-1) printf("%s\n",en[tk.tokenID]);

        if (tk.tokenID == -1)
        {
            int flag = 0;
            if (cur > 2)
            {
                while (1)
                {
                    if (checkFirstSetsWithEpsilon(symb))
                    {
                        // char *symbsInRule1[1000]={"epsilon"};
                        // insertNode(&latest,symbsInRule1,1);
                        topu = top();
                        pop();
                        if (topu.ntCheck)
                        {
                            strcpy(symb, NTMappings[topu.key - 1]);
                            j = keyfromstringNT(symb);
                        }
                        else
                        {

                            //     strcpy(symb,TMappings[topu.key-1]);
                            //     j=keyfromstring(symb);
                            break;
                        }
                    }
                    else
                    {
                        printf("Error: Input ended before stack and top terminal doesn't derive epsilon. Syntactically incorrect.\n");
                        break;
                    }
                }
            }
            else if (cur == 2)
            {
                // printf("%d yo %s yo\n", cur, symb);

                if (checkFirstSetsWithEpsilon(symb))
                {
                    pop();
                    latest = topu.node;
                    while (latest != NULL && strcmp(latest->val, symb) != 0)
                        latest = latest->sibling;
                    // printf("heheh %s\n",latest->val);
                    char *symbsInRule1[1000] = {"epsilon"};
                    parseNode *addrs[1];
                    insertNode(&latest, addrs, symbsInRule1, 1);
                    printf("successfully parsed.\n");
                    break;
                }
            }
            else
            {
                printf("Successfully parsed.\n");
                break;
            }
            if (flag)
                break;
        }
        char tkn[20];
        strcpy(tkn, en[tk.tokenID]);
        char prefix[1000] = "T_";
        strcat(prefix, tkn);
        strcpy(tkn, prefix);
        // printf("Terminal is %s %d\n",tkn,cur);
        int i = keyfromstring(tkn);
        if (cur == 1)
        {
            printf("Error : stack empty\n");
            break;
        }
        // printf("topu: %d cur=%d\n",topu.key,cur);
        // printf("non terminal is %s\n",symb);
        // int j=keyfromstringNT(symb);
        // printf("parsetable[%d][%d] %s\n",j,i,parseTable[j][i].str);
        latest = topu.node;
        while (latest != NULL && strcmp(latest->val, symb) != 0)
            latest = latest->sibling;

        if (keyfromstring(symb) == -1)
        { // NON TERMINAL IN STACK

            if (strcmp(parseTable[j][i].str, "") != 0)
            { // HAS PROD RULE
                pop();
                char *prod = parseTable[j][i].str;
                int produ = atoi(prod);
                struct Node *rule = &prodTable[--produ];
                // printf("rule is %d from %s\n",produ+1,rule->str);
                rule = rule->next;
                char *symbsInRule[1000];

                int p = 0;
                while (rule)
                {
                    symbsInRule[p++] = rule->str;
                    rule = rule->next;
                }
                
                parseNode *addrs[p];
                insertNode(&latest, addrs, symbsInRule, p);

                p--;
                for (; p >= 0; p--)
                {
                    
                    if (!strcmp(symbsInRule[p], "epsilon"))
                    {
                        continue;
                    }

                    if (symbsInRule[p][0] == 'T')
                    {
                        int key1 = keyfromstring(symbsInRule[p]);
                        push(key1, 0, addrs[p]);
                    }
                    else
                    {
                        int key1 = keyfromstringNT(symbsInRule[p]);
                        // printf("pushed %s\n",symbsInRule[p]);
                        if (key1 != -1)
                            push(key1, 1, addrs[p]);
                    }
                }
                // tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : No production rule for token %s at line %d.\n", en[tk.tokenID], tk.lineNo);
               
                int ntNo = keyfromstringNT(symb);
                int flag = 0;
                for (int i = 0; i < 100; i++)
                {
                    // printf("%d %s , follow %s compared %s\n",ntNo, symb, followSets[ntNo][i].str, tkn );
                    if (!strcmp(followSets[ntNo][i].str, tkn))
                    {
                        // printf("flagged here?/n");
                        pop();
                        printf("Non terminal %s removed since token %s exists in its synchronous set.\n", symb, tkn);
                        flag = 1;
                    }
                }
                if (flag){
                    
                    continue;
                }
                else
                {
                    printf("Terminal %s removed since it does not exit in the synchronous set of non terminal %s.\n", tkn, symb);
                    tk = getNextToken(lexerFP,false);
                    // printf("%s yooo\n", en[tk.tokenID]);
                }
            }
        }
        else
        {
            
            if (!strcmp(symb, tkn))
            {
                latest=topu.node;
 
                latest->lexeme.lex = malloc(strlen(tk.lexeme.lex) + 1);
                strcpy(latest->lexeme.lex, tk.lexeme.lex);
                char lineNoStr[20];
                sprintf(lineNoStr, "%u", tk.lineNo);
                // latest->lineNo = malloc(strlen(lineNoStr) + 1);
                // strcpy(latest->lineNo, lineNoStr);
                printf("lexeme: %s \n",latest->lexeme.lex);
                
                pop();
                printf("heelo\n");
                tk = getNextToken(lexerFP,false);
            }
            else
            {
                printf("Error : Terminal Mismatch at line %d at token %s\n", tk.lineNo, en[tk.tokenID]);
                pop();
            }
        }
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    // printInOrder(head,NULL);

    createSymTable_Sym2(head, NULL);
    //  printf("here eeeeee\n");
    fclose(lexerFP);
    // printf("%s parsetree\n",parseTree->val);
    // astProgram(parseTree);
    // printf("=========================================================================\n");
    // printAST(parseTree,NULL);
    return;
}


