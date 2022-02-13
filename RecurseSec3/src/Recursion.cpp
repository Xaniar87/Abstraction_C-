// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "strlib.h"
#include <stdio.h>
#include <vector.h>
using namespace std;

string writeChars(int n);
int evaluate(string st);
int evaluateHelper(string st, int& ind);
bool isMeasurable(int target, Vector<int>& weights);
//void isMeasurableHelper(Vector<int>& w, Vector<int>& left, Vector<int>& right, int ind);
void printBinary(int digits, string soFar);
void printBaseTen(int digits, string soFar);
int sumVec(Vector<int> vec);
int waysToClimb(int steps);
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
int numCalls=0;
int main()
{
    cout << "waysToClimb(steps-1): "<<waysToClimb(4)<<endl;
//    printBaseTen(2,"");
    //    for (int i=0;i<10;i++){
//        cout << writeChars(i)<< endl;
//    }
//    cout << evaluate("(((1+2)*(5+9))+7)")<<endl;
//    printBinary(2,"");
//    Vector<int> vec;
//    vec.add(3);
//    vec.add(4);
//    vec.add(6);
//    vec.add(8);
//    vec.add(9);
//    cout<< "isMeasurable(5,vec): "<<isMeasurable(5,vec)<<endl;
//    cout <<"numCalls: "<< numCalls <<endl;
    return 0;
}


int waysToClimb(int steps) {
    if(steps==0){
        return 1;
    }else if(steps<0){
        return 0;
    }else{
        return waysToClimb(steps-1) + waysToClimb(steps-2);
    }
}

bool isMeasurable(int target, Vector<int>& weights) {
    numCalls++;
    if (weights.isEmpty()) {
        return target == 0;
    }
    int first = weights[0];
    Vector<int> rest = weights; // need to use a copy!
    rest.remove(0);
    return isMeasurable(target, rest)
            || isMeasurable(target-  first, rest)
            || isMeasurable(target + first, rest);
}

//void isMeasurable(int target,Vector<int>& w){
//    Vector<int> left;
//    left.add(target);
//    Vector<int> right;
//    isMeasurableHelper(w,left,right,0);
//    cout <<"numCalls: "<< numCalls <<endl;
//}

//void isMeasurableHelper(Vector<int>& w, Vector<int>& left, Vector<int>& right, int ind){
////&& sumVec(left)<sumVec(w)-sumVec(left)+left[0]
////    cout << "isMeasurableHelper(left="<< left <<",           right="<<right<<",       w="<<w  <<")"<<endl;
//    numCalls++;
//    if(!w.isEmpty() && sumVec(left)-sumVec(right)<sumVec(w)){
//        Vector<int> oldleft=left;
//        int s=w[0];
//        left.add(s);
//        w.remove(0);
//        isMeasurableHelper(w,left,right,ind);
//        w.insert(0,s);
//        left=oldleft;

//        Vector<int> oldRight=right;
//        int ss=w[0];
//        right.add(ss);
//        w.remove(0);
//        isMeasurableHelper(w,left,right,ind);
//        w.insert(0,s);
//        right=oldRight;

//        int sss=w[0];
//        w.remove(0);
//        isMeasurableHelper(w,left,right,ind);
//        w.insert(0,sss);

//        if(sumVec(left)==sumVec(right)){
//            cout <<"====================== left="<< left.toString() <<", right="<<right.toString()<<"======================"<< endl;
//        }

//    }
//}

int sumVec(Vector<int> vec){
    int sum=0;
    for(int el:vec){
        sum+=el;
    }
    return sum;
}
void printBinary(int digits, string soFar){
    cout << "printBinary("<<digits<<", \""<<soFar<<"\")"<<endl;
    if(digits<1){
        cout << soFar <<endl;
    }else{
        printBinary(digits-1,soFar+"0");
        printBinary(digits-1,soFar+"1");


    }
}
void printBaseTen(int digits, string soFar){
    cout << "printBaseTen("<<digits<<", \""<<soFar<<"\")"<<endl;
    if(digits<1){
        cout << soFar <<endl;
    }else{
        for (int i=0;i<10;i++){
            printBaseTen(digits-1,soFar+integerToString(i));
        }
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
