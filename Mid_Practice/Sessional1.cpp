#include<iostream>
using namespace std;
int pow(int,int);
int factorial(int);
void Question_1(){
    int sameL=0;
    int rept=0;
    int a[6]={2,45,5,7,4,53};
    int b[6]={52,7,5,6,4,45};
    int *ptr1=a;
    int *ptr2=b;


    for(int i=0;i<6;i++){
        //cout<<a[i]<<" : "<<b[i]<<endl;
        if(*ptr1==*ptr2){
            sameL+=1;
        }
        ptr1+=1;
        ptr2+=1;

    }
    ptr1=a;
    for(int i=0;i<6;i++){
        ptr2=b;
        for(int j=0;j<6;j++){
            if(*ptr1==*ptr2){
                //cout<<"Hjkl";
                rept+=1;
                break;
            }
            ptr2=ptr2+1;
        }
        ptr1+=1;
    }
    cout<<"Same Locations are : "<<sameL<<endl<<"Same numbers are : "<<rept;
}
/*
//
//  X - (X^3 / 2!) + (X^5 / 4!) - (X^7 / 6!) + (X^9 / 8!) - (X^11 / 10!) + ..................
//
*/
void Question3(){
    int x,n;
    double den,num,sum=0.0;
    cout<<"Enter the value of X : ";
    cin>>x;
    cout<<"Enter the value of N : ";
    cin>>n;
    if(n==1)  {cout<<x<<endl; return;}
    int chk=0;
    for(int i=1;i<=n;i++){
        num=pow(x,2*i-1);
        den=factorial(2*i-2);
        if(chk%2==0){
            sum=sum+ (num/den);
        }
        else if(chk%2==1){
            sum=sum-(num/den);
        }
        chk+=1;
    }
    cout<<"Required value is : "<<sum;

}
int pow(int x,int n){
    int sum=x;
    for(int i=1;i<n;i++){
        sum*=x;
    }
    return sum;
}
int factorial(int x){
    int res=1;
    for(int i=1;i<=x;i++){
        res*=i;
    }
    return res;
}
int main(){
    //Question_1();
    Question3();
    }
