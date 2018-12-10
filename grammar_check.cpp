#include<bits/stdc++.h>
using namespace std;

string convert(string s){
    bool digit=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(digit){
                digit=0;
                ans+="3";
            }
            ans+="1";
        } else if(s[i]==')'){
            if(digit){
                digit=0;
                ans+="3";
            }
            ans+="2";
        } else if(s[i]=='+' || s[i]=='-'){
            if(digit){
                digit=0;
                ans+="3";
            }
            ans+="4";
        } else{
            if(!digit) digit=1;
        }
    }
    if(digit){
        digit=0;
        ans+="3";
    }
    return ans;
}

int main(){
    map< string, int >mp;
    mp["343"]=6;
    mp["643"]=6;
    mp["346"]=6;
    mp["162"]=6;
    freopen("inp.txt", "r+",stdin);
    string str;
    cin>>str;
    string ans=convert(str);
    //cout<<ans<<endl;
    while(1){
        string tmp;
        int len=ans.length()-1;
        bool f=0;
        ans+="###";
        //cout<<ans<<endl;
        for(int i=0;i<=len;){
            string s=ans.substr(i,3);
            //cout<<s<<endl;
            if(mp[s]){
                tmp+=(char)(mp[s]+48);
                f=1;
                i+=3;
            } else{
                tmp+=ans[i];
                i++;
            }
        }
        ans=tmp;
        //cout<<ans<<endl;
        if(!f) break;
    }
    //cout<<ans<<endl;
    if(ans.length()==1) cout<<"Accepted\n";
    else cout<<"Rejected\n";
    return 0;
}
