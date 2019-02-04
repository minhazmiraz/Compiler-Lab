#include <bits/stdc++.h>
using namespace std;
int main(){
    string dictionary[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dictionary[i];
    }

    string s;
    cin>>s;
    if(s[0]=='_' || (s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
        bool f=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='_' || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) continue;
            else{
                f=0;
                break;
            }
        }
        if(f){
            f=1;
            for(int i=0;i<n;i++){
                if(dictionary[i]==s){
                    f=0; break;
                }
/*                int pos = s.find(dictionary[i]);
                if(pos==-1) continue;
                else{
                    f=0; break;
                }*/
            }
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        } else cout<<"NO\n";
    } else cout<<"NO\n";
    return 0;
}
