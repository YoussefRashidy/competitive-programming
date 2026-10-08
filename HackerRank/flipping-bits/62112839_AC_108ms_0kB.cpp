#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        unsigned int n;
        cin >> n;
        unsigned int flip = ~n;
        cout << flip << '\n';
    }
}