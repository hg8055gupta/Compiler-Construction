int count = 0;
void astProgram(parseNode *p);
void astModuleDeclarations(parseNode *p);
void astOtherModules(parseNode *p);
void astModuleDeclaration(parseNode *p);
void astModule(parseNode *p);
void astModuleDef(parseNode *p);
void astInputPList(parseNode *p);
void astRet(parseNode *p);
void astOutputPList(parseNode *p);
void astDriverModule(parseNode *p);
void astDataType(parseNode *p);
void astN1(parseNode *p);
void astType(parseNode *p);
void astN2(parseNode *p);
void astRangeArrays(parseNode *p);
void astIndexArr(parseNode *p);
void astStatements(parseNode *p);
void astStatement(parseNode *p);
void astIoStmt(parseNode *p);
void astSimpleStmt(parseNode *p);
void astDeclareStmt(parseNode *p);
void astConditionalStmt(parseNode *p);
void astIterativeStmt(parseNode *p);
void astVarPrint(parseNode *p);
void astP1(parseNode *p);
void astBoolConstt(parseNode *p);
void astSign(parseNode *p);
void astNewIndex(parseNode *p);
void astIdNumRnum(parseNode *p);
void astArrayElementForPrint(parseNode *p);
void astAssignmentStmt(parseNode *p);
void astModuleReuseStmt(parseNode *p);
void astWhichSmt(parseNode *p);
void astLvalueIDStmt(parseNode *p);
void astLvalueArrStmt(parseNode *p);
void astExpression(parseNode *p);
void astElementIndexWithExpressions(parseNode *p);
void astOptional(parseNode *p);
void astActualParaList(parseNode *p);
void astK(parseNode *p);
void astAppendParaList(parseNode *p);
void astIdList(parseNode *p);
void astN3(parseNode *p);
void astArithmeticOrBooleanExpr(parseNode *p);
void astU(parseNode *p);
void astUnaryOp(parseNode *p);
void astNewNT(parseNode *p);
void astArithmeticExpr(parseNode *p);
void astVarIdNum(parseNode *p);
void astAnyTerm(parseNode *p);
void astN7(parseNode *p);
void astCaseStmt(parseNode *p);
void astLogicalOp(parseNode *p);
void astN8(parseNode *p);
void astRelationalOp(parseNode *p);
void astTerm(parseNode *p);
void astN4(parseNode *p);
void astOp1(parseNode *p);
void astFactor(parseNode *p);
void astN5(parseNode *p);
void astOp2(parseNode *p);
void astN11(parseNode *p);
void astArrExpr(parseNode *p);
void astArrTerm(parseNode *p);
void astArrN4(parseNode *p);
void astArrFactor(parseNode *p);
void astArrN5(parseNode *p);
void astN10(parseNode *p);
void astDefault(parseNode *p);
void astValue(parseNode *p);
void astN9(parseNode *p);
void astRangeForLoop(parseNode *p);
void astIndexForLoop(parseNode *p);
void astSignForLoop(parseNode *p);
void astNewIndexForLoop(parseNode *p);
parseNode * insert_at_begin(parseNode *list, parseNode *p);


void astProgram(parseNode *p){
     // ++++++++++++++++++++++++++++++++++++++++++
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //--------------------------------
    astModuleDeclarations(p->child);
    astOtherModules(p->child->sibling);
    astDriverModule (p->child->sibling->sibling);
    astOtherModules(p->child->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    p->syn_list->branch->branch->branch-> syn_list = p->child->sibling->sibling->sibling->syn_list;
}

void astModuleDeclarations(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // ++++++++++++++++++++++++++++
     //------------------------
    if(!strcmp(p->child->val,"epsilon")) {
        p->syn_list=NULL;
        return;
    }
    printf("%s \n",p->val);
    astModuleDeclaration(p->child);
    
    astModuleDeclarations(p->child->sibling);
    p->addr = p->child;
    p->syn_list=insert_at_begin(p->child->sibling->syn_list, p->addr);
    p->syn_list->branch = NULL;
}

void astOtherModules(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // ++++++++++++++++++++++++++++++++++
     //-------------------------------
    if(!strcmp(p->child->val , "epsilon")){
        return;
    }
    printf("%s ",p->val);
    count++;
    astModule(p->child);
    astOtherModules(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
}

void astModuleDeclaration(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // +++++++++++++++++++++++++++++
     //--------------
    p->addr = p->child->sibling->sibling;
}
 
void astDriverModule(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s \n",p->val);
      // +++++++++++++++++++++++++++++++
     // -----------------------
    astModuleDef(p->child->sibling->sibling->sibling->sibling);
    p->syn_list = p->child->sibling->sibling->sibling->sibling->syn_list;
    p->syn_list->branch = NULL;
}

void astModule(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // +++++++++++++++++++++++++++++++++++
     //-=-----------------------------------
     printf("%s ",p->val);
    count++;


    astInputPList(p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling);
    astRet(p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling);
    astModuleDef(p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->sibling->sibling;
    p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    p->syn_list->branch->branch->branch-> syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
}
 
void astModuleDef(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // ++++++++++++++++++++++++++++++++++++++++
     // ----------------------
    astStatements(p->child->sibling);
    p->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch = NULL;
    return;
}
 
void astInputPList(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // ++++++++++++++++++++++++++++++
     //-----------------------------------------
    astDataType(p->child->sibling->sibling);
    astN1(p->child->sibling->sibling->sibling);
    p->addr = p->child;
    p->addr->type = p->child->sibling->sibling;
    p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->syn_list,p->addr);
    p->syn_list->branch = NULL;
    return;
}
 
void astRet(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++
    
    if(!strcmp(p->child->val ,"epsilon")) {
        p->syn_list=NULL;
        p->addr = NULL;
        return;
    }
    astOutputPList(p->child->sibling->sibling);
    p->syn_list = p->child->sibling->sibling->syn_list;
    p->syn_list->branch = NULL;
    return;
}
 
void astOutputPList(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++
     //-----------------------------------------
    astType(p->child->sibling->sibling);
    astN2(p->child->sibling->sibling->sibling);
    p->addr = p->child;
    p->addr->type = p->child->sibling->sibling;
    p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->syn_list,p->addr);
    p->syn_list->branch = NULL;
    return;
}

void astDataType(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_INTEGER") || !strcmp(p->child->val ,"T_REAL") || !strcmp(p->child->val ,"T_BOOLEAN")) p->addr = p->child;
    else { 
        astRangeArrays(p->child->sibling->sibling);
        astType(p->child->sibling-> sibling-> sibling-> sibling ->sibling);
        p->addr = p->child->sibling->sibling->addr;
        p->addr->type = p->child->sibling-> sibling-> sibling-> sibling ->sibling->addr;
    }

    return;
}
 
void astN1(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }

    astDataType(p->child->sibling->sibling->sibling);
    astN1(p->child->sibling->sibling->sibling->sibling);
    p->addr = p->child->sibling;
    p->addr->type = p->child->sibling->sibling->sibling->addr;
    p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->sibling->syn_list, p->addr);
    p->syn_list->branch = NULL;
    return;
}
 
void astType(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
 
void astN2(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++
     //-----------------------------------------
     if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }

    astType(p->child->sibling->sibling->sibling);
    astN2(p->child->sibling->sibling->sibling->sibling);
    p->addr = p->child->sibling;
    p->addr->type = p->child->sibling->sibling->sibling->addr;
    p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->sibling->syn_list, p->addr);
    p->syn_list->branch = NULL;
    return;
}
 
void astRangeArrays(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     // +++++++++++++++++++++++++++
     //-----------------------------------------
    astIndexArr(p->child);
    astIndexArr(p->child->sibling->sibling);
    p->addr = p->child->addr;
    p->addr->type = p->child->sibling->sibling->addr;
    return;
}
 
void astIndexArr(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      // +++++++++++++++++++++++++
     //-----------------------------------------
    astSign(p->child);
    astNewIndex(p->child->sibling);
    if(p->child->addr!=NULL){
        p->addr = p->child->addr;
        p->addr->type = p->child->sibling->addr;
    }else{
        p->addr = p->child->sibling->addr;
        p->addr->type = NULL;
    }
    return;
}
 
void astStatements(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
       // +++++++++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astStatement(p->child);
    astStatements(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    return;
}
 
void astStatement(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     // ++++++++++++++++++++++++++++++++++++++
     //--------------------------
    if(!strcmp(p->child->val ,"N_ioStmt")){
        astIoStmt(p->child);
        p->addr = p->child;
        p->addr->type = NULL;
    }else if(!strcmp(p->child->val ,"N_simpleStmt")){
        astSimpleStmt(p->child);
        p->syn_list = p->child->syn_list;
        p->syn_list->branch = NULL;
    }else if(!strcmp(p->child->val ,"N_declareStmt")){
        astDeclareStmt(p->child);
        p->syn_list = p->child->syn_list;
        p->syn_list->branch = NULL;
    }else if(!strcmp(p->child->val ,"N_conditionalStmt")){
        astConditionalStmt(p->child);
        p->syn_list = p->child->syn_list;
        p->syn_list->branch = NULL;
    }else if(!strcmp(p->child->val ,"N_iterativeStmt")){
        astIterativeStmt(p->child);
        p->syn_list = p->child->syn_list;
        p->syn_list->branch = NULL;
    }
    return;
}
 
void astIoStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++
     //--------------------------
     
    if(!strcmp(p->child->val ,"T_GET_VALUE")) {
        p->addr=p->child;
        p->addr->type = p->child->sibling->sibling;
        return;
    }
    else{
        astVarPrint(p->child->sibling->sibling);
        p->addr=p->child;
        p->addr->type = p->child->sibling->sibling->addr;
    }

}
 
void astSimpleStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++
     //-----------------------
    if(!strcmp(p->child->val ,"N_assignmentStmt")){
        astAssignmentStmt(p->child);
        if(p->child->syn_list==NULL){
            p->addr = p->child->addr;
            p->addr->type = NULL;
        }else{
            p->syn_list = p->child->syn_list;
        }
    }else{
        astModuleReuseStmt(p->child);
        p->syn_list = p->child->syn_list;
    }
    p->syn_list->branch = NULL;
    return;
}
 
void astDeclareStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++
     //-----------------------------------------
     printf("%s ",p->val);
    count++;
    astIdList(p->child->sibling);
    astDataType(p->child->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->addr = p->child->sibling->sibling->sibling->addr;
    return;
}
 
void astConditionalStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
     //++++++++++++++++++++++++++++++
     //-------------------------------
    astStatements(p->child->sibling->sibling->sibling->sibling->sibling);
    astN9(p->child->sibling->sibling->sibling->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->sibling->sibling;
    p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    return;
}
 
void astIterativeStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //++++++++++++++++++++++++++++
     //-------------------------------
    if(!strcmp(p->child->val ,"T_FOR")){
        astRangeForLoop(p->child->sibling->sibling->sibling->sibling);
        astStatements(p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling);
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch->branch->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->addr = p->child;
        p->syn_list->branch->addr = p->child->sibling->sibling;
        p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->syn_list;
        p->syn_list->branch->branch->branch-> syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    }else{
        astArithmeticOrBooleanExpr(p->child->sibling->sibling);
        astStatements(p->child->sibling->sibling->sibling->sibling->sibling);
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->addr = p->child;
        p->syn_list->branch->syn_list = p->child->sibling->sibling->syn_list;
        p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->syn_list;
    }
}
 
void astVarPrint(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_NUM") || !strcmp(p->child->val ,"T_RNUM")) {
        p->addr=p->child;
        p->addr->type = NULL;
        return;
    }
    else if(!strcmp(p->child->val ,"N_boolConstt")){
        astBoolConstt(p->child);
        p->addr =p->child->addr;
        p->addr->type = NULL;
        return;
    }
    else{
        astP1(p->child->sibling);
        p->addr = p->child;
        p->addr->type = p->child->sibling->addr;
    return;
    }
}
 
void astP1(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++

    if(!strcmp(p->child->val ,"epsilon")) {
        p->addr=NULL;
        return;
    }
    astSign(p->child->sibling);
    astNewIndex(p->child->sibling->sibling);
    if(p->child->sibling->addr!=NULL){
        p->addr = p->child->sibling->addr;
        p->addr->type = p->child->sibling->sibling->addr;
    }else{
        p->addr = p->child->sibling->sibling->addr;
        p->addr->type = NULL;
    }
    return;
}
 
 
void astBoolConstt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     ///++++++++++++++++++++++++++++++
     //----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
}
  
void astSign(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        p->addr = NULL;
        return;
    }
    else {p->addr = p->child;p->addr->type = NULL;}
    return;
}
  
void astNewIndex(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
  
void astIdNumRnum(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
  
void astArrayElementForPrint(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++
     //-----------------------------------------
    astIndexArr(p->child->sibling->sibling);
    p->addr = p->child;
    p->addr->type = p->child->sibling->sibling;
}
  
void astAssignmentStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    astWhichSmt(p->child->sibling);
    p->addr = p->child;
    p->addr->type = NULL;
    if(p->child->sibling->syn_list == NULL){
        p->addr->type = p->child->sibling->addr;
    }else{
        p->syn_list =insert_at_begin( p->child->sibling->syn_list,p->addr);
        p->syn_list->branch = NULL;
    }
}
  
void astModuleReuseStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++
     //---------------------------------
     printf("%s ",p->val);
    count++;
    astOptional(p->child);
    astActualParaList(p->child->sibling->sibling->sibling->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->addr = p->child->sibling->sibling->sibling;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
}
    
void astWhichSmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"N_lvalueIDStmt")){
        astLvalueIDStmt(p->child);
    }else{
        astLvalueArrStmt(p->child);
    }
    if(p->child->syn_list == NULL){
        p->addr = p->child->addr;
        p->addr->type = NULL;
    }else{
        p->syn_list = p->child->syn_list;
        p->syn_list->branch = NULL;
    }
}
    
void astLvalueIDStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //++++++++++++++++++++++++++
     //-----------------------------------------
    astExpression(p->child->sibling);
    if(p->child->sibling->syn_list == NULL){
        p->addr = p->child->sibling->addr;
        p->addr->type = NULL;
    }else{
        p->syn_list = p->child->sibling->syn_list;
        p->syn_list->branch = NULL;
    }
}
    
void astLvalueArrStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //+++++++++++++++++++++++++++
     //-----------------------------------------
    astElementIndexWithExpressions(p->child->sibling);
    astExpression(p->child->sibling->sibling->sibling->sibling);

    if(p->child->sibling->syn_list == NULL){
        if(p->child->sibling->sibling->sibling->sibling !=NULL){
            p->addr = p->child->sibling->addr;
            p->addr->type = NULL;
            p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->sibling->syn_list,p->addr);
            p->syn_list->branch = NULL;
        }else{
            p->addr = p->child->sibling->addr;
            p->addr->type = p->child->sibling->sibling->sibling->sibling->addr;
        }
        
    }else{
        printf("%s ",p->val);
    count++;
        if(p->child->sibling->sibling->sibling->sibling !=NULL){
            p->syn_list=(parseNode*)malloc(sizeof(parseNode));
            p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
            p->syn_list->syn_list = p->child->sibling->syn_list;
            p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->sibling->syn_list;
        }else{
            p->syn_list=(parseNode*)malloc(sizeof(parseNode));
            p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
            p->syn_list->syn_list = p->child->sibling->syn_list;
            p->syn_list->branch->addr = p->child->sibling->sibling->sibling->sibling->addr;
        }
    }
}
    
void astExpression(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //++++++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"N_arithmeticOrBooleanExpr")) {
        astArithmeticOrBooleanExpr(p->child);
        p->syn_list=p->child->syn_list;
        p->syn_list->branch = NULL;
        return;
    }
    else{
        astU(p->child);
        if(p->child->syn_list == NULL){
            p->addr = p->child->addr;
            p->addr->type = NULL;
        }else{
            p->syn_list = p->child->syn_list;
            p->syn_list->branch = NULL;
        }
        return;
    }
}
    
void astElementIndexWithExpressions(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"N_arrExpr")) {
        astArrExpr(p->child);
        p->syn_list=p->child->syn_list;
        p->syn_list->branch = NULL;
        return;
    }
    else{
        astSign(p->child);
        astN10(p->child->sibling);
        if(p->child->sibling->syn_list == NULL){
            if(p->child->addr!=NULL){
                p->addr = p->child->addr;
                p->addr->type = p->child->sibling->addr;
            }else{
                p->addr = p->child->sibling->addr;
                p->addr->type = NULL;
            }
        }else{
            if(p->child->addr!=NULL){
                p->addr = p->child->addr;
                p->addr->type = NULL;
                p->syn_list = insert_at_begin(p->child->sibling->syn_list, p->addr);
            }else{
                p->syn_list = p->child->sibling->syn_list;
            }
            p->syn_list->branch = NULL;
        }
        return;
    }
}
    
void astOptional(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    astIdList(p->child->sibling);
    p->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch = NULL;
    return;
}
    
void astActualParaList (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++++++
     //------------------------------------
     printf("%s ",p->val);
    count++;
    astSign(p->child);
    astK(p->child->sibling);
    astAppendParaList(p->child->sibling->sibling);
    if(p->child->addr !=NULL){
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->addr = p->child->addr;
        if(p->child->sibling->syn_list !=NULL)
            p->syn_list->branch->syn_list = p->child->sibling->syn_list;
        else
            p->syn_list->branch->addr = p->child->sibling->addr;
        p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    }else{
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        if(p->child->sibling->syn_list !=NULL)
            p->syn_list->syn_list = p->child->sibling->syn_list;
        else
            p->syn_list->addr = p->child->sibling->addr;
        p->syn_list->branch->syn_list = p->child->sibling->sibling->syn_list;
    }
}
    
void astK(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_NUM") || !strcmp(p->child->val ,"T_RNUM" )) {
        p->addr=p->child;
        p->addr->type = NULL;
    }
    else if(!strcmp(p->child->val ,"N_boolConstt")){
        astBoolConstt(p->child);
        p->addr =p->child->addr;
        p->addr->type = NULL;
    }
    else{
        astN11(p->child->sibling);
        p->addr = p->child;
        p->addr->type = NULL;
        p->syn_list =insert_at_begin( p->child->sibling->syn_list, p->addr);
        p->syn_list->branch = NULL;
        return;
    }
}
    
void astAppendParaList (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++++++++++
     //---------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    astSign(p->child->sibling);
    astK(p->child->sibling->sibling);
    astAppendParaList(p->child->sibling->sibling->sibling);
    printf("%s ",p->val);
    count++;
    if(p->child->sibling->addr !=NULL){
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->addr = p->child->sibling->addr;
        if(p->child->sibling->sibling->syn_list !=NULL)
            p->syn_list->branch->syn_list = p->child->sibling->sibling->syn_list;
        else
            p->syn_list->branch->addr = p->child->sibling->sibling->addr;
        p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->syn_list;
    }else{
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        if(p->child->sibling->sibling->syn_list !=NULL)
            p->syn_list->syn_list = p->child->sibling->sibling->syn_list;
        else
            p->syn_list->addr = p->child->sibling->sibling->addr;
        p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->syn_list;
        
    }
}
    
void astIdList (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++
     //-----------------------------------------
    astN3(p->child->sibling);
    p->addr = p->child;
    p->addr->type = NULL;
    p->syn_list = insert_at_begin(p->child->sibling->syn_list,p->addr);
    p->syn_list->branch = NULL;
    return;
}
    
void astN3 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    astN3(p->child->sibling->sibling);
    p->addr = p->child->sibling;
    p->addr->type = NULL;
    p->syn_list = insert_at_begin(p->child->sibling->sibling->syn_list,p->addr);
    p->syn_list->branch = NULL;
    return;
}
    
void astArithmeticOrBooleanExpr (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    astAnyTerm(p->child);
    astN7(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    
}
    
void astU(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++
     //-----------------------------------------
    astUnaryOp(p->child);
    astNewNT(p->child->sibling);
    if(p->child->sibling->syn_list == NULL){
        p->addr = p->child->addr;
        p->addr->type = p->child->sibling->addr;
    }else{
        p->addr = p->child->addr;
        p->addr->type = NULL;
        p->syn_list = insert_at_begin(p->child->sibling->syn_list, p->addr);
        p->syn_list->branch = NULL;
    }
    return;
}
    
void astUnaryOp (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
}
    
void astNewNT (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_BO")){
        astArithmeticExpr(p->child->sibling);
        p->syn_list = p->child->sibling->syn_list;

        p->syn_list->branch = NULL;
    }else{
        astVarIdNum(p->child);
        p->addr = p->child->addr;
        p->addr->type = NULL;
    }
}
    
void astArithmeticExpr (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++
     //-----------------------------------------
    astTerm(p->child);
    astN4(p->child->sibling);
    printf("%s ",p->val);
    count++;
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    return;
}
  
void astVarIdNum (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++
      //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
  
void astAnyTerm (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
      //+++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"N_boolConstt")){
        astBoolConstt(p->child);
        p->addr =p->child->addr;
        p->addr->type = NULL;
        return;
    }else{
        astArithmeticExpr(p->child);
        astN8(p->child->sibling);
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->syn_list = p->child->syn_list;
        p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    }
}

void astCaseStmt(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //+++++++++++++++++++++++++++
     //-------------------------
    astValue(p->child->sibling);
    astStatements(p->child->sibling->sibling->sibling);
    astN9(p->child->sibling->sibling->sibling->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->sibling->addr;
    p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    return;
}
  
void astN7 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astLogicalOp(p->child);
    astAnyTerm(p->child->sibling);
    astN7(p->child->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch = (parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->addr;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    
    return;
}
  
void astLogicalOp (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
}
  
void astN8 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        p->syn_list = NULL;
        return;
    }
    astRelationalOp(p->child);
    astArithmeticExpr(p->child->sibling);
    p->addr = p->child->addr;
    p->addr->type = NULL;
    p->syn_list = insert_at_begin(p->child->sibling->syn_list, p->addr);
    p->syn_list->branch = NULL;
}
  
void astRelationalOp (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
  
void astTerm (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
     printf("%s ",p->val);
    count++;
    astFactor(p->child);
    astN5(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
}
  
void astN4 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astOp1(p->child);
    astTerm(p->child->sibling);
    astN4(p->child->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->addr;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    return;
}
  
void astOp1 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
}
 
void astFactor (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_NUM") || !strcmp(p->child->val ,"T_RNUM")) {
        p->addr=p->child;
        p->addr->type = NULL;
        return;
    }
    else if(!strcmp(p->child->val ,"N_boolConstt")){
        astBoolConstt(p->child);
        p->addr =p->child->addr;
        p->addr->type = NULL;
        return;
    }
    else if(!strcmp(p->child->val ,"T_BO" )){
        astArithmeticOrBooleanExpr(p->child->sibling);
        p->syn_list = p->child->sibling->syn_list;
        p->syn_list->branch = NULL;
    }
    else{
        astN11(p->child->sibling);
        p->addr = p->child;
        p->syn_list = insert_at_begin(p->child->sibling->syn_list, p->addr);
        p->syn_list->branch = NULL;
        return;
    }
}
 
void astN5 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astOp2(p->child);
    astFactor(p->child->sibling);
    astN4(p->child->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->addr;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    return;
}
 
void astOp2 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    p->addr = p->child;
    p->addr->type = NULL;
}
 
void astN11 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------

    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astElementIndexWithExpressions(p->child->sibling);
    astN11(p->child->sibling->sibling->sibling);
    if(p->child->sibling->syn_list == NULL){
        p->addr = p->child->sibling->addr;
        p->addr->type = NULL;
        p->syn_list = insert_at_begin(p->child->sibling->sibling->sibling->syn_list,p->addr);
        p->syn_list->branch = NULL;
    }else{
        p->syn_list=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
        p->syn_list->syn_list = p->child->sibling->syn_list;
        p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->syn_list;
    }

    
}
 
void astArrExpr (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
    printf("%s ",p->val);
    count++;
     //-----------------------------------------
    astArrTerm(p->child);
    astArrN4(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    return;
}
 
void astArrTerm (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    astArrFactor(p->child);
    astArrN5(p->child->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->syn_list = p->child->syn_list;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    return;
}
 
void astArrN4 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astOp1(p->child);
    astArrTerm(p->child->sibling);
    astArrN4(p->child->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->addr;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    return;
}
 
void astArrFactor (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"T_ID") || !strcmp(p->child->val ,"T_NUM")) {
        p->addr=p->child;
        p->addr->type = NULL;
        return;
    }
    else if(!strcmp(p->child->val ,"N_boolConstt")){
        astBoolConstt(p->child);
        p->addr =p->child->addr;
        p->addr->type = NULL;
        return;
    }
    else {
        astArrExpr(p->child->sibling);
        p->syn_list = p->child->sibling->syn_list;
        p->syn_list->branch = NULL;
        return;
    }
}
 
void astArrN5 (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astOp2(p->child);
    astArrFactor(p->child->sibling);
    astArrN4(p->child->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->addr;
    p->syn_list->branch->syn_list = p->child->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->syn_list;
    return;
}
 
void astN10  (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //-----------------------------------------
    if(p->child->val ,"N_new_index" ) {
        p->addr=p->child->addr;
        p->addr->type = NULL;
        return;
    }
    else {
        astArrExpr(p->child->sibling);
        p->syn_list =p->child->sibling->syn_list;
        p->syn_list->branch = NULL;
        return;
    }
}
 
void astDefault (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
      //-----------------
    if(!strcmp(p->child->val ,"epsilon")) {
        p->syn_list=NULL;
        return;
    }
    p->syn_list = p->child->sibling->sibling->syn_list;
    p->syn_list->branch = NULL;
    return;
}
 
void astValue (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
      //----------------------
    p->addr = p->child;
    p->addr->type = NULL;
    return;
}
 
void astN9(parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
      //+++++++++++++++++++++++++++++++
     //---------------------------------
    if(!strcmp(p->child->val ,"epsilon")) {
        return;
    }
    printf("%s ",p->val);
    count++;
    astValue(p->child->sibling);
    astStatements(p->child->sibling->sibling->sibling);
    astN9(p->child->sibling->sibling->sibling->sibling->sibling->sibling);
    p->syn_list=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->branch->branch=(parseNode*)malloc(sizeof(parseNode));
    p->syn_list->addr = p->child->sibling->addr;
    p->syn_list->branch->syn_list = p->child->sibling->sibling->sibling->syn_list;
    p->syn_list->branch->branch->syn_list = p->child->sibling->sibling->sibling->sibling->sibling->sibling->syn_list;
    return;
}
 
void astRangeForLoop (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //----------------
    astIndexForLoop(p->child);
    astIndexForLoop(p->child->sibling->sibling);
    p->addr=p->child->addr;
    p->addr->type=p->child->sibling->sibling->addr;
    return;
}
 
void astIndexForLoop (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
      //-----------------
    astSignForLoop(p->child);
    astNewIndexForLoop(p->child->sibling);
    if(p->child->addr!=NULL){
        p->addr = p->child->addr;
        p->addr->type = p->child->sibling->addr;
    }else{
        p->addr = p->child->sibling->addr;
        p->addr->type = NULL;
    }
    return;
}
 
void astSignForLoop (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++

    if(!strcmp(p->child->val ,"epsilon")) {
        p->addr = NULL;
        return;
    }
    else {p->addr = p->child;p->addr->type = NULL;}
    return;
}
 
void astNewIndexForLoop (parseNode *p){
    p->addr=NULL;
    p->syn_list=NULL;
    p->type=NULL;
    p->branch=NULL;
     //+++++++++++++++++++++++++++++++
     //--------------------
    p->addr=p->child;
    p->addr->type = NULL;
    return;
}

///*************** PLEASE VERIFY THIS HARSH PANDEY  ********************///

parseNode* insert_at_begin(parseNode *list, parseNode *p){
    printf("%s \n",p->val);
    if(list==NULL){
        return p;
    }
    if(p==NULL) return list;
    p->syn_list = list;
    return p;
}


void printAST(parseNode *p, parseNode *par){
    printf("%s call \n",p->val);
    if(p->syn_list !=NULL){
        // printf("hello3\n");
        // printf("%s\n",p->syn_list->val);
        if(p->syn_list->branch){
            // printf("hello1\n");
            printAST(p->syn_list,p);
            parseNode *temp = p->syn_list->branch;
            while(temp->branch!=NULL){
                printAST(temp,p);
                temp= temp->branch;
            }
        }else{
            // printf("hello2\n");
            printf("%s synlist ",p->syn_list->val);
            printAST(p->syn_list,p);
        }
    }else{
        // printf("hello4\n");
        if(p->addr !=NULL){
            // printf("hello5\n");
            printf("%s ",p->addr->val);
            if(p->addr->type){
                // printf("hello6\n");
                printf("%p ",p->addr);
            }
        }
    }
}
