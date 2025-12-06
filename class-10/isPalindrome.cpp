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

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

Node* reverseALinkedList(Node* head) {

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

    // Step-1: Break the list into 2 equal halves.
    Node* mid = getMiddle(head);
    Node* head2 = mid->next;
    mid->next = NULL;

    // Step-2: Reverse the second half.
    head2 = reverseALinkedList(head2);

    // Step-3: Compare the two halves node-by-node.
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
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << isPalindrome(head) << endl;


    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(1);
    head2->next->next->next->next = new Node(1);

    cout << isPalindrome(head2) << endl;

}
