#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
};
class Queue{
    private:
        int msize;
        Node *Front,*rear,*temp;
    public:
        Queue(){
            msize=0;
            Front=rear=temp=NULL;
        }
        void En_Queue(int val){
            if(rear==NULL){
                rear=new Node;
                rear->info=val;
                rear->next=NULL;
                Front = rear;
                msize+=1;
                return;
            }
            rear->next=new Node;
            rear=rear->next;
            rear->info=val;
            msize+=1;
        }
        void de_Queue(){
            temp=Front;
            Front=Front->next;
            delete temp;
            msize-=1;
        }
        void print(){
            temp=Front;
            while(temp != NULL){
                cout<<temp->info<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

};
int main(){
    Queue obj;
    obj.En_Queue(5);
    obj.En_Queue(2);
    obj.En_Queue(1);
    obj.En_Queue(3);
    obj.print();
    obj.de_Queue();
    obj.print();
    return 0;
}
