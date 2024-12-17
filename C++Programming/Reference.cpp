#include<iostream>
using namespace std;

int main(){

    int x = 10;
    int &refX = x;
    int y = 11;
    int& refY = y;;
    //int &ref2; its error because itis not initialized yet

    cout<<"x ="<<x<<endl<<"refX ="<<refX<<endl;

    cout<<"y ="<<y<<endl<<"refY  ="<<refY<<endl;


    refX = 100;
    cout<<"x ="<<x<<endl<<"refX  ="<<refX<<endl;
    return 0;
}