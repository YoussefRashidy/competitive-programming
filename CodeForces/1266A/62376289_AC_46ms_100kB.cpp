#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        string num;
        cin >> num;
        vector<int> digits(10, 0);
        int no_of_zeros = 0;
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            int number = num.at(i) - '0';
            if (number == 0)
            {
                no_of_zeros++;
            }
            sum+= number ;
            digits[number]++;
        }
        if (no_of_zeros == num.size())
        {
            cout << "red" << '\n';
            continue;
        }
        bool divBy5 = digits[0] ;
        bool divBy3 = sum % 3 == 0;
        bool divBy4 = false;
        if ((digits[2]|| digits[4]|| digits[6]|| digits[8]) && digits[0] || digits[0]>=2)
        {
            divBy4 = true;
        }
        cout << ((divBy4 && divBy3 && divBy5) ? "red" : "cyan") << '\n';
    }
}