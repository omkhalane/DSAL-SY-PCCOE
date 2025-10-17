/**
 * ===============================================
 * @file        october_challenge.cpp
 * @path        /code/DSA/DSAL-SY-PCCOE/lab_assignments
 * @author      Om Khalane
 * @created     2025-10-17
 * @updated     2025-10-17
 *
 * @description N/A
 *
 * @tech        cpp
 *
 * @notes       N/A
 * ===============================================
 */

// Problem Statement: "Browser History Management"
// You are tasked with implementing a simplified browser history management system. This system should allow users to navigate between previously visited pages, and also add new pages to their history. The system needs to efficiently handle both "back" and "forward" navigation, as well as adding new pages, while maintaining a limited history size.
// Requirements:
//  When a user visits a new page, it should be added to the current history. If there are any "forward" pages available (i.e., pages visited after the current page in the history), they should be cleared, as visiting a new page effectively creates a new branch in the history.
//  Users should be able to navigate to the previous page in their history. If there's no previous page, they remain on the current page.
//  Users should be able to navigate to a page they previously went "back" from. If there's no page to go forward to, they remain on the current page.
//  The browser history should have a maximum capacity. If adding a new page exceeds this capacity, the oldest page in the history should be automatically removed to make space.
// Input:
// A sequence of operations:
// visit(url): Adds url to the history.
// back(steps): Navigates back by steps pages.
// forward(steps): Navigates forward by steps pages.
// Output:
// For each visit, back, or forward operation, output the URL of the page the user is currently on after the operation.

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
private:
    int capacity;
    string current;
    deque<string> backStack;
    stack<string> forwardStack;

public:
    BrowserHistory(int cap, string homepage)
    {
        capacity = cap;
        current = homepage;
    }

    void visit(const string &url)
    {
        backStack.push_back(current);

        if ((int)backStack.size() > capacity)
        {
            backStack.pop_front();
        }

        while (!forwardStack.empty())
        {
            forwardStack.pop();
        }

        current = url;
        cout << "Visited: " << current << endl;
    }

    void back()
    {
        if (backStack.empty())
        {
            cout << "No previous page && Current Page : " << current << endl;
            return;
        }

        forwardStack.push(current);
        current = backStack.back();
        backStack.pop_back();

        cout << "redirecting  back to: " << current << endl;
    }

    void forward()
    {
        if (forwardStack.empty())
        {
            cout << "No forward page && Current page : " << current << endl;
            return;
        }

        backStack.push_back(current);
        current = forwardStack.top();
        forwardStack.pop();

        if ((int)backStack.size() > capacity)
        {
            backStack.pop_front();
        }

        cout << " redirecting forward to: " << current << endl;
    }

    // Display
    void showHistory()
    {
        cout << "\n----- Browser History -----\n";
        cout << "BackStack: ";
        for (auto &p : backStack)
            cout << p << " ";
        cout << "\nCurrent: " << current;
        cout << "\nForwardStack: ";

        stack<string> temp = forwardStack;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "\n----------------------------\n";
    }
};

// Driver code
int main()
{
    int capacity;
    cout << "Enter browser history capacity: ";
    cin >> capacity;

    string homepage;
    cout << "Enter homepage URL: ";
    cin >> homepage;

    BrowserHistory browser(capacity, homepage);

    int choice;
    string url;

    do
    {
        cout << "\n1. Visit New Page\n2. Back\n3. Forward\n4. Show History\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.visit(url);
            break;

        case 2:
            browser.back();
            break;

        case 3:
            browser.forward();
            break;

        case 4:
            browser.showHistory();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
