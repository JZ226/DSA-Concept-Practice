#include<iostream>
using namespace std;
void swap(int &x,int &y){
  int   temp=x;
         x=y;
         y=temp;
}
class MinHeap{
    public:
   int *harr;
   int capacity;
   int heap_size;
   MinHeap(int cap){
    heap_size=cap;
    capacity=cap;
    harr= new int[cap];
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
void unsortedarr(){
    for(int i=0; i<capacity; i++){
        cin>>harr[i];
    }
}
void Minheapify(int i){
   int  l=left(i);
   int  r=right(i);
   int smallest = i;
   if(l<heap_size && harr[l]<harr[i] ){
    smallest=l;
   }
    if(r<heap_size && harr[r]<harr[smallest]){
    smallest=r;
   }
   if(smallest!=i){
    swap(harr[i],harr[smallest]);
    Minheapify(smallest);
   }
}
int extraxtmin(){
    if(heap_size<=0){
        return INT_FAST16_MAX;
    }
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        Minheapify(0);
        return root;
}
void heapsort(){
    int temp[capacity];
    for(int j=0; j<capacity; j++){
        temp[j]=extraxtmin();
        cout<<temp[j]<<" ";
    }
}
};
int main(){
    int s;
    cout<<"Size of Array:";
    cin>>s;
    MinHeap obj(s);
    obj.unsortedarr();
    cout<<"Unsorted Array"<<endl;
    obj.printArray();
    for(int i=s/2-1; i>=0; i--){
        obj.Minheapify(i);
    }
    cout<<"Heap Sorted Array"<<endl;
    obj.heapsort();
}