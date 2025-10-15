#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeg(int val) {
        Node* newNode = new Node{val, nullptr, head};
        if (head != nullptr) head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert after position (1-based)
    void insertAfterPos(int pos, int val) {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position not found\n";
            return;
        }
        Node* newNode = new Node{val, temp, temp->next};
        if (temp->next != nullptr) temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteAtBeg() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
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
        while (temp->next != nullptr) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            deleteAtBeg();
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
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

    // Update at position
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

    // Sort (Bubble style)
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

    // Reverse list
    void reverse() {
        if (head == nullptr) return;
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        if (prev != nullptr) head = prev->prev;
    }

    // Print forward
    void printForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Print backward
    void printBackward() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

// -----------------------------
int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeg(5);
    dll.insertAfterPos(2, 15);
    dll.printForward();   // 5 <-> 10 <-> 15 <-> 20 <-> NULL

    dll.deleteByValue(10);
    dll.printForward();   // 5 <-> 15 <-> 20 <-> NULL

    dll.search(15);       // Found at position 2
    dll.update(2, 18);
    dll.printForward();   // 5 <-> 18 <-> 20 <-> NULL

    dll.insertAtEnd(2);
    dll.sortList();
    dll.printForward();   // 2 <-> 5 <-> 18 <-> 20 <-> NULL

    dll.reverse();
    dll.printForward();   // 20 <-> 18 <-> 5 <-> 2 <-> NULL

    dll.printBackward();  // 2 <-> 5 <-> 18 <-> 20 <-> NULL

    return 0;
}
