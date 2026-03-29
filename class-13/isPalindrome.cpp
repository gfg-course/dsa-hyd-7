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

Node* getMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

// TC: O(n)
// AS: O(1)
bool isPalindrome(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* mid = getMiddle(head);
    Node* head2 = mid->next;
    mid->next = NULL;

    head2 = reverse(head2);

    while (head != NULL && head2 != NULL) {
        if (head->data != head2->data) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << isPalindrome(head) << endl;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(3);
    head2->next->next->next->next = new Node(2);
    head2->next->next->next->next->next = new Node(1);

    cout << isPalindrome(head2) << endl;

    Node* head3 = new Node(1);
    head3->next = new Node(2);
    head3->next->next = new Node(3);
    head3->next->next->next = new Node(4);
    head3->next->next->next->next = new Node(2);
    head3->next->next->next->next->next = new Node(1);

    cout << isPalindrome(head3) << endl;

    cout << isPalindrome(NULL) << endl;
}
