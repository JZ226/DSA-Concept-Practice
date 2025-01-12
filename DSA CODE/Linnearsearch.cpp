#include<iostream>
using namespace std;
void linnearsearch(int arr[],int n){
    int temp=-1;
   for(int i=0; i<5; i++){
    if(arr[i]==n){
        cout<<"Your Number Find In Array location:"<<i+1;
        temp=0;
    }
   }
   if(temp==-1){
    cout<<"The array didn't consist of this element"<<endl;
   }
}
int main(){
    int arr[5]={2,4,6,8,10};
    int num;
    cout<<"Enter a Number Whose value U find from array:"<<endl;
    cin>>num;
    linnearsearch(arr,num);
    return 0;
}