#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string> set;
    string line, word;
    vector<string> vec;
    while (getline(cin, line))
    {
        for (char c : line)
        {
            if (isalpha(c))
            {
                word += tolower(c);
            }
            else if (!word.empty())
            {

                set.emplace(word);
                word.clear();
            }
        }
        if (!word.empty())
        {
            set.insert(word);
            word.clear();
        }
    }
    auto it = set.begin();
    for (; it != set.end(); it++)
    {
        cout << *it << '\n';
    }
}