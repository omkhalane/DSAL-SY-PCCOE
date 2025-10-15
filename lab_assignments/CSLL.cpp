#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeg(int val) {
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert after position (1-based)
    void insertAfterPos(int pos, int val) {
        if (head == nullptr) return;
        Node* temp = head;
        for (int i = 1; i < pos && temp->next != head; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteAtBeg() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        Node* del = head;
        head = head->next;
        temp->next = head;
        delete del;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) temp = temp->next;
        Node* del = temp->next;
        temp->next = head;
        delete del;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            deleteAtBeg();
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == head) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search
    void search(int val) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not Found\n";
    }

    // Update at position
    void update(int pos, int newVal) {
        if (head == nullptr) return;
        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position not found\n";
                return;
            }
        }
        temp->data = newVal;
    }

    // Sort list (Bubble style)
    void sortList() {
        if (head == nullptr || head->next == head) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            do {
                Node* nxt = temp->next;
                if (nxt != head && temp->data > nxt->data) {
                    swap(temp->data, nxt->data);
                    swapped = true;
                }
                temp = temp->next;
            } while (temp->next != head);
        } while (swapped);
    }

    // Reverse list
    void reverse() {
        if (head == nullptr || head->next == head) return;
        Node* prev = nullptr;
        Node* curr = head;
        Node* nxt = nullptr;
        Node* last = head;

        // find last node
        while (last->next != head) last = last->next;

        do {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        } while (curr != head);

        head->next = prev;
        head = prev;
        last->next = head;
    }

    // Print
    void printList() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

// -----------------------------
int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtBeg(5);
    cll.insertAfterPos(2, 15);
    cll.printList();  // 5 -> 10 -> 15 -> 20 -> (back to head)

    cll.deleteByValue(10);
    cll.printList();  // 5 -> 15 -> 20 -> (back to head)

    cll.search(15);   // Found at position 2
    cll.update(2, 18);
    cll.printList();  // 5 -> 18 -> 20 -> (back to head)

    cll.insertAtEnd(2);
    cll.sortList();
    cll.printList();  // 2 -> 5 -> 18 -> 20 -> (back to head)

    cll.reverse();
    cll.printList();  // 20 -> 18 -> 5 -> 2 -> (back to head)

    return 0;
}
