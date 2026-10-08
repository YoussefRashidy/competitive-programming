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
    int n , q ;
    cin >> n >> q ;
    vector<int> nums(n+1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> nums[i] ;
    }
    vector<int> prefix_xor(n+1) ;
    prefix_xor[0] = 0 ;
    for(int i = 1 ; i < n+1 ; i++){
        prefix_xor[i] = prefix_xor[i-1] ^ nums[i] ;
    }
    while(q--){
        int l , r ;
        cin >> l >> r ;
        cout << (prefix_xor[r] ^ prefix_xor[l-1]) << endl ;
    }
}