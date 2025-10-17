/**
 * ===============================================
 * @file        assignment12.cpp
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

// Consider an employee database of N employees considering emp Id and name as data members. Make use of a hash table implementation to quickly look up the employer's id number. Implement above scenario using hashing and linear probing.

// static
#include <bits/stdc++.h>
using namespace std;

// Employee
class Employee
{
public:
    int empId;
    string name;
    bool occupied;

    Employee()
    {
        empId = -1;
        name = "";
        occupied = false;
    }
};

class HashTable
{
private:
    int size;
    Employee *table;
    int insertCount;

    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTable(int s)
    {
        size = s;
        table = new Employee[size];
        insertCount = 0;
    }

    void insertEmployee(int id, const string &name)
    {
        int index = hashFunction(id);
        int startIndex = index;

        while (table[index].occupied)
        {
            index = (index + 1) % size;
            if (index == startIndex)
            {
                cout << "Hash table is full! Cannot insert employee.\n";

                // static code and overwrite the first inserted employee if table is full

                // int replaceIndex = insertCount % size;
                // cout << "Table full! Replacing oldest employee at index "
                //      << replaceIndex << " (ID: " << table[replaceIndex].empId << ")\n";

                // table[replaceIndex].empId = id;
                // table[replaceIndex].name = name;
                // table[replaceIndex].occupied = true;

                // insertCount++;

                return;
            }
        }

        table[index].empId = id;
        table[index].name = name;
        table[index].occupied = true;

        insertCount++;
        cout << "Inserted Employee: [ID: " << id << ", Name: " << name << "] at index " << index << endl;
    }

    void searchEmployee(int id)
    {
        int index = hashFunction(id);
        int startIndex = index;

        while (table[index].occupied)
        {
            if (table[index].empId == id)
            {
                cout << "Employee found at index " << index
                     << " -> ID: " << table[index].empId
                     << ", Name: " << table[index].name << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex)
                break;
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    void displayTable()
    {
        cout << "\n----- Employee Hash Table -----\n";
        for (int i = 0; i < size; i++)
        {
            if (table[i].occupied)
                cout << i << " -> [ID: " << table[i].empId << ", Name: " << table[i].name << "]\n";
            else
                cout << i << " -> [Empty]\n";
        }
        cout << "--------------------------------\n";
    }
};

int main()
{
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice, id;
    string name;

    do
    {
        cout << "\n1. Insert Employee\n2. Search Employee\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            ht.insertEmployee(id, name);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            ht.searchEmployee(id);
            break;

        case 3:
            ht.displayTable();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
