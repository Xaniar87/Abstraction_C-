// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "random.h"
using namespace std;



void file2Map(int N, Map<string,vector<string>>& map);
string toString(vector<string>& arr);
string newWindow(string st, string newWord);
string randomStart(Map<string,vector<string>>& map);
void randomGen(string start, Map<string,vector<string>>& map, int num);
// ------------------------ the Main start here-----------------------------------
//--------------------------------------------------------------------------------
int main() {
    int numGram=3;
    int numWindow=80;
    Map<string,vector<string>> map;
    file2Map(numGram,map);
    string start=randomStart(map);
//    cout <<"start: "<<start<<endl;
    randomGen(start,map,numWindow);
    cout << endl<<"Exiting." << endl;
    return 0;
}


void randomGen(string start, Map<string,vector<string>>& map, int num){
    int count=0;
    string currWin=start;
    string fullText=currWin;
    vector<string> vec;
    while (count<num){
//        cout << "fullText: " <<fullText<<endl;
        while(!map.containsKey(currWin)){
          currWin=randomStart(map);
        }
        vec=map.get(currWin);
//        cout <<"vec: "<<toString(vec) <<endl;
        int ind=randomInteger(0,vec.size()-1);
//        cout << "ind: "<<ind<<endl;
        string newWord=vec[ind];
//        cout << "newWord: " << newWord <<endl;
        fullText+=" "+newWord;

        currWin=newWindow(currWin,newWord);
        count++;
    }
    cout << fullText<<endl;
}
void file2Map(int N, Map<string,vector<string>>& map){
    ifstream file;
    vector<string> window;
    int count =0;
    file.open("hamlet.txt");
//    promptUserForFile(infile,"enter file name");
    string word;
    while(file >> word){
        string key;
        vector<string> val;
        if(count<N){
            window.push_back(word);
        }else{
            key=toString(window);
            if(map.containsKey(key)){
                val=map.get(key);
            }
                val.push_back(word);
                map.put(key,val);
//            cout << toString(window)<< " --> "<<toString(val)<<endl;
            window.erase(window.begin());
            window.push_back(word);
        }
        count++;
    }
}
string randomStart(Map<string,vector<string>>& map){
    string firstWindow;
    for(string window:map.keys()){
        if(randomReal(0,1) <0.3){
            firstWindow=window;
            break;
        }
        firstWindow=window;
    }
//    cout << "first start: " << firstWindow << endl;
    return firstWindow;
}
string toString(vector<string>& arr){
    string st="";
    for(string word:arr){
        st+=" "+ word;
    }
    return st.substr(1);
}
string newWindow(string st, string newWord){
   int ind=st.find_first_of(" ");
   st=st.substr(ind+1)+" "+newWord;
   return st;
}

