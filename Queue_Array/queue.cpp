#include<iostream>
using namespace std;
int maxsize=5;
class Queue{
    private:
        int *arr=NULL;
        int frnt,rear;
    public:
        Queue(){
            arr = new int[maxsize];
            frnt=-1;
            rear=-1;
        }

        //   to check that the Queue is Empty or not
        bool is_Empty(){
            if(frnt==-1 && rear==-1)
                return true;
            else
                return false;
        }
        //  to check that the Queue is Full or not
        bool is_Full(){
            if((rear+1)%maxsize ==frnt)
                return true;
            else
                return false;
        }
    // Inser an element in queue at end (rear)
        void Enqueue(int x){
            if(is_Full()){
                cout<<"Error: Queue is full"<<endl;
                return ;
            }
            if(is_Empty()){
                frnt=0;
                rear=0;
            }
            else{
                rear=(rear+1)%maxsize;
            }
            arr[rear]=x;

        }
    //    Removes an element in Queue from front end;
        void delete_queue(){
            if(is_Empty()){
                cout<<"Error: Queue is Empty:"<<endl;
                return;
            }
            else if(frnt == rear){
                frnt=NULL;
                rear=NULL;
            }
            else{
                frnt =(frnt+1) % maxsize;
            }
        }

        void Print(){
            // finding number of elements in Queue
            int siz=(rear + maxsize - frnt) % maxsize+1;
            int index;
            cout<<"_______________________"<<endl;
            for(int i=0 ; i<siz ; i++){
                index=(frnt+i)%maxsize;  // Index of element while travesing circularly from front
                cout<<" "<<arr[index]<<"  ";
            }
            cout<<endl;
        }
        ~ Queue(){
            delete [] arr;
        }

};



int main(){
    Queue Q;
    Q.Enqueue(2);
    Q.Enqueue(4);
    Q.Enqueue(6);
    Q.Enqueue(8);
    Q.Enqueue(10);
    Q.delete_queue();
    Q.Enqueue(12);
    //Q.delete_queue();
    cout<<"     ___________________"<<endl;
    Q.Print();
    return 0;
}
