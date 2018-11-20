#include <bits/stdc++.h>
using namespace std;
const char* args[] = {"int", "double", "float", "string", "char", "return"};
vector<string> keyList(args, args + 6);

const char* args2[] = {"+", "-", "*", "/", "=", "(", ")", "{", "}", ",", ";"};
vector<string> opList(args2, args2 + 11);

bool isKeyword(string s){
    for(int i=0;i<keyList.size();i++){
        if(keyList[i]==s) return 1;
    }
    return 0;
}


bool isidentifier(string s){
    if(s[0]=='_' || (s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
        for(int i=0;i<s.length();i++){
            if(s[i]=='_' || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) continue;
            else return 0;
        }
        return !isKeyword(s);
    } else return 0;
}

bool isFunction(string s){
    int sz=s.length();
    string tmp=s.substr(0,s.length()-2);
    if(isidentifier(tmp) && s[s.length()-2]=='(' && s[s.length()-1]==')') return 1;
    else return 0;
}

bool isoperator(string s){
    for(int i=0;i<opList.size();i++){
        if(opList[i]==s) return 1;
    }
    return 0;
}

bool isdigit(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9') continue;
        else return 0;
    }
    return 1;
}

int main(){
    string s;
    freopen("inp.txt", "r+", stdin);
    set< string > keywords, ops, digits, identifiers, funcs, errors;
    while(cin>>s){
        if(isKeyword(s)) keywords.insert(s);
        else if(isidentifier(s)) identifiers.insert(s);
        else if(isFunction(s)) funcs.insert(s);
        else if(isoperator(s)) ops.insert(s);
        else if(isdigit(s)) digits.insert(s);
        else errors.insert(s);
    }

    cout<<"Keywords: \n";
    for(auto p:keywords) cout<<p<<endl;
    //for(int i=0;i<keywords.size();i++) cout<<keywords[i]<<endl;
    cout<<"Identifier: \n";
    for(auto p:identifiers) cout<<p<<endl;
    //for(int i=0;i<identifiers.size();i++) cout<<identifiers[i]<<endl;
    cout<<"Functions: \n";
    for(auto p:funcs) cout<<p<<endl;
    //for(int i=0;i<funcs.size();i++) cout<<funcs[i]<<endl;
    cout<<"Operators: \n";
    for(auto p:ops) cout<<p<<endl;
    //for(int i=0;i<ops.size();i++) cout<<ops[i]<<endl;
    cout<<"Digits: \n";
    for(auto p:digits) cout<<p<<endl;
    //for(int i=0;i<digits.size();i++) cout<<digits[i]<<endl;
    cout<<"Errors:\n";
    for(auto p:errors) cout<<p<<endl;
    return 0;
}
