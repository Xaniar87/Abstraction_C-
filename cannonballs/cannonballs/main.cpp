#include <stdio.h>
#include <iostream>
using namespace std;

int cannonballs(int height);
string reverse(string st);
int main()
{
    cout << cannonballs(5) << endl;
    cout << reverse("abc") << endl;

    return 0;
}

int cannonballs(int height){
    if(height==1){
        return 1;
    }else{
        return height*height+cannonballs(height-1);
    }
}

string reverse(string st){
    if(st.length()<1){
        return (st);
    }else{
        return (reverse(st.substr(1,st.length())))+st[0];
    }
}



