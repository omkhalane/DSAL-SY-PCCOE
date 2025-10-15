#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class CDLL {
    Node* head;
public:
    CDLL() { head = NULL; }

    // Insert at beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertEnd(int val) {
        if (!head) {
            insertBegin(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    // Insert after a node
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                Node* nxt = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nxt;
                nxt->prev = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found!\n";
    }

    // Delete from beginning
    void deleteBegin() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* tail = head->prev;
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* tail = head->prev;
        Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }

    // Delete specific node
    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp == head) deleteBegin();
                else {
                    Node* prev = temp->prev;
                    Node* nxt = temp->next;
                    prev->next = nxt;
                    nxt->prev = prev;
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found!\n";
    }

    // Search
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Update
    void update(int oldVal, int newVal) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Value not found!\n";
    }

    // Display forward
    void displayForward() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    // Display backward
    void displayBackward() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* tail = head->prev;
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << "\n";
    }

    // Reverse list
    void reverse() {
        if (!head) return;
        Node* temp = NULL;
        Node* current = head;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != head);
        head = temp->prev;
    }
};

// ---------------------
// Driver code
// ---------------------
int main() {
    CDLL list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertBegin(5);
    list.insertAfter(10, 15);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.update(15, 17);
    list.deleteBegin();
    list.deleteEnd();
    list.deleteNode(17);

    cout << "After Deletions: ";
    list.displayForward();

    list.reverse();
    cout << "Reversed: ";
    list.displayForward();

    cout << "Search 20: " << (list.search(20) ? "Found\n" : "Not Found\n");

    return 0;
}
