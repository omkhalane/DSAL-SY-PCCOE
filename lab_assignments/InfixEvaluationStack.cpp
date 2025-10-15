#include <bits/stdc++.h>
using namespace std;

class intstack
{
    int top1, n;

public:
    intstack() {};
    intstack(int n)
    {
        int arr[n];
    }
    void push(int x)
    {
        if (top1 == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
    }
};

bool isoperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}

int priority(char op)
{
    if (op == '-')
        return 1;
    else if (op == '+')
        return 2;
    else if (op == '*')
        return 3;
    else if (op == '/')
        return 4;
    return 0;
}

void EvaluateInfix(stack<int> &ist, stack<char> cst, string s)
{
    int n = s.size(), op = 0;
    for (int i = 0; i < n; i++)
    {
        op = priority(s[i]);
        if (isoperator(s[i]))
        {
            cst.push(s[i]);
            int n1 = ist.top() - '0';
            ist.pop();
            int n2 = s[++i] - '0';
            int e = 0;
            switch (op)
            {
            case 1:
            {
                e = n1 - n2;
                ist.push(e);
                break;
            }
            case 2:
            {
                e = n1 + n2;
                ist.push(e);
                break;
            }
            case 3:
            {
                e = n1 * n2;
                ist.push(e);
                break;
            }
            case 4:
            {
                e = n1 / n2;
                ist.push(e);
                break;
            }
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ist.push(s[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {

        stack<int> I;
        stack<char> C;
        string s;
        cout << "Output : ";
        getline(cin, s);
        EvaluateInfix(I, C, s);
        while (!I.empty())
        {
            cout << I.top() << " ";
            I.pop();
        }
        cout << endl;
        while (!C.empty())
        {
            cout << C.top() << " ";
            C.pop();
        }
    }

    return 0;
}