#include<iostream>
using namespace std;
void test(int x, int y){
    if(y>=0){
        test(x,y-1);
        cout<<x<<" x "<<y<<" = "<<y*x<<endl;
    }
    
}
int main()
{
    test(3,12);
    return 0;
}
