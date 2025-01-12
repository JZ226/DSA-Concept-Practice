#include<iostream>
#define SPACE 10
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
class AVL{
    public:
    TreeNode* root;
    AVL(){
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
  int balancefactor(TreeNode* n){
    if(n==NULL)
    return -1;
    else
    return Heightoftree(n->Left) - Heightoftree(n->Right);
  }
  TreeNode* rotateleft(TreeNode* x){
    TreeNode* y=x->Right;
    TreeNode* t2=y->Left;
    //perform rotation
    y->Left=x;
    x->Right=t2;
    return y;
  }
  TreeNode* rotateright(TreeNode* y){
    TreeNode* x=y->Left;
    TreeNode* t2=x->Right;
    //perform rotation
    x->Right=y;
    y->Left=t2;
    return x;
  }
  TreeNode* insertRecursion(TreeNode *r,TreeNode *newnode){
        if(r==NULL){
            r=newnode;
            cout<<"Value Added Sucessfully"<<endl;
            return r;
        }
      if(newnode -> value < r -> value){
            r -> Left = insertRecursion(r->Left,newnode);
        }
      else if(newnode->value>r->value){
            r->Right=insertRecursion(r->Right,newnode);
        }
        else{
            cout<<"No Duplicate Is Allow"<<endl;
            return r;
        }
    int bf=balancefactor(r);
       if(bf==-2 && balancefactor(r->Right)<=0){
         return rotateleft(r);
       }
       else if(bf==-2 && balancefactor(r->Right)==1){
               r->Right=rotateright(r->Right);
               return rotateleft(r);
       }
       else if(bf==2 && balancefactor(r->Left)>=0){
           return rotateright(r);
       }
       else if(bf==2 && balancefactor(r->Left)==-1){
        r->Left=rotateleft(r->Left);
         return rotateright(r);
       }
        return r;
    }
    TreeNode* minvalue(TreeNode* r){
        TreeNode* current=r;
        while(current->Left!=NULL){
            current=current->Left;
        }
        return current;
    }
   TreeNode* Delete(TreeNode* r,int v){
    if(r==NULL)
    return r;
    else if(v<r->value){
        r->Left=Delete(r->Left,v);
    }
    else if(v>r->value){
        r->Right=Delete(r->Right,v);
    }
    else{ 
        if(r->Left==NULL){
      TreeNode*  temp=r->Right;
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
    int bf=balancefactor(r);
       if(bf==-2 && balancefactor(r->Right)<=0){
         return rotateleft(r);
       }
       else if(bf==-2 && balancefactor(r->Right)==1){
               r->Right=rotateright(r->Right);
               return rotateleft(r);
       }
       else if(bf==2 && balancefactor(r->Left)>=0){
           return rotateright(r);
       }
       else if(bf==2 && balancefactor(r->Left)==-1){
        r->Left=rotateleft(r->Left);
         return rotateright(r);
       }
       return r;
   }
   TreeNode* searchnode(TreeNode* r,int v){
       if(r==NULL || r->value==v)
       return r;
       else if(v<r->value){
        r->Left=searchnode(r->Left,v);
       }
       else if(v>r->value){
        r->Right=searchnode(r->Right,v);
       }
       return r;
   }
void print2D(TreeNode * r, int space) {
    if (r == NULL) 
      return;
    space += SPACE; 
    print2D(r ->Right, space); 
    cout << endl;
    for (int i = SPACE; i < space; i++) 
      cout << " "; 
    cout << r -> value << "\n"; 
    print2D(r ->Left, space);
  }
};
 int main(){
         int option,val;
         AVL obj;
         do
         {
            cout<<"What Operation U want to Performance?"<<endl;
            cout<<"1. Inserted a Node"<<endl;
            cout<<"2. Search Node"<<endl;
            cout<<"3. Delete a Node"<<endl;
            cout<<"4. Print BST Values"<<endl;
            cout<<"5. Check the height of tree"<<endl;
            cout<<"0. Exsit a Program"<<endl;
            TreeNode* newnode=new TreeNode();
            cin>>option;
            switch (option){
            case 1:
               cout << "AVL INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      cin >> val;
      newnode -> value = val;
    obj.root= obj.insertRecursion(obj.root, newnode);
      break;
      case 2:
        cout<<"Search a Node"<<endl;
        cout<<"Enter a Value To Search:"<<endl;
        cin>>val;
        newnode=obj.searchnode(obj.root,val);
        if(newnode!=NULL){
        cout<<"Value found"<<endl;
        }
        else{
            cout<<"Value din't found"<<endl;
        }
        break;
        case 3:
        cout<<"Delete a Node"<<endl;
        cout<<"Enter a Value Which You want to delete:"<<endl;
        cin>>val;
        newnode=obj.searchnode(obj.root,val);
        if(newnode!=NULL){
        obj.root= obj.Delete(obj.root,val);
        cout<<"Value Deleted Succesfully"<<endl;
        }
        else{
            cout<<"Value din't found"<<endl;
        }
        break; 
        case 4:
         cout<<"Print Vlues In Graphical way:"<<endl;
               obj.print2D(obj.root,5);
                cout<<endl;
         break;
         default:
         cout<<"Enter a Value From Given Option"<<endl;
         } }while (option!=0);
         return 0;
}