#include<bits/stdc++.h>

using namespace std;

struct node
{
    string val = "", code = "";
};


char lookAhead;
int takenNo, varNo=0;
string str;

node E();
node Ep();
node S();
node match();

string crtVar(){
    string ret = "t";
    ret += (varNo++)+'0';
    return ret;
}

void match(char c){

    if(lookAhead == c){
        lookAhead = str[++takenNo];
    }else{
        cout<<"2Syntax Error\n";
        exit(1);
    }
}

//void A()
//{
//    if(lookAhead == 'a')
//    {
//        match('a');
//        A();
//        match('b');
//    } else if(lookAhead == 'b')
//    {
//
//        match('b');
//    }
//
//}

/*
node id(){
	if(lookAhead>='a' && lookAhead<='z'){
		match(lookAhead);
	} else{
	    cout<<"Syntax Error\n";
        exit(1);
	}
}
*/

node Ep(){
    if(lookAhead == '+'){
        match('+');
        node t1 = E();
        node t2 = Ep();
        node ret;
        ret.val = "";
        ret.code = "+"+t1.val+t2.val+'\n'+t1.code+t2.code;
        //cout<<ret.code<<endl;
        return ret;
    } else if(lookAhead == '-') {
        match('-');
        //E(); Ep();
        node t1 = E();
        node t2 = Ep();
        node ret;
        ret.val = "";
        ret.code = "-"+t1.val+t2.val+'\n'+t1.code+t2.code;
        return ret;
    }
    node ret; ret.val=""; ret.code="";
    return ret;
}


node E(){
    /*if(lookAhead == '('){
        match('(');
        E();
        match(')');
        Ep();
    } else */
    if(lookAhead>='a' && lookAhead<='z') {
        char ch =lookAhead;
        string id = " ";
        id[0]=ch;
        match(lookAhead);
        node tmp = Ep();
        //cout<<"Here"<<id<<endl;
        //cout<<tmp.val<<" "<<tmp.code<<endl;
        node ret;
        if(tmp.code==""){
            ret.val=id;
            ret.code=tmp.code;
            return ret;
        } else{
            string var = crtVar();
            ret.code=var+"="+id+tmp.code;
            ret.val = var;
            //cout<<ret.code<<endl;
            return ret;
        }
    } else{
        cout<<"1Syntax Error\n";
        exit(1);
    }
}



node S(){
    if(lookAhead>='a' && lookAhead<='z') {
        char ch =lookAhead;
        string id = " ";
        id[0]=ch;
        match(lookAhead);
        match('=');
        node tmp = E();
        node ret;
        ret.val = tmp.val;
        ret.code = id + "=" + tmp.val + '\n' + tmp.code;
        //cout<<"Hello"<<id<<ret.code<<endl;
        return ret;
    } else{
        cout<<"3Syntax Error\n";
        exit(1);
    }
}


int main(){
    cin>>str;
    str += "$";
    lookAhead = str[0];
    takenNo = 0;
    varNo = 0;
    node ans = S();
    if(lookAhead == '$'){
        cout<<"Successful\n";
        reverse(ans.code.begin(), ans.code.end());
        cout<<ans.code<<endl;
    } else cout<<"Syntax Error\n";
    return 0;
}
