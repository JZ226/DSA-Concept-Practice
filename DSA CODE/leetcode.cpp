#include<iostream>
using namespace std;
int main(){
    int i=3;
    int n=6;
     int num[6];
    int arr[3]=[1,2,3];
    int arr[3] = new int[3*2];
    for(int z=0; z<n; z++){
          arr[z]=arr[z+n]=arr[z];
    }
    cout<<arr[n];
}