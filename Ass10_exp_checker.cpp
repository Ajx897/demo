#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isWellParenthesized(const string &expression)
{
    stack<char> s;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.empty();
}
int main()
{
    cout << "TEJAS NALAWADE SCOD09" << endl;
    string expression;
    cout << "Enter an expression: ";
    getline(std::cin, expression);
    if (isWellParenthesized(expression))
    {
        cout << "The expression is well-parenthesized." << std::endl;
    }
    else
    {
        cout << "The expression is not well-parenthesized." << std::endl;
    }
    return 0;
}
