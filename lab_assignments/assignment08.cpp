/**
 * ===============================================
 * @file        assignment8.cpp
 * @path        /code/DSA/files
 * @author      Om Khalane
 * @created     2025-10-08
 * @updated     2025-10-08
 *
 * @description N/A
 *
 * @tech        cpp
 *
 * @notes       N/A
 * ===============================================
 */

// Circular Single Linked list

#include <bits/stdc++.h>
using namespace std;

class Qqueue
{
public:
    int ID;
    string customerName;
    Qqueue *next;

    Qqueue(string name, int id)
    {
        customerName = name;
        ID = id;
        next = NULL;
    }
};

class TicketingSystem
{
    Qqueue *front;
    Qqueue *rear;

public:
    TicketingSystem()
    {
        front = rear = NULL;
    }

    void enqueue(string name, int id)
    {
        Qqueue *newNode = new Qqueue(name, id);

        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    // Urgent Enqueue
    void urgentEnqueue(string name, int id)
    {
        Qqueue *newNode = new Qqueue(name, id);

        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        newNode->next = front;
        front = newNode;
        rear->next = front;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "No tickets to resolve. ; Queue is empty \n";
            return;
        }

        Qqueue *temp = front;

        if (front == rear)
        {
            cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;
            delete temp;
            front = rear = NULL;
            return;
        }

        cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;

        front = front->next;
        rear->next = front;                 
        delete temp;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        Qqueue *temp = front;
        cout << "\n Tickets in Queue:\n";
        do
        {
            cout << "Ticket ID: " << temp->ID << " || Customer Name: " << temp->customerName << endl;
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main()
{
    int GlobalID = 1;
    TicketingSystem ts;

    while (true)
    {
        int choice;
        cout << "\n1. Add ticket"
             << "\n2. Add urgent ticket"
             << "\n3. Resolve ticket"
             << "\n4. Display tickets"
             << "\n5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            ts.enqueue(name, GlobalID++);
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            ts.urgentEnqueue(name, GlobalID++);
            break;
        }
        case 3:
            ts.dequeue();
            break;
        case 4:
            ts.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Enter valid choice!\n";
        }
    }
}

// Using Singly Linked List
// #include <bits/stdc++.h>
// using namespace std;

// class Qqueue
// {
// public:
//     int ID;
//     string customerName;
//     Qqueue *next;

//     Qqueue(string name, int id)
//     {
//         customerName = name;
//         next = NULL;
//         ID = id;
//     }
// };

// class TicketingSystem
// {
//     Qqueue *front;
//     Qqueue *rear;

// public:
//     TicketingSystem()
//     {
//         front = NULL;
//         rear = NULL;
//     }
//     void enqueue(string name, int id)
//     {
//         Qqueue *newNode = new Qqueue(name, id);
//         if (rear == NULL)
//         {
//             front = rear = newNode;
//             return;
//         }
//         rear->next = newNode;
//         rear = newNode;
//     }
//     void urgentEnqueue(string name, int id)
//     {
//         Qqueue *newNode = new Qqueue(name, id);
//         if (front == NULL)
//         {
//             front = rear = newNode;
//             return;
//         }
//         newNode->next = front;
//         front = newNode;
//     }

//     void dequeue()
//     {
//         if (front == NULL)
//             return;
//         Qqueue *temp = front;
//         front = front->next;
//         if (front == NULL)
//             rear = NULL;
//         cout << "resolving ticket:" << temp->ID << " " << temp->customerName << endl;
//         delete temp;
//     }

//     void display()
//     {
//         Qqueue *temp = front;
//         if (temp == NULL)
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         while (temp != NULL)
//         {
//             cout << "Ticket ID: " << temp->ID << " Customer Name: " << temp->customerName << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main()
// {
//     int GlobalID = 1;
//     TicketingSystem ts;

//     while (true)
//     {
//         int choice;
//         cout << "Enter 1 to add ticket" << endl
//              << "2 to add urgent ticket" << endl
//              << "3 to resolve ticket" << endl
//              << "4 to display tickets" << endl
//              << "5 to exit: " << endl;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             string y;
//             cout << "Enter Name :";
//             cin >> y;
//             ts.enqueue(y, GlobalID);
//             GlobalID++;
//             break;
//         }
//         case 2:
//         {
//             string x;
//             cout << "Enter Name :";
//             cin >> x;
//             ts.urgentEnqueue(x, GlobalID);
//             GlobalID++;
//             break;
//         }
//         case 3:
//         {
//             ts.dequeue();
//             break;
//         }
//         case 4:
//         {
//             ts.display();
//             break;
//         }
//         case 5:
//             return 0;
//         default:
//             cout << "Enter Valid Choice" << endl;
//         }
//     }
// }
