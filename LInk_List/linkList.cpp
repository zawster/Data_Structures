#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *link;
};
class Link_List{
    private:
        Node *head,*temp,*temp2;
    public:
        Link_List(){
            head=temp=temp2=NULL;

        }

        void Insert_End(int x){
            if(head==NULL){
                head=new Node;
                head->info=x;
                head->link=NULL;
                return;
            }

                temp=head;

                while(temp->link != NULL){
                    temp=temp->link;
                }

                temp->link=new Node();
                temp->link->info=x;
                temp->link->link=NULL;
        }
        void Insert_Start(int x){
            temp=new Node;
            temp->info=x;
            temp->link=head;
            head=temp;
        }

        void Insert_Center(int loc,int x){
            temp=head;
            temp2=new Node;
            temp2->info=x;
            while(temp != NULL){
                if(temp->info == loc){
                    temp2->link=temp->link;
                    temp->link=temp2;
                    break;
                }
                temp=temp->link;
            }
        }

        void Search(int x){
            temp=head;
            while(temp!=NULL){
                if(temp->info==x){
                    cout<<"Value is Found..:"<<endl;
                    return;
                }
                temp=temp->link;
            }
            cout<<"Value is Not-Found..:"<<endl;

        }

        void Delete_Start(){
            if(head->link==NULL){
                delete head;
                head=NULL;
            }
            else{
                temp=head;
                head=temp->link;
                delete temp;
            }
        }

        void Delete_End(){
            temp=head;
            while(temp->link!=NULL){
                temp2=temp;
                temp=temp->link;
            }
            temp2->link=NULL;
            delete temp;
        }

        void Delete_Centre(int x){
            temp=head;
            while(temp->link!=NULL){
                if(temp->link->info==x){
                    temp2=temp->link;
                    temp->link=temp2->link;
                    delete temp2;
                    break;
                }
                temp=temp->link;
            }
        }

        void Print(){
            temp=head;
            while(temp!=NULL){
                cout<<temp->info<<" , ";
                temp=temp->link;
            }
        }

        ~Link_List(){
            temp=head;
            while(temp->link!=NULL){
                temp2=temp;
                temp=temp->link;
                delete temp2;
            }
            delete temp;
            head=temp=temp2=NULL;
        }
};

int main(){
    Link_List obj;
    //      Insert Node at the End
    obj.Insert_End(2);
    obj.Insert_End(3);
    obj.Insert_End(5);
    //      Insert Node at the Start
    obj.Insert_Start(1);
    //      Insert Node in the Center
    obj.Insert_Center(3,4); // (after , value)
    //      Dlete   Start , End and Centre
    obj.Delete_Start();
    obj.Delete_End();
    obj.Delete_Centre(2);
    //      Search a specific Node
    obj.Search(2);
    obj.Print();
	return 0;
}
// Iterative C++ program to reverse an array
/* Function to reverse arr[] from start to end*/


/* Driver function to test above functions */

