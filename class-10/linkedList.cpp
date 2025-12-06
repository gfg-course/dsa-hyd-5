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

    // TC: O(pos)
    // AS: O(1)
    void deleteFromPos(int pos) {
        if (pos == 0 || head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        
        int hops = 0;
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
    
    ll->deleteFromBeginning();

    ll->print();

    ll->deleteFromEnd();

    ll->print();

    ll->insertAtBeginning(1);
    ll->insertAtEnd(4);
    ll->insertAtEnd(5);

    ll->print();

    ll->deleteFromPos(2);
    ll->deleteFromPos(1000);
    ll->deleteFromPos(0);

    ll->print();
}
