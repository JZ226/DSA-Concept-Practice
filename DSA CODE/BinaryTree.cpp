#include<iostream>
#define GLOBALSPACE 5
using namespace std;
class TreeNode{
    public:
    int value;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode(){
        value=0;
        Left=NULL;
        Right=NULL;
    }
    TreeNode(int v){
        value=v;
        Left=NULL;
        Right=NULL;
    }
};
class BST{
    public:
    TreeNode* root;
    BST(){
        root=NULL;
    }
    bool empty(){
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void insertnode(TreeNode* new_node){
       if(root==NULL){
        root=new_node;
        cout<<"Value Insert as Root Node"<<endl;
       }
       else{
        TreeNode* temp = root;
        while (temp!=NULL)
        {
            if(new_node->value==temp->value){
                cout<<"Value Already Exsit"<<endl;
                return;
            }
            else if((new_node->value<temp->value) && (temp->Left==NULL)){
                temp->Left=new_node;
                cout<<"Node Inserted at Left side Of Root Node"<<endl;
                break;
            }
            else if(new_node->value<temp->value){
                temp=temp->Left;
            }
            else if((new_node->value>temp->value) && (temp->Right==NULL)){
                temp->Right=new_node;
                cout<<"Node Inserted At Right Side Of Root Node"<<endl;
                break;
            }
            else if(new_node->value>temp->value){
                temp=temp->Right;
            }
        }
        
       }
    }
    void printPreOrder(TreeNode* r){
        if(r==NULL)
            return;
            cout<<r->value<<" ";
            printPreOrder(r->Left);
            printPreOrder(r->Right);
    }
    void printinorder(TreeNode *r){
        if(r==NULL)
        return;
        printinorder(r->Left);
        cout<<r->value<<" ";
        printinorder(r->Right);
    }
    void printpostorder(TreeNode* r){
        if(r==NULL)
        return;
        printpostorder(r->Left);
        printpostorder(r->Right);
        cout<<r->value<<" ";
    }
    void Print2D(TreeNode* r,int space){
        if(r==NULL)
        return;
        space=space+GLOBALSPACE;
        Print2D(r->Right,space);
        cout<<endl;
        for(int i=GLOBALSPACE; i<space; i++){
            cout<<" ";
        }
        cout<<r->value<<endl;
        Print2D(r->Left,space);
    }
    TreeNode* Iterativesearch(int val){
         if(root==NULL){
            return root;
         }
         else{
            TreeNode* temp;
            temp==root;
            while(temp!=NULL)
            {
             if(val==temp->value){
                return temp;
             }   
             else if(val<temp->value){
                temp=temp->Left;
             }
             else if(val>temp->value){
                temp=temp->Right;
             }
             else{
                return NULL;
             }
            }
         }
    }
  TreeNode* recursivesearch(TreeNode* r,int val){
    if((r==NULL) || (r->value==val)){
        return r;
    }
    else{
        if(val<r->value){
            recursivesearch(r->Left,val);
        }
        else if(val>r->value){
            recursivesearch(r->Right,val);
        }
    }
  }
  int Heightoftree(TreeNode* r){
    if(r==NULL){
        return -1;
    }
    else{
    int lheight=Heightoftree(r->Left);
    int rheight=Heightoftree(r->Right);
    if(lheight>rheight){
        return lheight+1;
    }
    else{
        return rheight+1;
    }
    }
  }
  void BFS(TreeNode* r){
    int h=Heightoftree(r);
    for(int i=0; i<=h; i++){
      Givenlevel(r,i);
    }
  }
  void Givenlevel(TreeNode* r,int level){
      if(r==NULL)
      return;
      else if(level==0){
        cout<<r->value<<" ";
      }
      else{
        Givenlevel(r->Left,level-1);
        Givenlevel(r->Right,level-1);
      }
  }
 TreeNode* minvalue(TreeNode*r){
    TreeNode* current=r;
    while(current->Left!=NULL){
        current=current->Left;
    }
    return current;
 }
  TreeNode* Delete(TreeNode* r,int v){
    if(r==NULL){
        return r;
    }
    else if(v<r->value){
        r->Left=Delete(r->Left,v);
    }
    else if(v>r->value){
        r->Right=Delete(r->Right,v);
    }
    else{
        if(r->Left==NULL){
            TreeNode* temp=r->Right;
            delete r;
            return temp;
        }
        else if(r->Right==NULL){
            TreeNode* temp=r->Left;
            delete r;
            return temp;
        }
        else{
        TreeNode* temp=minvalue(r->Right);
        r->value=temp->value;
        r->Right=Delete(r->Right,temp->value);
    }
    }
    return r;
  }
  
};

int main(){
         int option,val;
         BST obj;
         do
         {
            cout<<"What Operation U want to Performance?"<<endl;
            cout<<"1. Inserted a Node"<<endl;
            cout<<"2. Search Node"<<endl;
            cout<<"3. Delete a Node"<<endl;
            cout<<"4. Print BST Values"<<endl;
            cout<<"5. Check the height of tree"<<endl;
            cout<<"0. Exsit a Program"<<endl;
            TreeNode* new1=new TreeNode();
            cin>>option;
            switch (option)
            {
            case 1:
                cout<<"Insert Node"<<endl;
                cout<<"Insert a Value:";
                cin>>val;
                new1->value=val;
                obj.insertnode(new1);
                cout<<endl;
                break;
           case 2:
                cout<<"Search"<<endl;
                // we have two option to search 1 is Iterative search and other is Recursive search
                cout<<"Enter The Value:"<<endl;
                cin>>val;
                new1=obj.recursivesearch(obj.root,val);
                if(new1==NULL){
                    cout<<"No Value Found"<<endl;
                }
                else{
                    cout<<"Value Found"<<endl;
                }
                break;
           case 3:
                cout<<"Delete"<<endl;
                 cout<<"Enter The Value:"<<endl;
                cin>>val;
                new1=obj.recursivesearch(obj.root,val);
                if(new1==NULL){
                    cout<<"No Value Found"<<endl;
                }
                else{
                    obj.Delete(obj.root,val);
                    cout<<"Value Deleted"<<endl;
                }
                break;
           case 4:
                cout<<"Print BST"<<endl;
                cout<<"Pre Order:"<<endl;
                obj.printPreOrder(obj.root);
                cout<<endl;
                cout<<"In Order:"<<endl;
                obj.printinorder(obj.root);
                cout<<endl;
                cout<<"Post Order:"<<endl;
                obj.printpostorder(obj.root);
                cout<<endl;
                cout<<"Print Vlues In Graphical way:"<<endl;
                obj.Print2D(obj.root,5);
                cout<<endl;
                 cout<<"BFS:"<<endl;
                obj.BFS(obj.root);
                cout<<endl;
                break;
                case 5:
                cout<<"Height Of Tree Node Is:"<<endl;
                obj.Heightoftree(obj.root);
                cout<<endl;
                break;
            default:
            cout<<"Enter a Number from given Option"<<endl;
                break;
            }
         } while (option!=0);
}