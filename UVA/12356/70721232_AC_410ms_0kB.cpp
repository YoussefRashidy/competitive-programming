#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;

int main() {
    while(true) {
        int s, b ;
        cin >> s >> b ;
        if(s==0 && b== 0)
            break ;
        int leftBuddy[s+1] ;
        int rightBuddy[s+1] ;
        for (size_t i = 1; i <= s; i++) {
            leftBuddy[i] = i != 1 ? i-1 : -1 ;
            rightBuddy[i] = i != s ? i+1 : -1 ;
        }
        
        for (int i = 0; i < b; i++) {
            int l,r ;
            cin >> l >> r ;
            int leftSoldier = leftBuddy[l] ;
            int rightSoldier = rightBuddy[r] ;
            if(leftSoldier != -1 ) {
                rightBuddy[leftSoldier] = rightSoldier ;
                cout << leftSoldier << " " ;
            }
            else
                cout << "*" << " " ;
            
            if(rightSoldier != -1) {
                leftBuddy[rightSoldier] = leftSoldier ;
                cout << rightSoldier << endl ;
            }
            else
                cout << "*" << endl ;
            }
            cout << "-" << endl ;
        
    }
}