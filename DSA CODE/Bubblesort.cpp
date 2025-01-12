#include<iostream>
using namespace std;
void bubblesorting(int arr[]){
    for(int i=0; i<5; i++){
        for(int j=0; j<4-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
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
    bubblesorting(arr);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}