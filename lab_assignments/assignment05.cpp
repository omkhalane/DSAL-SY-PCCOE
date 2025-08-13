/**
 * ===============================================
 * @file        assignment05.cpp
 * @path        /code/DSA/problems/lab_assignments
 * @author      Om Khalane
 * @created     2025-08-13
 * @updated     2025-08-13
 *
 * @description N/A
 *
 * @tech        HTML
 *
 * @notes       N/A
 * ===============================================
 */

//  Write a program to perform Polynomial Addition using Linked Lists

// ● Each term is a node (with coefficient and power).
// ● Add two polynomials represented by linked lists.

#include <iostream>
using namespace std;

class node
{
public:
    int power;
    int coeff;
    node *next;
    node(int coef, int p)
    {
        power = p;
        coeff = coef;
        next = NULL;
    }
};

class LL
{
public:
    node *head, *tail;

    LL()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_var(int coef, int p)
    {
        node *temp = new node(coef, p);
        if (!head)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void print()
    {
        if (!head)
        {
            cout << "Empty Polynomial\n";
            return;
        }
        node *it = head;
        bool first = true;
        while (it)
        {
            if (!first && it->coeff >= 0)
                cout << " + ";
            cout << it->coeff << "x^" << it->power;
            it = it->next;
            first = false;
        }
        cout << endl;
    }

    void add_ply(LL &poly1, LL &poly2)
    {
        node *t1 = poly1.head;
        node *t2 = poly2.head;

        while (t1 && t2)
        {
            if (t1->power == t2->power)
            {
                insert_var(t1->coeff + t2->coeff, t1->power);
                t1 = t1->next;
                t2 = t2->next;
            }
            else if (t1->power > t2->power)
            {
                insert_var(t1->coeff, t1->power);
                t1 = t1->next;
            }
            else
            {
                insert_var(t2->coeff, t2->power);
                t2 = t2->next;
            }
        }
        while (t1)
        {
            insert_var(t1->coeff, t1->power);
            t1 = t1->next;
        }
        while (t2)
        {
            insert_var(t2->coeff, t2->power);
            t2 = t2->next;
        }
    }
};

int main()
{
    LL p1, p2, p3;
    int choice;

    do
    {
        cout << "\n===== Polynomial Menu =====\n";
        cout << "1. Enter 1st Polynomial\n";
        cout << "2. Enter 2nd Polynomial\n";
        cout << "3. Display Polynomials\n";
        cout << "4. Add Polynomials\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int t;
            cout << "Enter number of terms in 1st polynomial: ";
            cin >> t;
            p1 = LL();
            for (int i = 0; i < t; i++)
            {
                int coef, pow;
                cout << "Term " << i + 1 << " coefficient: ";
                cin >> coef;
                cout << "Term " << i + 1 << " power: ";
                cin >> pow;
                p1.insert_var(coef, pow);
            }
            break;
        }
        case 2:
        {
            int t;
            cout << "Enter number of terms in 2nd polynomial: ";
            cin >> t;
            p2 = LL();
            for (int i = 0; i < t; i++)
            {
                int coef, pow;
                cout << "Term " << i + 1 << " coefficient: ";
                cin >> coef;
                cout << "Term " << i + 1 << " power: ";
                cin >> pow;
                p2.insert_var(coef, pow);
            }
            break;
        }
        case 3:
            cout << "1st Polynomial: ";
            p1.print();
            cout << "2nd Polynomial: ";
            p2.print();
            break;
        case 4:
            p3 = LL();
            p3.add_ply(p1, p2);
            cout << "Resultant Polynomial: ";
            p3.print();
            break;
        case 5:
            cout << "Exiting ..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
