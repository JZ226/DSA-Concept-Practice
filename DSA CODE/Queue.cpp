#include<iostream>
using namespace std;
class queue{
    private:
    int rare;
    int front;
    int arr[4];
    public:
    queue(){
        rare=-1;
        front=-1;
        for(int i=0; i<4; i++){
            arr[i]=0;
        }
    }
    bool isempty(){
        if(rare==-1 && front==-1)
        return true;
        else
        return false;
    }
    bool isfull(){
        if(rare==3)
        return true;
        else 
        return false;
    }
   void enqueue(int value){
        if(isfull())
         return;
         else if(rare==-1){
          front=rare=0;
         }
         else{
            rare++;
         }
         arr[rare]=value;
    }
    int dequeue(){
        int x=0;
        if(isempty())
        return;
        else if(front==rare){
            x=arr[front];
           front=-1;
           rare=-1;
        }
        else{
              x=arr[front];
              front++;
        }
          return x;
    } 
    void diplay(){
        for(int i=0; i<4; i++){
            cout<<arr[i];
            cout<<endl;
        }
    }
    void count(){
        cout<<rare+1;
    }
};
int main(){
     int option,value;
    queue obj;
    do
    {
      cout<<"Enter 1 if U check queue is empty or not"<<endl;  
      cout<<"Enter 2 if U check queue is Full or not"<<endl;  
      cout<<"Enter 3 if U put any value from queue"<<endl;  
      cout<<"Enter 4 if U delete any value from queue"<<endl;
      cout<<"Enter 5 if U display All values In queue"<<endl;
      cout<<"Enter 6 if U count Values In queue"<<endl;
      cout<<"If U Exsit a Program enter a 0"<<endl;
      cin>>option;
      switch (option)
      {
      case 1:
         if(obj.isempty())
         cout<<"queue is empty"<<endl;
         else
         cout<<"queue is not empty"<<endl;
        break;
      case 2:
          if(obj.isfull())
          cout<<"queue is Full"<<endl;
          else
          cout<<"queue is not full"<<endl;
          break;
      case 3:
           cout<<"Enter the value which u want to put in queue:";
           cin>>value;
           cout<<"You enter a value in queue is:"<<value<<endl;
           break;
      case 4:
            cout<<"The value delete from queue:"<<obj.dequeue()<<endl;
            break;
      case 5:
      cout<<"Display all the values in queue:";
         obj.diplay();
         break;
      case 6:
      cout<<"Count Values In queue:";
      obj.count();
      break;
      default:
         cout<<"Any Number from 1 to 4 or 0 for exsit:";
         break;
      }
    } while (option!=0);
}