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
}
