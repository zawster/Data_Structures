#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
};
class Ring{
    private:
        Node *head,*temp,*temp2;
    public:
        Ring(){
            head=temp=temp2=NULL;
        }
//  Insert Node at very start
        void Insert_start(int val){
             if(head==NULL){
                head=new Node;
                head->info=val;
                head->next=head;
                return;
            }
            temp2=head;
            while(temp2->next!=head){
                temp2=temp2->next;
            }
            temp=new Node;
            temp->info=val;
            temp->next=head;
            temp2->next=temp;
            head=temp;

        }

//  Insert Node at very end
        void Insert_end(int val){
            if(head==NULL){
                head=new Node;
                head->info=val;
                head->next=head;
                return;
            }
            temp=head;
            if(temp->next==head){
                temp2=new Node;
                temp2->info=val;
                temp2->next=head;
                temp->next=temp2;
                return;
            }
           // temp=temp->next;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp2=new Node;
            temp2->info=val;
            temp2->next=head;
            temp->next=temp2;

        }
//  Insert Node at very Cnetre
        void Insert_Centre(int key,int val){
            temp=head;
            while(temp->next!=head){
                if(temp->info==key){
                    temp2=new Node;
                    temp2->info=val;
                    temp2->next=temp->next;
                    temp->next=temp2;
                    return;
                }
                temp=temp->next;
            }
        }
//
//      Deletion of Nodes
//
        void Delete_Start(){
            temp=temp2=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            head=temp2->next;
            temp->next=head;
            delete temp2;
        }

        void Delete_End(){
            temp=head;
            while(temp->next!=head){  //  (temp->next->next != head)
                temp2=temp;
                temp=temp->next;
            }
            temp2->next=head;
            delete temp;        // delete temp->next;
        }

        void Delete_Centre(int key){
            temp=head;
            while(temp->next!=head){

                if(temp->info==key)
                    break;
                temp2=temp;
                temp=temp->next;
            }
            temp2->next=temp->next;
            delete temp;
            return;

        }

         void Print(){
            temp=head;
            while(temp->next!=head){
                cout<<temp->info<<"  ";
                temp=temp->next;
            }
            cout<<temp->info<<"  ";

        }

        ~Ring(){
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
    Ring obj;
  /*  obj.Insert_start(4);
    obj.Insert_start(2);
    obj.Insert_start(1);
    //obj.Insert_end(3);
    */
    obj.Insert_end(5);
    obj.Insert_end(7);

    //obj.Insert_Centre(5,6);
    //obj.Insert_Centre(2,3);
//  dlete start Node
    //obj.Delete_Start();
//  delet end Node
    //obj.Delete_End();
//  Delete centre nod
    //obj.Delete_Centre(7);

    obj.Print();
    return 0;
}
