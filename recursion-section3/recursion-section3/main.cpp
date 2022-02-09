
#include <stdio.h>
#include <iostream>
using namespace std;

string writeChars(int n);
int main()
{
    for (int i=0;i<10;i++){
        cout << writeChars(i)<< endl;
    }

    return 0;
}

string writeChars(int n) {
    if(n==0){
        return "";
    }else if(n==1){
        return "*";
    } else if(n==2){
        return "**";
    }else{
        return "<"+writeChars(n-2)+">";
    }
}
