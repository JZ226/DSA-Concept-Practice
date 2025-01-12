#include<iostream>
using namespace std;
void countingsort(int input[],int size,int range){
     int output[size];
     int count_array[range];
     for(int i=0; i<range; i++){
        count_array[i]=0;
     }
     for(int i=0; i<size; i++){
        ++count_array[input[i]];
     }
     for(int i=1; i<range; i++){
        count_array[i]=count_array[i]+count_array[i-1];
     }
     for(int i=0; i<size; i++){
        output[--count_array[input[i]]]=input[i];
     }
     
     for(int i=0; i<size; i++){
        input[i]=output[i];
     }
}
int main(){
    int size=7;
    int range=10;
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
      countingsort(input,size,range);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<size; i++){
        cout<<input[i]<<" ";
    }
}