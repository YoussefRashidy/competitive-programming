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
        int a , b ;
        cin >> a >> b ;
        int res = 0 ;
        for(int i = 0 ; i < 31 ; i++) {
            if(((a & (1<<i)) && !(b&(1<<i))) || (!(a & (1<<i)) && (b&(1<<i))))
                res = res | (1<<i) ;
        }
        cout << res << endl ;
    }
}