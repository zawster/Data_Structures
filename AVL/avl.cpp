#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
    int bf;
};
class AVL{
    private:
        Node *temp,*temp1;
    public:
        int number;
        Node *root;
        AVL(){
            root=temp=temp1=NULL;
        }
        void Insert(Node *);
        void InOrder(Node *);
        int height(Node *);
};
//
//      Height Function
//
int AVL::height(Node *temp){
    if(temp == NULL){
        return 0;
    }
    else{
        return max(height(Node->left), height(Node->right)) + 1;
    }
}

//
//      Insert Function
//
void AVL::Insert(Node *temp){
    if(temp->info==number){
        cout<<"Value already exist!"<<endl;
        return;
    }
    if(temp==NULL){
        temp=new Node;
        temp->info=number;
        temp->left=NULL;
        temp->right=NULL;
        temp->bf=0;
    }
    if(temp->info > key){
        if(temp->left != NULL){
            Insert(temp->left);
        }
        else{
            if()
        }
    }

   
}
//
//      Inorder Function
//
void AVL::InOrder(Node *temp){
    if(temp==NULL){
        cout<<"Tree is empty!"<<endl;
        return;
    }
    if(temp->left != NULL){
        InOrder(temp->left);
    }
    cout<<temp->info<<"  ";
    if(temp->right != NULL){
        InOrder(temp->right);
    }
    return;
}
int main(){
    
    return 0;
}