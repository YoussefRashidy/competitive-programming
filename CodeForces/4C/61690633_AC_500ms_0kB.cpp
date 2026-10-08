#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    map <string,int> names ;
    for (int i = 0; i < n; i++)
    {
        string name ;
        cin >> name ;
        if(names.find(name) != names.end())
        {
            cout << name+to_string(names[name]) << '\n' ;
            names[name] ++;
        } else
        {
            cout <<"OK" <<'\n' ;
            names[name] = 1 ;
        }
        
    }
    
}