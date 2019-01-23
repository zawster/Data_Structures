#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
    string lth;
    string rth;
};
//
//      main Class
//
class thrdBinaryTree{
    private:
        Node *temp,*temp2;
    public:
        Node *root,*dummy;
        int key;        //  key to be deleted
        int value;      //  value to be insert
        string chld;    //  for child thread
        string thrd;    //  for thread
        thrdBinaryTree(){
            chld="child";
            thrd="thread";
            root=temp=temp2=NULL;
            dummy=new Node;
            dummy->info=-01;
            dummy->left=dummy;
            dummy->right=dummy;
            dummy->lth=thrd;
            dummy->rth=chld; 
        }
        void Insert(Node *);
        Node* nextInorder(Node *);
        void fastInorder(Node *);
        void Delete(Node *);
        Node* ImidiateSuccessor(Node *);
};
//
//      Insert new node
//
void thrdBinaryTree::Insert(Node *temp){
    if(root==NULL){
        root=new Node;
        root->info=value;
        dummy->left=root;
        root->left=dummy;
        root->right=dummy;
        root->lth=thrd;
        root->rth=thrd;
        dummy->lth=chld;
        temp=root;
        return;
    }
    if(temp->info==value){
        cout<<value<<" is already exist in Tree. "<<endl;
        return;
    }
    
    if(temp->info > value){     //   Insert in Left
        if(temp->lth != thrd){
            Insert(temp->left);
            return;
        }
        else{
            temp2 =new Node;
            temp2->info=value;
            temp2->left=temp->left;
            temp2->right=temp;
            temp2->lth=thrd;
            temp2->rth=thrd;
            temp->left=temp2;   // Assigning new node in left of temp
            temp->lth=chld;
            return;
        }
    }
    if(temp->info < value){     //   Insert in right
        if(temp->rth != thrd){
            Insert(temp->right);
            return;
        }
        else{
            temp2=new Node;
            temp2->info=value;
            temp2->left=temp;
            temp2->right=temp->right;
            temp2->lth=thrd;
            temp2->rth=thrd;
            temp->right=temp2;  // Assigning new node in right of temp
            temp->rth=chld;
            return;
        }
    }
    
}
//
//      Inorder traversal
//
void thrdBinaryTree::fastInorder(Node *temp){

    if(temp->left!=dummy){
        while((temp=nextInorder(temp)) != dummy){
            cout<<temp->info<<" , "<<temp->left->info<<" , "<<temp->right->info<<endl;
        }
    }
    else{
        cout<<"Tree is empty"<<endl;
    }
    
}
//
//      find imediate sucessor
//
Node* thrdBinaryTree::nextInorder(Node *temp){
    if(temp->rth == thrd){
        return temp->right;
    }
    else{
        temp=temp->right;
        while(temp->lth == chld){
            temp=temp->left;
        }
        return temp;
    }
}
//
//      Delete Node
//
void thrdBinaryTree::Delete(Node *temp){
    if(root==NULL){     //  Tree is empty
        cout<<"Tree is empty."<<endl;
        return;
    }
    /*
     /   Delete from Root
    */
    if(temp->info==key){    //  deletion of root
        if(temp->lth==thrd && temp->rth==thrd){     //  only one node exist
            dummy->left=temp->left;
            dummy->lth=thrd;
            delete temp;   
            root=NULL;
            return;
        }
        if(temp->lth != thrd && temp->rth == thrd){ // root has only one left Node
            dummy->left=temp->left;
            if(temp->left->rth != thrd){
                temp2=temp->left->right;
                while(temp2->rth != thrd){
                    temp2=temp2->right;
                }
                temp2->right=dummy->left;
            }
            delete temp;
            temp2=NULL;
            return;
        }
        if(temp->lth == thrd && temp->rth != thrd){
            dummy->left=temp->right;
            if(temp->right->lth != thrd){
                temp2=temp->right->left;
                while(temp2->lth != thrd){
                    temp2=temp2->left;
                }
                temp2->left=dummy->left;
            }
            delete temp;
            temp2=NULL;
            return;
        }
        else{
            temp2=ImidiateSuccessor(temp->right);
            swap(temp->info,temp2->left->info);
            key=temp2->left->info;
            Delete(temp2);
            return;
        }

    }
     /*
     /   Delete from Left Subtree
    */
    if(temp->info > key ){      // delete from left
        if(temp->lth != thrd){
            if(temp->left->info==key){  // Value is found
                temp2=temp->left;
                if(temp2->lth==thrd && temp2->rth==thrd){   // node is leaf
                    temp->left=temp2->left;
                    temp->lth=temp2->lth;
                    delete temp2;
                    temp2=NULL;
                    return;
                }
                else if(temp2->lth != thrd && temp2->rth==thrd){// only has one left child Node
                    temp->left=temp2->left;
                    //temp2->left->rth=temp2->rth;
                    if(temp2->left->rth == thrd){
                        temp2->left->right=temp2->right;
                        delete temp2;
                    }
                    else if(temp2->left->rth != thrd){
                        temp2=temp2->left;
                        while(temp2->rth != thrd){
                            temp2=temp2->right;
                        }
                        delete temp2->right;
                        temp2->right=temp;
                    }

                    return;
                }
                else if(temp2->lth == thrd && temp2->rth != thrd){ // only has one right child Node
                    temp->left=temp2->right;
                    temp2->right->lth=temp2->lth;
                    temp2->right->left=temp2->left;
                    delete temp2;
                    return;

                }
                else{   //  Node has 2 child
                    if(temp2->right->rth == thrd && temp2->right->lth == thrd){
                        swap(temp2->info,temp2->right->info);
                        temp2->rth=temp2->right->rth;
                        Node *temp1= temp2->right;
                        temp2->right=temp1->right;
                        delete temp1;
                        temp1=NULL;
                        return;
                    }
                    if(temp2->right->rth != thrd && temp2->right->lth == thrd){
                        swap(temp2->info,temp2->right->info);
                        Node *t=temp2->right;
                        temp2->right=t->right;
                        if(t->right->lth == thrd){
                            t->right->left=t->left;
                        }
                        else{
                            Node *te=ImidiateSuccessor(t->right);
                            te->left=t->left;
                        }
                        delete t;
                        t=NULL;
                        return;
                    } 
                    else{
                        Node *temp1=ImidiateSuccessor(temp2->right);
                        swap(temp2->info,temp1->left->info);
                        key=temp1->left->info;
                        Delete(temp1);
                        return;
                    }

                }//case 3 of root end here

            }
            else{
                Delete(temp->left);
                return;
            }
        }
        else{
            cout<<"value not exist left"<<endl;
        }
        
        
    }
        // end of left deletion

    if(temp->info < key ){      // delete from right
        if(temp->rth != thrd){
            if(temp->right->info==key){     //   Value found
                temp2=temp->right;
                if(temp2->lth==thrd && temp2->rth==thrd){   //  Case-1 Node is leaf
                    temp->right=temp2->right;
                    temp->rth=temp2->rth;
                    delete temp2;
                    temp2=NULL;
                    return;
                }
                if(temp2->lth != thrd && temp2->rth == thrd){   // only has one left child Node
                    temp->right=temp2->left;
                    temp2->left->rth=temp2->rth;
                    temp2->left->right=temp2->right;
                    if(temp2->right->rth==thrd){
                        temp2->right->right=temp2->right;
                    }
                    delete temp2;
                    temp2=NULL;
                    return;
                }
                if(temp2->lth ==  thrd && temp2->rth != thrd){  // only has one right child Node
                    temp->right=temp2->right;
                    delete temp2;
                    temp2=temp->right;
                    while(temp2->lth != thrd){
                        temp2=temp2->left;
                    }
                    temp2->left=temp;
                    return;
                }
                else{
                    if(temp2->right->rth == thrd && temp2->right->lth == thrd){
                        swap(temp2->info,temp2->right->info);
                        Node *t=temp2->right;
                        temp2->right=t->right;
                        temp2->rth=t->rth;
                        delete t;
                        t=NULL;
                        return;
                    }
                    if(temp2->right->rth != thrd && temp2->right->lth==thrd){
                        swap(temp2->info,temp2->right->info);
                        Node *t=temp2->right;
                        temp2->right=t->right;
                        if(t->right->lth == thrd){
                            t->right->left=temp2;
                        }
                        else{
                            Node *t2=ImidiateSuccessor(t->right);
                            t2->left->left=temp2;
                        }
                        delete t;
                        t=NULL;
                        return;
                    }
                    else{
                        Node *temp1=ImidiateSuccessor(temp2->right);
                        swap(temp2->info,temp1->left->info);
                        key=temp1->left->info;
                        Delete(temp1);
                        return;
                    }
                }
            }
            else{
                Delete(temp->right);
                return;
            }
        }
        else{
            cout<<"Value not exist in right"<<endl;
        }
    }   // end of right deleteion
// end of function
}
Node* thrdBinaryTree::ImidiateSuccessor(Node *temp){
        while(temp->left->lth!=thrd){
            temp=temp->left;
        }    
        return temp;    
}
//
//      main function
//
int main(){
    thrdBinaryTree obj;
    obj.value = 10;
    obj.Insert(obj.root);
    obj.value=8;
    obj.Insert(obj.root);
    obj.value=9;
    obj.Insert(obj.root);
    obj.value=14;
    obj.Insert(obj.root);
    obj.value=12;
    obj.Insert(obj.root);
    obj.value=9;
    obj.Insert(obj.root);
    obj.value=11;
    obj.Insert(obj.root);
    obj.value=15;
    obj.Insert(obj.root);
    obj.value=13;
    obj.Insert(obj.root);
   
    obj.fastInorder(obj.dummy);
    cout<<endl;
    obj.key=8;
    obj.Delete(obj.root);
    obj.fastInorder(obj.dummy);
    cout<<endl;
    return 0;
}
