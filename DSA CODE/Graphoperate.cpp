#include<iostream>
#include<vector>
#include <iterator>
#include<list>
using namespace std;
class edge{
    public:
    int vertex_id;
    int weight;
    edge(int v_id, int w){
        vertex_id=v_id;
        weight=w;
    }
    void setedges(int v_id,int w){
        vertex_id=v_id;
        weight=w;
    }
    void setweight(int w){
        weight=w;
    }
    int getvertexid(){
        return vertex_id;
    }
    int getweight(){
        return weight;
    }
};
class Vertex{
        public:
        int state_id;
        string state_name;
        list<edge> edgelist;
        Vertex(){
            state_id=0;
            state_name=" ";
        }
        Vertex(int s_id,string s_name){
            state_id=s_id;
            state_name=s_name;
        }
        int getstateid(){
            return state_id;
        }
        string getstatename(){
            return state_name;
        }
        void set_id(int s_id){
            state_id=s_id;
        }
        void set_state(string s_name){
            state_name=s_name;
        }
        list<edge> get_edgelist(){
            return edgelist;
        }
        void printedges(){
    cout<<"[";
    for(auto it=edgelist.begin(); it!=edgelist.end(); it++){
        cout<<it->getvertexid()<<"("<<it->getweight()<<")";
    }
    cout<<"]";
    cout<<endl;
}
};
class Graph{
    public:
      vector<Vertex>vertices;
    void addvertex(Vertex newVertex){
      bool current=currentvertexidexsit(newVertex.getstateid());
      if(current==true){
        cout<<"Value id Already exsit"<<endl;
      }
      else{
        vertices.push_back(newVertex);
        cout<<"New Vertex Added Successfully!!"<<endl;
      }
    }
    bool currentvertexidexsit(int v_id){
        for(int i=0; i<vertices.size(); i++){
            if(vertices.at(i).getstateid()==v_id){
            return true;
            }
        }
        return false;
    }
    Vertex getVertexby(int v_id){
              Vertex temp;
              for(int i=0; i<vertices.size(); i++){
                temp=vertices.at(i);
                if(temp.getstateid()==v_id)
                return temp;
              }
    }
    bool checkedgealreadyexsit(int fromvertex,int tovertex){
        Vertex v=getVertexby(fromvertex);
        list<edge>e;
        e=v.get_edgelist();
        for(auto it=e.begin(); it!=e.end(); it++){
            if(it->vertex_id==tovertex){
                return true;
            }
            return false;
        }
    }

    void addedgebetweenvertex(int fromvertex,int tovertex,int weight){
       bool check1=currentvertexidexsit(fromvertex);
       bool check2=currentvertexidexsit(tovertex);
       if((check1 && check2 == true)){
        bool check3=checkedgealreadyexsit(fromvertex,tovertex);
        if(check3==true){
            cout<<"Edge between"<<"("<<fromvertex<<")"<<"("<<tovertex<<")"<<"already exsit"<<endl;
        }
        else{
             for(int i=0; i<vertices.size(); i++){
                if(vertices.at(i).getstateid()==fromvertex){
                    edge e(tovertex,weight);
                   vertices.at(i).edgelist.push_back(e);
                }
                else if(vertices.at(i).getstateid()==tovertex){
                    edge e(fromvertex,weight);
                    vertices.at(i).edgelist.push_back(e);
                }
             }
             cout<<"Edge Is Scuccessfully Created!!"<<endl;
        }
       }
       else{
       cout<<"Invalid vertex id enter"<<endl;
    }
}
void printgraph(){
    Vertex temp;
    for(int i=0; i<vertices.size(); i++){
        temp=vertices.at(i);
        cout<<temp.getstatename()<<"("<<temp.getstateid()<<")---";
        temp.printedges();
    }
}
void updateEdgebyID(int fromvertex,int tovertex,int weight){
      bool Check = checkedgealreadyexsit(fromvertex,tovertex);
      if(Check==true){
          for(int i=0; i<vertices.size(); i++){
            if(vertices.at(i).getstateid()==fromvertex){
                for(auto it = vertices.at(i).edgelist.begin(); it!=vertices.at(i).edgelist.end(); it++){
                    if(it->getvertexid()==tovertex){
                        it->setweight(weight);
                        break;
                    }
                }
            }
            else if(vertices.at(i).getstateid()==tovertex){
                for(auto it=vertices.at(i).edgelist.begin(); it!=vertices.at(i).edgelist.end(); it++){
                    if(it->getvertexid()==fromvertex){
                        it->setweight(weight);
                        break;
                    }
                }
            }
            cout<<"Weight Is Update of two edges Scuccessfully"<<endl;
          }
      }
      else{
        cout<<"There Is No exsistence Of edge between"<<"("<<fromvertex<<" and "<<tovertex<<")"<<endl;
      }
}
void DeleteEdgebyID(int fromvertex,int tovertex){
             bool Check = checkedgealreadyexsit(fromvertex,tovertex);
             if(Check==true){
                  for (int i=0; i<vertices.size(); i++){
                    if(vertices.at(i).getstateid()==fromvertex){
                        for(auto it=vertices.at(i).edgelist.begin(); it!=vertices.at(i).edgelist.end(); it++){
                               if(it->getvertexid()==tovertex){
                                vertices.at(i).edgelist.erase(it);
                                break;
                               }
                        }
                    }
                    else if(vertices.at(i).getstateid()==tovertex){
                        for(auto it=vertices.at(i).edgelist.begin(); it!=vertices.at(i).edgelist.end(); it++){
                            if(it->getvertexid()==fromvertex){
                                vertices.at(i).edgelist.erase(it);
                                break;
                            }
                        }
                    }
                    cout<<"Edge between node Deleted Sucessfully!!!"<<endl;
                  }
             }
             else{
                cout<<"There is no any type of edge between"<<fromvertex<<" and "<<tovertex<<endl;
             }
}
void DeleteVertexById(int v_id){
    int vindex=0;
    for(int i=0; i<vertices.size(); i++){
        if(vertices.at(i).getstateid()==v_id){
            vindex=i;
        }
            for(auto it = vertices.at(vindex).edgelist.begin(); it!=vertices.at(vindex).edgelist.end(); it++){
                DeleteEdgebyID(it->getvertexid(),v_id);
            }
            vertices.erase(vertices.begin()+vindex);
            cout<<"Vertex Is Deleted Succesfully!!!"<<endl;
    }
}
void UpdateVertexById(int v_id,string newname){
        bool Check= currentvertexidexsit(v_id);
        if(Check==true){
            for(int i=0; i<vertices.size(); i++){
                if(vertices.at(i).getstateid()==v_id){
                    vertices.at(i).set_state(newname);
                    break;
                }
            }
        }
}
void PrintALLNeighboursNodesBYID(int v_id){
    cout<<vertices.at(v_id).getstatename()<<" "<<"("<<vertices.at(v_id).getstateid()<<")---";
    cout<<"[";
    for(int i=0; i<vertices.size(); i++){
        if(vertices.at(i).getstateid()==v_id){
            for(auto it=vertices.at(i).edgelist.begin(); it!=vertices.at(i).edgelist.end(); it++){
                cout<<it->getvertexid()<<" "<<"("<<it->getweight()<<")";
                cout<<"]";
            }
        }
    }
}
};
int main(){
    int option,ID,ID1,W;
    string sname;
    Graph g;
    Vertex v;
do{
    cout<<"Select any one option from a given one's and if U want to break a program enter a zero"<<endl;
    cout<<"1:Add a Vertex"<<endl;
    cout<<"2:Create a Edges between two nodes"<<endl;
    cout<<"3:Print a Graph"<<endl;
    cout<<"4:Update a Edge"<<endl;
    cout<<"5:Delete a Edge"<<endl;
    cout<<"6:Delete a Vertex"<<endl;
    cout<<"7:Update a Vertex By Help Of Id"<<endl;
    cout<<"8:Print the Neighbours Of Node By help Of Node Id"<<endl;
    cin>>option;
   switch(option){
    case 1:
        cout<<"Add a Vertex Now:-"<<endl;
        cout<<"Enter a Id:"<<endl;
        cin>>ID;
        cout<<"Enter a Name of City:"<<endl;
        cin>>sname;
        v.set_id(ID);
        v.set_state(sname);
        g.addvertex(v);
        break;
    case 2:
    cout<<"Create a edge:-"<<endl;
      cout<<"The 1st Node ID WHICH U connect:"<<endl;
      cin>>ID;
      cout<<"The 2nd one Node Which u want to connect:"<<endl;
      cin>>ID1;
       cout<<"The distance between nodes:"<<endl;
       cin>>W;
       g.addedgebetweenvertex(ID,ID1,W);
       break;
       case 3:
       cout<<"PRINT A GRAPH"<<endl;
       g.printgraph();
       break;
       case 4:
       cout<<"Update a Weight By Help of Id:-"<<endl;
       cout<<"The 1st Node ID WHICH U update:"<<endl;
      cin>>ID;
      cout<<"The 2nd one Node Whose weight u want to update:"<<endl;
      cin>>ID1;
       cout<<"The NEW distance between nodes:"<<endl;
       cin>>W;
       g.updateEdgebyID(ID,ID1,W);
       break;
       case 5:
       cout<<"Delete a Edges between Nodes:-"<<endl;
       cout<<"Id of which u want to delete a edge:"<<endl;
       cin>>ID;
       cout<<"2nd Id of which U want to delete edge:"<<endl;
       cin>>ID1;
       g.DeleteEdgebyID(ID,ID1);
       break;
       case 6:
       cout<<"Delete a vertex which U want:-"<<endl;
       cin>>ID;
       g.DeleteVertexById(ID);
       break;
       case 7:
       cout<<"Update a Name By give Vertex Id:-"<<endl;
        cout<<"Id of which u want to change a name:"<<endl;
       cin>>ID;
        cout<<"Enter a new Name of City:"<<endl;
        cin>>sname;
        g.UpdateVertexById(ID,sname);
        break;
       case 8:
       cout<<"Print a Neighbours of nodes:-"<<endl;
        cout<<"Id of which u want to print Neighbours:"<<endl;
       cin>>ID;
       g.PrintALLNeighboursNodesBYID(ID);
       break;
       default:
       cout<<"Enter a Number From Given Option"<<endl;
       }
}while(option!=0);
}