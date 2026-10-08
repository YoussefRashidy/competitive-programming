#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
bool check(int l , int r , int k ,vector<vector<int>> & prefix_ones){
    int f = 0 ;
    for(int i = 0 ; i < 30 ; i++){
        if(prefix_ones[r][i] - prefix_ones[l-1][i] == r-l+1){
            f |= (1 << i) ;
        }
    }
    return f >= k ;
}
int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> a(n) ;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i] ;
        }
        vector<vector<int>> prefix_ones(n+1,vector<int>(30)) ;
        for(int i = 1 ; i <= n ;i++){
            for(int j = 0 ; j < 30 ; j++){
                prefix_ones[i][j] = (a[i-1] & (1<<j)) ? prefix_ones[i-1][j]+1 : prefix_ones[i-1][j] ;
            }
        }
        int q ;
        cin >> q ;
        while(q--){
            int st , k ;
            cin >> st >> k;
            int l = st , r = n  ;
            int ans = -1 ;
            while(l<=r) {
                int mid = l + (r-l)/2 ;
                if(check(st,mid,k,prefix_ones)){
                    ans = mid ;
                    l = mid + 1 ;
                }
                else {
                    r = mid -1 ;
                }
            }
            cout << ans << " " ;
        }
        cout << endl ;
        
    }
}