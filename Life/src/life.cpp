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
#include "lifegui.h"
#include "strlib.h"
using namespace std;


void readFile(Grid<char>& grid);
void animate(Grid<char>& grid,Grid<int>& neigbhor);
void updateNeigbhorRowCol(int row,int col, Grid<char>& grid, Grid<int>& neigbhor);
void updateNeigbhor(Grid<char>& grid, Grid<int>& neigbhor);
void nextStatus(int row,int col, Grid<char>& grid, Grid<int>& neigbhor);
void tick(Grid<char>& grid,Grid<int>& neigbhor);
void printGrid(Grid<char>& grid);
void printNeigbhor(Grid<int>& neigbhor);

int main() {
    Grid<char> grid;
    Grid<int> neigbhor;
    readFile(grid);
    updateNeigbhor(grid,neigbhor);
    while(true){
        cout <<"enter a character. Choices: a t q: ";
        string cmd;
        cin >> cmd;
        cmd=toLowerCase(cmd);
        if (cmd=="t"){
//            clearConsole();
            tick(grid,neigbhor);
//            updateNeigbhor(grid,neigbhor);
            printGrid(grid);
        } else if(cmd=="a"){
            animate(grid,neigbhor);
        }else if(cmd=="q"){
            cout << "Have a nice Life!";
            break;
        }else{
            cout << "Invalid choice; please try again." << endl;
        }
    }
    return 0;
}

void readFile(Grid<char>& grid){
    string fileName="dinner-table.txt";
//    cin >> fileName;
    ifstream input;
    openFile(input, fileName);
    string line;
    int count=0;
    int numRow=0;
    int numCol=0;
    while(getline(input,line)){
        if(count==0){
            numRow=stringToInteger(line);
            count++;
        }else if(count==1){
            numCol=stringToInteger(line);
            count++;
            grid.resize(numRow,numCol);
        }else if(line.length()>0){
            int col=0;
            for(char ch:line){
                grid[count-2][col]=ch;
                col++;
            }
//            cout << line << endl;
            count++;
        } else{
            break;
        }

    }
    input.close();
}

void tick(Grid<char>& grid,Grid<int>& neigbhor){
    for(int i=0;i<grid.numRows();i++){
        for (int j=0;j<grid.numCols();j++){
            nextStatus(i,j,grid,neigbhor);
        }
    }
    updateNeigbhor(grid,neigbhor);
}
void animate(Grid<char>& grid,Grid<int>& neigbhor){
    int repeat=getInteger();
    clearConsole();
    for(int i=0;i<repeat;i++){
        printGrid(grid);
        tick(grid,neigbhor);
        pause(200);
        clearConsole();
    }
    updateNeigbhor(grid,neigbhor);
    printGrid(grid);
}
void updateNeigbhor(Grid<char>& grid, Grid<int>& neigbhor){
    neigbhor.resize(grid.numRows(),grid.numCols());
    for (int i=0;i<grid.numRows();i++){
        for(int j=0;j<grid.numCols();j++){
            updateNeigbhorRowCol(i,j,grid,neigbhor);
        }
    }
}
void updateNeigbhorRowCol(int row,int col, Grid<char>& grid, Grid<int>& neigbhor){
    neigbhor[row][col]=0;
    for (int i=row-1;i<row+2;i++){
        for (int j=col-1;j<col+2;j++){
//            cout << "row: "<<row<<" col: "<<col<<" i :"<< i<<" j: "<< j << endl;
            if( !(i==row && j==col) && i>0 && j>0 && i<grid.numRows() && j<grid.numCols() && grid[i][j]=='X'){
                neigbhor[row][col]+=1;
            }
        }
    }
}
void nextStatus(int row,int col, Grid<char>& grid, Grid<int>& neigbhor){
    int numNeigbhor=neigbhor[row][col];
    if(numNeigbhor==3){
        grid[row][col]='X';
    } else if(numNeigbhor<2 ||numNeigbhor>3){
        grid[row][col]='-';
    }
}
void printGrid(Grid<char>& grid){
    for (int i=0;i<grid.numRows();i++){
        for(int j=0;j<grid.numCols();j++){
            cout <<grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void printNeigbhor(Grid<int>& neigbhor){
    for (int i=0;i<neigbhor.numRows();i++){
        for(int j=0;j<neigbhor.numCols();j++){
            cout <<neigbhor[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

