#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;

int main(){
    int n ;
    while(cin >> n) {
        if(n==0)
            break ;
        int carNumber[n] ;
        int positionDiff[n] ;

        for (size_t i = 0; i < n; i++){
            cin >> carNumber[i] >> positionDiff[i] ;
        }

        int correctOrder[n] ;
        memset(correctOrder , 0 , sizeof(correctOrder)) ;
        bool fixed = true ;

        for (size_t i = 0; i < n; i++) {
            int absolutePosition = positionDiff[i] + i ;
            if(absolutePosition >= n || absolutePosition < 0) {
                fixed = false ;
                break;
            }
            if(correctOrder[absolutePosition] != 0) {
                fixed = false ;
                break;
            }
            correctOrder[absolutePosition] = carNumber[i] ;
        }
        
        if(fixed) {
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << correctOrder[i];
            }
            cout << '\n';
        }
        else 
            cout << -1 << endl ;
    }
}