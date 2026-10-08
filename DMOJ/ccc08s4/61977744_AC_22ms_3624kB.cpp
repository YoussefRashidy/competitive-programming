#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;
vector<int> operation(char op1, char op2, char op3, vector<int> numbers);
int applyOperation(int num1, int num2, char op);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    while (n--)
    {
        vector<int> hand;
        set<int, greater<int>> results;
        for (int i = 0; i < 4; i++)
        {
            int number;
            cin >> number;
            hand.push_back(number);
        }
        vector<char> oper = {'+', '-', '*', '/'};
        do
        {
            for (char c1 : oper)
            {
                for (char c2 : oper)
                {
                    for (char c3 : oper)
                    {
                        vector<int> diffExpr = operation(c1, c2, c3, hand);
                        for (int i : diffExpr)
                        {
                            results.emplace(i);
                        }
                    }
                }
            }
        } while (next_permutation(hand.begin(), hand.end()));

        for (int res : results)
        {
            if (res <= 24)
            {
                cout << res << '\n';
                break;
            }
        }
    }
}
vector<int> operation(char op1, char op2, char op3, vector<int> numbers)
{
    int res = 0;
    int num1 = numbers[0], num2 = numbers[1], num3 = numbers[2], num4 = numbers[3];
    vector<int> results;
    res = applyOperation(num1, num2, op1);
    res = applyOperation(res, num3, op2);
    res = applyOperation(res, num4, op3);
    results.push_back(res);
    res = applyOperation(num2, num3, op2);
    res = applyOperation(num1, res, op1);
    res = applyOperation(res, num4, op3);
    results.push_back(res);
    res = applyOperation(num2, num3, op2);
    res = applyOperation(res, num4, op3);
    res = applyOperation(num1, res, op1);
    results.push_back(res);
    res = applyOperation(num2, applyOperation(num3, num4, op3), op2);
    res = applyOperation(num1, res, op1);
    results.push_back(res);
    res = applyOperation(num3, num4, op3);
    res = applyOperation(num2, res, op2);
    res = applyOperation(num1, res, op1);
    results.push_back(res);
    int left = applyOperation(num1, num2, op1);
    int right = applyOperation(num3, num4, op3);
    res = applyOperation(left, right, op2);
    results.push_back(res);
    return results;
}
int applyOperation(int num1, int num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':

        if (num2 == 0 || num1 % num2 != 0)
        {
            return 10000000;
        }

        return num1 / num2;
        break;
    default:
        return 0;
        break;
    }
}
