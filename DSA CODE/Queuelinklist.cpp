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
class Queue{
    public:
    linklistnode* top;
    linklistnode* rear;
    Queue(){
     top=NULL;
     rear=NULL;    
    }
    bool Empty(){
        if(top==NULL && rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool checkifnodeexsit(linklistnode* n){
        linklistnode* temp=top;
        bool exsit=false;
        while(temp!=NULL){
             if(temp->key=n->key){
                exsit=true;
                break;
             }
             temp=temp->next;
        }
        return exsit;
    }
 void enqueue(linklistnode* n){
    if(Empty()){
        top=n;
        rear=n;
        cout<<"Node Equeue Succesfully"<<endl;
    }
    else if(checkifnodeexsit(n)){
        cout<<"This Node IS Exsit Already"<<endl;
    }
    else{
        rear->next=n;
        rear=n;
        cout<<"Node Equeue Succesfully"<<endl;
    }
 }
 linklistnode* Dequeue(){
    linklistnode* temp=NULL;
    if(Empty()){
        cout<<"Queue Is In Under flow state"<<endl;
        return top;
    }
    else if(rear==top){
        temp=top;
        rear=NULL;
        top=NULL;
        return temp;
    }
    else{
        temp=top;
      top=top->next;
      return temp;
    }
 }
  int Count(){
    linklistnode* temp;
      int count=0;
       temp=top;
       while(temp!=NULL){
        count++;
        temp=temp->next;
       }
       return count;
  }
  void display(){
    linklistnode* temp;
    temp=top;
    while(temp!=NULL){
        cout<<"Key is"<<" "<<temp->key<<" , "<<"Data is"<<" "<<temp->data;
        temp=temp->next;
    }
  }
};
int main(){
Queue s1;
    int data;
    int key;
    int option;
    do{
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Empty"<<endl;
        cout<<"4. Count"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"Enter 0 To Exsit The Program"<<endl;
        linklistnode* n1=new linklistnode();
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enqueue THE DATA AND KEY"<<endl;
            cin>>data;
            cin>>key;
            n1->key=key;
            n1->data=data;
            s1.enqueue(n1);
            break;
        case 2:
        cout<<"Data Is Dequeue"<<endl;
        n1=s1.Dequeue();
        cout<<"Top In Queue Now"<<n1->key<<" "<<n1->data<<endl;
        break;
           case 3:
           cout<<"Check the stack is empty or not"<<endl;
         if (s1.Empty()){
            cout<<"Queue Is Empty"<<endl;
         }
         else{
            cout<<"Queue Is Not Empty"<<endl;
         }
           break;
          case 4:
          cout<<"Count all Data In Queue"<<endl;
          s1.Count();
          break;
          case 5:
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
