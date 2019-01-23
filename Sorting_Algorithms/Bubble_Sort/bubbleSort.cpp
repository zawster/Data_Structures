#include<iostream>
using namespace std;
void BubbleSort(int [],int);
void Swap(int*,int*);
int main(){
    int arr[]={64,4,25,12,10,22,11,24,3};
    int siz=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,siz);
    cout<<"Sorted array is : ";
    for(int i=0;i<siz;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
    return 0;
}
void BubbleSort(int arr[],int siz){
    int min;
    for(int i=0;i<siz;i++){
        for(int j=i;j<siz;j++){
            if(arr[i]>arr[j]){
                Swap(&arr[i],&arr[j]);
            }
        }
    }
}
void Swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
