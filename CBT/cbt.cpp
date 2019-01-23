#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
    int lh;
};
class CBT{
    private:
        int h,count,flg;
        Node *temp,*temp2;
    public:
        Node *root;
        int value;
        CBT(){
            root=temp=temp2=NULL;
            count=h=value=flg=0;
        }
        void Insert(Node *);
        void Inorder(Node *);
        ~CBT();
        void Destructor(Node *);
};
//  
//      Insert new Node
//
void CBT::Insert(Node *temp){
    flg=0;
    if(root==NULL){
        temp=new Node;
        temp->info=value;
        temp->left=temp->right=NULL;
        temp->lh=0;
        root=temp;
        count+=1;
        return;
    }
    if(temp->left != NULL){
        Insert(temp->left);
    }
    if(count == pow(2,h+1)-1){
        temp->left=new Node;
        temp->left->info=value;
        temp->left->left=NULL;
        temp->left->right=NULL;
        h+=1;
        temp->left->lh=h;
        count+=1;
        flg=1;
        return;
    }
    else if(temp->left != NULL && temp->right==NULL){
        temp2=new Node;
        temp2->info=value;
        temp2->right=NULL;
        temp2->left=NULL;
        temp2->lh=h;
        temp->right=temp2;   // Insert node in right side
        count+=1;
        flg=1;
        return;
    }
    else if(temp->lh==h-1 && temp->left==NULL && temp->right==NULL){
        temp2=new Node;
        temp2->info=value;
        temp2->left=NULL;
        temp2->right=NULL;
        temp2->lh=h;
        temp->left=temp2;
        flg=1;
        count+=1;
        return;
    }
    
    if(temp->right != NULL && flg != 1){
        Insert(temp->right);
    }  
    return;
}
//
//      Inorder traversal
//
void CBT::Inorder(Node *temp){
    if(temp==NULL){
        cout<<" Tree is empty."<<endl;
        return;
    }
    if(temp->left != NULL){
        Inorder(temp->left);
    }
    cout<<temp->info<<"  level="<<temp->lh<<endl;
    if(temp->right != NULL){
        Inorder(temp->right);
    }
    return;
}
//
//          Destructor
//
CBT::~CBT(){
    Destructor(root);
    root = NULL;
}
void CBT::Destructor(Node *temp){
    if(temp == NULL){
        cout<<"Tree is empty."<<endl;
        return;
    }
    if(temp->left != NULL){
        Destructor(temp->left);
    }
    if(temp->right != NULL){
        Destructor(temp->right);
    }
    delete temp;
    return;
}
//
//      Main function
//
int main(){
    CBT obj;
    obj.value=1;
    obj.Insert(obj.root);
    obj.value=8;
    obj.Insert(obj.root);
    obj.value=7;
    obj.Insert(obj.root);
    obj.value=19;
    obj.Insert(obj.root);
    obj.value=10;
    obj.Insert(obj.root);
    obj.value=12;
    obj.Insert(obj.root);
    obj.value=13;
    obj.Insert(obj.root);
    obj.value=14;
    obj.Insert(obj.root);
    obj.value=15;
    obj.Insert(obj.root);
    obj.value=17;
    obj.Insert(obj.root);

    //   Traverse
    obj.Inorder(obj.root);
    cout<<endl;
    return 0;
}
