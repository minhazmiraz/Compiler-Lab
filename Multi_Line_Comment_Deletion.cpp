#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, str;
    int j=0;
    while(getline(cin,str)){
    if(str=="EOF") break;
        if(j) s+='\n';
        s+=str;
        j++;
    }

    int start=-1, last=-1, shuru=0;
    while(1){
        start=s.find("/*");
        last=s.find("*/");
        if(start==-1 && last==-1) break;
        else if(last==-1) last=s.length()-2;
         for(int k=shuru;k<=last+1;k++){
            if(k>=start && k<=last+1) continue;
            cout<<s[k];
        }
        s[start]='.', s[start+1]='.', s[last]='.', s[last+1]='.';
        shuru=last+2;
        //cout<<endl;
    }
    for(int k=shuru;k<s.length();k++){
        cout<<s[k];
    }

}
