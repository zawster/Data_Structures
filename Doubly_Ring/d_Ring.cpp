#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
    Node *previous;
};
class dRing{
    private:
        Node *head,*temp,*temp2;
    public:
        dRing(){
            head=temp=temp2=NULL;
        }
//  Insert Node at the start of Ring
        void Insert_Start(int val){
            if(head==NULL){
                head=new Node;
                head->info=val;
                head->next=head;
                head->previous=head;
                return;
            }
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp2=new Node;
            temp2->info=val;
            temp2->next=head;
            temp2->previous=temp;
            temp->next=temp2;
            head=temp2;
        }
//  Insert Node at the end of Ring
        void Insert_End(int val){
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp2=new Node;
            temp2->info=val;
            temp2->next=head;
            temp2->previous=temp;
            head->previous=temp2;
            temp->next=temp2;

        }
//  Insert Node at the centre of Ring
        void Insert_Centre(int key, int val){
            temp=head;
            while(temp->next!=head){
                if(temp->info==key){
                    temp2=new Node;
                    temp2->info=val;
                    temp2->next=temp->next;
                    temp2->previous=temp;
                    temp->next=temp2;
                }
                temp=temp->next;
            }
        }
//  Deletetion of the starting Node
        void Delete_Start(){
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp2=head;
            head=head->next;
            head->previous=temp;
            temp->next=head;
            delete temp2;
        }
//  Deletion the last Node
        void Delete_End(){
            temp=head->previous;
           temp->previous->next=head;
           head->previous=temp->previous;
           // temp->previous=temp->next=NULL;
           delete temp;
           temp=NULL;
        //   cout<<head->info<<" | "<<head->previous->info<<endl;

        }

//  Deletion from centre
        void Delete_Centre(int key){
            temp=head;
            bool check;
            if(temp->info==key){
                temp2=head;
                head->previous->next=head->next;
                head->next->previous=head->previous;
                head=head->next;
                delete temp;
                return;
            }
            while(temp->next!=head){
                if(temp->info==key){
                    check=true;
                    break;
                }
                temp2=temp;
                temp=temp->next;
            }
                   // cout<<endl<<temp->previous->info<<endl;
            if(check){
               /* temp2->next=temp->next;
                temp->next->previous=temp2;
                delete temp;*/

                temp->next->previous=temp->previous;
                temp=temp->next;
                delete temp->previous->next;
                 temp->previous->next=temp;
               // temp=NULL;
            }
        }

//  Print the list
        void Print(){
            temp=head;
            while(temp->next!=head){
                cout<<temp->info<<" ";
                temp=temp->next;
            }
            cout<<temp->info<<" ";
        }
        ~dRing(){
            temp=head;
            while(temp->next!=head){
                temp2=temp;
                temp=temp->next;
                delete temp2;
            }
            delete temp;
            head=temp=temp2=NULL;
        }


};
int main(){
    dRing obj;
    obj.Insert_Start(5);
    obj.Insert_Start(2);
    obj.Insert_Start(3);

    obj.Insert_End(6);
   // obj.Insert_Centre(3,7);

    //obj.Delete_Start();

   // obj.Delete_End();
    //obj.Delete_End();

    obj.Delete_Centre(6);
    //obj.Delete_Centre(3);

     obj.Print();
    return 0;
}
