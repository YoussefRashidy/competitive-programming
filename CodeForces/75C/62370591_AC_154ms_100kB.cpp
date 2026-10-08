#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
vector<int> divsors(int a);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int Gcd = gcd(a, b);
    vector<int> divs = divsors(Gcd);
    sort(divs.begin(), divs.end());

    while (n--)
    {
        int low, high;
        cin >> low >> high;
        auto lower = lower_bound(divs.begin(), divs.end(), low);
        auto upper = lower_bound(divs.begin(), divs.end(), high);
        // if (upper == lower)
        // {
        //     cout << -1 << '\n';
        // }
        // else
        // {

        // }
        int GCD = -1 ;
        for (int i = 0; i < divs.size(); i++)
        {
            int num = divs[i] ;
            if (num >= low && num <= high)
            {
                GCD = max(GCD,num) ;
            }
        }
        cout << GCD << '\n' ;
    }
}

vector<int> divsors(int a)
{
    vector<int> divs;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            divs.push_back(i);
            if (i != a / i)
            {
                divs.push_back(a / i);
            }
        }
    }
    return divs;
}