#include<iostream>
using namespace std;
class stack
{
public:
   int top;
   int arr[5];
public:
   stack(){
    top=-1;
    for(int i=0; i<5; i++){
        arr[i]=0;
    }
   }
   bool is_empty(){
    if(top==-1)
    return 1;
    else
    return 0;
   }
   bool is_full(){
    if(top==4)
    return 1;
    else
    return 0;
   }
   void push(int var){
    if(is_empty()){
        arr[top]=var;
         top++;
    }
    else{
        cout<<"Stack is in overflow state";
    }
   }
   void pop(){
    if(is_full()){
        arr[top]=0;
        top--;
    }
    else{
        cout<<"Stack is in underflow state";
    }
   }
   void peek(int pos){
    if(is_empty()){
     cout<<"Stack is underflow";
    }
     else{
        cout<<arr[pos];
     }
   }
   int count(){
       return top+1;
   }
   int change(int pos,int var){
    return arr[pos]=var;
   }
   void diplay(){
    for(int i=4; i>0; i--){
        cout<<arr[i];
    }
   }
};
int main(){
    stack s1;
    int option,variable,Position;
    do
    {
        /* code */
    cin>>option;
       switch (option)
       {
       case 1:
              cout<<"The stack is empty or not"<<endl;
               if(s1.is_empty())
                cout<<"Stack is empty"<<endl;
               else 
               cout<<"Stack is not empty"<<endl;
        break;
        case 2:
        cout<<"The stack is Full or not"<<endl;
        if(s1.is_full())
        cout<<"Stack is Full"<<endl;
        else 
        cout<<"Stack is Not Full"<<endl;
       break;
       case 3:
       cout<<"Push The value in stack"<<endl;
       cout<<"The Value Is:";
       cin>>variable;
       s1.push(variable);
        break;
        case 4:
        cout<<"Pop The Value In Stack"<<endl;
        s1.pop();
        break;
      case 5:
      cout<<"Acess the value"<<endl;
      cout<<"The position of value which we acess:";
      cin>>Position;
      s1.peek(Position);
      break;
       case 6:
       cout<<"Count the total values in stack"<<endl;
       cout<<s1.count();
       break;
       case 7:
       cout<<"Change the value In Stack:"<<endl;
       cout<<"Positiion of value:";
       cin>>Position;
       cout<<"The Value Which We give:";
       cin>>variable;
       cout<<s1.change(Position,variable);
       break;
       case 8:
       cout<<"Display the values in stack"<<endl;
       s1.diplay();
       break;
       default:
       cout<<"Take a option 1 to 8 if u perform any operation"<<endl;
        break;    
        } 
}
while (option!=0);
}