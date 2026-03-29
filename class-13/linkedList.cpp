#include<bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {

public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    // TC: O(1)
    // AS: O(1)
    void insertAtBeginning(int value) {

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    // AS: O(1)
    void insertAtEnd(int value) {
        if (head == NULL) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new Node(value);
    }
    
    // TC: O(min(pos, n))
    // AS: O(1)
    void insertAtPos(int value, int pos) {
        if (head == NULL || pos == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        int hops = 0;
        while (hops < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // TC: O(1)
    // AS: O(1)
    void deleteFromBeginning() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete(temp);
    }

    // TC: O(n)
    // AS: O(1)
    void deleteFromEnd() {
        if (head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* temp2 = temp->next;
        temp->next = NULL;
        delete(temp2);
    }

    // TC: O(min(n, pos))
    // AS: O(1)
    void deleteFromPos(int pos) {

        if (head == NULL || pos == 0) {
            deleteFromBeginning();
            return;
        }

        int hops = 0;
        Node* temp = head;

        while (hops < pos - 1 && temp->next->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete(temp2);
    }

    // TC: O(n)
    // AS: O(1)
    void reverse() {
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    int getMiddle() {
        if (head == NULL) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    // TC: O(n)
    // AS: O(1)
    void print() {

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    LinkedList* ll = new LinkedList;
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(4);
    ll->insertAtBeginning(0);

    ll->print(); // 0 1 2 3 4

    ll->insertAtPos(5, 2); // 0 1 5 2 3 4
    ll->insertAtPos(-1, 0); // -1 0 1 5 2 3 4
    ll->insertAtPos(6, 1000); // -1 0 1 5 2 3 4 6

    ll->print(); // -1 0 1 5 2 3 4 6

    ll->deleteFromBeginning(); // 0 1 5 2 3 4 6
    ll->deleteFromEnd(); // 0 1 5 2 3 4
    ll->deleteFromPos(2); // 0 1 2 3 4
    ll->deleteFromPos(200); // 0 1 2 3

    ll->print(); // 0 1 2 3

    ll->reverse();

    ll->print(); // 3 2 1 0

    cout << ll->getMiddle() << endl; // 1

    ll->insertAtBeginning(4); // 4 3 2 1 0

    ll->print(); // 4 3 2 1 0

    cout << ll->getMiddle() << endl; // 2
}
