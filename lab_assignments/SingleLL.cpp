#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeg(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after given position (1-based index)
    void insertAfterPos(int pos, int val) {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position not found\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteAtBeg() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not Found\n";
    }

    // Update value at position
    void update(int pos, int newVal) {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position not found\n";
            return;
        }
        temp->data = newVal;
    }

    // Sort (Bubble Sort style)
    void sortList() {
        if (head == nullptr) return;
        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    // Reverse
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Print list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// -----------------------------
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtBeg(5);
    list.insertAfterPos(2, 20);
    list.printList(); // 5 -> 10 -> 20 -> 30 -> NULL

    list.deleteByValue(10);
    list.printList(); // 5 -> 20 -> 30 -> NULL

    list.search(20);  // Found at position 2
    list.update(2, 25);
    list.printList(); // 5 -> 25 -> 30 -> NULL

    list.insertAtEnd(15);
    list.sortList();
    list.printList(); // 5 -> 15 -> 25 -> 30 -> NULL

    list.reverse();
    list.printList(); // 30 -> 25 -> 15 -> 5 -> NULL

    return 0;
}
