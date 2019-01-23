#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
    int lh;
    int c;
};
class Heap{
    private:
        int h,count,flg,flg1;
        Node *temp,*temp2;
    public:
        Node *root;
        int value;
        Heap(){
            root=temp=temp2=NULL;
            count=h=value=flg=flg1=0;
        }
        void Insert(Node *);
        void Inorder(Node *);
        void Delete(Node *);
        void minHeap(Node *);
};
//  
//      Insert new Node
//
void Heap::Insert(Node *temp){
    flg=0;
    if(root==NULL){
        temp=new Node;
        temp->info=value;
        temp->left=temp->right=NULL;
        temp->lh=0; temp->c=1;
        root=temp;
        count+=1;
        return;
    }
    if(temp->info > value){
        swap(temp->info,value);
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
        count+=1;
        temp->left->lh=h;
        temp->left->c=count;
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
        temp2->c=count;
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
        temp2->c=count;
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
void Heap::Inorder(Node *temp){
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
//    Min heap  deletion
//
void Heap::Delete(Node *temp){
    flg1=0;
    if(temp==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(h<=1 && count<=3){
        if(temp->left==NULL && temp->right==NULL){
            delete temp;
            temp=NULL;
            root=NULL;
            count-=1;
            return;
        }
        if(temp->left->info < temp->right->info){
            swap(temp->left->info,temp->right->info);
            swap(temp->right->info,temp->info);
            delete temp->right;
            temp->right=NULL;
            count-=1;
            return;
        }
        if(temp->right == NULL){
            swap(temp->info,temp->left->info);
            delete temp->left;
            temp->left=NULL;
            count-=1;
            h-=1;
            return;
        }
    }
   if(temp->left!= NULL && flg1 != 1){
       temp2=temp;
       Delete(temp->left);
   }
   if(temp->lh == h && temp->c == count){
        swap(root->info,temp->info);
        if(temp2->left == temp){
            temp2->left=NULL;
        }
        else if(temp2->right == temp){
            temp2->right=NULL;
        }
        delete temp;
        temp=temp2;
        count-=1;
        if(count==pow(2,h+1)-1){
            h-=1;
        }
        flg1=1;
        cout<<"Working"<<endl;
        return;
   }
   if(temp->right != NULL && flg1 != 1){
       temp2=temp;
       Delete(temp->right);
   }
   return;
}
void Heap::minHeap(Node *temp){
    if(temp==NULL){
        cout<<"Tree is empty "<<endl;
        return;
    }
    
    if(temp->left != NULL){
        if(temp->info > temp->left->info){
            swap(temp->info,temp->left->info);
        }
        temp2=temp;
        minHeap(temp->left);
    }
    
    if(temp->right != NULL){
        if(temp->info > temp->right->info){
            swap(temp->info,temp->right->info);
        }
        temp2=temp;
        minHeap(temp->right);
    }
    if(temp2->info > temp->info){
            swap(temp2->info,temp->info);
    }
    return;
}
int main(){
    Heap obj;
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
    obj.value=1;
    obj.Insert(obj.root);
    obj.value=8;
    obj.Insert(obj.root);
    obj.value=7;
    obj.Insert(obj.root);
   /* obj.value=19;
    obj.Insert(obj.root);
    obj.value=10;
    obj.Insert(obj.root);
    */
    obj.Delete(obj.root);
    obj.Delete(obj.root);
    //obj.Delete(obj.root);
    //obj.minHeap(obj.root);
    //   Traverse
    obj.Inorder(obj.root);
    cout<<endl;
    return 0;
}
