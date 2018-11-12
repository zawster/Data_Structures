#include<iostream>
using namespace std;
class Stack{
    private:
        int *top,*arr,*temp,Tsize,Count;
    public:
        Stack(){
            /*
            cout<<"Enter the size of Stack:";
            cin>>Tsize;
            */
            Tsize=5;
            arr=new int[Tsize];
            Count=0;
            top=NULL;
        }
        void push(int x){
            if(Count==Tsize){
                cout<<"Stack is Full already";
                return;
            }
            if(top==NULL){
                top=arr;
                *top=x;
                Count++;
                return ;
            }
            temp=top+1;
            *temp=x;
            top=temp;
            Count+=1;
        }
        void pop(){
            if(Count==0){
                cout<<"Stack Underflow Occured";
                return;
            }
            *top=0;
            top=top-1;
            Count-=1;
        }
        void print(){
            temp=arr;
            for(int i=0;i<Tsize;i++){
                cout<<*temp<<"  ";
                temp=temp+1;
            }
            cout<<endl;
        }
};
int main(){
    Stack obj;
    obj.push(3);
    obj.push(2);
    obj.push(5);
    obj.print();
    obj.pop();
    obj.print();
    return 0;
}
