#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool can_reach(vector<pair<int,int>> &boundries , int k) {
    int l = 0 , r = 0 ;
    for (size_t i = 0; i < boundries.size(); i++)
    {
        l-= k ;
        r+= k ;
        auto[x,y] = boundries[i] ;
        if(x > r || y < l) {
            return false ;
        }
        l = max(l,x) ;
        r = min(r,y) ;
    }
    return true ;
}
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        vector<pair<int,int>> boundries(n) ;
        for(int i = 0 ; i < n ; i++) {
            cin >> boundries[i].first >> boundries[i].second ;
        }
        int low = 0 , high = 1e9 ;
        while (low < high)
        {
            int mid = low + (high - low)/2 ;
            if(can_reach(boundries,mid))
                high = mid ;
            else 
                low = mid + 1 ;
        }
        cout << low << endl ;
    }
}