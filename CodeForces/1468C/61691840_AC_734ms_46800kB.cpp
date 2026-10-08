#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    int cus_number = 1;
    cin >> q;
    map<int, int> customers;
    multimap<int, int, greater<int>> money;
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            int m;
            cin >> m;
            customers.emplace(cus_number, m);
            money.emplace(m, cus_number);
            cus_number++;
            break;
        }
        case 2:
        {
            auto it = customers.begin();
            int customer = it->first;
            auto it2 = money.find(it->second);

            money.erase(it2);

            customers.erase(it);
            cout << customer << " ";
            break;
        }
        case 3:
        {
            auto it = money.begin();
            int customer = it->second;
            money.erase(it);
            customers.erase(customer);
            cout << customer << " ";
            break;
        }

        default:
            break;
        }
    }
}