#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <chrono>
using namespace std;
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    unordered_map<long long, int,CustomHash> mp;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        if (mp.count(t-val))
        {
            cout << mp[t-val] <<" " <<i;
            return 0 ;
        }
        
        mp.emplace(val, i);
    }
    cout << "IMPOSSIBLE";
    
}