#include<iostream>
using namespace std;
void swap(int &x,int &y){
  int   temp=x;
         x=y;
         y=temp;
}
class MinHeap{
    public:
   int* harr;
   int capaciity;
   int heap_size;
   MinHeap(int cap){
    heap_size=0;
    capaciity=cap;
    harr= new int[cap];
   }
   void linnearsearch(int val){
    for(int i=0; i<heap_size; i++){
        if(harr[i]==val)
        cout<<"Value found"<<endl;
    }
     cout<<"Value didn't Found"<<endl;
   }
void printArray(){
    for(int i=0; i<heap_size; i++){
    cout<<harr[i]<<" ";
    cout<<endl;
    }
}
int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return (i*2)+1;
}
int right(int i){
    return (2*i)+2;
}
void insert(int k){
    if(heap_size==capaciity){
        cout<<"Heap is Over Flow!!!!!!!!!!"<<endl;
        return;
    }
    heap_size++;
   int  i=heap_size-1;
   harr[i]=k;
   while(i!=0 && harr[parent(i)]>harr[i]){
    swap(harr[parent(i)],harr[i]);
    i=parent(i);
   }
}
int extraxtmin(){
    if(heap_size<=0){
        return INT_FAST16_MAX;
    }
    else if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    else{
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        Minheapify(0);
        return root;
    }
}
void Minheapify(int i){
   int  l=left(i);
   int  r=right(i);
   int smallest = i;
   if(l<heap_size && harr[l]<harr[i] ){
    smallest=l;
   }
   else if(r<heap_size && harr[r]<harr[smallest]){
    smallest=r;
   }
   if(smallest!=i){
    swap(harr[i],harr[smallest]);
    Minheapify(smallest);
   }
}
void Delete(int i){
    decreasevalue(i,INT16_MIN);
    extraxtmin();
}
void decreasevalue(int i,int new_val){
    harr[i]=new_val;
    while(i!=0 && harr[i]<harr[parent(i)]){
        swap(harr[i],harr[parent(i)]);
        i=parent(i);
    }
}
};
int main(){
     int s,option,val;
     cout<<"Size Of heap:";
     cin>>s;
      MinHeap obj(s);
     do{
         cout<<"What Operation U want to perform"<<endl;
         cout<<"If You want to exsit a program click a zero"<<endl;
         cout<<"1:Insert a value"<<endl;
         cout<<"2:Extract a Value"<<endl;
         cout<<"3:Delete a value"<<endl;
         cout<<"4:print a Heap"<<endl;
         cin>>option;
         switch(option){
            case 1:
            cout<<"Insert a Value in heap:";
            cin>>val;
            obj.insert(val);
            break;
            case 2:
            cout<<"Extract a Value:"<<endl;
           cout<<obj.extraxtmin();
           cout<<endl;
            break;
            case 3:
            cout<<"Delete a Value"<<endl;
            cout<<"Value number which U want to delete"<<endl;
            cin>>val;
            obj.Delete(val);
            break;
            case 4:
            cout<<"Print The Value In The Heap:"<<endl;
            obj.printArray();
            break;
            default:
            cout<<"Enter a values From Given Option"<<endl;
         }
     }while(option!=0);
     return 0;
}