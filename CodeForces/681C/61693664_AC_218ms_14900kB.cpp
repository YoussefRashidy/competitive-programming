#include <iostream>
#include <queue>
#include <set>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    queue<string> oper;
    queue<string> minOP;
    priority_queue<int, vector<int>, greater<int>> heap;
    multiset<int> track;
    for (int i = 0; i < n; i++)
    {
        string operation;
        getline(cin, operation);
        oper.push(operation);
    }
    while (!oper.empty())
    {
        string operation = oper.front();
        if (operation.substr(0, 6) == "insert")
        {
            int number = stoi(operation.substr(7));
            heap.emplace(number);
            minOP.emplace(operation);
            track.emplace(number);
        }
        else if (operation.substr(0, 6) == "getMin")
        {
            if (heap.empty())
            {
                heap.emplace(stoi(operation.substr(7)));
                track.emplace(stoi(operation.substr(7)));
                minOP.emplace("insert "+to_string(stoi(operation.substr(7))));
                minOP.emplace(operation);
            }
            else if (stoi(operation.substr(7)) == heap.top())
            {
                minOP.push(operation);
            }
            else
            {
                if (track.find(stoi(operation.substr(7))) != track.end())
                {
                    while (heap.top() != stoi(operation.substr(7)))
                    {
                        heap.pop();
                        track.erase(track.begin());
                        minOP.emplace("removeMin");
                    }
                }
                else
                {
                    while (!heap.empty() && heap.top() < stoi(operation.substr(7)) )
                    {
                        heap.pop();
                        track.erase(track.begin());
                        minOP.emplace("removeMin");
                    }
                    heap.emplace(stoi(operation.substr(7)));
                    track.emplace(stoi(operation.substr(7)));
                    minOP.emplace("insert "+to_string(stoi(operation.substr(7))));
                }
                minOP.emplace(operation);
            }
        }
        else
        {
            if (!heap.empty())
            {
                heap.pop();
                track.erase(track.begin());
                minOP.emplace(operation);
            }
            else
            {
                minOP.emplace("insert 1");
                minOP.emplace(operation);
            }
        }
        oper.pop();
    }
    cout<< minOP.size() <<'\n' ;
    while (!minOP.empty())
    {
        cout << minOP.front() << '\n';
        minOP.pop();
    }
}