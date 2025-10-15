/**
 * ===============================================
 * @file        assignment06.cpp
 * @path        /code/DSA/files
 * @author      Om Khalane
 * @created     2025-10-15
 * @updated     2025-10-15
 *
 * @description N/A
 *
 * @tech        cpp
 *
 * @notes       N/A
 * ===============================================
 */

// Write a program for Mathematical Expression Evaluation in
// Calculator: Implement a calculator that supports evaluation of
// complex arithmetic expressions using stacks for operands and
// operators.
// postifx

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string exp;
    stack<char> st;
    cout << "Enter Exp: ";
    getline(cin, exp);
    // getchar();
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int t1 = st.top() - '0';
            st.pop();
            int t2 = st.top() - '0';
            st.pop();
            int sol = 0;
            switch (exp[i])
            {
            case '+':
                sol = t1 + t2;
                break;
            case '-':
                sol = t2 - t1;
                break;
            case '*':
                sol = t1 * t2;
                break;
            case '/':
                sol = t2 / t1;
                break;
            default:
                break;
            }
            st.push(char(sol) + '0');
        }
        else
        {
            st.push(exp[i]);
        }
    }

    cout << "Ans is: " << st.top();

    return 0;
}