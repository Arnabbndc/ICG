%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTILINE_COMMENT
%x SINGLE_QUOT_STARTS
%x SPECIAL_CHAR
%x NORMAL_CHAR
%x MULTI_CHAR_ERROR
%x STRING_STATE
%{
#include<bits/stdc++.h>
#include "1905065_SymbolInfo.h"
#include "y.tab.h"

using namespace std;

extern int line_cnt, err_cnt, multi_line;
string cmnt, cstr, strASCI;
bool multi_string;
extern ofstream logout, errorout;
extern string idName,idType;

// void yylval.si = new SymbolInfo( yytext,string cstr, string strASCI=""){
// 	tokenout<<'<'<<cstr;
// 	if(strASCI!=""){
// 		tokenout<<", "<<strASCI;
// 	}
// 	tokenout<<">\n";

// }
void logPrint( string cstr, string strASCI){

	logout << "Line# " << line_cnt-multi_line << ": Token <"<<cstr<<"> Lexeme " << strASCI << " found\n";

}
extern void errorPrint(string cstr, string strASCI="");
string getSpecialChar(string s){
	int l= s.length();
	if(s[1]=='\\'){
    if(s[l-2] == 'n') return "\n";
    else if(s[l-2] == 't') return "\t";
    else if(s[l-2] == 'r') return "\r";
    else if(s[l-2] == 'a') return "\a";
    else if(s[l-2] == 'b') return "\b";
    else if(s[l-2] == 'f') return "\f";
    else if(s[l-2] == 'v') return "\v";
    else if(s[l-2] == '\\') return "\\";
    else if(s[l-2] == '\'') return "\'";
    else if(s[l-2] == '0') return "\0";
}
	string t(s,1,l-2);
    return t;

}
%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE (\r\n|\n)
FLOAT_LITERAL {DIGIT}*"."({DIGIT}+|{DIGIT}+("E"|"e")[-]?{DIGIT}+)|{DIGIT}+("E"|"e")[-]?{DIGIT}+ 
SUFF_PREF_ERR {DIGIT}+[^\]"+""-""/""*""%"".""E""e""("")""{""}""[""=""+=""-=""*=""/=""%=""&&""||"","";"\n\r ]+ 
ILL_FORMED_NUMBER ({DIGIT}+("E"|"e")[-]?{DIGIT}+("."({DIGIT}*|{DIGIT}*("E"|"e")[-]?{DIGIT}+))+)|{DIGIT}+"."
MANY_DECIMAL_POINTS {DIGIT}*"."{DIGIT}+(("E"|"e")[-]?[0-9]+)?("."{DIGIT}*|"."{DIGIT}*("E"|"e")[-]?{DIGIT}+) 
%%

"if"	{
	yylval.si = new SymbolInfo( yytext,"IF", line_cnt-multi_line, line_cnt-multi_line,1);
	logPrint( "IF",yytext);	
	return IF;
}

"else"	{
	yylval.si = new SymbolInfo( yytext,"ELSE", line_cnt-multi_line, line_cnt-multi_line,1);
	logPrint( "ELSE",yytext);	
	return ELSE ;
}
"for"  {	
	logPrint( "FOR",yytext);
	yylval.si = new SymbolInfo( yytext,"FOR", line_cnt-multi_line, line_cnt-multi_line,1);
	return  FOR  ;
}
"while" {
	yylval.si = new SymbolInfo( yytext,"WHILE", line_cnt-multi_line, line_cnt-multi_line,1);
	logPrint( "WHILE",yytext);
	return  WHILE  ;
}
"do" {
	yylval.si = new SymbolInfo( yytext,"DO", line_cnt-multi_line, line_cnt-multi_line,1);
	logPrint( "DO",yytext);
	return  DO  ;
}

"break" {
	yylval.si = new SymbolInfo( yytext,"BREAK", line_cnt-multi_line, line_cnt-multi_line,1);
	logPrint( "BREAK",yytext);
	return  BREAK  ;
}
"int" {
	logPrint( "INT",yytext);
	yylval.si = new SymbolInfo( yytext,"INT", line_cnt-multi_line, line_cnt-multi_line,1);
	idType=yylval.si->type;
	return  INT  ;
}
"char" {
	logPrint( "CHAR",yytext);
	yylval.si = new SymbolInfo( yytext,"CHAR", line_cnt-multi_line, line_cnt-multi_line,1);
	idType=(yylval.si)->type;
	return  CHAR  ;
}
"float" {
	logPrint( "FLOAT",yytext);
	
	yylval.si = new SymbolInfo( yytext,"FLOAT", line_cnt-multi_line, line_cnt-multi_line,1);
	idType=yylval.si->type;
	return  FLOAT  ;
}
"double" {
	logPrint( "DOUBLE",yytext);
	yylval.si = new SymbolInfo( yytext,"DOUBLE", line_cnt-multi_line, line_cnt-multi_line,1);
	idType=yylval.si->type;
	return  DOUBLE  ;
}
"void" {
	logPrint( "VOID",yytext);
	yylval.si = new SymbolInfo( yytext,"VOID", line_cnt-multi_line, line_cnt-multi_line,1);
	idType=yylval.si->type;
	return  VOID  ;
}	
"return"  {
	logPrint( "RETURN",yytext);
	yylval.si = new SymbolInfo( yytext,"RETURN", line_cnt-multi_line, line_cnt-multi_line,1);
	return  RETURN  ;
}	
"switch"  {
	logPrint( "SWITCH",yytext);
	yylval.si = new SymbolInfo( yytext,"SWITCH", line_cnt-multi_line, line_cnt-multi_line,1);
	return  SWITCH  ;
}
"case" {
	logPrint( "CASE",yytext);
	yylval.si = new SymbolInfo( yytext,"CASE", line_cnt-multi_line, line_cnt-multi_line,1);
	return  CASE  ;
}		
"default" {
	logPrint( "DEFAULT",yytext);
	yylval.si = new SymbolInfo( yytext,"DEFAULT", line_cnt-multi_line, line_cnt-multi_line,1);
	return  DEFAULT  ;
}		
"continue" {
	logPrint( "CONTINUE",yytext);
	yylval.si = new SymbolInfo( yytext,"CONTINUE", line_cnt-multi_line, line_cnt-multi_line,1);
	return  CONTINUE  ;
}	


		
{DIGIT}+ 	{
	yylval.si = new SymbolInfo( yytext,"CONST_INT", line_cnt-multi_line, line_cnt-multi_line,1);
	yylval.si->dataType="INT";
	logPrint( "CONST_INT",yytext);
	return  CONST_INT  ;
}

{SUFF_PREF_ERR}	{
	err_cnt++;
	errorPrint("INVALID_ID_SUFFIX_NUM_PREFIX ",yytext);
}	

{FLOAT_LITERAL} {
	yylval.si = new SymbolInfo( yytext,"CONST_FLOAT", line_cnt-multi_line, line_cnt-multi_line,1);
	yylval.si->dataType="FLOAT";
	logPrint( "CONST_FLOAT",yytext);				
	return  CONST_FLOAT  ;
}

{MANY_DECIMAL_POINTS} {
	err_cnt++;
	errorPrint("TOO_MANY_DECIMAL_POINTS ",yytext);
}

{ILL_FORMED_NUMBER} {
	err_cnt++;
	errorPrint("ILLFORMED_NUMBER ",yytext);
}

"'" {
   cstr="'";
   BEGIN SINGLE_QUOT_STARTS;
}


<SINGLE_QUOT_STARTS>{NEWLINE} {
	err_cnt++;
   errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   line_cnt++;
   cstr= "";
   BEGIN INITIAL;
}
<SINGLE_QUOT_STARTS>"'" {
	cstr+=yytext;
	   err_cnt++;
   errorPrint("EMPTY_CONST_CHAR ",cstr);
   BEGIN INITIAL;
}
<SINGLE_QUOT_STARTS>[^\\] {
   cstr +=yytext;
   BEGIN NORMAL_CHAR;
}

<SINGLE_QUOT_STARTS>"\\" {
		cstr+=yytext;
		BEGIN SPECIAL_CHAR;
}


<SINGLE_QUOT_STARTS><<EOF>> {
   err_cnt++;
	errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   cstr="";
   BEGIN INITIAL;
}
<NORMAL_CHAR>{NEWLINE} {
   errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   err_cnt++;
   line_cnt++;
   BEGIN INITIAL;
}
<NORMAL_CHAR>[^;\'] {
   cstr +=yytext;
   BEGIN MULTI_CHAR_ERROR;
}
<NORMAL_CHAR>";" {
	err_cnt++;
   errorPrint("UNFINISHED_CONST_CHAR ",cstr);
		logPrint( "SEMICOLON",yytext);
		yylval.si = new SymbolInfo( yytext,"SEMICOLON", line_cnt-multi_line, line_cnt-multi_line,1);   
   cstr="";
   BEGIN INITIAL;
   return  SEMICOLON  ;
}
<NORMAL_CHAR>"'" {

   cstr+=yytext;
   logPrint( "CONST_CHAR",getSpecialChar(cstr));
   yylval.si = new SymbolInfo(getSpecialChar(cstr),"CONST_CHAR", line_cnt-multi_line, line_cnt-multi_line,1);
   yylval.si->dataType="CHAR";
   cstr=""; 
   BEGIN INITIAL;
   return  CONST_CHAR ;
}
<NORMAL_CHAR><<EOF>> {
	err_cnt++;
	errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   BEGIN INITIAL;
}
<SPECIAL_CHAR>"'"  {
	err_cnt++;
	cstr+=yytext;
   errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   BEGIN INITIAL;
}
<SPECIAL_CHAR>"''"  {
	cstr+=yytext;
   logPrint( "CONST_CHAR","'");
   yylval.si = new SymbolInfo( "'","CONST_CHAR", line_cnt-multi_line, line_cnt-multi_line,1);
      yylval.si->dataType="CHAR";
   cstr=""; 
   BEGIN INITIAL;
   return  CONST_CHAR ;
}
<SPECIAL_CHAR>[tnabfvr0\\] {
   cstr+=yytext;
   BEGIN NORMAL_CHAR;
}

<MULTI_CHAR_ERROR>{NEWLINE} {
   err_cnt++;
   errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   line_cnt++;
   cstr="";
   BEGIN INITIAL;
}
<MULTI_CHAR_ERROR><<EOF>> {
   err_cnt++;
      errorPrint("UNFINISHED_CONST_CHAR ",cstr);
   cstr="";
   BEGIN INITIAL;
}
<MULTI_CHAR_ERROR>[^\'] {
	cstr +=yytext;
}
<MULTI_CHAR_ERROR>"'" {
	cstr+=yytext;
   err_cnt++;
      errorPrint("MULTICHAR_CONST_CHAR ",cstr);
   cstr="";
   BEGIN INITIAL;
}

[+-] 	{
	logPrint( "ADDOP",yytext);
	yylval.si = new SymbolInfo( yytext,"ADDOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  ADDOP  ;
}

[*/%]			{
	logPrint( "MULOP",yytext);
	yylval.si = new SymbolInfo( yytext,"MULOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  MULOP  ;
}

"++"		{
	logPrint( "INCOP",yytext);
	yylval.si = new SymbolInfo( yytext,"INCOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  INCOP  ;
}
"--"    {
	logPrint( "DECOP",yytext);
	yylval.si = new SymbolInfo( yytext,"DECOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  DECOP  ;
}

"="			{
	logPrint( "ASSIGNOP",yytext);
	yylval.si = new SymbolInfo( yytext,"ASSIGNOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  ASSIGNOP  ;
}

"<"|"<="|">"|">="|"=="|"!=" {
	logPrint( "RELOP",yytext);
	yylval.si = new SymbolInfo( yytext,"RELOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  RELOP  ;
}

"&"|"|"|"^"|"<<"|">>"	{
	logPrint( "BITOP",yytext);
	yylval.si = new SymbolInfo( yytext,"BITOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  BITOP  ;
}

"&&"|"||" {
	logPrint( "LOGICOP",yytext);
	yylval.si = new SymbolInfo( yytext,"LOGICOP", line_cnt-multi_line, line_cnt-multi_line,1);
	return  LOGICOP  ;
}

"!"	{
	logPrint( "NOT",yytext);
	yylval.si = new SymbolInfo( yytext,"NOT", line_cnt-multi_line, line_cnt-multi_line,1);
	return  NOT  ;
}

"(" {
	logPrint( "LPAREN",yytext);
	yylval.si = new SymbolInfo( yytext,"LPAREN", line_cnt-multi_line, line_cnt-multi_line,1);
	return  LPAREN  ;
}
")" {
	logPrint( "RPAREN",yytext);
	yylval.si = new SymbolInfo( yytext,"RPAREN", line_cnt-multi_line, line_cnt-multi_line,1);
	return  RPAREN  ;
}
"[" {
	logPrint( "LSQUARE",yytext);
	yylval.si = new SymbolInfo( yytext,"LSQUARE", line_cnt-multi_line, line_cnt-multi_line,1);
	return  LSQUARE  ;
}
"]" {
	logPrint( "RSQUARE",yytext);
	yylval.si = new SymbolInfo( yytext,"RSQUARE", line_cnt-multi_line, line_cnt-multi_line,1);
	return  RSQUARE  ;
}
"{" {
	logPrint( "LCURL",yytext);
	yylval.si = new SymbolInfo( yytext,"LCURL", line_cnt-multi_line, line_cnt-multi_line,1);
	//st.enterScope();
	return  LCURL  ;
}
"}" {
	logPrint( "RCURL",yytext);
	yylval.si = new SymbolInfo( yytext,"RCURL", line_cnt-multi_line, line_cnt-multi_line,1);
	//st.exitScope();
	return  RCURL  ;
}

"," {
	logPrint( "COMMA",yytext);
	yylval.si = new SymbolInfo( yytext,"COMMA", line_cnt-multi_line, line_cnt-multi_line,1);
	return  COMMA  ;
}
";" {
	logPrint( "SEMICOLON",yytext);
	yylval.si = new SymbolInfo( yytext,"SEMICOLON", line_cnt-multi_line, line_cnt-multi_line,1);
	return  SEMICOLON  ;
}

[A-Za-z_][A-Za-z0-9_]* {
		logPrint( "ID",yytext);
		idName=yytext;
		yylval.si = new SymbolInfo( yytext,"ID", line_cnt-multi_line, line_cnt-multi_line,1);
		// bool success = st.insert(yytext,"ID");
		// if(success){
		// 	st.printAllScopeTables(logout);;
		// }
		// else {
		// 	logout<<"\t"<<yytext<<" already exisits in the current ScopeTable" << endl;
		// }
		
		return  ID  ;
}
\" {
		multi_string=false;
		cstr=yytext;
		strASCI="";
		multi_line=0;
		BEGIN STRING_STATE;
}

<STRING_STATE>\\n|\\r|\\\\|\\t|\\0|\\v|\\\'|\\a|\\f|\\b {
	cstr+=yytext;
	string p="'";
	p+=yytext;
	p+="'";
	strASCI+=getSpecialChar(p);
}


<STRING_STATE>\\{NEWLINE} {
	multi_string=true;
	multi_line++;
	line_cnt++;
	cstr+=yytext;
}

<STRING_STATE>"\\\"" {
	cstr+=yytext;
	strASCI+='\"';
}

<STRING_STATE>\" {
	cstr+=yytext;
	 
	if(!multi_string){
		yylval.si = new SymbolInfo( strASCI,"SINGLE_LINE_STRING", line_cnt-multi_line, line_cnt-multi_line,1);
		logPrint( "SINGLE LINE STRING",cstr);
		return SINGLE_LINE_STRING;
	}
	else{
		yylval.si = new SymbolInfo( strASCI,"MULTI LINE STRING", line_cnt-multi_line, line_cnt-multi_line,1);
		logPrint( "MULTI LINE STRING",cstr);
		return  MULTILINE_STRING ;
	}
	 
	multi_line=0;
	cstr="";
	strASCI="";	
	multi_string=false;
	BEGIN INITIAL;
}

<STRING_STATE>. {
	cstr+=yytext;
	strASCI+=yytext;
}

<STRING_STATE>{NEWLINE} {

	multi_line=0; 
	errorPrint("UNFINISHED_STRING ",cstr);
	 
	err_cnt++;
	line_cnt++;
	
	cstr="";
	strASCI="";	
	multi_string=false;
	BEGIN INITIAL;
}

<STRING_STATE><<EOF>> {
	errorPrint("UNFINISHED_STRING ",cstr);
	err_cnt++;
	
}

"//" {
	cmnt="//";
	multi_line=0;
	BEGIN SINGLE_LINE_COMMENT;

}
<SINGLE_LINE_COMMENT>(\\\n|\\\r\n) {
		cmnt+=yytext;
		multi_line++;
		line_cnt++;
}
<SINGLE_LINE_COMMENT>{NEWLINE} {
		 
		logPrint( "SINGLE LINE COMMENT", cmnt);
		 
		multi_line=0;
		line_cnt++;
		cmnt="";
		BEGIN INITIAL;
   
}
<SINGLE_LINE_COMMENT><<EOF>> {
	logPrint( "SINGLE LINE COMMENT", cmnt);
	cmnt="";
	multi_line=0;
	
}
<SINGLE_LINE_COMMENT>. {
	cmnt+=yytext;
}

"/*" {
	cmnt="/*";
	multi_line=0;
	BEGIN MULTILINE_COMMENT;
}
<MULTILINE_COMMENT>"*/" {
	cmnt+="*/";
	 
	logPrint( "MULTI LINE COMMENT",cmnt);
	 
	multi_line=0;
	cmnt="";
	BEGIN INITIAL;
}


<MULTILINE_COMMENT>{NEWLINE} {
	cmnt+=yytext;
	multi_line++;
   line_cnt++;
   
}

<MULTILINE_COMMENT><<EOF>> {
   multi_line=0;
   errorPrint("UNFINISHED_COMMENT ",cmnt);
   err_cnt++;
   cmnt="";
   
   BEGIN INITIAL;
	
}

<MULTILINE_COMMENT>. {
   cmnt+=yytext;
}

{NEWLINE} {
	line_cnt++;
	
}

{WHITESPACE}    {}

. {
   err_cnt++;
	logout<<"Error at line# "+to_string(line_cnt-multi_line)+": UNRECOGNIZED CHAR "+yytext<<endl;
	
}

%%

// int main(int argc, char** argv) {
// 	if(argc!=2){
// 		cout<<"Please provide input file name and try again\n";
// 		return 0;
// 	}
	
// 	FILE *fin=fopen(argv[1],"r");
// 	if(fin==NULL){
// 		cout<<"Cannot open specified file\n";
// 		return 0;
// 	}
	
// 	logout.open("1905065_log.txt");
// 	tokenout.open("1905065_token.txt");

// 	yyin= fin;
// 	yylex();
// 	st.printAllScopeTables(logout);
//  	logout << "Total lines: " << line_cnt << endl;
//  	logout << "Total errors: " << err_cnt << endl;
// 	fclose(yyin);
// 	tokenout.close();
// 	logout.close();
// 	return 0;
// }
