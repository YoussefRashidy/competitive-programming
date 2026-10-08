#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
using namespace std;

int backtrack(int i , string & s1 , string & s2 , string & s3){
    if(i >= s1.length()) {
        int sum1 = 0 , sum2 = 0 ;
        for(int j=0;j<s1.length();j++) {
            if(s1.at(j) == '+')
                sum1++ ;
            else
                sum1-- ;

            if(s3.at(j) == '+')
                sum2++ ;
            else
                sum2-- ;
        }
        if(sum1 == sum2)
            return 1 ;
        return 0 ;
    }

    int ways = 0 ;
    if(s2.at(i) != '?') {
        s3.push_back(s2.at(i)) ;
        ways = backtrack(i+1,s1,s2,s3) ;
        s3.pop_back() ;
    }
    else {
        s3.push_back('+') ;
        ways+= backtrack(i+1,s1,s2,s3);
        s3.pop_back() ;

        s3.push_back('-');
        ways+= backtrack(i+1,s1,s2,s3);
        s3.pop_back();
    }

    return ways ;
}
int main() {
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    string s3 = "" ;
    int ways = backtrack(0,s1,s2,s3) ;
    int unrecognized = 0 ;
    for(int i=0;i<s2.length();i++) {
        if(s2.at(i) == '?')
            unrecognized++ ;
    }
    cout << fixed << setprecision(12) << (double)ways/(1<<unrecognized) << endl ;
}