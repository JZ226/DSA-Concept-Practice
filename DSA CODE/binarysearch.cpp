#include<iostream>
using namespace std;
int Binarysearch(int arr[],int left,int right,int x){
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    
    }
    return -1;
}
int main(){
    int num;
    int arr[10];
    int output;
    cout<<"Write a Array In Asscending Order:"<<endl;
    for(int i=0; i<10; i++){
        cin>>arr[i];
    }
    cout<<"Enter a Number which You want to find in array:"<<endl;
    cin>>num;
   output=Binarysearch(arr,0,9,num);
   if(output==-1){
    cout<<"The Number Is Not In array So It didn't found";
   }
   else{
    cout<<"The Number Which You find is in no:"<<output+1;
   }
}