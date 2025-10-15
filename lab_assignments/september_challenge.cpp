/**
 * ===============================================
 * @file        september_challenge.cpp
 * @path        /code/DSA/DSAL-SY-PCCOE/lab_assignments
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

//  Check if the Given Linked list is palindrome.
// OR
// Write a CPP program to create clone of the given linked list
// OR
// Write a program to print the Addition of two linked list with negative integers.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList() { head = NULL; }

    Node *getHead() { return head; }

    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display(Node *node = NULL)
    {
        if (node == NULL)
            node = head;
        while (node)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    // Check Palindrome
    bool isPalindrome()
    {
        if (!head || !head->next)
            return true;

        Node *slow = head;
        Node *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = NULL;
        Node *curr = slow->next;
        while (curr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        Node *first = head;
        Node *second = prev;
        bool palindrome = true;
        while (second)
        {
            if (first->data != second->data)
            {
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }
        return palindrome;
    }

    // 2️ Clone Linked List
    LinkedList cloneList()
    {
        LinkedList clone;
        if (!head)
            return clone;

        unordered_map<Node *, Node *> mp;
        Node *curr = head;
        while (curr)
        {
            mp[curr] = new Node(curr->data);
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            mp[curr]->next = mp[curr->next];
            curr = curr->next;
        }
        clone.head = mp[head];
        return clone;
    }

    // Add Two Linked Lists
    static LinkedList addLists(LinkedList &l1, LinkedList &l2)
    {
        Node *n1 = l1.getHead();
        Node *n2 = l2.getHead();
        stack<int> s1, s2;
        while (n1)
        {
            s1.push(n1->data);
            n1 = n1->next;
        }
        while (n2)
        {
            s2.push(n2->data);
            n2 = n2->next;
        }

        int carry = 0;
        LinkedList result;
        Node *resHead = NULL;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int x = 0, y = 0;
            if (!s1.empty())
            {
                x = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                y = s2.top();
                s2.pop();
            }

            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;

            Node *newNode = new Node(sum);
            newNode->next = resHead;
            resHead = newNode;
        }
        result.head = resHead;
        return result;
    }
};

int main()
{
    cout << "===== CHECK PALINDROME =====\n";
    LinkedList l1;
    l1.insertEnd(1);
    l1.insertEnd(2);
    l1.insertEnd(3);
    l1.insertEnd(2);
    l1.insertEnd(1);
    cout << "List: ";
    l1.display();
    // Palindrome check
    cout << (l1.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;

    cout << "\n===== CLONE LINKED LIST =====\n";
    LinkedList clone = l1.cloneList();
    cout << "Original List: ";
    l1.display();
    cout << "Cloned List:   ";
    clone.display();

    cout << "\n===== ADD TWO LINKED LISTS =====\n";
    LinkedList a, b;
    a.insertEnd(9);
    a.insertEnd(9);
    b.insertEnd(-2);
    b.insertEnd(3);
    cout << "List A: ";
    a.display();
    cout << "List B: ";
    b.display();

    LinkedList sum = LinkedList::addLists(a, b);
    cout << "Sum: ";
    sum.display();

    return 0;
}
