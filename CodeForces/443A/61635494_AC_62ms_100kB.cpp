#include <iostream>
#include <set>
#include <cctype>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<char> set ;
    char c ;
    cin >> c ;
    while (c != '}')
    {
        cin >> c ;
        if (isalpha(c))
        {
           set.emplace(c) ;
        }
    }
    cout << set.size() ;
    
    
}