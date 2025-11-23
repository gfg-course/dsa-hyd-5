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

    // TC: O(min(n, pos))
    // AS: O(1)
    void insertAtPos(int value, int pos) {
        if (pos == 0 || head == NULL) {
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

    LinkedList* ll = new LinkedList();

    ll->insertAtBeginning(4);
    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);

    ll->print();

    ll->insertAtEnd(6);
    ll->insertAtEnd(7);
    ll->insertAtEnd(8);

    ll->print();

    ll->insertAtPos(5, 4);
    ll->insertAtPos(0, 0);
    ll->insertAtPos(9, 100);

    ll->print();
}
