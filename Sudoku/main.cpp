//
//  main.cpp
//  Sudoku
//
//  Created by zhaozeyu on 2019/1/10.
//  Copyright © 2019 zhaozeyu. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int array1[9][9];

void input()//for input the array
{
    ifstream fin;
    fin.open("Sudoku.txt");
    int a,b;
    for(a=0;a<9;a++){
        for(b=0;b<9;b++){
            fin>>array1[a][b];
        }
    }
}
bool judge(int x)
{
    int row=x/9;
    int col=x%9;
    int y;
    for(y=0;y<9;y++){
        if(array1[row][y]==array1[row][col]&&y!=col)//Judging if there is same number in same line
            return false;
    }
    for(y=0;y<9;y++){
        if(array1[y][col]==array1[row][col]&&y!=row)//Judging if there is same number in same col
            return false;
    }
    int lRow = row / 3 * 3;  //Judging if there is same number in same 3*3 square
    int lCol = col / 3 * 3;
    for(y=lRow;y<lRow+3;y++){
        for(int z=lCol;z<lCol+3;z++){
            if(array1[y][z]==array1[row][col]&&y!=row&&z!=col){
                return false;
            }
        }
    }
    return true;
}
void back(int x){
    if(x==81){//Output the answer
        cout<<"result£∫"<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<array1[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    int row=x/9;//Try each single number
    int col=x%9;
    if(array1[row][col]==0){
        for(int i=1;i<=9;i++){
            array1[row][col]=i;
            if(judge(x)){//return to judge
                back(x+1);
            }
        }
        array1[row][col]=0;
    }
    else{
        back(x+1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Please input 9*9 Sudoku, using 0 to replace spaces"<<endl;
    input();
    back(0);
    return 0;
}
