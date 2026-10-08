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

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        map<int,int> mp ;
        for(int i = 0 ; i < n ; i++) {
            int x ;
            cin >> x ;
            mp[x]++ ;
        }
        int ans = 0 ;
        for(auto[x, occurences] : mp) {
            if(occurences == 0) {
                continue ;
            }
            int complement = ~x & (~(1<<31)) ;
            if(mp.find(complement) != mp.end()) {
                auto complement_occurences = mp[complement] ;
                if(occurences > complement_occurences) {
                    ans += occurences;
                    mp[complement] = 0 ;
                    mp[x] = 0 ;
                }
                else {
                    ans += complement_occurences ;
                    mp[x] = 0 ;
                    mp[complement] = 0 ;
                }
            }
            else {
                ans += occurences ;
                mp[x] = 0 ;
            }
        }
        cout << ans << endl ;
    }
}