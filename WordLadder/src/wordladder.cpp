// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include <queue.h>
#include <stack.h>
#include "strlib.h"
#include <set.h>
#include "filelib.h"

using namespace std;
void find(string w1, string w2);
Set<string> neigbhor(string word, Set<string> dictionary);
Set<string> dict();


int main() {
    find("ANGEL","deVil");
//    cout << "queueStack: "<< queueStack<<endl;
    cout << "Have a nice day." << endl;
    return 0;
}
void find(string w1, string w2){
    w1=toLowerCase(w1);
    w2=toLowerCase(w2);
    Set<string> dictionary=dict();
    cout << "word1: "<< w1 << " word2: "<< w2<<endl;
//    Create an empty queue of stacks.
    Queue<Stack<string>> queueStack;
//    Create/add a stack containing {w1} to the queue.
    Stack<string> stack;
    stack.push(w1);
    queueStack.enqueue(stack);
    Set <string> set;
//    While the queue is not empty:
    while(!queueStack.isEmpty()){
//        Dequeue the partial-ladder stack from the front of the queue.
        Stack<string> partialStack=queueStack.dequeue();
        string currWord=partialStack.peek();
//        For each valid English word that is a "neighbor" (differs by 1 letter) of the word on top of the stack:
        for(string word:neigbhor(currWord,dictionary)){
            if(!set.contains(word)){
                set.add(word);
//                cout << "word: "<< word<< endl;
                if(word==w2){
                    partialStack.push(word);
                    cout << partialStack<<endl;
                    cout << "Hooray! we have found a solution." << endl;
                    break;
                }else{
                    Stack<string> newStack=partialStack;
                    newStack.push(word);
                    queueStack.enqueue(newStack);
//                    cout << "queueStack.peek(): "<< queueStack.peek()<< endl;
                }
            }
        }
    }
}
Set<string> neigbhor(string word, Set<string> dictionary){
    Set<string> set;
//    cout << dictionary.contains("work")<< endl;
    string w=word;
    for(char r='a';r<='z';r++){
        for(int i=0;i<w.length();i++){
            w[i]=r;
//            cout<< "word in neigbhor: "<< w<<endl;
            if(dictionary.contains(w)){
                set.add(w);
//                cout<< "word in neigbhor: "<< word<<endl;
            }
            w=word;

        }
    }
    return set;
}
Set<string> dict(){
    ifstream infile;
    promptUserForFile(infile, "enter a Dictionary file name? example: smalldict1.txt  smalldict2.txt dictionary.txt");
//    infile=
    Set<string> dictionary;
    string line;
    while(getline(infile,line)){
        dictionary.add(toLowerCase(line));
    }
    return dictionary;
}

