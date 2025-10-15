/**
 * ===============================================
 * @file        assignment10.cpp
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

//  Write a C++ Program to insert elements in Hash Table using Separate
// Chaining.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;

    Node(int k)
    {
        key = k;
        next = nullptr;
    }
};

class HashTable
{
    int tableSize;
    vector<Node *> table;

public:
    HashTable(int size)
    {
        tableSize = size;
        table.resize(tableSize, nullptr);
    }

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);

        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted " << key << " at index " << index << endl;
    }

    void display()
    {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < tableSize; i++)
        {
            cout << i << ": ";
            Node *curr = table[i];
            while (curr)
            {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}
