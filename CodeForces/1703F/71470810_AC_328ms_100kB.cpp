#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        vector<int> a(n+1) ;
        for(int i = 1 ; i <= n ; i++) {
            cin >> a[i] ;
        }
        vector<int> b ;
        for(int i = 1 ; i <= n ; i++) {
            if(a[i] < i) {
                b.push_back(i) ;
            }
        }
        long long ans = 0 ;
        for(int i = 0 ; i < b.size() ; i++) {
            ans+= lower_bound(b.begin(),b.end(),a[b[i]]) - b.begin() ;
        }
        cout << ans << endl ;
    }
}