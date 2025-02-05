#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int queens[8] = {0},columns = 0, sol_num = 1;
    queens[0]=0;

    NextColumn:
    columns++;
    if(columns == 8) goto print;
    queens[columns] = -1;
    NextRow:
    queens[columns]++;
    if(queens[columns] == 8)goto backtracking;
    // Test to see if the queen has any conflict being placed there
    for(int i = 0; i < columns;i++) {
        if(queens[i] == queens[columns] || abs(queens[i]-queens[columns]) ==abs(i-columns)){
            goto NextRow;
        }
    }
    goto NextColumn;

    backtracking:
    columns--;
    if(columns == -1)return 0;
    goto NextRow;

    print:
    cout << "solution:" << '#' << sol_num++ << endl;
    cout << "Array to solution: [";
    for(int i = 0; i < 8;i++) {
        cout << queens[i];
        if( i <=6) cout << ',';
    }
    cout << ']' << endl;
    for(int rows = 0; rows < 8; rows++) {
        for(int col = 0; col < 8; col++) {
            if(queens[col] == rows) {
                cout <<"x ";
            }else {
                cout <<"0 ";
            }
        }
        cout << endl;
    }
    cout << endl;

    goto backtracking;
}