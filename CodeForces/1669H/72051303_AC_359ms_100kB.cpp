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

int required_ops(int bit , vector<int> nums ) {
    int ops_count = 0 ;
    for(int num : nums) {
        ops_count = (num & (1<<bit)) ? ops_count : ops_count+1 ;
    }
    return ops_count ;
}
int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n , k ;
        cin >> n >> k ;
        vector<int> nums(n) ;
        for(int i = 0 ; i < n ; i++){
            cin >> nums[i] ;
        }
        int max_and = 0 ;
        for (int i = 30 ; i >= 0 ; i--){
            auto ops = required_ops(i,nums) ;
            if(ops <= k) {
                k-= ops , max_and = max_and | (1 << i) ;
            }
        }
        cout << max_and << endl ;
        
    }
}