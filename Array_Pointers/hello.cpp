#include<iostream>

using namespace std;
class test{
    private:
        int *ptr;
        int *current,*temp;
        int arr[8];
        int siz,total;
    public:
        test(){
            temp=current=ptr=NULL;
            siz=5;
            ptr=&arr[0];
            for(int i=0; i<5; i++){
                cin>>*ptr;
                temp=ptr;
                ptr=ptr+1;
            }
           // cout<<"_______"<<endl;
            ptr=arr;

           // print();
            current=&arr[2];
        }

        void print(){
            for(int i=0 ; i<8 ; i++){
                cout<<*ptr<<",";
                ptr=ptr+1;
            }
            ptr=arr;
            cout<<endl;
        }

        void add(int x){
            cout<<"-------------------"<<endl;
            while(temp!=current){
                *(temp+1)=*temp;
                temp=temp-1;
            }
            *(temp+1)=x;
            current=temp+1;
            siz=siz+1;
            //cout<<"-----"<<*temp<<"---"<<endl;
            //print();

        }
        void next(){
            //total=sizeof(arr)/sizeof(*arr);
            if(current != &arr[siz]){
                current=current+1;
                cout<<"next value of current is "<<*current<<endl;
            }
        }

        void back_(){
            if(current!=arr){
                current=current-1;
                cout<<"back value of current is "<<*current<<endl;
            }
            else{
               cout<<"Current is at the start it has no back value"<<endl;
            }
        }

        void Remove(){
            int l=0;
            ptr=arr;
            temp=NULL;
            for( int i=0; i<total; i++ ) {
                //if( arr[i] != *current )
                //  arr[l++]=arr[i];
                if(ptr==current){
                    l++;
                    //temp=ptr+l;
                    //*ptr = *temp;
                    *ptr=*(ptr+l);
                    *(ptr+1)=NULL;
                    current=current-1;
                    //cout<<*current<<"-----"<<*temp<<endl;
                }
                else
                    ptr++;
                }
            ptr=arr;
            siz=siz-1;
            //cout<<"----"<<*current<<"....."<<*ptr<<endl;
            print();
        }
        bool find_(int x){
            temp=ptr;
            for(int i=0;i<siz;i++){
                if(*temp==x){
                    return true;
                }
                temp=temp+1;
            }
            return false;
        }
        int get(){
            cout<<"current is at "<<*current<<endl;
            return *current;
        }

        void update(int x){
            *current=x;
        }

        void start(){
            current=ptr;
            cout<<"Current is at the start : "<<*current<<endl;
        }

        void end_(){
            current=&arr[siz];
            cout<<"end value of array is "<<*current<<endl;
        }

        void length(){
            cout<<"length of an array is "<<siz<<endl;
        }

};
int main(){
    test obj;
    obj.add(9);
    obj.get();
    obj.next();
    obj.back_();
    obj.Remove();
    obj.update(8);
    obj.length();

    cout<<obj.get()<<endl;

    if(obj.find_(3))
        cout<<"Desired value is found"<<endl;
    else
        cout<<"Desired value is not found"<<endl;

    obj.end_();
    obj.start();

    return 0;
}