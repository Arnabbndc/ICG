#include <bits/stdc++.h>
#include "1905065_SymbolInfo.h"
#define si_ SymbolInfo
using namespace std;

class ScopeTable{
    public:
        int total_buckets, current_id;
        ScopeTable* parentScope;
        si_** table;
        ScopeTable(int total_buckets);
        ~ScopeTable();
        void setParentScope(ScopeTable* parent, int childID);
        ScopeTable* getParentScope();
        int getId();
        int sdbmHash(string name);
        bool insert(string name, string type);
        bool insert(SymbolInfo syminf);
        si_* lookup(string name);
        bool deleteEntry(string name);
        void print(ofstream& cout);

};

ScopeTable::ScopeTable(int total_buckets){
    this->total_buckets = total_buckets;
    this->table = new si_*[total_buckets];
    for(int i = 0; i < total_buckets; i++){
        this->table[i] = NULL;
    }
    parentScope = NULL;
    current_id=1;
}
void ScopeTable::setParentScope(ScopeTable* parent, int childID){
    this->parentScope = parent;
    this->current_id = childID;
}

ScopeTable* ScopeTable::getParentScope(){
    return this->parentScope;
}
int ScopeTable::getId(){
    return current_id;    
}
ScopeTable::~ScopeTable(){
    for(int i = 0; i < total_buckets; i++){
        si_* t1 = table[i];
        si_* t2 = t1;
        while(t1 != NULL){
            t2=t1;
            t1 = t1->next;
            delete t2;
        }
        
    }
    delete[] table;
}
int ScopeTable::sdbmHash(string name)
{
    uint64_t hashval = 0;
    int sz = name.length();
    for (int i = 0; i < sz; i++)
    {
        hashval = name[i] + (hashval << 16) + (hashval << 6) - hashval;
    }
    hashval = hashval % ((uint64_t)total_buckets);

    return (int)hashval;
}
bool ScopeTable::insert(string name, string type){

    unsigned int hashVal = sdbmHash(name), pos=1;
    si_* curr = table[hashVal];
    si_* prev = NULL;
    while(curr != NULL ){
        if(name!="" && curr->getName() == name){
            //cout<<"\t'" << name <<"' already exists in the current ScopeTable"<<endl;
            return false;
        }
        prev=curr;
        curr = curr->next;
        pos++;
    }
    if(prev!=NULL)
        prev->next= new si_(name, type);
    else 
        table[hashVal]= new si_(name, type);
    //cout<<"\tInserted in ScopeTable# " << current_id << " at position " << hashVal+1<< ", " <<pos<<endl;
    return true;
}
bool ScopeTable::insert(SymbolInfo syminf){
    string name= syminf.getName();

    unsigned int hashVal = sdbmHash(name), pos=1;
    si_* curr = table[hashVal];
    si_* prev = NULL;
    while(curr != NULL){
        if(name!="" && curr->getName() == name){
            //cout<<"\t'" << name <<"' already exists in the current ScopeTable"<<endl;
            return false;
        }
        prev=curr;
        curr = curr->next;
        pos++;
    }
    if(prev!=NULL)
        prev->next= new si_(syminf);
    else 
        table[hashVal]= new si_(syminf);
    //cout<<"\tInserted in ScopeTable# " << current_id << " at position " << hashVal+1<< ", " <<pos<<endl;
    return true;
}
si_* ScopeTable::lookup(string name){
    int hashVal = sdbmHash(name), pos=1;
    si_* curr = table[hashVal];
    while(curr != NULL){
        if(curr->getName() == name){
            //cout<<"\t'"<<name<<"'"<<" found in ScopeTable# " << current_id << " at position " << hashVal+1 << ", " << pos<<endl;
            return curr;
        }
        curr = curr->next;
        pos++;
    }
    return curr;
}

bool ScopeTable::deleteEntry(string name){
    int hashVal = sdbmHash(name), pos=1;
    si_* curr = table[hashVal];
    si_* prev = NULL;
    while(curr != NULL){
        if(curr->getName() == name){
            if(prev==NULL){
                table[hashVal]=curr->next;
            }
            else{
                prev->next= curr->next;
            }
            delete curr;
            //cout<<"\tDeleted '" << name<< "' from ScopeTable# " << current_id << " at position " << hashVal+1 << ", " << pos<<endl;
            return true;
        }
        prev=curr;
        curr = curr->next;
        pos++;
    }

    //cout<<"\tNot found in the current ScopeTable\n";
    return false;
    
}

void ScopeTable::print(ofstream& cout){
    cout << " ScopeTable# " << current_id << endl;
    for(int i = 0; i < total_buckets; i++){
        si_* temp = table[i];
        if(temp!= NULL){
        cout <<' '<< i+1 << "--> ";
        while(temp != NULL){
            temp->print(cout);
            temp = temp->next;
        }
        cout<<endl;
    }
    }

}



