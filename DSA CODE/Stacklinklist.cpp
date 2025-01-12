#include<iostream>
using namespace std;
class linklistnode{
    public:
    int key;
    int data;
    linklistnode* next;
    linklistnode(){
        key=0;
        data=0;
        next=NULL;
    }
    linklistnode(int k,int d){
        key=k;
        data=d;
        next=NULL;
    }
};
class Stack{
    public:
    linklistnode* top;
    Stack(){
      top=NULL;
    }
    bool checkifnodeexsit(linklistnode* n){
        linklistnode* temp=top;
        bool exsit=false;
        while(temp!=NULL){
            if(temp->key==n->key){
                exsit=true;
                break;
            }
            temp=temp->next;
        }
        return exsit;
    }
    bool Empty(){
        if(top==NULL)
        return true;
        else
        return false;
    }
    void push(linklistnode* n){
        if(top==NULL){
            top=n;
            cout<<"Node Push Successfully"<<endl;
        }
        else if(checkifnodeexsit(n)){
            cout<<"Same Key Is Not Allowed"<<endl;
        }
        else{
            linklistnode* temp=top;
            top=n;
            n->next=temp;
            cout<<"Node Push Successfully"<<endl;
        }
    }
  linklistnode* pop(){
    linklistnode* temp=NULL;
    if(Empty()){
        cout<<"Stack Is Under Flow State"<<endl;
        return temp;
    }
    else{
        temp=top;
        top=top->next;
        return temp;
    }
  }
  linklistnode* peek(){
    linklistnode* temp=NULL;
    if(Empty()){
        cout<<"Stack Is Under Flow State"<<endl;
        return temp;
    }
    else{
        return top;
    }
  }
  int Count(){
        int Count=0;
        linklistnode* temp=top;
        while(temp!=NULL){
            Count++;
            temp=temp->next;
        }
        return Count;
  }
void display(){
    linklistnode* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<","<<temp->key;
        temp=temp->next;
    }
}
};
int main(){
    Stack s1;
    int data;
    int key;
    int option;
    do{
        cout<<"1. Push"<<endl;
        cout<<"2. POP"<<endl;
        cout<<"3. Empty"<<endl;
        cout<<"4. Peek"<<endl;
        cout<<"5. Count"<<endl;
        cout<<"6. Display"<<endl;
        cout<<"Enter 0 To Exsit The Program"<<endl;
        linklistnode* n1=new linklistnode();
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"PUSH THE DATA AND KEY"<<endl;
            cin>>data;
            cin>>key;
            n1->key=key;
            n1->data=data;
            s1.push(n1);
            break;
        case 2:
        cout<<"Data Is POPED"<<endl;
        n1=s1.pop();
        cout<<"Top In Stack Now"<<n1->key<<" "<<n1->data<<endl;
        break;
         case 4:
         cout<<"Show the peek one data"<<endl;
           n1=s1.peek();
           cout<<"The Data Is:"<<n1->data<<" "<<"Key Is:"<<n1->key<<endl;
           break;
           case 3:
           cout<<"Check the stack is empty or not"<<endl;
          s1.Empty();
           break;
          case 5:
          cout<<"Count all Data In Stack";
          s1.Count();
          break;
          case 6:
             cout<<"Display The Data In The Stack"<<endl;
              s1.display();
              cout<<endl;
              break;
        default:
          cout<<"Enter The Number From The Given Option"<<endl;
            break;
        }
    }
    while (option!=0);
}