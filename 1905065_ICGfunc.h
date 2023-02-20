#pragma once
 #include <bits/stdc++.h>
 #include "1905065_SymbolTable.h"

int line_cnt=1, err_cnt=0 , multi_line=0; 
ofstream logout, errorout, parseout;
ofstream asmout, codeout;
vector<SymbolInfo> vars, params, args;
vector<string> labels;
string idName,idType, funcName,funcType="",stat_func_type,mulop_flag="";
double current_val=1;
bool err_def_func=0;
bool globalSc=true;
int offset=0;
extern FILE *yyin;
SymbolInfo* startSi;
SymbolTable st(11);


int labelCount=0;
int tempCount=0;


string newLabel()
{
	string lb="L";
    lb+=to_string(labelCount);
	labelCount++;
	return lb;
}

// prev
 void yyerror(char *s){
    err_cnt++;
    errorout << "Line " << line_cnt << ": "<< s << '\n' ;

 }

 int yylex(void) ;

 
string rulePrint(string ls,string rs){
    if(err_def_func && (ls=="func_definition"|| ls=="func_declaration"||ls=="declaration_list"||ls=="var_declaration"));
    else 
    logout<<ls<<" : "<<rs<<'\n';
    return ls+" : "+rs;
 }

void errorPrint(string cstr, string strASCI=""){
	errorout << "Line# " << line_cnt-multi_line << ": "<< cstr+strASCI <<'\n';

}
void codePrint(string s){
    codeout<<s<<endl;
}
vector<string> getStrfromSi(vector<SymbolInfo>& vec){
    vector<string> names(vec.size());
    for(int i=0;i<vec.size();i++)
        names[i]=vec[i].getType();
    return names;
}

// prev finished

void header(){
    string header= 
    ".MODEL SMALL\r\n"
     ""
".STACK 1000H\r\n"
".DATA\r\n\t"
	"CR EQU 0DH\r\n\t"
	"LF EQU 0AH\r\n\t"
	"number DB \"00000$\"\r\n";
    asmout<<header;
}
void finishing(){
    asmout<<".CODE\r\n";
    string mainn=
    "main PROC\r\n"
	"\tMOV AX, @DATA\r\n"
	"\tMOV DS, AX\r\n"
	"\tPUSH BP\r\n"
	"\tMOV BP, SP\r\n";
    asmout<<mainn;
     string hard=
    "MOV AX, 0\r\n"
	"JMP L36\r\n"
"L36:\r\n"
	"ADD SP,"+to_string(offset)+"\r\n"
	"POP BP\r\n"
	"MOV AX,4CH\r\n"
	"INT 21H\r\n"
"main ENDP\r\n";
        string newLine = "new_line proc \r\n\t"
                            "push ax\r\n\t"
                            "push dx\r\n\t"
                            "mov ah,2\r\n\t"
                            "mov dl,cr\r\n\t"
                            "int 21h\r\n\t"
                            "mov ah,2\r\n\t"
                            "mov dl,lf\r\n\t"
                            "int 21h\r\n\t"
                            "pop dx\r\n\t"
                            "pop ax\r\n\t"
                            "ret\r\n\t"
                        "new_line endp\r\n";
        string printAX = 
        "print_output proc  ;print what is in ax\r\n\t"
            "push ax\r\n\t"
            "push bx\r\n\t"
            "push cx\r\n\t"
            "push dx\r\n\t"
            "push si\r\n\t"
            "lea si,number\r\n\t"
            "mov bx,10\r\n\t"
            "add si,4\r\n\t"
            "cmp ax,0\r\n\t"
            "jnge negate\r\n\t"
            "print:\r\n\t"
            "xor dx,dx\r\n\t"
            "div bx\r\n\t"
            "mov [si],dl\r\n\t"
            "add [si],'0'\r\n\t"
            "dec si\r\n\t"
            "cmp ax,0\r\n\t"
            "jne print\r\n\t"
            "inc si\r\n\t"
            "lea dx,si\r\n\t"
            "mov ah,9\r\n\t"
            "int 21h\r\n\t"
            "call new_line\r\n\t"
            "pop si\r\n\t"
            "pop dx\r\n\t"
            "pop cx\r\n\t"
            "pop bx\r\n\t"
            "pop ax\r\n\t"
            "ret\r\n\t"
            "negate:\r\n\t"
            "push ax\r\n\t"
            "mov ah,2\r\n\t"
            "mov dl,'-'\r\n\t"
            "int 21h\r\n\t"
            "pop ax\r\n\t"
            "neg ax\r\n\t"
            "jmp print\r\n\t"
        "print_output endp\r\n"
    "END main";
            codeout<<hard<<newLine<<printAX;
        
    if (codeout.is_open())
    {
        codeout.close();
    }
    ifstream codesegmentin("1905065_temp.asm");
    string codeLine;
     while (getline(codesegmentin, codeLine))
    {
        asmout << codeLine << endl;
    }
   
}

void codeVarDecl(SymbolInfo* variable)
{
    if (!globalSc)
    {
        if (variable->arraySize!=-1)
        {
            variable->offset=offset+2;
            offset+=2*(variable->arraySize);
            codeout << "\tSUB SP, " << (variable->arraySize * 2) << endl;
        }
        else
        {
            offset+=2;
            variable->offset=offset;
            codeout << "\tSUB SP, 2"<<endl;

        }    
    }
    else
    {
        
        asmout << "\t" << variable->getName()<< " DW " << (variable->arraySize==-1?1:variable->arraySize)<< " DUP (0000H)\r\n";
        //variable->isGlobal=true;
    }
}

string getVar(SymbolInfo *var, bool pop=false)
{
    if (pop)
    {
        codePrint("\tPOP SI");
        return "[SI]";
    }
    if(var->isGlobal){
        return var->getName();
    }

   return "W. [BP-"+to_string(var->offset)+"]";

}

























/*
#pragma once
#include <bits/stdc++.h>
#include "symboltable/symbolinfo.h"
#include "symboltable/symboltable.h"
using namespace std;

// external function and variable declarations
int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int yylineno;

SymbolTable table = SymbolTable(31);
int errorCnt = 0;
ofstream errorOut, dataSegOut, codeout, asmCodeOut; // output files
const string dataSegmentFile = "dataSegment.txt";      // temporary file for data segment
const string codeSegmentFile = "codeSegment.txt";      // temporary file for code segment
vector<SymbolInfo *> *funcParamList = nullptr;
int paramDeclineNo;

void genPrintNewLine()
{
    string str = "\n\tPRINT_NEWLINE PROC\r"
                 "\n"
                 "        ; PRINTS A N"
                 "EW LINE WITH CARRIAG"
                 "E RETURN\r\n"
                 "        PUSH AX\r\n"
                 "        PUSH DX\r\n"
                 "        MOV AH, 2\r"
                 "\n"
                 "        MOV DL, 0Dh"
                 "\r\n"
                 "        INT 21h\r\n"
                 "        MOV DL, 0Ah"
                 "\r\n"
                 "        INT 21h\r\n"
                 "        POP DX\r\n"
                 "        POP AX\r\n"
                 "        RET\r\n"
                 "    PRINT_NEWLINE EN"
                 "DP";
    codeout << str << endl;
}

void genMyFunctionForPrintln()
{
    char *str = "PRINT_NUM_FROM_BX PR"
                "OC\r\n"
                "    PUSH CX  \r\n"
                "    ; push to stack "
                "to \r\n"
                "    ; check the end "
                "of the number  \r\n"
                "    MOV AX, \'X\'\r"
                "\n"
                "    PUSH AX\r\n"
                "    \r\n"
                "    CMP BX, 0  \r\n"
                "    JE ZERO_NUM\r\n"
                "    JNL NON_NEGATIVE"
                " \r\n"
                "    \r\n"
                "    NEG BX\r\n"
                "    ; print - for ne"
                "gative number\r\n"
                "    MOV DL, \'-\'\r"
                "\n"
                "    MOV AH, 2\r\n"
                "    INT 21H\r\n"
                "    JMP NON_NEGATIVE"
                "  \r\n"
                "    \r\n"
                "    ZERO_NUM:\r\n"
                "        MOV DX, 0\r"
                "\n"
                "        PUSH DX\r\n"
                "        JMP POP_PRIN"
                "T_LOOP\r\n"
                "    \r\n"
                "    NON_NEGATIVE:\r"
                "\n"
                "    \r\n"
                "    MOV CX, 10 \r\n"
                "    \r\n"
                "    MOV AX, BX\r\n"
                "    PRINT_LOOP:\r\n"
                "        ; if AX == 0"
                "\r\n"
                "        CMP AX, 0\r"
                "\n"
                "        JE END_PRINT"
                "_LOOP\r\n"
                "        ; else\r\n"
                "        MOV DX, 0 ; "
                "DX:AX = 0000:AX\r\n"
                "        \r\n"
                "        ; AX = AX / "
                "10 ; store reminder "
                "in DX \r\n"
                "        DIV CX\r\n"
                "    \r\n"
                "        PUSH DX\r\n"
                "        \r\n"
                "        JMP PRINT_LO"
                "OP\r\n\r\n"
                "    END_PRINT_LOOP:"
                "\r\n"
                "    \r\n"
                "    \r\n"
                "    \r\n"
                "    POP_PRINT_LOOP:"
                "\r\n"
                "        POP DX\r\n"
                "        ; loop endin"
                "g condition\r\n"
                "        ; if DX == "
                "\'X\'\r\n"
                "        CMP DX, \'X"
                "\'\r\n"
                "        JE END_POP_P"
                "RINT_LOOP\r\n"
                "        \r\n"
                "        ; if DX == "
                "\'-\'\r\n"
                "        CMP DX, \'-"
                "\'\r\n"
                "        JE PRINT_TO_"
                "CONSOLE\r\n"
                "        \r\n"
                "        ; convert to"
                " ascii\r\n"
                "        ADD DX, 30H "
                "      \r\n"
                "        ; print the "
                "digit\r\n"
                "        PRINT_TO_CON"
                "SOLE:\r\n"
                "        MOV AH, 2\r"
                "\n"
                "        INT 21H\r\n"
                "        \r\n"
                "        JMP POP_PRIN"
                "T_LOOP\r\n"
                "    \r\n"
                "    END_POP_PRINT_LO"
                "OP: \r\n"
                "CALL PRINT_NEWLINE\r\n"
                "    POP CX\r\n"
                "    RET\r\n"
                "PRINT_NUM_FROM_BX EN"
                "DP";
    codeout << str << endl;
}

void genFunctionForPrintln()
{
    genPrintNewLine();
    codeout << endl;
    genMyFunctionForPrintln();
}


void openFiles()
{
    errorOut.open("error.txt", ios::out);
    freopen("log.txt", "w", stdout);
    dataSegOut.open(dataSegmentFile, ios::out);
    codeout.open(codeSegmentFile, ios::out);
}

void optimizeCode()
{
    ifstream codeSegmentIn("code.asm");

    // optimize the code
    ofstream optimizeOut("optimized_code.asm", ios::out);
    vector<string> lines;
    string line;
    while (getline(codeSegmentIn, line))
    {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        if (i + 1 >= lines.size() || lines[i].size() < 4 || lines[i + 1].size() < 4)
        {
        }
        else if (lines[i].substr(1, 3) == "MOV" && lines[i + 1].substr(1, 3) == "MOV")
        {
            string line1 = lines[i].substr(4);
            string line2 = lines[i + 1].substr(4);

            int delIndex1 = line1.find(",");
            int delIndex2 = line2.find(",");

            if (line1.substr(1, delIndex1 - 1) == line2.substr(delIndex2 + 2))
                if (line1.substr(delIndex1 + 2) == line2.substr(1, delIndex2 - 1))
                {
                    optimizeOut << "\t; Redundant MOV optimized" << endl;
                    i++;
                    continue;
                }
        }

        optimizeOut << lines[i] << endl;
    }

    optimizeOut.close();
    codeSegmentIn.close();
}


void generateCodeDotAsmFile()
{
    // close the files first
    if (dataSegOut.is_open())
    {
        dataSegOut.close();
    }
    if (codeout.is_open())
    {
        codeout.close();
    }
    ifstream dataSegmentIn(dataSegmentFile);
    ifstream codeSegmentIn(codeSegmentFile);
    ofstream codeDotAsmOut("code.asm", ios::out);
    string line;
    while (getline(dataSegmentIn, line))
    {
        codeDotAsmOut << line << endl;
    }
    codeDotAsmOut << endl;
    while (getline(codeSegmentIn, line))
    {
        codeDotAsmOut << line << endl;
    }

    codeDotAsmOut << endl
                  << "END MAIN" << endl;

    dataSegmentIn.close();
    codeSegmentIn.close();
    codeDotAsmOut.close();
    remove(dataSegmentFile.c_str());
    remove(codeSegmentFile.c_str());

    optimizeCode();
}

void yyerror(const char *s)
{
    cout << "Error at line " << yylineno << ": " << s << "\n"
         << endl;
    // errout<<"Error at line "<<line_count<<": "<<s<<"\n"<<endl;
    errorCnt++;
}

void debug(string s)
{
    cout << "debug: Line " << yylineno << ": " << s << endl
         << endl;
}

void logError(string s, int lineNo = -1)
{
    errorOut << "Error at line " << (lineNo == -1 ? yylineno : lineNo) << ": " << s << "\n"
             << endl;
    cout << "Error at line " << (lineNo == -1 ? yylineno : lineNo) << ": " << s << "\n"
         << endl;
    errorCnt++;
}

void logRule(string rule, string code)
{
    cout << "Line " << yylineno << ": " << rule << endl
         << endl
         << code << endl
         << endl;
}

/**
 * @brief make comma separated variable declaration code
 * @return the code as string

string toVarDeclarationListStr(vector<SymbolInfo *> *list)
{
    string code = "";
    for (SymbolInfo *info : *list)
    {
        if (info->getArraySize() == "")
        {
            code += info->getName() + ",";
        }
        else
        {
            code += info->getName() + "[" + info->getArraySize() + "],";
        }
    }
    int len = code.length();
    if (len > 0)
    {
        code = code.substr(0, len - 1);
    }
    return code;
}

void freeSymbolInfoVector(vector<SymbolInfo *> *list)
{
    for (SymbolInfo *info : *list)
    {
        delete info;
    }
    delete list;
}

string toFuncParamListStr(vector<SymbolInfo *> *list)
{
    string code = "";
    for (SymbolInfo *info : *list)
    {
        code += info->getDataType() + " " + info->getName() + ",";
    }
    int len = code.length();
    if (len > 0)
    {
        code = code.substr(0, len - 1);
    }
    return code;
}

string toSymbolNameListStr(vector<SymbolInfo *> *list)
{
    string code = "";
    for (SymbolInfo *info : *list)
    {
        code += info->getName() + ",";
    }
    int len = code.length();
    if (len > 0)
    {
        code = code.substr(0, len - 1);
    }
    return code;
}

void declareFuncParam(string dataType, string name, int offset, int lineNo = yylineno)
{
    if (dataType == "void")
    {
        logError("Function parameter cannot be void");
        return;
    }
    if (table.insert(name, "ID"))
    {
        SymbolInfo *info = table.lookup(name);
        info->setDataType(dataType);
        info->setAsmName("W. [BP + " + to_string(offset) + "]");
        return;
    }
    logError("Multiple declaration of " + name + " in parameter", lineNo);
}

void declareFuncParamList(vector<SymbolInfo *> *&list, int lineNo = yylineno)
{
    if (list == nullptr)
    {
        // cout<< "Line "<<yylineno<<": "<<"declareFuncParamList: no params"<<endl;
        return;
    }
    // cout<<"Line "<<yylineno<<": "<<"declaring function parameter list"<<endl;
    int cnt = 0;
    int n = list->size();
    for (SymbolInfo *info : *list)
    {
        int offset = 4 + (n - cnt) * 2;
        declareFuncParam(info->getDataType(), info->getName(), offset, lineNo);
        cnt++;
    }
    list = nullptr;
}

void declareFunction(string functionName, string returnType, vector<SymbolInfo *> *parameterList = nullptr, int lineNo = yylineno)
{
    cout << "define function " << functionName << endl;
    // insert a new ID in the symbol table
    bool success = table.insert(functionName, "ID");
    // get the symbol info to add return type and params
    SymbolInfo *info = table.lookup(functionName);

    if (success)
    {
        info->setInfoType(SymbolInfo::FUNCTION_DECLARATION);
        info->setReturnType(returnType);
        // add functions params to the symbol info
        if (parameterList != nullptr)
            for (SymbolInfo *param : *parameterList)
            {
                info->addParameter(param->getDataType(), param->getName());
            }

        // debug("Function \""+functionName+"\" declared");
        // debug("Total params: "+to_string(info->getParameters().size()));
    }
    else
    {
        if (info->getInfoType() == SymbolInfo::FUNCTION_DECLARATION)
        {
            logError("redeclaration of " + functionName, lineNo);
            return;
        }
    }
}

void defineFunction(string functionName, string returnType, int lineNo = yylineno, vector<SymbolInfo *> *parameterList = nullptr)
{
    // get the symbol info to add return type and params
    SymbolInfo *info = table.lookup(functionName);

    // if the function is not declared
    // then insert it in the symbol table as ID
    if (info == nullptr)
    { // function name not found in the symbol table
        table.insert(functionName, "ID");
        info = table.lookup(functionName);
    }
    else
    {
        // function already declared previously
        if (info->getInfoType() == SymbolInfo::FUNCTION_DECLARATION)
        {
            if (info->getReturnType() != returnType)
            {
                logError("Return type mismatch with function declaration in function " + functionName, lineNo);
                return;
            }
            vector<pair<string, string>> params = info->getParameters();
            int paramCnt = parameterList == nullptr ? 0 : parameterList->size();
            if (params.size() != paramCnt)
            {
                logError("Number of arguments doesn't match prototype of the function " + functionName, lineNo);
                return;
            }
            if (parameterList != nullptr)
            { // for non-void functions
                vector<SymbolInfo *> paramList = *parameterList;
                for (int i = 0; i < params.size(); i++)
                {
                    if (params[i].first != paramList[i]->getDataType())
                    {
                        logError("conflicting argument types for " + functionName, lineNo);
                        return;
                    }
                }
            }
        }
        else
        { // non-function type declared with same name
            logError(" Multiple declaration of " + functionName);
            return;
        }
    }
    if (info->getInfoType() == SymbolInfo::FUNCTION_DEFINITION)
    {
        logError("redefinition of " + functionName, lineNo);
        return;
    }
    info->setInfoType(SymbolInfo::FUNCTION_DEFINITION);
    info->setReturnType(returnType);
    info->setParameters(vector<pair<string, string>>());
    // add functions params to the symbol info
    if (parameterList != nullptr) // for non void functions
        for (SymbolInfo *param : *parameterList)
        {
            info->addParameter(param->getDataType(), param->getName());
        }
}

void callFunction(SymbolInfo *&funcSym, vector<SymbolInfo *> *args = nullptr)
{
    string functionName = funcSym->getName();
    SymbolInfo *info = table.lookup(functionName);
    if (info == nullptr)
    {
        logError("Undeclared Function " + functionName);
        return;
    }
    if (!info->isFunction())
    { // a function call cannot be made with non-function type identifier.
        logError(functionName + " is not a function");
        return;
    }
    funcSym->setReturnType(info->getReturnType());
    if (info->getInfoType() != SymbolInfo::FUNCTION_DEFINITION)
    {
        logError("Function " + functionName + " not defined");
        return;
    }
    vector<pair<string, string>> params = info->getParameters();
    int paramCnt = args == nullptr ? 0 : args->size();
    // Check whether a function is called with appropriate number of parameters
    if (params.size() != paramCnt)
    {
        logError("Total number of arguments mismatch in function " + functionName);
        return;
    }
    if (args != nullptr)
    { // for non-void functions
        vector<SymbolInfo *> argList = *args;
        // Type Checking: During a function call all the arguments should be consistent with the function definition.
        for (int i = 0; i < params.size(); i++)
        {
            // Check whether a function is called with appropriate types.
            if (params[i].first != argList[i]->getDataType())
            {
                logError(to_string(i + 1) + "th argument mismatch in function " + functionName);
                return;
            }
        }
    }
}

string autoTypeCasting(SymbolInfo *x, SymbolInfo *y)
{
    if (x->getDataType() == y->getDataType())
        return x->getDataType();
    if (x->getDataType() == "int" && y->getDataType() == "float")
    {
        x->setDataType("float");
        return "float";
    }
    else if (x->getDataType() == "float" && y->getDataType() == "int")
    {
        y->setDataType("float");
        return "float";
    }
    if (x->getDataType() != "void")
    {
        return x->getDataType();
    }
    return y->getDataType();
}

void checkVoidFunction(SymbolInfo *a, SymbolInfo *b)
{
    // Type Checking: A void function cannot be called as a part of an expression.
    if (a->getDataType() == "void" || b->getDataType() == "void")
    {
        logError("Void function used in expression");
    }
}

*/