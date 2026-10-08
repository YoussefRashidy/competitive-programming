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
char ops[] = {'+', '-', '*'} ;

int eval(int a , int b , char op) {
    if(op == '+') {
        return a + b ;
    }
    else if(op == '-') {
        return a - b ;
    }
    else if(op == '*') {
        return a * b ;
    }
}

bool recursion(int i ,vector<int>& nums , vector<bool>& used , int res , int target) {
    if(i >= 5) {
        return res == target ;
    }
    bool result = false ;
    for(char op : ops) {
        for(int j = 0 ; j < nums.size() ; j++) {
            if(used[j]) {
                continue ;
            }
            used[j] = true ;
            result |= recursion(i+1,nums,used,eval(res,nums[j],op),target) ;
            used[j] = false ;
        }
    }
    return result ; 
}

int main() {
    int target = 23 ;
    while(true) {
        vector<int> nums(5) ;
        vector<bool> used(5,false) ;
        for(int i = 0 ; i < 5 ; i++) {
            cin >> nums[i] ;
        }
        if(!nums[0] && !nums[1] && !nums[2] && !nums[3] && !nums[4]) {
            break ;
        }
        bool found = false ;
        for(int i = 0 ; i < 5 ; i++) {
            used[i] = true ;
            if(recursion(1,nums,used,nums[i],target)) {
                cout << "Possible" << endl ;
                found = true ;
                break ;
            }
            used[i] = false ;
        }
        if(!found)
            cout << "Impossible" << endl ;
    }

    
}

