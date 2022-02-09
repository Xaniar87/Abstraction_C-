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

using namespace std;
void find(string w1, string w2);
int main() {
    // TODO: Finish the program!


    cout << "Have a nice day." << endl;
    return 0;
}

void find(string w1, string w2){
//    Create an empty queue of stacks.
    Queue<Stack<string>> queueStack;
//    Create/add a stack containing {w1} to the queue.
    Stack<string> stack;
    stack.push(w1);
    queueStack.enqueue(stack);
    while(!queueStack.isEmpty()){

    }
}

/***
 * Finding a word ladder between words w1 and w2:
    Create an empty queue of stacks.
    Create/add a stack containing {w1} to the queue.
    While the queue is not empty:
        Dequeue the partial-ladder stack from the front of the queue.
        For each valid English word that is a "neighbor" (differs by 1 letter)
        of the word on top of the stack:
            If that neighbor word has not already been used in a ladder before:
                If the neighbor word is w2:
                    Hooray! we have found a solution.
                Otherwise:
                    Create a copy of the current partial-ladder stack.
                    Put the neighbor word on top of the copy stack.
                    Add the copy stack to the end of the queue.
 *
 * **/
