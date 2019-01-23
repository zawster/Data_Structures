#include<iostream>
using namespace std;
void Swap(int *,int *);
void SlectionSort(int [],int);
int main(){
    int arr[]={14,33,27,10,35,19,44,42};
    int siz=sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted array : ";
    for(int i=0;i<siz;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    SlectionSort(arr,siz );
    cout<<"Sorted array : ";
    for(int i=0;i<siz;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
void SlectionSort(int arr[], int siz){
    int min=0;
    
    for(int i=0;i<siz-1;i++){
        min=i;
        for(int j=i+1; j<siz;j++){
            if(arr[min] > arr[j]){
                min=j;
            }
        }
        Swap(&arr[min],&arr[i]);
    }
}
void Swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}