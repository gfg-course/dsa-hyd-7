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

Node* merge2SortedLinkedLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    if (head1->data < head2->data) {
        head1->next = merge2SortedLinkedLists(head1->next, head2);
        return head1;
    } else {
        head2->next = merge2SortedLinkedLists(head1, head2->next);
        return head2;
    }
}

int main() {
}
