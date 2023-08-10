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
#include "structs.h"
#define size 512
#define md 391

char en[65][100] = {"INTEGER" , "REAL" ,"BOOLEAN" ,"OF" ,"ARRAY" ,"START" ,"END" ,"DECLARE" ,"MODULE" ,"DRIVER" ,
"PROGRAM" ,"GET_VALUE" ,"PRINT" ,"USE" , "WITH" ,"PARAMETERS" ,"TAKES" ,
"INPUT" ,"RETURNS" ,"FOR" ,"IN" ,"SWITCH" ,"CASE" ,"BREAK" ,"DEFAULT" ,"WHILE" ,"ID", "NUM" ,"RNUM", 
"AND" ,"TRUE" ,"FALSE", "PLUS"  ,"MINUS" ,"MUL", "DIV" ,"LT" ,"LE" ,"GE" ,"GT" ,"EQ" ,"NE" ,"DEF" ,"ENDDEF" ,
"DRIVERDEF" ,"DRIVERENDDEF" ,"COLON" ,"RANGEOP" ,"SEMICOL" ,"COMMA" ,"ASSIGNOP" ,"SQBO" ,"SQBC" ,
"BO" ,"BC" ,"COMMENTMARK","OR", "IF", "THEN", "ELSE", "ENDIF", "PRINTANCESTOR", "SUBRANGE", "SIZE", "HEXNUM"};

typedef struct lookupTable lookupTable;


int pow1(long long x,int y){
    x=x%md;
    unsigned long long res=1;
    while(y>0){
        if(y&1){
            res=res*x%md;
        }
        y=y>>1;
        x=x*x%md;
    }
    return res;
}

int hash(char *keyword){
    int cnt=0;
    for(int i=0;i<100;i++){
        if(keyword[i]=='\0') break;
        cnt+=pow1(66,i)*(keyword[i]-'a');
        cnt%=md;
    }
    
    int index = cnt%md+53+173;
    return index;
}



lookupTable keywords [36]= {
            {"integer", INTEGER},
            {"real", REAL},
            {"boolean", BOOLEAN}, 
            {"of", OF},
            {"array", ARRAY},
            {"start", START},
            {"end", END},
            {"declare", DECLARE}, 
            {"module", MODULE},
            {"driver", DRIVER},
            {"program", PROGRAM},
            {"get_value", GET_VALUE},
            {"print", PRINT},
            {"use", USE},
            {"with", WITH},
            {"parameters", PARAMETERS}, 
            {"takes", TAKES}, 
            {"input", INPUT}, 
            {"returns", RETURNS},
            {"for", FOR},
            {"in", IN},
            {"switch", SWITCH}, 
            {"case", CASE},
            {"break", BREAK}, 
            {"default", DEFAULT}, 
            {"while",WHILE},
            {"true",TRUE},
            {"false",FALSE},
            {"AND", AND},
            {"OR", OR},
            {"if",IF}, 
            {"then",THEN}, 
            {"else",ELSE}, 
            {"endif",ENDIF}, 
            {"printAncestor",PRINTANCESTOR},
            {"subrange",SUBRANGE}
        };

lookupTable hashedKeywords[650];

void dbger(char* input){
    FILE *fileTestCasePtr;
    fileTestCasePtr = fopen (input,"a+");
    fputc(' ', fileTestCasePtr);
    fputc('$', fileTestCasePtr);
    fclose(fileTestCasePtr);
    return;
}


void hashKeywordsFiller(lookupTable *keywords){
    for(int i=0;i<30;i++){
      
        int index = hash(keywords[i].name);
         
        hashedKeywords[index] = keywords[i];
    }
}

//**     GLOBAL VARIABLES        **//

char buf1[size];
char buf2[size];
bool bufFlag = false; //false means currently buf1 is being used and true means buf2 is being used
int startPtr=0;
int lineNo=1;


FILE *getStream(FILE *fp1){
    if(bufFlag){
        if(fread(buf1, size, 1,fp1) == 0) return NULL;
    }
    else{
        if(fread(buf1, size, 1,fp1) == 0) return NULL;
    }
    return fp1;
}

void toggleBuff(char currentBuff[]){
    if(!bufFlag)
        strcpy(currentBuff,buf1);
    else
        strcpy(currentBuff,buf2);
}

char tempLexeme[100];
Token getNextToken(FILE* fp1, bool consolePrint){
    Token tkInfo;
    tempLexeme[0] = '\0';
    int lookAheadPtr=startPtr;
    char currentBuff[size];
    toggleBuff(currentBuff);
    int state =0;
    int finalStageReached = 0;
    bool retractFlag = false;
    while(currentBuff[lookAheadPtr]!='$'){
        // printf("%c",currentBuff[lookAheadPtr]);
        retractFlag = false;

        if(lookAheadPtr==size){
            bufFlag = !bufFlag;
            lookAheadPtr=0;
            toggleBuff(currentBuff);
            fp1 = getStream(fp1);
        }

        char currChar = (currentBuff)[lookAheadPtr];
        
        switch (state) {
            case 0:
                if(currChar<='9' && currChar>='0'){
                    state=1;
                }
                else if(currChar=='X'){
                    state = 48;
                }
                else if( currChar=='@'){
                    state = 44;
                }
                
                else if((currChar<='z' && currChar>='a') 
                    || (currChar<='Z' && currChar>='A') 
                    || (currChar=='_')){ 
                        state=9;
                }

                else if(currChar=='+') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = PLUS;
                }
                else if(currChar=='-') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = MINUS;
                }
                else if(currChar=='*') state=13;
                else if(currChar=='/') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = DIV;
                }
                else if(currChar=='!') state=17;
                else if(currChar==':') state=19;
                else if(currChar=='<') state=22;
                else if(currChar=='>') state=31;
                else if(currChar==']') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = SQBC;
                }
                else if(currChar=='[') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = SQBO;
                }
                else if(currChar==')') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = BC;
                }
                else if(currChar=='(') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = BO;
                }
                else if(currChar=='=') state=38;
                else if(currChar==';') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = SEMICOL;
                }
                else if(currChar=='.'){
                    state=43;
                }
                else if(currChar==','){
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = COMMA;
                }
                else if(currChar=='$'){
                    tkInfo.tokenID=-1;
                    break;
                }
                else if(currChar == '\n'){
                    lookAheadPtr++;
                    lineNo++;
                    continue;
                }
                else if((currChar !=' ')&&(currChar!='\t')){
                    state = 41;
                }
                break;

            case 1:
                if(currChar<='9' && currChar>='0'){
                    state=1;
                }
                else if(currChar=='.'){
                    state = 3;
                }
                else{
                    state=0;
                    finalStageReached = 2;
                    lookAheadPtr--;
                    retractFlag=true;
                    tkInfo.tokenID = NUM;
                }
                break;
      
            case 3:
                if(currChar<='9' && currChar>='0') state=4;
                else if(currChar=='.') {
                    state=0;
                    finalStageReached = true;
                    retractFlag=true;
                    int i=0;
                    for(i=0;i<20;i++){
                        if(tempLexeme[i]=='\0'){
                            tempLexeme[i-1] = '\0';
                        }
                    }
                    tkInfo.tokenID=NUM;
                    lookAheadPtr--;
                    lookAheadPtr--;
                }
                else {state = 41; lookAheadPtr--;}
                break;
                
            case 4:
                if(currChar<='9' && currChar>='0') state=4;
                else if((currChar=='E') || (currChar=='e')) state=5;
                else {
                    state=0;
                    finalStageReached = 3;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = RNUM;
                }
                break;
            
            case 5:
                if((currChar=='+') || (currChar=='-') || (currChar=='~')) state=6;
                else {state = 41; lookAheadPtr--;}
                break;

            case 6:
                if(currChar<='9' && currChar>='0') state=7;
                else {state = 41; lookAheadPtr--;}
                break;

            case 7:
                if(currChar<=57 && currChar>=48) state=7;
                else{
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = RNUM;
                }
                break;
            
            case 9:
                if(!((currChar<='z' && currChar>='a') 
                    || (currChar<='Z' && currChar>='A') 
                    || (currChar=='_') || (currChar<= '9' && currChar>='0'))
                    || (currChar=='\n')) {
                        state=0;
                        finalStageReached = true;
                        char nul = '\0';
                        strncat(tempLexeme, &nul, 1);
                        // int index = hash(tempLexeme);

                        int flag = 0;

                        for(int i=0; i<36; i++){
                            if(!strcmp(tempLexeme, keywords[i].name)){
                                tkInfo.tokenID = keywords[i].value;
                                flag=1;
                                break;
                            }
                        }
                        if(!flag){
                            tkInfo.tokenID = ID;
                        }

                    // // if(!strcmp(tempLexeme, "OR")){
                    // //     tkInfo.tokenID = OR;
                    // // }
                    //   // printf("ID lexeme = %s %d %s\n",tempLexeme,index,hashedKeywords[index].name);
                    //     if(strcmp(hashedKeywords[index].name,tempLexeme)==0){
                    //         // printf("HI inside lex");
                    //         tkInfo.tokenID= hashedKeywords[index].value;
                    //     }
                    //     else tkInfo.tokenID = ID;
                        lookAheadPtr--;
                        retractFlag = true;
                    }
                break;

            case 13:
                if(currChar=='*') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = COMMENTMARK;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = MUL;
                }
                break;

            case 17:
                if(currChar=='=') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = NE;
                }
                else {state = 41; lookAheadPtr--;}
                break;

            case 19:
                if(currChar=='=') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = ASSIGNOP;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = COLON;
                }
                break;

            case 22:
                if(currChar=='<') state=25;
                else if(currChar=='=') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = LE;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = LT;
                }
                break;

            case 25:
                if(currChar=='<') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = DRIVERDEF;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = DEF;
                }
                break;

            case 31:
                if(currChar=='>') state=34;
                else if(currChar=='=') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = GE;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = GT;
                }
                
                break;

            case 34:
                if(currChar=='>') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = DRIVERENDDEF;
                }
                else {
                    state=0;
                    finalStageReached = true;
                    lookAheadPtr--;
                    retractFlag = true;
                    tkInfo.tokenID = ENDDEF;
                }
                
                break;

            case 38:
                if(currChar=='=') {
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = EQ;
                }
                else {state = 41; lookAheadPtr--;}
                break;

            case 41:
                printf("\n Error found on line %d, at %s\n", lineNo, tempLexeme);
                tempLexeme[0] = '\0';
                lookAheadPtr--;
                retractFlag = true;
                state = 0;
                break;
            
            case 43:
                if(currChar=='.'){
                    state=0;
                    finalStageReached=true;
                    tkInfo.tokenID=RANGEOP;
                }else {state=41; lookAheadPtr--;}
                break;
            case 44:
                if(currChar=='s'){
                    state = 45;
                }else{
                    state = 41;
                    lookAheadPtr--;
                    retractFlag = true;
                }
                break;
            case 45:
                if(currChar=='i'){
                    state = 46;
                }else{
                    state = 41;
                    lookAheadPtr--;
                    retractFlag = true;
                }
                break;
            case 46:
                if(currChar=='z'){
                    state = 47;
                }else{
                    state = 41;
                    lookAheadPtr--;
                    retractFlag = true;
                }
                break;
            case 47:
                if(currChar=='e'){
                    state = 0;
                    finalStageReached = true;
                    // lookAheadPtr--;
                    // retractFlag = true;
                    tkInfo.tokenID = SIZE;
                }else{
                    state = 41;
                    lookAheadPtr--;
                    retractFlag = true;
                }
                break;
            case 48:
                if( (currChar>='0' && currChar<='9') || (currChar>='A' && currChar<='F')){
                    state = 49;
                }else if(((currChar<='z' && currChar>='a') 
                    || (currChar<='Z' && currChar>='A') 
                    || (currChar=='_') || (currChar<= '9' && currChar>='0'))
                    || (currChar=='\n')){

                        state=9;
                }else{
                    state=0;
                    finalStageReached = true;
                    tkInfo.tokenID = ID;
                }
                break;
            case 49:
                if( (currChar>='0' && currChar<='9') || (currChar>='A' && currChar<='F') ){
                    state = 49;
                }else{
                    state = 0;
                    finalStageReached = true;
                    tkInfo.tokenID = HEXNUM;
                    retractFlag = true;
                    lookAheadPtr--;
                }

            default:

                break;
                
        }
        
        if(!retractFlag){
            if(currChar!=' ' && currChar!='\t' && currChar != '\n'){
                strncat(tempLexeme, &currChar, 1);
            }
        }
        lookAheadPtr++;
        if(finalStageReached){
            // reset startPtr
            if(512 == lookAheadPtr)
                startPtr = 0;  
            else
                startPtr = lookAheadPtr;

            // set and return token
            
            if(state == 2){
                tkInfo.lexeme.valueInt = atoi(tempLexeme);
            }else if(state == 3){
                tkInfo.lexeme.valueFloat = atof(tempLexeme);
            }else{
                tkInfo.lexeme.lex = tempLexeme;

            }
                
            tkInfo.lineNo = lineNo;
            finalStageReached = 0;
            if(consolePrint) printf("%d. %s %s\n",tkInfo.lineNo,tempLexeme,  en[tkInfo.tokenID]);
            return tkInfo;    
        }
        
        
        // printf("FINAL LOOK %d\n",lookAheadPtr);
        if(currentBuff[lookAheadPtr]=='$'){
            // printf("in $\n");
            tkInfo.tokenID=-1;
        }
    }
    return tkInfo;
}


void removeComments(char *testcaseFile, bool consolePrint){
    char *cleanFile = "cmtsRemoved.txt";
    FILE *fileTestCasePtr, *fileCleanFilePtr;
    fileTestCasePtr = fopen (testcaseFile,"r");
    fileCleanFilePtr = fopen (cleanFile,"w");
    char nextChar;
    char lookAheadChar;
    bool flag = true;

    while((nextChar = fgetc(fileTestCasePtr)) != EOF){
        // printf("%c",nextChar);
        if(nextChar == '"'){
            flag = !flag;
        }
        
        if(nextChar == '*' && flag){
            lookAheadChar = fgetc(fileTestCasePtr);

            if(lookAheadChar == '*' && flag){
                char removeAllChars;
                char lookAheadChar;
                while((removeAllChars = fgetc(fileTestCasePtr)) != EOF){
                    if(removeAllChars == '\n' && flag){
                        fputc(removeAllChars, fileCleanFilePtr);
                    }
                    if((removeAllChars == '*' ) && flag && ((lookAheadChar = fgetc(fileTestCasePtr)) == '*')){
                        break;
                    }
                }
            }
            else{
                
                fputc(nextChar, fileCleanFilePtr);
                fputc(lookAheadChar, fileCleanFilePtr);
            }       
        }
        else{
            fputc(nextChar, fileCleanFilePtr);
        }
    }

    fclose(fileTestCasePtr);
    fclose(fileCleanFilePtr);
    if(consolePrint){
        FILE *fp = fopen(cleanFile,"r");
        int lineNo=1;
        char nextChar;
        printf("%d. ",lineNo++);
        while ((nextChar = fgetc(fp))!= '$')
        {
            printf("%c", nextChar);
            if(nextChar=='\n') printf("%d. ",lineNo++);
        }
        printf("\n");
        fclose(fp);
    }
    return;
}

FILE* lexerMain(char *input){
    dbger(input);
    removeComments(input,false);
    hashKeywordsFiller(keywords);
    FILE *cmtsRemovedFP = fopen("cmtsRemoved.txt","r");
    startPtr=0;
    lineNo=1;
    bufFlag=false;
    buf1[0]='\0';
    buf2[0]='\0';
    fread(buf1, size, 1,cmtsRemovedFP);
    fread(buf2, size, 1,cmtsRemovedFP);
    
    return cmtsRemovedFP;
}
// int main(){
    
//     char input[] = "mynewfile.txt";
//     char output[] = "mynewnewfile.txt";
//     char en[57][100] = {"INTEGER" , "REAL" ,"BOOLEAN" ,"OF" ,"ARRAY" ,"START" ,"END" ,"DECLARE" ,"MODULE" ,"DRIVER" ,
//     "PROGRAM" ,"GET_VALUE" ,"PRINT" ,"USE" , "WITH" ,"PARAMETERS" ,"TAKES" ,
//     "INPUT" ,"RETURNS" ,"FOR" ,"IN" ,"SWITCH" ,"CASE" ,"BREAK" ,"DEFAULT" ,"WHILE" ,"ID", "NUM" ,"RNUM", 
//     "AND" ,"TRUE" ,"FALSE", "PLUS"  ,"MINUS" ,"MUL", "DIV" ,"LT" ,"LE" ,"GE" ,"GT" ,"EQ" ,"NE" ,"DEF" ,"ENDDEF" ,
//     "DRIVERDEF" ,"DRIVERENDDEF" ,"COLON" ,"RANGEOP" ,"SEMICOL" ,"COMMA" ,"ASSIGNOP" ,"SQBO" ,"SQBC" ,
//     "BO" ,"BC" ,"COMMENTMARK", "OR"};

    
//     // getStream();
//     // printf("Buffer added! \n");
    
//     fread(buf1, size, 1,fp);
//     fread(buf2, size, 1,fp);
//     buf1[size] = '\0';
//     buf2[size] = '\0';
//     // printf("buf1 = %s\n",buf1);
//     // printf("buf2 = %s\n",buf2);
//     // for(int i=0;i<25;i++){
//     //     printf("%c,",buf1[i]);
//     // }
//     for(int i=0;i<5000;i++){ //// if both buffers empty, 
//         Token tk = getNextToken(fp);
//         if(tk.tokenID!=-1) printf("%s %d %d\n",en[tk.tokenID], tk.tokenID, tk.lineNo);
//         else break;
//     }
//     return 0;
// }