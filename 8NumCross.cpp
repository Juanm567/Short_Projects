#include<iostream>
#include<cmath>
using namespace std;
bool ok (int cross[], int c) {
    static  int adj[8][5] = { // static allows for less use of memory at every call of the function
        {-1},       //0 Sentinel value(-1)
        {0,-1},     //1
        {0,-1},     //2
        {0,1,2,-1}, //3
        {0,1,3,-1},  //4
        {1,4,-1},    //5
        {2,3,4,-1},  //6
        {3,4,5,6,-1}, //7
    };
    for (int i = 0; i < c; i++) {
        if(cross[i] == cross[c]) {  //make sure there are no repeated values
            return false;
        }
    }
    for (int i = 0; adj[c][i] != -1;i++) {
        if(abs(cross[c] - cross[adj[c][i]]) == 1) {  //use the adj array to test for adjacent values
            return false;
        }
    }
    return true; /*allows for the value to be used since it doesn't satisfy either a repeated value
    or adjacent value with a difference of 1*/
}
void print (int cross[]) {
    static int sol_num = 1;
    cout << "solution #" <<sol_num++<<":"<< endl << "["; //wanted to show the array
    for (int i = 0; i < 8; i++) {
       if(i < 7) cout << cross[i] << " ";
       else {
            cout << cross[7];
        }           // wrote it this way because I wanted for the last ']' to be close to the last value and not (# ])
    }cout << "]";
    cout << endl;
    cout << "        " << cross[0] << cross[1] << endl;
    cout << "       " << cross[2] << cross[3] << cross[4] << cross[5] << endl;
    cout << "        " << cross[6] << cross[7] << endl << endl;
}
void Eight_numbers (int cross[],int c) {
    if(c == 8){ //if all possible values 1-8 have been tested then go to the print function
        print(cross);
        return;
    }
    for(int i = 1; i <= 8; i++) {
        cross[c] = i; // numbers from 1-8;
        if(ok(cross, c)){ // ok test function
            Eight_numbers(cross, c+1); //recursive call
        }
    }
}
int main() {
        int cross_board[8] ={0},c= 0; // board and board spot initialization
        Eight_numbers(cross_board,c); // function call for the recursive function to find all valid solutions
        return 0;
    }