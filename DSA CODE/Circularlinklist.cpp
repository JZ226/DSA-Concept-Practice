#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int key;
    Node* next;
    Node(){
        data=0;
        key=0;
        next=NULL;
    }
    Node(int d,int k){
        data=d;
        key=k;
    }
};
class Circularlinkedlist{
    public:
       Node* head;
     Circularlinkedlist(){
        head=NULL;
     }
     Node* nodeexsit(int k){
     Node* temp=NULL;   
     Node* ptr=head;
     if(ptr==NULL){
          return temp;  
     }
     else{
         do{
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
         }   while(ptr!=head);
     }
     return temp;
     }
     // Append a Node
 void Appendednode(Node *n){
    if (nodeexsit(n->key)!=NULL){
        cout<<"Node Is Already Exsited"<<n->key<<"Appended node with different key value"<<endl;
    }
    else{
        if(head==NULL){
       head = n;
       n->next=head;
       cout<<"Node Appended"<<endl;
        }
        else{
            Node* ptr=head;
    while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=head;
        cout<<"Node Appended"<<endl;
    }
        }
}
// Node Prepended
void Prependednode(Node *n){
       if (nodeexsit(n->key)!=NULL){
        cout<<"Node Is Already Exsited"<<n->key<<"Prepended node with different key value"<<endl;
    }
    else{
        if(head==NULL){
       head = n;
       n->next=head;
       cout<<"Node prepended"<<endl;
        }
        else{
        Node* ptr=head;
        while(ptr!=head){
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=head;
        head=n;
        cout<<"Node Is Prepended"<<endl;
        }
    }
}
 // Inserted a Node
 void insertnode(int k,Node *n){
    Node* ptr=nodeexsit(k);
    if (ptr==NULL){
        cout<<"No node exsit with value:"<<k<<endl;
    }
    else{
         if (nodeexsit(n->key)!=NULL){
        cout<<"Node Is Already Exsited"<<n->key<<"Insert node with different key value"<<endl;
    }
    else{
         if(ptr->next==head){
              ptr->next=n;
              n->next=head;
              cout<<"Node Inserted"<<endl;
         }
         else{
            ptr->next=n;
        n->next=ptr->next;
        cout<<"Node Inserted"<<endl;
         }
    }
    }
}
// Delete a Node
void delatenode(int k){
    if(head==NULL){
     cout<<"There is no any node exsited already"<<endl;
    }
    else if(head!=NULL){
        if(head->key==k){
            head=head->next;
            cout<<"Node Is Now Unliked with key value:"<<k<<endl;
        }
        else{
            Node *temp=NULL;
            Node *preptr=head;
            Node *currptr=head->next;
            while(currptr!=NULL){
            if(currptr->key==k){
                temp=currptr;
                currptr=NULL;
            }
            else{
                currptr=currptr->next;
                preptr=preptr->next;
            }
        }
        if (temp!=NULL){
            preptr->next==temp->next;
            cout<<"Node Is Now Unlinked with key value:"<<k<<endl;
        }
        else{
            cout<<"Node doesnot exsit with this key Value:"<<k<<endl;
        }
        }
    }
}
// update a node
void updatenode(int k,int d){
         Node *ptr=nodeexsit(k);
         if (ptr!=NULL){
            ptr->data=d;
            cout<<"Node Is Updated Now"<<endl;
         }
         else{
            cout<<"Node Is not Exsited With this Key:"<<k<<endl;
         }
}
// print a circular link list
void linkedlist(){
    if(head==NULL){
        cout<<"No Nodes In Circular Linked List"<<endl;
    }
    else{
        cout<<endl<<"Circular linked List Values is:";
        Node *temp=head;
        while(temp!=head){
            cout<<"("<<temp->key<<","<<temp->data<<")";
            temp=temp->next;
        }
    }
}
};
int main(){
  int option;
        Circularlinkedlist s;
        int key1,data1,k1;
        do{
         cout<<"What function U want To perform and enter 0 to exsit"<<endl;
         cout<<"1:Appended Node"<<endl;
         cout<<"2:Prepended Node"<<endl;
         cout<<"3:Insert a Node"<<endl;
         cout<<"4:Delete a Node"<<endl;
         cout<<"5:Update a Node"<<endl;
         cout<<"6:Print a Node"<<endl;
         cout<<"7:Clear the screen"<<endl;
         cin>>option;
         Node* n1=new Node();
         switch (option)
         {
         case 0:
            break;
         case 1:
         cout<<"Append a node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.Appendednode(n1);
            break;
        case 2:
         cout<<"Prepended a Node"<<endl;
         cin>>key1;
         cin>>data1;
         n1->key=key1;
         n1->data=data1;
         s.Prependednode(n1);
         break;
         case 3:
         cout<<"insert a Node"<<endl;
         cin>>k1;
         cout<<"Enter a key or data"<<endl;
         cin>>key1;
         cin>>data1;
         n1->key=key1;
         n1->data=data1;
         s.insertnode(k1,n1);
         break;
         case 4:
         cout<<"Delete a node by key operation"<<endl;
         cin>>k1;
         s.delatenode(k1);
         break;
         case 5:
         cout<<"Update a Node"<<endl;
         cin>>key1;
         cin>>data1;
         s.updatenode(key1,data1);
         break;
         case 6:
         s.linkedlist();
         break;
         case 7:
         system("cls");
         break;
         default:
         cout<<"Enter the Proper Option"<<endl;
            break;
         }
        }while (option!=0);
        return 0;
}