#include<iostream>
using namespace std;
void Shellsort(int arr[],int n){
    for(int gap=n/2; gap>0; gap/=2){
         for(int j=gap; j<n; j+=1){
            int temp=arr[j];
            int i=0;
            for(i=j; i>=gap && arr[i-gap]>temp; i-=gap){
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
         }
    }                                                                             
}
int main(){
    int size=7;
     int input[size];
    cout<<"Write a Items which you want to sort in array:";
    for(int i=0; i<size; i++){
        cin>>input[i];
    }
    cout<<endl;
    cout<<"Array Before SORT:"<<endl;
    for(int i=0; i<size; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    Shellsort(input,size);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<size; i++){
        cout<<input[i]<<" ";
    }
    }
