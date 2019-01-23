#include<iostream>
using namespace std;
class Merge{
   private:
		int *arr;
		int tsize;
	public:
		
		void mergeSort(int , int*, int*);
		void merge(int , int*, int*);
        void Make(int* , int);

};
void Merge::Make(int* a,int s){
    arr=a;
    tsize=s;
}
void Merge::mergeSort(int size, int *start, int *end){
        if(size > 1){
            	// cout<<"size " <<size<<endl;
            int mid = size / 2;
            int size2 = size-mid; //  mid+1
            int *start1 = start;
            int *end1 = start+mid-1;    // 
            int *start2 = start+mid;
            int *end2 = end;
            mergeSort(mid, start1, end1);
            mergeSort(size2, start2, end2);
            merge(size2, start1, start2);

        }
}
void Merge:: merge(int size1, int *st1, int *st2)
{
	int flag = 0;
	// cout<<"count "<<"good"<<endl;
	for (int j = 0; j < size1; j++){
		int *start1 = st1;
		int *start2 = st2;
		for (int i = 0; i < size1; i++){
			
			if (*start2 < *start1){
				int temp = *start1;
				*start1 = *start2;
				*start2 = temp;
				start1++;
				start2++;
			}
			else{		
				start1++;
			}
			// cout<<"start1 "<<*start1<<" start2 :"<<*start2<<endl;
		}
	}

}


int main(){
    int arr[]={64,4,25,12,10,2,1,9,24,55};
    int siz=sizeof(arr)/sizeof(*arr);
    int *strt=arr;
    int *end=arr+(siz-1);
    cout<<*end<<endl;
    Merge obj;
    obj.Make(arr,siz);
    obj.mergeSort(siz,strt,end);
    for(int i=0;i<siz;i++){
        cout<<arr[i]<<" ";
    }
   cout<<endl;
    return 0;
}
