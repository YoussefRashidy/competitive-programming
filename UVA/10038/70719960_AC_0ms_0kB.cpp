#include<iostream>
#include<cmath>
#include<cstring>
using namespace std ;

int main() {
    int n ;
    while (cin >> n ) {
        int nums[n] ;
        for (size_t i = 0; i < n; i++) {
            cin >> nums[i] ;
        }
        bool flags[n] ;
        memset(flags,false , sizeof(flags)) ;
        for (size_t i = 1; i < n; i++) {
            int diff = abs(nums[i] - nums[i-1]) ;
            if(diff < n) 
                flags[diff] = true ;
        }
    
        bool isJolly = true ;
        for (size_t i = 1; i < n; i++)
            isJolly &= flags[i] ;
        
        if(isJolly)
            cout << "Jolly" << endl ;
        else
            cout << "Not jolly" << endl ;
    }
    
    
}