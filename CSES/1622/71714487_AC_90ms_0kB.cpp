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

void backtrack(string & destination ,string & source ,vector<bool> & used , set<string> &set) {
    if(destination.size() == source.size() && set.find(destination) == set.end() ) {
        set.emplace(destination) ;
    }

    for(int i = 0 ; i < source.size() ; i++) {
        if(!used[i]) {
            destination.push_back(source.at(i));
            used[i] = true ;
            backtrack(destination,source,used,set) ;
            destination.pop_back() ;
            used[i] = false ;
        }
    }
}


int main() {
    string s ;
    cin >> s ;
    vector<bool> used(s.size(),false) ;
    set<string> set ;
    string destination = "" ;
    backtrack(destination,s,used,set) ;
    cout << set.size() << endl ;
    for(string s : set) {
        cout << s << endl ;
    }
}