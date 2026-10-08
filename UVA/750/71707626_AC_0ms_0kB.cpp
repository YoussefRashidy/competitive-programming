#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>
#include<bitset>

using namespace std ;

int solution_count = 0 ;

void backtrack(int c  , int a , int b , int row , int ld , int rd , vector<int> & col_row ) ;

int main() {
    int t ;
    cin >> t ;
    for(int i = 0 ; i < t ; i++) {
        if(i > 0)
            cout << endl ;
        int a , b ;
        cin >> a >> b ;
        int row = 0 , ld = 0 , rd = 0 ;
        vector<int> col_row (9,-1) ; 
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        backtrack(1,a,b,row,ld,rd,col_row) ;
        solution_count = 0 ;
    }
}

void backtrack(int c  , int a , int b , int row , int ld , int rd , vector<int> & col_row ) {
    if(c > 8 && col_row[b] == a) {
       cout << setw(2) << ++solution_count << "     ";
    for (int i = 1; i <= 8; i++)
        cout << setw(2) << col_row[i];

        cout << endl ;
        return ;
    }

    for(int i = 1 ; i < 9 ; i++) {
        if(c == b && a != i )
            continue;
        if(!(row&(1<<i)) && !(ld&(1<<(i-c+7))) && !(rd&(1<<(i+c)))) {
            row |= 1<<i ;
            ld |= 1<<(i-c+7) ;
            rd |= 1<<(i+c) ;
            col_row[c] = i ;
            backtrack(c+1,a,b,row,ld,rd,col_row) ;
            row &= ~(1<<i) ;
            ld &= ~(1<<(i-c+7)) ;
            rd &= ~(1<<(i+c) );
            col_row[c] = -1 ; // just for consistency 
        }
    }
}