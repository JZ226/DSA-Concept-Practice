#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int i=l;
    int j=m+1;
    int k=l;
    int temp[5];
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int s=0; s<=r; s++){
        arr[s]=temp[s];
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
    int m=(l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
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
      mergesort(arr,0,4);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}