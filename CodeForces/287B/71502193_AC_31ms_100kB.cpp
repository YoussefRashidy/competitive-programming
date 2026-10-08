#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>

using namespace std;
bool check(long long n , long long k , long long mid ) {
    long long k_sum = (((k-1)*k) /2 ) - ((k-mid-1)*(k-mid))/2 +1  ;
    return k_sum >= n ;
}
int main() {
    long long n , k ;
    cin >> n >> k ;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    
    long long mx = 1 + k * (k - 1) / 2;
    if (mx < n) {
        cout << -1;
        return 0;
    }
        long long low = 1 , high = k-1  ;
    while (low < high)
    {
        long long mid = low + (high - low) / 2 ;
        if(check(n,k,mid))
            high = mid ;
        else 
            low = mid + 1 ;

    }
    cout << low << endl ;

    
}