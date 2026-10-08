#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n,m,q ;
        cin >> n >> m >> q ;
        vector<int> b(m) ;
        for(int i = 0 ; i < m ; i++) {
            cin >> b[i] ;
        }
        sort(b.begin(),b.end()) ;
        while(q--) {
            int x ;
            cin >> x ;
            auto it = lower_bound(b.begin(),b.end(),x) ;
            int ans ;
            if(it == b.end()) {
                 ans = n - b[m-1] ;
            }
            else if (it == b.begin()) {
                 ans = b[0] - 1 ;
            }
            else {
                 ans = (b[it - b.begin()] - b[it - b.begin() - 1]) / 2 ;
            }
            cout << ans << endl ;
        }
    }
}