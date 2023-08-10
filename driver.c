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
#include <time.h>
#include "parser.c"


void printCase1(char *input){
    removeComments(input,true);
}

void printCase2(char *input, char* sizebuf){
    readProductionRules();
    storeElements();
    FILE *fp1=lexerMain(input);
    Token tk;
    do{
        tk = getNextToken(fp1,true);
    }while(tk.tokenID!=-1);
    fclose(fp1); 
}

void printCase3(char *input, char *output){
    startPtr=0;
    lineNo=1;
    bufFlag=false;

    bool checkInFFSet(Str *buff, char *str, int k);
    Str firstSets[lineNum][100];
    Str followSets[lineNum][100];
    readProductionRules();
    storeElements();
    calcFirstSets();
    fillParseTable();
    fillEpsilonDerivations();
    // printNonTerminalSet(1);
    // printProdTable();
    // calcFollowSets();
    // printSets(0);
    
    FILE *fp = fopen(output,"w");
    parseInputSourceCode(input);
    fclose(fp);
    astProgram(parseTree);
    // printAST(parseTree);
    // printNonTerminalSet(1);
    // printNonTerminalSet(0);
}




void printCase5(char *input, char *output){
    startPtr=0;
    lineNo=1;
    bufFlag=false;

    bool checkInFFSet(Str *buff, char *str, int k);
    Str firstSets[lineNum][100];
    Str followSets[lineNum][100];
    readProductionRules();
    storeElements();
    calcFirstSets();
    fillParseTable();
    fillEpsilonDerivations();
    // printNonTerminalSet(1);
    // printProdTable();
    // calcFollowSets();
    // printSets(0);
    
    FILE *fp = fopen(output,"w");
    parseInputSourceCode_Sym2(input);
    fclose(fp);
    // printNonTerminalSet(1);
    // printNonTerminalSet(0);
}


void printCase6(char *input, char *output){
    startPtr=0;
    lineNo=1;
    bufFlag=false;

    bool checkInFFSet(Str *buff, char *str, int k);
    Str firstSets[lineNum][100];
    Str followSets[lineNum][100];
    readProductionRules();
    storeElements();
    calcFirstSets();
    fillParseTable();
    fillEpsilonDerivations();
    // printNonTerminalSet(1);
    // printProdTable();
    // calcFollowSets();
    // printSets(0);
    
    FILE *fp = fopen(output,"w");
    parseInputSourceCode_Sym3(input);
    fclose(fp);
    // printNonTerminalSet(1);
    // printNonTerminalSet(0);
}



// createSymTable_Sym2



void printCase4(char *input, char *output){
    startPtr=0;
    lineNo=1;
    bufFlag=false;

    // bool checkInFFSet(Str *buff, char *str, int k);
    // Str firstSets[lineNum][100];
    // Str followSets[lineNum][100];
    readProductionRules();
    storeElements();
    calcFirstSets();
    fillParseTable();
    fillEpsilonDerivations();
    // printNonTerminalSet(1);
    // printProdTable();
    // calcFollowSets();
    // printSets(0);
    
    FILE *fp = fopen(output,"w");
    parseInputSourceCode(input);
    printf("\nhelldfnkvnjfd\n");
    fclose(fp);
    // printNonTerminalSet(1);
    // printNonTerminalSet(0);
    printf("%p parsetree\n",parseTree);

    // astProgram(parseTree);
    // printAST(parseTree);
}

int main(int argc, char* argv[]){

    clock_t start_time, end_time;
    double total_CPU_time, total_CPU_time_in_seconds;
    start_time = clock();

    // invoke your lexer and parser here
    int ch;
    printf("\n\n----------------------Compiler Construction Project----------------------\n\n");
    printf("Implementation Status : \n=> Lexer and Parser Working on all Test Cases.\n=> First and Follow Sets are automated\n\n");
    do{
        printf("Enter your choice : \nPress 0 for exit\nPress 1 to print the lexemes and tokens line number wise on the console\nPress 2 to verify the syntactic correctness of input source code\nPress 3 to print ast\nPress 4 for memory\nPress 5 to print symbol table\nPress 6 for activation record size\nPress 7 for printing the type expression and width of array variables\nPress 8 for error reporting\nPress 9 for code generation\n\n");
        scanf("%d",&ch);
        switch (ch){
            case 0:{
                printf("You have exited the program!!\n");
                break;
            }
            // case 1:{
            //     printCase1(argv[1]);
            //     break;
            // }
            case 1:{
                printCase2(argv[1],argv[3]);
                break;
            }
            case 2:{
                printCase3(argv[1],argv[2]);
                break;
            }
            case 3:{
                printCase3(argv[1],argv[2]);
                break;
            }
            case 4:{
                printCase3(argv[1],argv[2]);
                printf("===============================================================================\n");
                printf("parsenodes: %d (size %d), astNodes: %d (size %d), compression ratio: %d", count1, sizeof(parseNode),count,sizeof(parseNode), count/count1);
                break;
            }
            case 5:{
                printCase5(argv[1],argv[2]);
                break;
            }
            case 6:{
                printCase5(argv[1],argv[2]);

                break;
            }
            case 7:{
                printCase5(argv[1],argv[2]);
                break;
            }
            case 8:{
                printCase5(argv[1],argv[2]);
                break;
            }
            case 9:{
                printCase5(argv[1],argv[2]);
                break;
            }
            default:{
                printf("Invalid Entry!!!!\n");
                break;
            }
        }
    }while(ch==1 || ch==2 || ch==3 || ch==4 || ch == 5 || ch == 6 || ch == 7 || ch == 8 || ch == 9);

    // Print both total_CPU_time and total_CPU_time_in_seconds 

    end_time = clock();
    total_CPU_time = (double) (end_time - start_time);
    total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;
    printf("\nTotal time : %f\n", total_CPU_time);
    return 0;
}