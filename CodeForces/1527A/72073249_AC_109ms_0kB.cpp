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
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        int msb = (32 - __builtin_clz(n) - 1) ;
        int res = (1<<msb) - 1 ;
        cout << res << endl ;
    }
}