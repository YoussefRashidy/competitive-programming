#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ull = unsigned long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        ull l, r;
        cin >> l >> r;
        ull number = l;
        for (int i = 0; i <=63; i++)
        {
            ull bit = 1ull << i ;
            if((number|bit)<= r)
            {
                number|=bit ;
            }
        }
        cout << number << '\n';
    }
}
