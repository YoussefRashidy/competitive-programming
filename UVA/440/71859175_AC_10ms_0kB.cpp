#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>
#include<bitset>
#include<set>

using namespace std ;

int main() {
    int n ;
    while(cin>>n && n) {
        int m = -1 ;
        for(int i = 1  ; ; i++) {
            vector<int> cities(n) ;
            iota(cities.begin(), cities.end(), 1);
            int idx = 0 ;
            cities.erase(cities.begin() + idx) ;
            while (cities.size() != 1 )
            {
                idx = (idx + i - 1) % cities.size() ;
                cities.erase(cities.begin() + idx) ;
            }
            if(cities[0] == 2) {
                m = i ;
                break ;
            }
        }
        cout << m << endl ;
    }
}