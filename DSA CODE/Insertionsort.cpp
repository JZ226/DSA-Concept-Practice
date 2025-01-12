#include<iostream>
using namespace std;
void Insertionsorting(int arr[]){
    for(int i=1; i<5; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            j=j-1;
        }
        arr[j+1]=key;
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
    Insertionsorting(arr);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

}