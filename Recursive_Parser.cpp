#include <bits/stdc++.h>
using namespace std;
#define INT(a) scanf("%d",&a)
#define STR(a) scanf("%s",a)
#define DBL(a) scanf("%lf",&a)
#define LNG(a) scanf("%lld",&a)
#define PI acos(-1)
string s;
int ptr=0;
int F(){
	if(s[ptr]=='I' || s[ptr]=='N'){
		cout<<s[ptr];
		ptr++;
	} else return -1;
	return 1;
}

int T(){
	cout<<"( ";
	int tmp=F();
	if(tmp==-1) return -1;
	while(1){
		if(s[ptr]=='*' || s[ptr]=='/'){
			cout<<s[ptr];
			ptr++;
			tmp=F();
			if(tmp==-1) return -1;
		} else return cout<<" )", 1;
	}
}

int E(){
	cout<<"( ";
	int tmp=T();
	if(tmp==-1) return -1;
	while(1){
		if(s[ptr]=='+' || s[ptr]=='-'){
			cout<<s[ptr];
			ptr++;
			tmp=T();
			if(tmp==-1) return -1;
		} else return cout<<" )", 1;
	}
}




int main(){
	cin>>s;
	int tmp=E();
	cout<<endl;
	if(tmp==-1) cout<<"Error\n";
	else cout<<"Correct\n";
	return 0;
}