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

// TC: O(n) - TODO: try to estimate the number of iterations of the loop.
// AS: O(1)
void detectAndRemoveLoop(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return;
    }

    // if the meeting point is head, i.e., x = 0.
    if (slow == head) {
        while (slow->next != head) {
            slow = slow->next;
        }

        slow->next = NULL;
        return;
    }

    Node* p1 = head;
    Node* p2 = slow;

    while (p1->next != p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }

    p2->next = NULL;
}

int main() {
}
