#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>
#include<bitset>
#include<set>

using namespace std ;

int josephus_iter(int n, int k) {
    int ans = 0 ;
    for(int i = 2 ; i <= n ; i++) {
        ans = (ans + k) % i ;
    }
    return ans ;
}
int main() {
    int t ;
    cin >> t ;
    int counter = 1 ;
    while(t--) {
        int n , k ;
        cin >> n >> k ;
        cout << "Case " << counter++ << ": " << josephus_iter(n,k) + 1 << endl ;
    }
}