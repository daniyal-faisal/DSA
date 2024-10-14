#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* next;
    
    node() : value(0){
    	next = NULL;
	};
    
    node(int _value) : value(_value){
    	next = NULL;
	};
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
    //neww->value = x;
    neww->next = head;
    head = neww;
}

int addnodeend(node* n, node* end) {
    while (1) {
        if (n->next == NULL) {
            end->value = 5;
            n->next = end;
            end->next = NULL;
            return 1;
        } else {
            n = n->next;
        }
    }
}

void insertNodeAfter(int pos, int data, node* n) {
    node* between = new node(data);
   // between->value = data;
    int currpos = 0;
    node* temp = n;

    while (temp != NULL && currpos < pos - 1) {
        temp = temp->next;
        currpos++;
    }

    between->next = temp->next;
    temp->next = between;
}

void deletenodelast(node* head) {
    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deletenode(node* head, int loc) {
    for (int i = 0; i < loc - 1; i++) {
        head = head->next;
    }
    head->next = head->next->next;
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

   // head->value = 1;
    head->next = second;

    //second->value = 2;
    second->next = third;

    //third->value = 3;
    third->next = NULL;

    cout << "Linked list Made:" << endl;
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
