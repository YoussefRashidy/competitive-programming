#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int number;
    cin >> n;
    vector<int> vec0, vecne, vecpo;
    set<int> set1;
    set<int> set2;
    set<int> set3;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if (number == 0)
        {
            set3.emplace(0);
        }
        else if (number < 0)
        {
            vecne.emplace_back(number);
        }
        else
        {
            vecpo.emplace_back(number);
        }
    }
    if (vecne.size() % 2 == 0)
    {
        set1.emplace(vecne.back());
        vecne.pop_back();
        set3.emplace(vecne.back());
        vecne.pop_back();
    }
    else
    {
        set1.emplace(vecne.back()) ;
        vecne.pop_back() ;
    }
    for (int i : vecne)
    {
        set2.emplace(i);
    }
    for (int i : vecpo)
    {
        set2.emplace(i);
    }

    cout << set1.size() << " ";
    for (int i : set1)
    {
        cout << i << " ";
    }
    cout << '\n';
    cout << set2.size() << " ";
    for (int i : set2)
    {
        cout << i << " ";
    }
    cout << '\n';
    cout << set3.size() << " ";
    for (int i : set3)
    {
        cout << i << " ";
    }
    cout << '\n';
}