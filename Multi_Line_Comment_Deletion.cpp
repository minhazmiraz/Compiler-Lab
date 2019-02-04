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
    //cout<<s<<endl;

    int start=-1, last=-1, shuru=0;
    while(1){
        //cout<<shuru<<endl;
        for(int i=shuru;i<s.length()-1;i++){
            if(s[i]=='/' && s[i+1]=='*'){
                start=i;
                break;
            }
        }

        if(start!=-1){
            for(int i=start+2;i<s.length()-1;i++){
                if(s[i]=='*' && s[i+1]=='/'){
                    last=i;
                    break;
                }
            }
        } else break;


        if(start==-1 && last==-1) break;
        else if(last==-1) last=s.length();

        for(int k=shuru;k<last;k++){
            if(k>=start && k<=last+1) continue;
            cout<<s[k];
        }
        shuru=last+2; start=-1; last=-1;
    }

    for(int k=shuru;k<s.length();k++){
        cout<<s[k];
    }

}


//input:
//this is me /* this is 
//me */...... helo/*lolo*/oo
//this is me this is 
//me */...... helo/*lolooo
//this is me /* this is 
//me */...... helo*/lolo/*oo
//EOF

