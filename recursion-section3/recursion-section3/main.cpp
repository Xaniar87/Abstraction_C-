
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

string writeChars(int n);
int evaluate(string st);
int evaluateHelper(string st, int& ind);
bool isMeasurable(int target, vector<int>& weights);
int isMeasurableHelper(int target, vector<int>& weights, int& ind);

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
int main()
{
//    for (int i=0;i<10;i++){
//        cout << writeChars(i)<< endl;
//    }
//    cout << evaluate("(((1+2)*(5+9))+7)")<<endl;
    vector<int> vec={3,5};
    cout << isMeasurable(2,vec) <<endl;
    return 0;
}
bool isMeasurable(int target, vector<int>& weights) {
    int ind=0;
    if(isMeasurableHelper(target,weights,ind)==1){
        return true;
    }
    return false;
}

int isMeasurableHelper(int target, vector<int>& weights, int ind){
    cout << "target: "<< target<< " ind: " <<ind<< endl;
    if(ind < 2){
        int left=isMeasurableHelper(target+weights[ind],weights,ind+1);
        cout << "left: "<< left<< endl;
        int right=isMeasurableHelper(target+weights[ind],weights,ind+1);
        cout << "right: "<< right<< endl;

        if(left==right){
            return 1;
        }
        return 1;
    }else{
        return target;
    }
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


int evaluate(string st){
    int ind=0;
    return evaluateHelper(st,ind);
}
int evaluateHelper(string st, int& ind){
    cout << "st: "<< st <<endl;
    if(st[ind]=='('){
        ind++;
        int left=evaluateHelper(st,ind);
        cout << "left: "<<left<<endl;
        ind++;
        char opr=st[ind];
        cout << "opr: "<<opr<<endl;
        ind++;
        int right=evaluateHelper(st,ind);
        cout << "right: "<<right<<endl;

        ind++;

        if(opr=='+'){
            return left+right;
        }else{
            return left*right;
        }
    }else{
        return st[ind]-'0';
    }
}
