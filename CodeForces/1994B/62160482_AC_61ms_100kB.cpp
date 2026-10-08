#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ull = unsigned long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<char> s(n);
        vector<char> t(n);
        vector<char> diff(n);
        bool can = false;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        int zero_count = 0 ;
        for (int i = 0; i < n; i++)
        {
            diff[i] = (t[i] == s[i]) ? '0' : '1';
            if (t[i] == s[i])
            {
                zero_count++;
            }
            
        }
        if (zero_count==n)
        {
            cout << "YES" << '\n';
            continue;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (diff[i] == '1')
            {
                for (int j = 0; j <= i; j++)
                {
                    if (s[j] == '1')
                    {
                        can = true;
                        break;
                    }
                }
                if (!can)
                {
                    cout << "NO" << '\n';
                    break;
                }
                else
                {
                    cout << "YES" << '\n';
                    break;
                }
            }
        }
    }
}