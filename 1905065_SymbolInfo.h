#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define pl pair<ll, ll>
#define ff first
#define ss second
#define pdl pair<double, ll>
#define pb push_back
#define oo 10000000.0
using namespace std;

class SymbolInfo
{
    public:
    string name, type, dataType, label;
    bool isFunc,isFuncDefined, isLeaf,isParam=false, isGlobal=false, isBool=false;
    int startLine,endLine, arraySize, offset,value;
    vector<string> paramTypeList;
    SymbolInfo *next, *child, *valPointer=NULL;
    //value er kaam koroooo
    SymbolInfo()
    {
        next = NULL;
        child=NULL;
        isFunc=false;
        isFuncDefined=false;
        isLeaf=false;
        paramTypeList=vector<string>(0);
        arraySize=-1;
        offset=0;
    }
    SymbolInfo(string name, string type, int sline=0, int eline=0, bool isleaf=0)
    {
        this->name = name;
        this->type = type;
        dataType=type;
        next = NULL;
        child=NULL;
        isFunc=false;
        isFuncDefined=false;
        isLeaf=isleaf;
        startLine=sline;
        endLine=eline;
        arraySize=-1;
        offset=0;

    }
        SymbolInfo(const SymbolInfo& si)
    {
        this->name = si.name;
        this->type = si.type;
        dataType=si.type;
        next = si.next;
        child=si.child;
        isFunc=si.isFunc;
        isFuncDefined=si.isFuncDefined;
        isLeaf=si.isLeaf;
        startLine=si.startLine;
        endLine=si.endLine;
        paramTypeList=si.paramTypeList;
        arraySize=si.arraySize;
        offset= si.offset;
        isGlobal=si.isGlobal;
        isBool= si.isBool;
        valPointer= si.valPointer;
        isParam= si.isParam;
    }
    SymbolInfo(SymbolInfo* si)
    {
        this->name = si->name;
        this->type = si->type;
        dataType=si->type;
        next = si->next;
        child=si->child;
        isFunc=si->isFunc;
        isFuncDefined=si->isFuncDefined;
        isLeaf=si->isLeaf;
        startLine=si->startLine;
        endLine=si->endLine;
        paramTypeList=si->paramTypeList;
        arraySize=si->arraySize;
        offset= si->offset;
        isGlobal=si->isGlobal;
        isBool= si->isBool;
        valPointer= si->valPointer;
        isParam= si->isParam;
    }
    ~SymbolInfo()
    {
        next = NULL;
        child=NULL;
    }
    string getName()
    {
        return this->name;
    }
    string getType()
    {
        return this->type;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setType(string type)
    {
        this->type = type;
        this->dataType= type;
    }
    void print(ofstream& cout){
        if(!isFunc && arraySize==-1)
            cout << "<" << getName() << ", " << getType() << "> ";
        else if(arraySize!=-1)
            cout << "<" << getName() << ", " << "ARRAY" << ", "<< getType() << "> ";
        else if(isFunc)
            cout << "<" << getName() << ", " << "FUNCTION" << ", "<< getType() << "> ";

    }
    void setArraySize(string size){
        arraySize= stoi(size);
    }

};
