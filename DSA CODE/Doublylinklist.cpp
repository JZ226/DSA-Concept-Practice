#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    int data;
    Node* next;
    Node* Previous;
    Node(){
        key=0;
        data=0;
        next=NULL;
        Previous=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};
class doublylinkedlist{
    public:
    Node* head;
    doublylinkedlist(){
         head=NULL;
    }
    doublylinkedlist(Node *n){
        head=n;
    }
  // Node exsit or not
  Node* checkifnodeexsit(int k){
    Node* temp=NULL;
    Node* ptr=head;
    while (ptr!=NULL){
    if(ptr->key==k){
        temp=ptr;
    }
    ptr=ptr->next; 
    }
    return temp;
  }
// Appended Node
void nodeappended(Node* n){
    if(checkifnodeexsit(n->key)==n){
        cout<<"Node Is Already exstied with this key:"<<n->key<<"Appended node with different Key"<<endl;
    }
    else{
        if(head==NULL){
            head=n;
            cout<<"Node Appended";
        }
        else{
             Node* ptr=head;
             while(ptr->next!=NULL){
                ptr=ptr->next;
             } 
             ptr->next=n;
             n->Previous=ptr;
             cout<<"Node Appended"<<endl;
        }
    }
}
// Prepended Node
void prependednode(Node* n){
    if(checkifnodeexsit(n->key!=NULL)){
        cout<<"Node Is Already Exsited with this key:"<<n->key<<"Try with other one key"<<endl;
    }
        else{
            if(head==NULL){
            head=n;
            cout<<"Node prepended";
        }
        else{
            head->Previous=n;
            n->next=head;
            head=n;
            cout<<"Node prepended";
        }
        }
}
// Inserted a Node
void insertednode(int k,Node* n){
   Node* ptr=checkifnodeexsit(k);
   if(ptr==NULL){
    cout<<"There Is No Node Exsited with this key"<<endl;
   }
   else{
     Node* nextnode=ptr->next;
        if(checkifnodeexsit(n->key==k)){
            cout<<"Node is Exsit Already With This Key:"<<n->key<<"Try with other key"<<endl;
        }
        // Insert In Between
        else if(nextnode==NULL){
             ptr->next=n;
             n->Previous=ptr;
          cout<<"Node Is Inserted"<<endl;
        }
        // Insert At the end
        else{
               n->next=nextnode;
               nextnode->Previous=n;
               n->Previous=ptr;
               ptr->next=n;
               cout<<"Node Is Inserted"<<endl;
        }
   }
}
// Delete a Node 
void deletenode(int k){
    Node* ptr=checkifnodeexsit(k);
    Node* nextnode=ptr->next;
    Node* previousnode=ptr->Previous;
    if(ptr==NULL){
        cout<<"Node Is Not exsited with This key"<<endl;
    }
   else {
    if(head->key==k){
        head=head->next;
        cout<<"Delete a Node Successfully"<<endl;
    }
    else{
           nextnode->Previous=previousnode;
           previousnode->next=nextnode;
           cout<<"Node is deleted Now"<<endl;
    }
   }
}
// Node Updated
void updatenode(int k,int d){
    Node* ptr=checkifnodeexsit(k);
    if(ptr!=NULL){
        ptr->data=d;
        cout<<"Node is Updated Successfully"<<endl;
    }
    else{
        cout<<"With this key nothing any node exsit"<<endl;
    }
}
// Print all the Nodes
void printdoublylinklist(){
    Node* temp=head;
    if(head==NULL){
        cout<<"Not Any Node Exsited"<<endl;
    }
    else{
         while(temp!=NULL){
            cout<<"("<<temp->key<<","<<temp->data<<")"<<endl;
            temp=temp->next;
         }

    }
}
};
int main(){
     doublylinkedlist obj;
       int option;
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
            obj.nodeappended(n1);
            break;
        case 2:
         cout<<"Prepended a Node"<<endl;
         cin>>key1;
         cin>>data1;
         n1->key=key1;
         n1->data=data1;
         obj.prependednode(n1);
         break;
         case 3:
         cout<<"insert a Node"<<endl;
         cin>>k1;
         cout<<"Enter a key or data"<<endl;
         cin>>key1;
         cin>>data1;
         n1->key=key1;
         n1->data=data1;
         obj.insertednode(k1,n1);
         break;
         case 4:
         cout<<"Delete a node by key operation"<<endl;
         cin>>k1;
         obj.deletenode(k1);
         break;
         case 5:
         cout<<"Update a Node"<<endl;
         cin>>key1;
         cin>>data1;
         obj.updatenode(key1,data1);
         break;
         case 6:
         obj.printdoublylinklist();
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