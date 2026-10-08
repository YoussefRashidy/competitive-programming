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

struct segment {
    int l , r ;
    int len() {
        return r - l + 1 ;
    }
} ;

int main() {
    auto compare = [](segment& a , segment& b){
        if(a.len() != b.len())
            return a.len() < b.len() ;
        return a.l > b.l ; 
    } ;
    int t ;
    cin >> t ;
    while(t--){
        priority_queue<segment , vector<segment>,decltype(compare)> pq (compare) ;
        int n ;
        cin >> n ;
        vector<int> a (n+1) ;
        pq.push({1,n}) ;
        for(int i = 1 ; i <= n ; i++){
            auto [l,r] = pq.top() ; pq.pop() ;
            if((r-l+1) % 2 != 0) {
                int j = (l+r)/2 ;
                a[j] = i ;
                pq.push({l,j-1}) ;
                pq.push({j+1,r}) ;
            }
            else {
                int j = (l+r-1)/2 ;
                a[j] = i ;
                pq.push({l,j-1}) ;
                pq.push({j+1,r}) ;
            }
        }
        for(int i = 1 ; i <= n ; i++)
            cout << a[i] << " " ;
        cout << endl ;
    }
}