#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
    Node *previous;
};
class Doublely_List{
    private:
        Node *head,*temp,*temp2;
    public:
        Doublely_List(){
            head=temp2=temp=NULL;
        }
        void Insert_Satrt(int val){
            temp2=new Node();
            temp2->info=val;
            temp2->previous=NULL;
            temp2->next=head;
            head->previous=temp2;
            head=temp2;

        }

        void Insert_End(int x){
            temp2=new Node();
            temp2->info=x;
            temp2->next=NULL;
            temp2->previous=NULL;
            if(head==NULL){
                head=temp2;
                return;
            }
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            //cout<<"  hi";

            temp->next=temp2;
            temp2->previous=temp;
            }
        void Insert_Centre(int key,int val){
            temp=head;
            while(temp->info!=key){
                temp=temp->next;
            }
            temp2=new Node();
            temp2->info=val;
            temp2->next=temp->next;
            temp2->previous=temp;
            temp->next=temp2;
        }
        void Dlete_Start(){
            temp=head;
            head=temp->next;
            head->previous=NULL;
            delete temp;
        }
        void Delete_End(){
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp2=temp->previous;
            temp2->next=NULL;
            delete temp;
        }
        void Delete_Centre(int key){
            temp=head;
            while(temp->next!=NULL){
                if(temp->info==key){
                  /*  temp2=temp->previous;
                    temp2->next=temp->next;
                    temp->next->previous=temp2;
                    delete temp;*/
                    temp->previous->next=temp->next;
                    temp->next->previous=temp->previous;
                    delete temp;
                    return;
                }
                temp=temp->next;
            }

        }

        void print(){
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            cout<<"Reverse DLL:"<<endl;
            while(temp!=NULL){
                cout<<temp->info<<" ";
                temp=temp->previous;
            }
           // cout<<temp->info;
            cout<<endl;
        }

        ~Doublely_List(){
            temp=head;
            while(temp->next!=NULL){
                temp2=temp;
                temp=temp->next;
                delete temp2;
            }
            delete temp;
            head=temp=temp2=NULL;
        }

};
int main(){
    Doublely_List obj;

    obj.Insert_End(4);
    obj.Insert_End(6);
    obj.Insert_End(7);
    //obj.Insert_End(8);
    obj.Insert_End(9);
    //obj.Insert_Satrt(1);
    //obj.Insert_Centre(4,5);
    //obj.Insert_Centre(6,7);
    //obj.Insert_Centre(1,2);
    //obj.Insert_Centre(2,3);


    //obj.print();
    //obj.Dlete_Start();
    //obj.Delete_End();
    obj.Delete_Centre(6);

    obj.print();
    return 0;
}
