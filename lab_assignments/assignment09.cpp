/**
 * ===============================================
 * @file        assignment09.cpp
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

// using array
// Design a simplified railway reservation system where users can book,
// cancel, and view tickets. Use an array to store booking details and a
// queue to manage the waiting list.

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int ID;
    string name;
    Queue *next = nullptr;

public:
    Queue() {}
    Queue(string n, int id)
    {
        name = n;
        ID = id;
    }
    friend class Ticket_system;
};

class Ticket_system
{
    static const int MAX = 5;
    string booked[MAX];
    int bookedCount = 0;

    int identy = 1;
    Queue *front = nullptr, *rear = nullptr;

public:
    void add_ticket(string name)
    {
        if (bookedCount < MAX)
        {
            booked[bookedCount++] = name;
            cout << "Ticket confirmed for " << name << " (ID " << identy++ << ")\n";
        }
        else
        {
            Queue *temp = new Queue(name, identy++);
            if (rear == nullptr)
            {
                front = rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
            cout << "All seats full! Added to waiting list: " << name << endl;
        }
    }

    void remove_ticket()
    {
        if (bookedCount == 0)
        {
            cout << "No confirmed bookings to cancel!\n";
            return;
        }

        cout << "Cancelled ticket of " << booked[0] << endl;

        for (int i = 1; i < bookedCount; i++)
            booked[i - 1] = booked[i];
        bookedCount--;

        if (front != nullptr)
        {
            booked[bookedCount++] = front->name;
            cout << "Moved from waiting list to confirmed: " << front->name << endl;

            Queue *temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr)
                rear = nullptr;
        }
    }

    void print_all()
    {
        cout << "\n--- Confirmed Tickets ---\n";
        if (bookedCount == 0)
            cout << "None\n";
        else
            for (int i = 0; i < bookedCount; i++)
                cout << i + 1 << ". " << booked[i] << endl;

        cout << "\n--- Waiting List ---\n";
        if (front == nullptr)
            cout << "None\n";
        else
        {
            Queue *temp = front;
            while (temp != nullptr)
            {
                cout << temp->ID << ". " << temp->name << endl;
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    Ticket_system obj;
    cout << "=== Railway Reservation System ===\n";
    cout << "1. Book Ticket\n";
    cout << "2. Cancel Ticket\n";
    cout << "3. View All Tickets\n";
    cout << "4. Exit\n";

    while (true)
    {
        int op;
        cout << "\nEnter Option: ";
        cin >> op;
        cin.ignore();

        switch (op)
        {
        case 1:
        {
            string name;
            cout << "Enter Passenger Name: ";
            getline(cin, name);
            obj.add_ticket(name);
            break;
        }
        case 2:
            obj.remove_ticket();
            break;
        case 3:
            obj.print_all();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option!\n";
            break;
        }
    }
}

// usiing LL

// // Design a simplified railway reservation system where users can book,
// // cancel, and view tickets. Use an array to store booking details and a
// // queue to manage the waiting list.
// // #include <bits/stdc++.h>
// // using namespace std;

// class pq
// {
// public:
//     int ID;
//     string customerName;
//     pq *next;

//     pq(string name, int id)
//     {
//         customerName = name;
//         ID = id;
//         next = NULL;
//     }
// };

// class TicketingSystem
// {
//     pq *front;
//     pq *rear;

// public:
//     TicketingSystem()
//     {
//         front = rear = NULL;
//     }

//     void enqueue(string name, int id)
//     {
//         pq *nn = new pq(name, id);

//         if (front == NULL)
//         {
//             front = rear = nn;
//             rear->next = front;
//             return;
//         }

//         rear->next = nn;
//         rear = nn;
//         rear->next = front;
//     }

//     // Urgent Enqueue
//     void urgentEnqueue(string name, int id)
//     {
//         pq *nn = new pq(name, id);

//         if (front == NULL)
//         {
//             front = rear = nn;
//             rear->next = front;
//             return;
//         }

//         nn->next = front;
//         front = nn;
//         rear->next = front;
//     }

//     void dequeue()
//     {
//         if (front == NULL)
//         {
//             cout << "No tickets to resolve. ; Queue is empty \n";
//             return;
//         }

//         pq *temp = front;

//         if (front == rear)
//         {
//             cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;
//             delete temp;
//             front = rear = NULL;
//             return;
//         }

//         cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;

//         front = front->next;
//         rear->next = front;
//         delete temp;
//     }

//     void display()
//     {
//         if (front == NULL)
//         {
//             cout << "Queue is empty\n";
//             return;
//         }

//         pq *temp = front;
//         cout << "\n Tickets in Queue:\n";
//         do
//         {
//             cout << "Ticket ID: " << temp->ID << " || Customer Name: " << temp->customerName << endl;
//             temp = temp->next;
//         } while (temp != front);
//         cout << endl;
//     }
// };

// int main()
// {
//     int GlobalID = 1;
//     TicketingSystem ts;

//     while (true)
//     {
//         int choice;
//         cout << "\n1. Add ticket"
//              << "\n2. Add urgent ticket"
//              << "\n3. Resolve ticket"
//              << "\n4. Display tickets"
//              << "\n5. Exit\n"
//              << "Enter choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             string name;
//             cout << "Enter Name: ";
//             cin.ignore();
//             getline(cin, name);
//             ts.enqueue(name, GlobalID++);
//             break;
//         }
//         case 2:
//         {
//             string name;
//             cout << "Enter Name: ";
//             cin.ignore();
//             getline(cin, name);
//             ts.urgentEnqueue(name, GlobalID++);
//             break;
//         }
//         case 3:
//             ts.dequeue();
//             break;
//         case 4:
//             ts.display();
//             break;
//         case 5:
//             return 0;
//         default:
//             cout << "Enter valid choice!\n";
//         }
//     }
// }
