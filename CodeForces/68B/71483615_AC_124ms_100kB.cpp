#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>

using namespace std;

bool can_exchange(double num ,vector<int> &energy, double k) {
    double excess = 0 ;
    double need = 0 ;
    for(int i = 0 ; i < energy.size() ; i++) {
        if(energy[i] > num) {
            excess += (energy[i]-num) ;
        }
        else {
            need += (num-energy[i]) ;
        }
    }
    return excess*(1.0- k/100.0) >= need ;
}

int main() {
    int n , k ; 
    cin >> n >> k ;
    vector<int> energy(n) ;
    int min_energy = INT_MAX , max_energy = INT_MIN ;
    for(int i = 0 ; i < n ; i++) {
        cin >> energy[i] ;
        min_energy = min(min_energy , energy[i]) ;
        max_energy = max(max_energy,energy[i]) ;
    }
    double l = min_energy , h = max_energy ;
    while(h - l >= 1e-9) {
        double mid = l + (h-l)/2.0 ;
        if(can_exchange(mid , energy , k))
            l = mid ;
        else 
            h = mid  ;
    }
    
    cout <<fixed << setprecision(9) << l << endl ;
}