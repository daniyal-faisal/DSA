#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* next;
    node* prev; // Adding a prev pointer

    node() : value(0), next(NULL), prev(NULL) {};
    
    node(int _value) : value(_value), next(NULL), prev(NULL) {};
};

void printlist(node* n) {
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

void addnode(node*& head, int x) {
    node* neww = new node(x);
    neww->next = head;
    if (head != NULL) {
        head->prev = neww; // Set the previous head's prev pointer
    }
    head = neww;
}

int addnodeend(node* n, node* end) {
    while (n->next != NULL) {
        n = n->next;
    }
    end->value = 5;
    n->next = end;
    end->prev = n; // Set the new node's prev pointer
    return 1;
}

void insertNodeAfter(int pos, int data, node* n) {
    node* between = new node(data);
    int currpos = 0;
    node* temp = n;

    while (temp != NULL && currpos < pos - 1) {
        temp = temp->next;
        currpos++;
    }

    between->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = between; // Update the next node's prev pointer
    }
    temp->next = between;
    between->prev = temp; // Set the between node's prev pointer
}

void deletenodelast(node* head) {
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deletenode(node* head, int loc) {
    for (int i = 0; i < loc - 1; i++) {
        head = head->next;
    }
    node* toDelete = head->next;
    head->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = head; // Update the next node's prev pointer
    }
    delete toDelete;
}

void updatenode(node* head, int loc, int x) {
    for (int i = 0; i < loc; i++) {
        head = head->next;
    }
    head->value = x;
}

int main() {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* end = new node();

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = NULL;

    cout << "Doubly Linked list Made:" << endl;
    printlist(head);
    cout << endl;

    cout << "Node Added at start:" << endl;
    addnode(head, 4);
    printlist(head);

    cout << endl;
    cout << "Node Added at End:" << endl;
    addnodeend(head, end);
    printlist(head);

    cout << endl;
    cout << "Node Added after a position:" << endl;
    insertNodeAfter(2, 9, head);
    printlist(head);

    cout << endl;
    cout << "Last node deleted:" << endl;
    deletenodelast(head);
    printlist(head);

    cout << endl;
    cout << "Node deleted from position:" << endl;
    deletenode(head, 2);
    printlist(head);

    cout << endl;
    cout << "Node updated from position:" << endl;
    updatenode(head, 2, 5);
    printlist(head);

    return 0;
}
