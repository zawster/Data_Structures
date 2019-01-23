#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
};
class Stack{
    private:
        Node *top,*temp;
        int c=0;
        int maxSize;       // maximum size of stack
    public:

        Stack(){
            cout<<"Maximum size of Stack : ";
            cin>>maxSize;
            top=temp=NULL;
        }
        void push(int val){
            if(c==maxSize){
                cout<<"Overflow!";
                return;
            }
            temp=new Node;
            temp->info=val;
            temp->next=top;
            top=temp;
            c+=1;
        }
        void pop(){
            if(top==NULL){
                cout<<"Underflow! "<<endl;
                return;
            }
            temp=top;
            top=top->next;
            delete temp;
            c-=1;
        }

        void print(){
            temp=top;
            while(temp!=NULL){
                cout<<temp->info<<"  ";
                temp=temp->next;
            }
            cout<<endl;
        }
        ~Stack(){
            while(top!=NULL){
                temp=top;
                top=top->next;
                delete temp;
            }
        }
};
int main(){
    Stack obj;
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.print();
    obj.pop();
    obj.push(2);
    obj.print();
    return 0;
}
