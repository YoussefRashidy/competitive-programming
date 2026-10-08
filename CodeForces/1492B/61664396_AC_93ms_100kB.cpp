#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n;
    cin >> t;
    deque<int> de;
    deque<int> newde;
    

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> pos(n + 1);
        int number;
        int maxPosition = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> number;
            de.emplace_back(number);
            pos[number] = i;
        }
        int size = de.size();

        maxPosition = size - 1;
        for (int i = size; i >= 1; i--)
        {
            if (pos[i] > maxPosition)
            {
                continue;
            }
            for (int j = pos[i]; j <= maxPosition; j++)
            {
                newde.emplace_front(de[j]);
            }
            maxPosition = pos[i] - 1;
        }
        int sizeP =  newde.size() ;
        for (int i = 0; i < sizeP; i++)
        {
            cout << newde.back() << " ";
            newde.pop_back();
        }
        cout << '\n' ;
        de.clear();
    }
}