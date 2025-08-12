/**
 * ===============================================
 * @file        assignment02.cpp
 * @path        /code/DSA/problems/lab_assignments
 * @author      Om Khalane
 * @created     2025-08-11
 * @updated     2025-08-11
 *
 * @description N/A
 *
 * @tech        cpp
 *
 * @notes       N/A
 * ===============================================
 */

// 2 Quick sort A warehouse management system wants to sort inventory items by
// stock quantity to prioritize restocking.Write a program for above
// scenario.
// Hint:
// Given an unsorted list of inventory quantities, implement Quick Sort
// to sort items by stock quantity in ascending order. Discuss how the
// presence of many duplicate quantities affects Quick Sort’s efficiency.

#include <bits/stdc++.h>
using namespace std;

// partition and sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// quick sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> q;
    int n;

    cout << "Enter number of inventory items: ";
    cin >> n;

    cout << "Enter stock quantities:\n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push_back(temp);
    }

    quickSort(q, 0, n - 1);

    cout << "\nSorted stock quantities (Ascending):\n";
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    return 0;
}
