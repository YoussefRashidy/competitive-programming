#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
#include<queue>
using namespace std;

int main(){
    long long a , b ;
    cin >> a >> b ;
    int years_count = 0 ;
    for(int i = 0 ; i < 63 ; i++) {
        long long x = (1LL << i) - 1LL ;
        long long y = 0 ;
        for(int j = 0 ; j < __builtin_popcountll(x) ; j++) {
            y = x - (1LL << j) ;
            if (y>= a && y <= b && (64-__builtin_clzll(y)-__builtin_popcountll(y))==1) {
                years_count++ ;
            }
        }
    }
    cout << years_count << endl ;
}