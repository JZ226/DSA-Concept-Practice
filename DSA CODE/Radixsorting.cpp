#include<iostream>
using namespace std;
void Counting(int arr[],int size,int div){
    int range=10;
   int  output[size];
    int count[range];
    for(int i=0; i<range; i++){
        count[i]=0;
    }
    for(int i=0; i<size; i++){
        count[(arr[i]/div)%10]++;
    }
    for(int i=1; i<range; i++){
          count[i]=count[i]+count[i-1];
    }
    for(int i=size-1; i>=0; i--){
        output[count[(arr[i]/div)%10]-1]=arr[i];
        count[(arr[i]/div)%10]--;
    }
    for(int i=0; i<size; i++){
        arr[i]=output[i];
    }
}
int Getmaxno(int arr[],int size){
   int  max=arr[0];
      for(int i=1; i<size; i++){
        if(arr[i]>max){
            max=arr[i];
        }
      }
      return max;
}
void Radixsorting(int arr[],int size){
       int m=Getmaxno(arr,size);
       for(int div=1;m/div>0; div*=10){
        Counting(arr,size,div);
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
    Radixsorting(input,size);
    cout<<"Array After SORT:"<<endl;
    for(int i=0; i<size; i++){
        cout<<input[i]<<" ";
    }
}