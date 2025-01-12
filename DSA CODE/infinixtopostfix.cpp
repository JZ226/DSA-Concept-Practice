#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    else{
        return false;
    }
}
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
    return -1;
    }
}
string infnixtopostfix(stack<char>s,string infinix){
    string postfix;
    for(int i=0; i<infinix.length(); i++){
        if((infinix[i]>='a' || infinix[i]<='z') || (infinix[i]>='A' || infinix[i]<='Z')){
               postfix+=infinix[i];
        }
       else if(infinix[i]=='('){  
            s.push(infinix[i]);
        }
        else if(infinix[i]==')'){
            while((s.top()!='(')&&(!s.empty())){
                 postfix+=s.top();
                s.pop();
            }
        }
        else if(isOperator(infinix[i])){
            if(s.empty()){
                s.push(infinix[i]);
            }
            else{
         if(precedence(infinix[i])>precedence(s.top())){
            s.push(infinix[i]);
        }
        else if((precedence(infinix[i])==precedence(s.top())) || (infinix[i]=='^')){
            s.push(infinix[i]);
        }
        else{
               while((!s.empty()) && (precedence(infinix[i])<=precedence(s.top()))){
                     char temp = s.top();
                      postfix+=temp;
                        s.pop();
               }
               s.push(infinix[i]);
        }
            }
        }
             
            }
            while(!s.empty()){
            postfix+=s.top();
            s.pop();
            }
            return postfix;
        }
int main(){
    string infix,postfix_exp;
    cout<<"The Integer which u change into infinix to postfix:";
    cin>>infix;
    cout<<"Infix Expression:"<<infix<<endl;
    stack<char>stack;
   postfix_exp=infnixtopostfix(stack,infix);
   cout<<"After Conversion:"<<postfix_exp;
}