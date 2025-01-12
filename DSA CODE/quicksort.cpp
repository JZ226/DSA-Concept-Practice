#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
   int pindex=s;
   int pivot=arr[e];
   for(int i=s; i<e; i++){
   if(arr[i]<=pivot){
      int temp=arr[i];
      arr[i]=arr[pindex];
      arr[pindex]=temp;
      pindex++;
   }
   }
   int temp=arr[e];
   arr[e]=arr[pindex];
   arr[pindex]=temp;
   return pindex;
}
void Quicksort(int arr[],int s,int e){
    if(s<e){
   int p=partition(arr,s,e);
    Quicksort(arr,s,(p-1));
    Quicksort(arr,(p+1),e);
    }
}
int main(){
     int arr[5];
    cout<<"Write a Items which you want to sort in array:";
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array Before SORT:"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Quicksort(arr,0,4);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}