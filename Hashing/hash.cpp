#include<iostream>
using namespace std;
class Hash{
    private:
        int *arr,*temp;
        int index,count;
    public:
        int siz;
        Hash(){
            arr=NULL;
            siz=index=count=0;
            MakeArr(siz);
        }
        void MakeArr(int);
        void fillArr();
        void PrintArr();
        void Insert(int);
        void HashTable(int);
        int HashFunction(int);
        void Rehashing(int);
        bool Checking(int);
        ~Hash();
};
//||||||||||||||||||||||||||||||||||||||||||||||||||||
void Hash::Insert(int val){
    HashTable(val);
    return;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||
void Hash::HashTable(int val){
    index=HashFunction(val);
    if(Checking(count)){
        if(arr[index] == -1){
            arr[index]=val;
            count+=1;
        }
        else{
            int i=1;
            while (1){
                if(index+i == siz){    //  making circular array
                   index=0;
                   i=0;
                }
                if(arr[index+i] == -1){
                    arr[index+i]=val;
                    count+=1;
                    break;
                }
                i+=1;   
            }
        }
    }
    else{
        MakeArr(siz+siz);
        //Rehashing(val);
        count=0;
        HashTable(val);
         delete [] temp;
    }
    return;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||   
void Hash::Rehashing(int val){
    int i=0;
    int x=count=0;
    while(i<siz){
        x=temp[i];
        if( x != -1){
            index=HashFunction(x);
            arr[index]=x;
        }
        i+=1;
    }
    index=HashFunction(val);
    arr[index]=val;
    count+=1;
    delete [] temp;
    return;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||   
int Hash::HashFunction(int value){
    int rem=0;
    rem=value % siz;
    return rem;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||| 
bool Hash::Checking(int ind){
    int temp1=siz/2;
    if(ind+3 == siz){
        return false;        
    }
    else{
        return true;
    }
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||
 void Hash::MakeArr(int x){
     siz+=siz;
     temp=arr;
     arr=new int[x];    // make new array
     fillArr();
     return;
 }
 //|||||||||||||||||||||||||||||||||||||||||||||||||||
 void Hash::fillArr(){
    int* temp1=arr;
    int i=0;
    while(i < siz){
        *temp1=-1;   // default value
        i+=1;
        temp1 += 1;
    }
    return;
 }
//||||||||||||||||||||||||||||||||||||||||||||||||||||
void Hash::PrintArr(){
    int* temp1=arr;
    int i=0;
    while(i < siz){
        cout<<*temp1<<" ";
        i+=1;
        temp1 += 1;
    }
    cout<<endl;
    return;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||
Hash::~Hash(){
    count=0;
    delete [] arr;
    return;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||
int sizl;
int main(){
    sizl=5;
    Hash obj;
    obj.siz=sizl;

    //obj.siz=sizl;
    obj.fillArr();

    obj.Insert(50);
    obj.Insert(33);
    obj.Insert(101);
    obj.Insert(13);
    obj.Insert(23);
    obj.Insert(44);
     
   // obj.Insert(50);

    obj.PrintArr();
    return 0;
}
