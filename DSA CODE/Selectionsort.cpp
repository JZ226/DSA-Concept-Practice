#include<iostream>
using namespace std;
void Selectionsorting(int arr[]){
        // for example if size of array is n then this loop stop at n-1
     for(int i=0; i<4; i++){
         int min=i;
         for(int j=i+1; j<5; j++){
            if(arr[min]>arr[j])
            min=j;
         }
         if(min!=i){
               int temp=arr[min];
                  arr[min]=arr[i];
                  arr[i]=temp;
         }
     }
}
int main(){
    int arr[5];
    cout<<"Array Items Before Sorted:"<<endl;
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    cout<<endl;
    Selectionsorting(arr);
    cout<<"Array Items After Sorted";
    for(int i=0; i<5; i++){
        cout<<arr[i];
        cout<<endl;
    }
}
