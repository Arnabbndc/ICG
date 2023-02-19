#include <bits/stdc++.h>
#include "1905065_ScopeTable.h"

using namespace std;

class SymbolTable{

    public:
        int total_buckets, max_scope_id;
        ScopeTable* current_scope ;
        SymbolTable();
        SymbolTable(int total_buckets);
        ~SymbolTable();
        void enterScope();
        void exitScope();
        void quit();
        bool insert(string name, string type);
        bool insert(SymbolInfo syminf);
        bool remove(string name);
        si_* lookup(string name);
        void printCurrentScopeTable(ofstream& cout);
        void printAllScopeTables(ofstream& cout);
        int getCurrentScopeId();
};

SymbolTable::SymbolTable(){
    this->current_scope = NULL;
    max_scope_id=0;
}

SymbolTable::SymbolTable(int total_buckets){
    this->total_buckets = total_buckets;
    current_scope = new ScopeTable(total_buckets);
    max_scope_id=1;
    //cout<<"\tScopeTable# 1 created\n";

}

SymbolTable::~SymbolTable(){
    while(current_scope!=NULL){
        ScopeTable* temp = current_scope;
        current_scope = current_scope->getParentScope();
        delete temp;
    }
}
void SymbolTable::quit(){
    while(current_scope!=NULL){
        ScopeTable* temp= current_scope;
        current_scope= current_scope->getParentScope();
        //cout << "\tScopeTable# " << temp->getId() << " removed" << endl;    
        delete temp;

    }
}
void SymbolTable::enterScope(){
    ScopeTable* new_scope = new ScopeTable(total_buckets);
    max_scope_id++;
    new_scope->setParentScope(current_scope, max_scope_id );
    current_scope= new_scope;
    //cout << "\tScopeTable# " << max_scope_id << " created" << endl;
}

void SymbolTable::exitScope(){
    if(current_scope==NULL){
        //cout << "\tNO CURRENT SCOPE" << endl;
        return;
    }
    if(current_scope->getId()==1){
        //cout<<"\tScopeTable# 1 cannot be removed\n";
        return;
    }

    ScopeTable* temp= current_scope;
    current_scope= current_scope->getParentScope();
    //cout << "\tScopeTable# " << temp->getId() << " removed" << endl;
    delete temp;

}

bool SymbolTable::insert(string name, string type){
    if(current_scope==NULL){
        current_scope = new ScopeTable(total_buckets);
        max_scope_id++;
        current_scope->setParentScope(NULL, max_scope_id);
    }
    return current_scope->insert(name, type);
}
bool SymbolTable::insert(SymbolInfo syminf){
    if(current_scope==NULL){
        current_scope = new ScopeTable(total_buckets);
        max_scope_id++;
        current_scope->setParentScope(NULL, max_scope_id);
    }
    return current_scope->insert(syminf);
}

bool SymbolTable::remove(string name){
    if(current_scope==NULL){
        //cout << "\tNO SCOPE TO REMOVE FROM" << endl;
        return false;
    }
    return current_scope->deleteEntry(name);
}

si_* SymbolTable::lookup(string name){
    if(current_scope==NULL){
        //cout << "\tNO SCOPE TO LOOKUP FROM" << endl;
        return NULL;
    }

    ScopeTable* itr = current_scope;
    si_* temp = NULL;
    while(itr!=NULL){
        temp = itr->lookup(name);
        if(temp != NULL){
            return temp;
        }
        itr= itr->getParentScope();
    }
    //cout <<"\t'"<< name<<"'"<<" not found in any of the ScopeTables\n";
    return NULL;
}

void SymbolTable::printCurrentScopeTable(ofstream& cout){
    if(current_scope==NULL){
        cout << "\tNO CURRENT SCOPE" << endl;
        return;
    }
    current_scope->print(cout);
}

void SymbolTable::printAllScopeTables(ofstream& cout){
    if(current_scope==NULL){
        cout << "\tNO SCOPE AVAILABLE" << endl;
        return;
    }
    ScopeTable* itr = current_scope;
    while(itr!=NULL){
        itr->print(cout);
        itr= itr->getParentScope();
    }

}
int SymbolTable::getCurrentScopeId(){
    return current_scope->current_id;
}