%{
 #include "1905065_ICGfunc.h"

void preOrder(SymbolInfo* root,int depth){
    for(int i=0;i<depth;i++)parseout<<' ';
    
    if(root->isLeaf){
        parseout<<root->type<<" : "<<root->name<<"\t<Line: ";
        parseout<<to_string(root->startLine)<<">\n";
    }
    else{
        parseout<<root->name <<" \t<Line: ";
        parseout<<to_string(root->startLine)<<"-"<<to_string(root->endLine)<<">\n";
        if(root->child!=NULL){
            SymbolInfo* curr= root->child;
            while(curr!=NULL){
                preOrder(curr, depth+1);
                curr=curr->next;
            }
        }
    }
}
void printParseTree(){
    preOrder(startSi,0);
}

%}

%union{
    SymbolInfo* si   ;
}



%token<si> IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE CONST_INT CONST_FLOAT SEMICOLON CONST_CHAR ADDOP MULOP INCOP DECOP ASSIGNOP RELOP BITOP LOGICOP NOT LPAREN RPAREN LSQUARE RSQUARE LCURL RCURL COMMA ID SINGLE_LINE_STRING MULTILINE_STRING PRINTLN
%type<si> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression mulop simple_expression term unary_expression factor argument_list arguments if_common_part
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
start:{
    header();
} program {
         $$ = new SymbolInfo( rulePrint("start","program"),$2->dataType, $2->startLine, $2->endLine);   
        startSi=$$;
        $$->child=$2;
        finishing();
} ;

program: program unit{
        $$ = new SymbolInfo( rulePrint("program","program unit"),$1->dataType, $1->startLine, $2->endLine);
        $$->child=$1;
        $1->next=$2;
}
    | unit{
        $$ = new SymbolInfo( rulePrint("program","unit"),$1->dataType, $1->startLine, $1->endLine);      
        $$->child=$1;
 
    }
 ;

unit: var_declaration{
    $$ = new SymbolInfo( rulePrint("unit","var_declaration"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

    
}
    | func_declaration{
    $$ = new SymbolInfo( rulePrint("unit","func_declaration"),$1->dataType, $1->startLine, $1->endLine); 
    $$->child=$1;
   
    
    }
    | func_definition{
     $$ = new SymbolInfo( rulePrint("unit","func_definition"),$1->dataType, $1->startLine, $1->endLine);    
    $$->child=$1;

    }
 ;

func_declaration: type_specifier ID before_params LPAREN parameter_list RPAREN  SEMICOLON{
    $$ = new SymbolInfo( rulePrint("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"),$1->dataType, $1->startLine, $7->endLine);
    $$->child=$1;
    $1->next=$2;
    $2->next= $4;
   
    $4->next=$5;
    $5->next=$6;
    $6->next=$7;
    SymbolInfo syminf(funcName,funcType);
    syminf.isFunc=true;
    syminf.paramTypeList= getStrfromSi(params);
    if(!err_def_func){
    if(!st.insert(syminf)){
        err_cnt++;
        errorPrint(" multiple declaration of "+funcName);
    }
    err_def_func=0;
    }
    if(params.size()==1 && params[0].getType()=="VOID"){
        syminf.paramTypeList.clear();
        /* only parameter is void */
    }
    else{
        st.enterScope();

            for(int i=0;i<params.size();i++){
                
            if(params[i].getType()=="VOID"){
                err_cnt++;
                errorPrint("Parameter '"+params[i].getName()+"' declared void");
            }
            bool success = st.insert(params[i]);
            if(!success) {
                err_cnt++;
                errorPrint("Conflicting types for'"+params[i].getName()+"'");
            }
            
        }
        st.exitScope();
        st.max_scope_id--;
    }
    funcType="";
    params.clear();
}
    | type_specifier ID before_params LPAREN RPAREN SEMICOLON{
        $$ = new SymbolInfo( rulePrint("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON"),$1->dataType, $1->startLine, $6->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $4;
        
        $4->next=$5;
        $5->next=$6;
        
        SymbolInfo syminf(funcName,funcType);
        syminf.isFunc=true;
        syminf.paramTypeList= getStrfromSi(params);
        if(!err_def_func){
        if(!st.insert(syminf)){
            err_cnt++;
            errorPrint(" multiple declaration of "+funcName);
        }
        err_def_func=0;
        }
        funcType="";
        params.clear();
    }
 ;
before_params: {
    
    funcName=idName;
    funcType=idType;    
}
func_definition: type_specifier ID before_params LPAREN parameter_list RPAREN compound_statement{
        $$ = new SymbolInfo( rulePrint("func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement"),$1->dataType, $1->startLine, $7->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $4;
        
        $4->next=$5;
        $5->next=$6;
        $6->next=$7;
        err_def_func=0;
}
   | type_specifier ID before_params LPAREN  RPAREN compound_statement{
    $$ = new SymbolInfo( rulePrint("func_definition", "type_specifier ID LPAREN RPAREN compound_statement"),$1->dataType, $1->startLine, $6->endLine);
    $$->child=$1;
    $1->next=$2;
        $2->next= $4;
    
        $4->next=$5;
        $5->next=$6;
        
        err_def_func=0;
    err_def_func=0;
   }
 ;

parameter_list: parameter_list COMMA type_specifier ID{
        params.push_back( SymbolInfo($4->getName(),$3->getType(), $4->startLine, $4->endLine));
    $$ = new SymbolInfo( rulePrint("parameter_list","parameter_list COMMA type_specifier ID"),$1->dataType, $1->startLine, $4->endLine);
    $$->child=$1;
    $1->next=$2;
    $2->next= $3;
    $3->next=$4;

    err_def_func=0;
}
    | parameter_list COMMA type_specifier{
        
        params.push_back( SymbolInfo("",$3->getType(), $3->startLine, $3->endLine));
        $$ = new SymbolInfo( rulePrint("parameter_list","parameter_list COMMA type_specifier"),$1->dataType, $1->startLine, $3->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        
    }
    | type_specifier ID{
        params.clear();
        params.push_back( SymbolInfo($2->getName(),$1->getType(), $2->startLine, $2->endLine));
        $$ = new SymbolInfo( rulePrint("parameter_list","type_specifier ID"),$1->dataType, $1->startLine, $2->endLine);
        $$->child=$1;
        $1->next=$2;
    }
    | type_specifier{
        params.clear();
        params.push_back( SymbolInfo("",$1->getType(), $1->startLine, $1->endLine));
        $$ = new SymbolInfo( rulePrint("parameter_list","type_specifier"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;

    }
    | type_specifier error  {
        yyclearin;
        yyerrok;
        $$ = new SymbolInfo( rulePrint("parameter_list","type_specifier ID"),"error", $1->startLine, $1->endLine);
        $$->child=$1;
        
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
        err_def_func=1;
    }
 ;

compound_statement: LCURL before_stats statements RCURL{
    $$ = new SymbolInfo( rulePrint("compound_statement", "LCURL statements RCURL"),$3->dataType, $1->startLine, $4->endLine);
    $$->child=$1;
    $1->next=$3;
    $3->next= $4;   
    st.printAllScopeTables(logout);
    st.exitScope();
    
}
    | LCURL before_stats RCURL{
        $$ = new SymbolInfo( rulePrint("compound_statement", "LCURL RCURL"),"INT", $1->startLine, $3->endLine);
        $$->child=$1;
        $1->next=$3;
        st.printAllScopeTables(logout);
        st.exitScope();
        if(st.getCurrentScopeId()==1)
            globalSc=true;
    }
 ;
before_stats: {
    if(st.getCurrentScopeId()==1)
        {
            globalSc=false;
            offset=0;
        }
    if(funcType!=""){
        SymbolInfo syminf(funcName,funcType);
    syminf.isFunc=true;
    syminf.isFuncDefined=true;
    syminf.paramTypeList= getStrfromSi(params);
    SymbolInfo* temp= st.lookup(syminf.getName());
    if(temp!=NULL){
        bool err=0;
        if(!temp->isFunc){
            err=1;
            errorPrint("'"+funcName+"' redeclared as different kind of symbol");
        }
        else if(temp->isFuncDefined) {
            err=1;
            errorPrint(funcName+" already defined");
        }
        else if(funcType!=temp->type) {
            err=1;
            errorPrint("Conflicting types for '"+funcName+"'");
        }
        else if(temp->paramTypeList.size()!=syminf.paramTypeList.size()){
            err=1;
            errorPrint("Conflicting types for '"+funcName+"'");
        }
        else if(temp->paramTypeList.size()==1 && temp->paramTypeList[0]=="VOID" && syminf.paramTypeList.size()!=0){
            err=1;
            errorPrint(" multiple declaration of "+funcName+" (Parameters does not match)");
        }
        temp->isFuncDefined=true;
        int sz=syminf.paramTypeList.size();
        for(int i=0;!err && i<sz;i++)
            if(temp->paramTypeList[i]!=syminf.paramTypeList[i])
                err=1;
        if(err){
            err_cnt++;
        }
    }
    else{
        if(!err_def_func){
        st.insert(syminf);
        
        }
    }
    st.enterScope();
    if(params.size()==1 && params[0].getType()=="VOID"){
        /* only parameter is void */
    }
    else{
    

            for(int i=0;i<params.size();i++){
                
            if(params[i].getType()=="VOID"){
                err_cnt++;
                errorPrint("Parameter '"+params[i].getName()+"' declared void");
            }
            bool success = st.insert(params[i]);
            if(!success) {
                err_cnt++;
                errorPrint("Redefinition of parameter '"+params[i].getName()+"'");
            }
            
        }
        
    }
    funcType="";
    params.clear();
    
    }
    else {
        st.enterScope();
    }
};
var_declaration: type_specifier declaration_list SEMICOLON{

    $$ = new SymbolInfo( rulePrint("var_declaration","type_specifier declaration_list SEMICOLON"),$1->dataType, $1->startLine, $3->endLine);
    $$->child=$1;
    $1->next=$2;
$2->next= $3;
    if($1->getType()=="VOID")
        {   
            err_cnt++;
            errorPrint("Variable or field '"+vars[0].getName()+"' declared void");
        }   
    else{
        for(int i=0;i<vars.size();i++){
            
            vars[i].setType($1->getType());
        if(st.getCurrentScopeId()==1) vars[i].isGlobal=1;
        bool success = st.insert(vars[i]);
		if(!success){
            err_cnt++;
            errorPrint("Conflicting types for'"+vars[i].getName()+"'");
		}
        }
    }
    err_def_func=0;
}
    | error SEMICOLON   {
        yyclearin;
        yyerrok;
        $$ = new SymbolInfo("", "error", $2->startLine, $2->endLine);
        $$->child=$2;
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';

    }
 ;
type_specifier: INT{
    $$ = new SymbolInfo( rulePrint("type_specifier","INT"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

}
    | FLOAT{
            
        $$ = new SymbolInfo( rulePrint("type_specifier","FLOAT"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;

    }
    | VOID{
        $$ = new SymbolInfo( rulePrint("type_specifier","VOID"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;

    }
 ;

declaration_list: declaration_list COMMA ID{
        
        $$ = new SymbolInfo( rulePrint("declaration_list","declaration_list COMMA ID"),$3->dataType, $1->startLine, $3->endLine);      
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        codeVarDecl($3);
        vars.push_back(*$3);
}
    | declaration_list COMMA ID LSQUARE CONST_INT RSQUARE{
        $3->setArraySize($5->name);
        codeVarDecl($3);
        vars.push_back(*$3);
        $$ = new SymbolInfo( rulePrint("declaration_list","declaration_list COMMA ID LSQUARE CONST_INT RSQUARE"),$1->dataType, $1->startLine, $6->endLine);    
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        $3->next=$4;
        $4->next=$5;
        $5->next=$6;
    }
    | ID{
        vars.clear();
        $$ = new SymbolInfo( rulePrint("declaration_list","ID"),$1->dataType, $1->startLine, $1->endLine);      
        $$->child=$1;
        codeVarDecl($1);
         vars.push_back(*$1);

    }
    | ID LSQUARE CONST_INT RSQUARE{
        vars.clear();
        $1->setArraySize($3->name);

        codeVarDecl($1);
        vars.push_back(*$1);
        $$ = new SymbolInfo( rulePrint("declaration_list","ID LSQUARE CONST_INT RSQUARE"),$1->dataType, $1->startLine, $4->endLine);    
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        $3->next=$4;
    }
    | declaration_list error {
        yyclearin;
        $$ = new SymbolInfo($1->getName(), "error",$1->startLine, $1->endLine);
        $$->child=$1;

        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
        err_def_func=1;
    }
 ;

statements: statement{
    $$ = new SymbolInfo( rulePrint("statements", "statement"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

}
    | statements statement{
        $$ = new SymbolInfo( rulePrint("statements", "statements statement"),$1->dataType, $1->startLine, $2->endLine);
        $$->child=$1;
        $1->next=$2;
    }
 ;
 
statement: var_declaration{
    $$ = new SymbolInfo( rulePrint("statement", "var_declaration"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

}
    | expression_statement{
        $$ = new SymbolInfo( rulePrint("statement", "expression_statement"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;
    	codePrint("\tPOP AX");

    }
    | compound_statement{
        $$ = new SymbolInfo( rulePrint("statement", "compound_statement"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;

    }
    | FOR { 
    
    }  LPAREN  expression_statement{
        //initialization
        labels.push_back(newLabel()); //FOR_COND->-4
		labels.push_back(newLabel()); //FOR_STMT->-3
		labels.push_back(newLabel()); //FOR_UPDATE->-2
		labels.push_back(newLabel()); //END_FOR->-1
		codePrint("\tPOP AX");
		codePrint("\t"+labels[labels.size()-4]+":");
    } expression_statement{
        //cond check
        codePrint("\tPOP AX"); 
		codePrint("\tCMP AX, 0");
		codePrint("\tJE "+labels[labels.size()-1]); 
		codePrint("\tJMP "+labels[labels.size()-3]);
		codePrint("\t"+labels[labels.size()-2]+":"); 
    } exp_void_func expression{
        // update
		codePrint("\tPOP AX");
		codePrint("\tJMP "+labels[labels.size()-4]);
		codePrint("\t"+labels[labels.size()-3]+":");       
    } RPAREN statement{
        //1->3->4->6->9->11->12
        $$ = new SymbolInfo( rulePrint("statement", "FOR LPAREN expression_statement expression_statement expression RPAREN statement"),$1->dataType, $1->startLine, $12->endLine);
        $$->child=$1;
        $1->next=$3;
        $3->next= $4;
        $4->next=$6;
        $6->next=$9;
        $9->next=$11;
        $11->next=$12;
        codePrint("\tJMP "+labels[labels.size()-2]);
		codePrint("\t"+labels[labels.size()-1]+":"); 
		labels.pop_back();
        labels.pop_back();
        labels.pop_back();
        labels.pop_back();
    }
    | if_common_part %prec LOWER_THAN_ELSE{
        $$ = new SymbolInfo( rulePrint("statement", "IF LPAREN expression RPAREN statement"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1->child;
        // print end label
		codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
    }
    | if_common_part ELSE {
		labels.push_back(newLabel());// elseend ->-1, ifend->-2
		codePrint("\tJMP "+labels[labels.size()-1]); 
		codePrint("\t"+labels[labels.size()-2]+":\n");
		
	} statement{
        $$ = new SymbolInfo( rulePrint("statement", "IF LPAREN expression RPAREN statement ELSE statement"),$1->dataType, $1->startLine, $4->endLine);
        $$->child=$1->child;
        $1->next->next=$2;
        $2->next= $4;
        codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
        labels.pop_back();
    }
    | WHILE LPAREN { //1->2->4->6->8
        labels.push_back(newLabel());// wloop->-2
        labels.push_back(newLabel());// wloopend->-1
        codePrint("\t"+labels[labels.size()-2]+":");
    }
        expression exp_void_func RPAREN{
		
		codePrint("\tPOP AX");
		codePrint("\tCMP AX,0");
		codePrint("\tJE "+labels[labels.size()-1]);
	} statement{
        $$ = new SymbolInfo( rulePrint("statement", "WHILE LPAREN expression RPAREN statement"),$1->dataType, $1->startLine, $8->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $4;
        $4->next=$6;
        $6->next=$8;
        codePrint("\tJMP "+labels[labels.size()-2]);
		codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
        labels.pop_back();
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON{
        $$ = new SymbolInfo( rulePrint("statement", "PRINTLN LPAREN ID RPAREN SEMICOLON"),$1->dataType, $1->startLine, $5->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next=$3;
        $3->next=$4;
        $4->next=$5;
        SymbolInfo* temp= st.lookup($3->getName());
        if(temp!=NULL)
        {
            codePrint("\tMOV AX, "+getVar(temp));
			codePrint("\tCALL print_output");
            
        }
    }
    | RETURN expression exp_void_func SEMICOLON{
        $$ = new SymbolInfo( rulePrint("statement", "RETURN expression SEMICOLON"),$1->dataType, $1->startLine, $4->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $4;
               
    }
    ;
if_common_part: IF LPAREN expression exp_void_func RPAREN {// creating end label and jeq 0 end
	
    labels.push_back(newLabel());// ifend
	codePrint("\tPOP AX");
	codePrint("\tCMP AX, 0");
	codePrint("\tJE "+labels[labels.size()-1]);
} statement{
        $$->startLine=$1->startLine;
        $$->endLine= $7->endLine;
        $$->dataType= $1->dataType;
        $$->child=$1;
        $$->next=$7;
        $1->next=$2;
        $2->next= $3;
        $3->next=$5;
        $5->next=$7;

} ;

 exp_void_func: {
    stat_func_type=idType;
    if(stat_func_type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
 };
expression_statement: SEMICOLON{
    idType = "INT";
    $$ = new SymbolInfo( rulePrint("expression_statement","SEMICOLON"),"INT", $1->startLine, $1->endLine);
    $$->child=$1;
    codePrint("\tPUSH 1\n");//for infinite loop
}
    |  expression SEMICOLON{
        idType= $1->type;
        $$->isBool=$1->isBool;
        $$ = new SymbolInfo( rulePrint("expression_statement","expression SEMICOLON"),$1->dataType, $1->startLine, $2->endLine);
        $$->child=$1;
        $1->next=$2;
    }
    | expression error  {
        yyclearin;
        $$ = new SymbolInfo("", "error", $1->startLine, $1->endLine);
        $$->child=$1;
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
    
    }
    
 ;

variable: ID{
 
$$ = new SymbolInfo( rulePrint("variable", "ID"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

    SymbolInfo *temp= st.lookup($1->name);
    if(temp==NULL || temp->isFunc){
        err_cnt++;
        errorPrint("Undeclared variable '"+$1->name+"'");
     
    }
    else{
         $1=new SymbolInfo(temp);
        // // $$->valPointer= $1;
        $1->next=$1->child=NULL;
         $$->child=$1;
        if(temp->type == "VOID") {
         
           err_cnt++;
           errorPrint("variable "+$1->name+" of type void");
        } else {
            $$->setType(temp->dataType); 
        }
    }

}
    | ID LSQUARE expression RSQUARE{

        $$ = new SymbolInfo( rulePrint("variable", "ID LSQUARE expression RSQUARE"),$1->dataType, $1->startLine, $4->endLine);
    
    
    $2->next= $3;
    $3->next=$4;
    SymbolInfo *temp= st.lookup($1->name);

    $$->child=$1;
    
    if(temp==NULL || temp->isFunc){
        err_cnt++;
        errorPrint("Undeclared variable '"+$1->name+"'");
     
    }
            
    else{
        $1= new SymbolInfo(temp);
         $$->child=$1;
         $1->next=$2;
         $1->child=NULL;
        if(temp->arraySize==-1){
            err_cnt++;
            errorPrint("'"+$1->name+"' is not an array");
         
        }
        else{
            if(temp->type == "VOID") {
         
            err_cnt++;
            errorPrint("variable "+$1->name+" of type void");
        } else {
            $$->setType(temp->dataType); 
        }

        }
    }
    if($3->dataType!="INT"){
            err_cnt++;
            errorPrint("Array subscript is not an integer");
        }
    codePrint("\tPOP AX");
    codePrint("\tSHL AX, 1");
    codePrint("\tLEA SI, "+getVar(temp));
    codePrint("\tSUB SI, AX");
    codePrint("\tPUSH SI\n");
        
}
 ;

expression: logic_expression{
    $$ = new SymbolInfo( rulePrint("expression", "logic_expression"),$1->dataType, $1->startLine, $1->endLine);
    $$->isBool=$1->isBool;
    $$->child=$1;

    idType=$1->dataType;
    mulop_flag="";
    current_val=1;
}

    | variable ASSIGNOP logic_expression{
        $$ = new SymbolInfo( rulePrint("expression", "variable ASSIGNOP logic_expression"),$1->dataType, $1->startLine, $3->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        if($$->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if($3->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
        else if($3->dataType=="FLOAT" && $1->dataType=="INT" ){
            err_cnt++;
            errorPrint("Warning: possible loss of data in assignment of FLOAT to INT");
        }
        idType=$1->dataType;
        mulop_flag="";
    current_val=1;
    	codePrint("\tPOP AX");
        //if($1->child->next==NULL)
		    codePrint("\tMOV "+getVar($1->child,$1->child->next!=NULL)+", AX");
        //else codePrint("\tMOV "+getVar($1->child,$1->child->next->next->value)+", AX");
		codePrint("\tPUSH AX");
    }


    
 ;

logic_expression: rel_expression{
    $$ = new SymbolInfo( rulePrint("logic_expression", "rel_expression"),$1->dataType, $1->startLine, $1->endLine);
    $$->isBool=$1->isBool;
    $$->child=$1;

}
    | rel_expression LOGICOP {
        {
		codePrint("\tPOP AX");
		string pushBool = $2->getName() == "&&" ? "1" : "0";
		codePrint("\tCMP AX, "+pushBool);
		string jmpL = newLabel();
		codePrint("\tJNE "+jmpL);
		$1->label=jmpL;

	}
    } rel_expression{

       $$ = new SymbolInfo( rulePrint("logic_expression", "rel_expression LOGICOP rel_expression"),"INT", $1->startLine, $4->endLine);
        $$->isBool=true;
        $$->child=$1;
        $1->next=$2;
        $2->next= $4;
        if($$->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
    else if($4->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
    codePrint("\tPOP AX");
    string pushBool = $2->getName() == "&&" ? "1" : "0";
    codePrint("\tCMP AX, "+pushBool);
    codePrint("\tJNE "+$1->label);
    codePrint("\tPUSH "+pushBool);
    string endLabel = newLabel();
    codePrint("\tJMP "+endLabel);
    codePrint("\t"+$1->label+":");
    pushBool[0]=('1'-pushBool[0])+'0';
    codePrint("\tPUSH " +pushBool);
    codePrint("\t"+endLabel+":\n");
    }
 ;

rel_expression: simple_expression{
    $$ = new SymbolInfo( rulePrint("rel_expression", "simple_expression"),$1->dataType, $1->startLine, $1->endLine);
    $$->isBool=$1->isBool;
    $$->child=$1;

}
    | simple_expression RELOP simple_expression{

       $$ = new SymbolInfo( rulePrint("rel_expression", "simple_expression RELOP simple_expression"),"INT", $1->startLine, $3->endLine); 
       $$->isBool=true;
       $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        if($$->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if($3->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     
    }
    	string L1 = newLabel(),L2 = newLabel();
		string relJump="";
        if($2->getName() == "<") relJump= "JL";
        else if($2->getName() == "!=") relJump= "JNE";
        else if($2->getName() == "<=") relJump= "JLE";
        else if($2->getName() == ">") relJump= "JG";
        else if($2->getName() == ">=") relJump= "JGE";
        else if($2->getName() == "==") relJump= "JE";
		codePrint("\tPOP BX");
		codePrint("\tPOP AX");
		codePrint("\tCMP AX, BX");
		codePrint("\t"+relJump+" "+L1);
		codePrint("\tPUSH 0\n\tJMP "+L2);
		codePrint("\t"+L1+":\n\tPUSH 1");
		codePrint("\t"+L2+":\n");
        
    }

 ;

simple_expression: term{
    $$ = new SymbolInfo( rulePrint("simple_expression", "term"),$1->dataType, $1->startLine, $1->endLine);
    $$->isBool=$1->isBool;
    $$->child=$1;

}
    | simple_expression ADDOP term{

        $$ = new SymbolInfo( rulePrint("simple_expression", "simple_expression ADDOP term"),$1->dataType, $1->startLine, $3->endLine);
        $$->child=$1;
        $1->next=$2;
        $2->next= $3;
        if($$->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if($3->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
        if($3->dataType=="FLOAT"){
         
        }
        string addop = $2->getName() == "+" ? "ADD" : "SUB";
    	codePrint("\tPOP BX");
		codePrint("\tPOP AX");
		codePrint("\t"+addop+" AX, BX");
		codePrint("\tPUSH AX");

       
    }
    | error_rr CONST_INT{

    }
       
    
 ;
 error_rr: error{
     yyclearin;
           
   logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';

 }
 mulop: MULOP{
    $$ = new SymbolInfo( $1->name,$1->dataType, $1->startLine, $1->endLine,1);
    mulop_flag=$1->name;

 }
term: unary_expression{
    $$ = new SymbolInfo( rulePrint("term", "unary_expression"),$1->dataType, $1->startLine, $1->endLine);
    $$->isBool=$1->isBool;
    $$->child=$1;

}
    | term  mulop unary_expression{
    $$ = new SymbolInfo( rulePrint("term", "term MULOP unary_expression"),$1->dataType, $1->startLine, $3->endLine);
    $$->child=$1;
    $1->next=$2;
    $2->next= $3;
    if($$->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
         else   if($3->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if($2->name=="%" && ($1->dataType=="FLOAT"|| $3->dataType=="FLOAT")){
        err_cnt++;
        errorPrint("Operands of modulus must be integers");
        $$->setType("INT");
    }
    
    else if($2->name!="%" && ($1->dataType=="FLOAT"|| $3->dataType=="FLOAT")){
        $$->dataType="FLOAT";
    }
    if(($2->name=="%" || ($2->name=="/"))&& mulop_flag!="" &&current_val==0){
        errorPrint("Warning: division by zero i=0f=1Const=0");
        err_cnt++;
    }
    mulop_flag="";
    current_val=1;
    string mulop = $2->getName() == "*" ? "IMUL" : "IDIV" , res = $2->getName() == "%" ? "DX" : "AX";
    codePrint("\tPOP BX");
    codePrint("\tPOP AX");
    codePrint("\tXOR DX, DX");
    codePrint("\t"+mulop+" BX");
    codePrint("\tPUSH "+res);

    }
 ;

unary_expression: ADDOP unary_expression{
    $$ = new SymbolInfo( rulePrint("unary_expression", "ADDOP unary_expression"),$2->dataType, $1->startLine, $2->endLine);
    $$->child=$1;
    $1->next=$2;
    if($$->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
    codePrint("\tPOP AX");
    codePrint("\tNEG AX");
    codePrint("\tPUSH AX\n");
}
    | NOT unary_expression{
    $$ = new SymbolInfo( rulePrint("unary_expression", "NOT unary_expression"),$2->dataType, $1->startLine, $2->endLine);
    $$->isBool=true;
    $$->child=$1;
    $1->next=$2;
    if($$->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
    	string je = newLabel(), jne = newLabel(); 
    	codePrint("\tPOP AX\t;load "+$2->getName());
		codePrint("\tCMP AX, 0");
		codePrint("\tJE "+je);
		codePrint("\tPUSH 0");
		codePrint("\tJMP "+jne);
		codePrint("\t"+je+":\n\tPUSH 1\n");
		codePrint("\t"+jne+":");
    }
    | factor{
    $$ = new SymbolInfo( rulePrint("unary_expression", "factor"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;
    }
 ;
 
factor: variable{
    $$ = new SymbolInfo( rulePrint("factor", "variable"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;

    mulop_flag="";
    current_val=1;
    codePrint("\tPUSH "+getVar($1->child, $1->child->next!=NULL));

}
   | ID LPAREN argument_list RPAREN{
    
    $$ = new SymbolInfo( rulePrint("factor","ID LPAREN argument_list RPAREN"),$1->dataType, $4->startLine, $1->endLine);
    $$->child=$1;
    $1->next=$2;
    $2->next= $3;
    $3->next=$4;
        SymbolInfo *temp= st.lookup($1->name);
    if(temp==NULL){
        err_cnt++;
        errorPrint("Undeclared function '"+$1->name+"'");
     
    }
    else{
        $$->setType(temp->dataType);
        if(!temp->isFuncDefined){
            err_cnt++;
            errorPrint("no such function definition found");
           
        }
        else{
            if(temp->paramTypeList.size()>args.size()) 
            {
                err_cnt++;
                errorPrint("Too few arguments to function '"+$1->name+"'");
             
        }else if(temp->paramTypeList.size()<args.size()) 
            {
                err_cnt++;
                errorPrint("Too many arguments to function '"+$1->name+"'");
             
        }
         else {
            bool okay=1;
            for(int i=0; i<args.size();i++){
                if(temp->paramTypeList[i]!=args[i].dataType || args[i].arraySize!=-1)
                    {
                        err_cnt++;
                        errorPrint("Type mismatch for argument "+to_string(i+1)+" of '"+$1->name+"'");
                        okay=0;
                    }
            }
            if(okay){
                 $$->setType(temp->dataType);
            } 

        }

        }
    }
    args.clear();
    mulop_flag="";
    current_val=1;
   }
   | LPAREN expression RPAREN{
    $$ = new SymbolInfo( rulePrint("factor","LPAREN expression RPAREN"),$2->dataType, $1->startLine, $3->endLine);
    $$->child=$1;
    $1->next=$2;
    $2->next= $3;
    if($$->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
   }
    | CONST_INT{
    $$ = new SymbolInfo( rulePrint("factor","CONST_INT"),$1->dataType, $1->startLine, $1->endLine);
    $$->child=$1;
 
    if(mulop_flag=="/" || mulop_flag=="%"){
            current_val=stoi($1->name);
        }
    codePrint("\tPUSH " + $1->getName());
    }
    | CONST_FLOAT{
        $$ = new SymbolInfo( rulePrint("factor","CONST_FLOAT"),$1->dataType, $1->startLine, $1->endLine);
        $$->child=$1;

        if(mulop_flag=="/" || mulop_flag=="%"){
            current_val=stoi($1->name);
        }
        codePrint("\tPUSH " + $1->getName());
    }
    | variable INCOP{
    $$ = new SymbolInfo( rulePrint("factor","variable INCOP"),$1->dataType, $1->startLine, $2->endLine);
    $$->child=$1;
    $1->next=$2;
    mulop_flag="";
    current_val=1;

    string var = getVar($1->child,$1->child->next!=NULL );
    codePrint("\tPUSH " + var);
    codePrint("\tINC " + var);
    }
    | variable DECOP{
         $$ = new SymbolInfo( rulePrint("factor","variable DECOP"),$1->dataType, $1->startLine, $2->endLine);
         $$->child=$1;
        $1->next=$2;
            mulop_flag="";
         current_val=1;
    string var = getVar($1->child,$1->child->next!=NULL );
    codePrint("\tPUSH " + var);
    codePrint("\tDEC " + var);
    }
 ;

argument_list: arguments{
    $$ = new SymbolInfo( rulePrint("argument_list","arguments"),$1->dataType, $1->startLine, $1->endLine);       
    $$->child=$1;

        mulop_flag="";
    current_val=1;
}
    |{
    $$ = new SymbolInfo( rulePrint("argument_list","<epsilon-production>"),"INT", line_cnt-multi_line, line_cnt-multi_line);              
    

    mulop_flag="";
    current_val=1;
    }
 ;
arguments: arguments COMMA logic_expression{
    $$ = new SymbolInfo( rulePrint("arguments","arguments COMMA logic_expression"),$1->dataType, $1->startLine, $3->endLine);       
    $$->child=$1;
    $1->next=$2;
    $2->next= $3;
    args.push_back(*$3);
}
    | logic_expression{
    $$ = new SymbolInfo( rulePrint("arguments","logic_expression"),$1->dataType, $1->startLine, $1->endLine);       
    $$->child=$1;
 
        args.clear();
        args.push_back(*$1);
    }
 ;

%%

main(int argc, char* argv[], char* endp[])
{
    if(argc != 2){
        cout<<"provide file name\n"  ;
        exit(1)  ;
    }

    FILE* filein = fopen(argv[1], "r")  ;
    if(filein == NULL){
        cout<<"Cannot open file\n"   ;
        exit(1)  ;
    }
    parseout.open("1905065_parsetree.txt", ios::out);
    logout.open("1905065_log.txt", ios::out);
    errorout.open("1905065_error.txt", ios::out);
    asmout.open("1905065_code.asm", ios::out);
    codeout.open("1905065_temp.asm", ios::out);
   yyin = filein   ;
    yyparse();
    logout << "Total Lines: " << line_cnt << '\n' ;
    logout << "Total Errors: " << err_cnt << '\n'   ;
    printParseTree();
    logout.close()  ;
    fclose(yyin) ;
    parseout.close();
    errorout.close();
    asmout.close();
    codeout.close();
    exit(0)  ;
}