#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
string twoString(string s1 , string s2) ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p ;
    string s1,s2 ;
    cin >> p ;
    for(int i = 0 ; i < p ; i++)
    {
        cin >> s1 ;
        cin >> s2 ;
        cout << twoString(s1,s2) << '\n' ;
    }
}  

string twoString(string s1 , string s2)
{
    unordered_map <char,int> un_map ;
    for(char c : s1)
    {
        un_map[c]++ ;
    }
    for(char c : s2)
    {
        if(un_map.find(c) !=un_map.end() )
        {
            return "YES" ;
        }
    }
    return "NO" ;
    
}