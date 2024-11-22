-----------------------------------------------------------------------------------------------------------------------------------
bubble sort
----------------------------------------------------------------------------------------------------------------------------------------

void Bubble_Sort(int arr[], int n)  
{
    for(int i = 1; i < n; ++i)      
    {    
                for(int j = 0; j <= (n - i - 1); ++j)   
        {    
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);  
        }
    }
}
----------------------------------------------------------------------------------------------------------------------------------------
selection sort
----------------------------------------------------------------------------------------------------------------------------------------

selection_Sort(int arr[], int n)  
{
    for(int i = 0; i < n - 1; ++i)  
    {
        int min_index = i;  
        for(int j = i + 1; j < n; ++j)  
        {
            if(arr[j] < arr[min_index])  
                min_index = j;
        }
        swap(arr[i], arr[min_index]);  
    }
}
----------------------------------------------------------------------------------------------------------------------------------------
inserttion sort
----------------------------------------------------------------------------------------------------------------------------------------

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
----------------------------------------------------------------------------------------------------------------------------------------
comb sort
----------------------------------------------------------------------------------------------------------------------------------------

int shellSort(int arr[], int n)
{
  
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            
            int temp = arr[i];

            
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            
            arr[j] = temp;
        }
    }
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
radix sort
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int getMax(int a[], int n) {
int max = a[0];
for(int i = 1; i<n; i++) {
if(a[i] > max)
max = a[i];
}
return max; //maximum element from the array
}

void countingSort(int a[], int n, int place) // function to implement counting sort
{
int output[n + 1];
int count[10] = {0};

// Calculate count of elements
for (int i = 0; i < n; i++)
count[(a[i] / place) % 10]++;

// Calculate cumulative frequency
for (int i = 1; i < 10; i++)
count[i] += count[i - 1];

// Place the elements in sorted order

for (int i = n - 1; i >= 0; i--) {
output[count[(a[i] / place) % 10] - 1] = a[i];
count[(a[i] / place) % 10]--;
}

for (int i = 0; i < n; i++)
a[i] = output[i];
}

// function to implement radix sort
void radixsort(int a[], int n) {

// get maximum element from array
int max = getMax(a, n);

// Apply counting sort to sort elements based on place value
for (int place = 1; max / place > 0; place *= 10)
countingSort(a, n, place);
}

// function to print array elements
void printArray(int a[], int n) {
for (int i = 0; i < n; ++i)
cout<<a[i]<<" ";
}

int main() {
int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
int n = sizeof(a) / sizeof(a[0]);

cout<<"Before sorting array elements are - \n";
printArray(a,n);
radixsort(a, n);
cout<<"\n\nAfter applying Radix sort, the array elements are - \n";
printArray(a, n);
return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
shell sort
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
/* function to implement shellSort */
int shell(int a[], int n)
{
/* Rearrange the array elements at n/2, n/4, ..., 1 intervals */
for (int interval = n/2; interval > 0; interval /= 2)
{
for (int i = interval; i < n; i += 1)
{
/* store a[i] to the variable temp and make the ith position empty */
int temp = a[i];
int j;
for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
a[j] = a[j - interval];

// put temp (the original a[i]) in its correct position
a[j] = temp;

}
}
return 0;
}
void printArr(int a[], int n) /* function to print the array elements */
{
int i;
for (i = 0; i < n; i++)
cout<<a[i]<<" ";
}
int main()
{
int a[] = { 32, 30, 39, 7, 11, 16, 24, 41 };
int n = sizeof(a) / sizeof(a[0]);
cout<<"Before sorting array elements are - \n";
printArr(a, n);
shell(a, n);
cout<<"\nAfter applying shell sort, the array elements are - \n";
printArr(a, n);
return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
binary serach
----------------------------------------------------------------------------------------------------------------------------------------

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == x)
            return mid;

        
        if (arr[mid] < x)
            low = mid + 1;

        
        else
            high = mid - 1;
    }

    return -1;
    ------------------------------------------------------------------------------------------------
    interpolation 
    ------------------------------------------------------------------------------------------
	if (lo <= hi && x >= arr[lo] && x <= arr[hi])
	pos = lo+ (((double)(hi - lo) / (arr[hi] - arr[lo]))* (x - arr[lo]));

----------------------------------------------------------------------------------------------------------------------------------------
infix to postfix 
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;  // Maximum size of the stack

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;  // For non-operators
    }
}

// Function to convert infix to postfix
void infixToPostfix(const string& infix, string& postfix) {
    char stack[MAX];  // Array to simulate stack
    int top = -1;     // Stack pointer

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop from stack until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += stack[top--];
            }
            top--;  // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix += stack[top--];
            }
            stack[++top] = c;  // Push the current operator to the stack
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        postfix += stack[top--];
    }
}

int main() {
    string infix;
    string postfix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

---------------------------------------------------------------------------
postfix to infix 
-----------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    string stack[100];  // Simulating stack with an array
    int top = -1;       // Stack pointer

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            stack[++top] = string(1, c);  // Push the character as a string
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string operand2 = stack[top--];  // Pop top
            string operand1 = stack[top--];  // Pop next

            // Create a string representing the infix expression
            string expr = "(" + operand1 + c + operand2 + ")";
            stack[++top] = expr;  // Push the new expression back onto the stack
        }
    }

    // The final expression is at the top of the stack
    return stack[top];
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------

prefix to infix
---------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix to infix expression
string prefixToInfix(string prefix) {
    int length = prefix.size();
    // Array to simulate a stack for storing partial results
    string arr[length];
    int top = -1;

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand (a-z or A-Z), push it to the 'stack'
        if (!isOperator(c)) {
            arr[++top] = string(1, c);
        }
        // If the character is an operator
        else {
            // Pop two operands from the 'stack'
            string op1 = arr[top--];
            string op2 = arr[top--];

            // Form the new infix expression: (op1 operator op2)
            string temp = "(" + op1 + c + op2 + ")";

            // Push the new expression back to the 'stack'
            arr[++top] = temp;
        }
    }

    // The final result will be at the top of the 'stack'
    return arr[top];
}

int main() {
    string prefix = "*+AB-CD";
    cout << "Infix expression: " << prefixToInfix(prefix) << endl;
    return 0;
}

-------------------------------------------------------------------
 infix to prefix  
---------------------------------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;  // Maximum size of the stack

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;  // For non-operators
    }
}

// Function to reverse a string
void reverse(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

// Function to convert infix to postfix
void infixToPostfix(const string& infix, string& postfix) {
    char stack[MAX];  // Array to simulate stack
    int top = -1;     // Stack pointer

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop from stack until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += stack[top--];
            }
            top--;  // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix += stack[top--];
            }
            stack[++top] = c;  // Push the current operator to the stack
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        postfix += stack[top--];
    }
}

// Function to convert infix to prefix
void infixToPrefix(const string& infix, string& prefix) {
    string reversedInfix = infix; // Copy of infix for reversal
    reverse(reversedInfix);        // Reverse the infix expression

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < reversedInfix.length(); i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    string postfix;
    infixToPostfix(reversedInfix, postfix); // Convert reversed infix to postfix
    reverse(postfix);                       // Reverse the postfix to get prefix
    prefix = postfix;                       // Store the result in prefix
}

int main() {
    string infix;
    string prefix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPrefix(infix, prefix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------
linkedlist se calculator
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string data;  // Can be a number, operator, or parentheses
    Node* next;
    Node* prev;

    Node(string val) : data(val), next(NULL), prev(NULL) {}
};

// Linked List class to store the expression
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // Function to add nodes to the linked list
    void append(string data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to evaluate a part of the list without parentheses
    int evaluateSimple(Node* start, Node* end) {
        Node* current = start;
        int result = stoi(current->data);
        current = current->next;

        while (current != end && current != NULL) {
            string op = current->data;
            current = current->next;
            int num = stoi(current->data);

            if (op == "+") result += num;
            else if (op == "-") result -= num;
            else if (op == "*") result *= num;
            else if (op == "/") result /= num;

            current = current->next;
        }
        return result;
    }

    // Function to evaluate the expression in the linked list
    int evaluate() {
        Node* current = head;

        while (current != NULL) {
            if (current->data == "(") {
                // Find the matching closing parenthesis
                Node* innerStart = current->next;
                Node* innerEnd = findClosingParenthesis(current);
                
                // Evaluate the sub-expression inside parentheses
                int innerResult = evaluateSimple(innerStart, innerEnd);

                // Replace the parenthesis with the result in the linked list
                replaceWithResult(current, innerEnd, innerResult);

                current = head;  // Restart after modifying the list
            } else {
                current = current->next;
            }
        }

        // Evaluate the remaining expression (without parentheses)
        return evaluateSimple(head, NULL);
    }

private:
    // Function to find the matching closing parenthesis for a given opening parenthesis
    Node* findClosingParenthesis(Node* start) {
        Node* current = start;
        int openCount = 1;

        while (current != NULL) {
            if (current->data == "(") openCount++;
            if (current->data == ")") openCount--;

            if (openCount == 0) return current;
            current = current->next;
        }
        return NULL;  // Shouldn't reach here if parentheses are balanced
    }

    // Function to replace a parenthesis pair with the result of the evaluation
    void replaceWithResult(Node* start, Node* end, int result) {
        // Create a new node with the result
        Node* resultNode = new Node(to_string(result));

        // Link the previous node to the result node
        if (start->prev != NULL) {
            start->prev->next = resultNode;
            resultNode->prev = start->prev;
        } else {
            head = resultNode;
        }

        // Link the result node to the node after the closing parenthesis
        if (end->next != NULL) {
            resultNode->next = end->next;
            end->next->prev = resultNode;
        } else {
            tail = resultNode;
        }

        // Free the memory of nodes from start to end
        Node* current = start;
        while (current != end) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete end;
    }
};

int main() {
    LinkedList expression;

    // Building the expression: 10 + (12 * (2 - 2))
    expression.append("10");
    expression.append("+");
    expression.append("(");
    expression.append("12");
    expression.append("*");
    expression.append("(");
    expression.append("2");
    expression.append("-");
    expression.append("2");
    expression.append(")");
    expression.append(")");

    // Evaluate the expression in the linked list
    cout << "Answer: " << expression.evaluate() << endl;

    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
stack using linklist
----------------------------------------------------------------------------------------------------------------------------------------

// C++ program to implement a stack using singly linked list
#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

// Class to implement stack using a singly linked list
class Stack {

    // head of the linked list
    Node* head;

public:
    // Constructor to initialize the stack
    Stack() { this->head = nullptr; }

    // Function to check if the stack is empty
    bool isEmpty() {
      
        // If head is nullptr, the stack is empty
        return head == nullptr;
    }

    // Function to push an element onto the stack
    void push(int new_data) {
      
        // Create a new node with given data
        Node* new_node = new Node(new_data);

        // Check if memory allocation for the new node
        // failed
        if (!new_node) {
            cout << "\nStack Overflow";
        }

        // Link the new node to the current top node
        new_node->next = head;

        // Update the top to the new node
        head = new_node;
    }

    // Function to remove the top element from the stack
    void pop() {

        // Check for stack underflow
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            // Assign the current top to a temporary
            // variable
            Node* temp = head;

            // Update the top to the next node
            head = head->next;

            // Deallocate the memory of the old top node
            delete temp;
        }
    }

    // Function to return the top element of the stack
    int peek() {

        // If stack is not empty, return the top element
        if (!isEmpty())
            return head->data;
        else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
    }
};

// Driver program to test the stack implementation
int main() {
    // Creating a stack
    Stack st;

    // Push elements onto the stack
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
      cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
linked list using bubble sort
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream> 
Using namespace std; 
class Node { 
public: 
 int data; 
 Node* next; 
 Node(int val) : data(val), next(nullptr) {} 
}; 
class LinkedList { 
private: 
 Node* head; 
public: 
 LinkedList() : head(nullptr) {} 
 // Insert a new node at the front of the list 
 void insert(int val) { 
 Node* newNode = new Node(val); 
 newNode->next = head; 
 head = newNode; 
 }
 // Bubble sort function for the linked list  void bubbleSort() { 
 if (!head) return; 
 bool swapped; 
 do { 
 swapped = false; 
 Node* current = head; 
 while (current && current->next) {  if (current->data > current->next->data) {  // Swap data directly 
 int temp = current->data; 
 current->data = current->next->data;  current->next->data = temp;  swapped = true; 
 } 
 current = current->next; 
 } 
 } while (swapped); 
 } 
 // Function to print the linked list 
 void printList() const { 
 Node* current = head; 
 while (current) { 
 cout << current->data << " ";
 current = current->next;  } 
 cout << endl; 
 } 
}; 
int main() { 
 LinkedList list; 
 list.insert(5); 
 list.insert(1); 
 list.insert(4); 
 list.insert(2); 
 list.insert(3); 
 cout << "Before sorting: ";  list.printList(); 
 list.bubbleSort(); 
 cout << "After sorting: ";  list.printList(); 
 return 0; 
} 

----------------------------------------------------------------------------------------------------------------------------------------
selection sort using linked list
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream> 
Using namespace std; 
class Node { 
public: 
 int data; 
 Node* next; 
  
 Node(int val) : data(val), next(nullptr) {} 
}; 
class LinkedList { 
public: 
 Node* head; 
 LinkedList() : head(nullptr) {} 
 // Function to insert a new node at the end  void insert(int data) { 
 Node* newNode = new Node(data); 
 if (!head) { 
 head = newNode; 
 } else { 
 Node* temp = head; 
 while (temp->next) { 
 temp = temp->next;
 } 
 temp->next = newNode; 
 } 
 } 
 // Function to print the list 
 void printList() { 
 Node* temp = head; 
 while (temp) { 
 cout << temp->data << " "; 
 temp = temp->next; 
 } 
 cout << endl; 
 } 
 // Function to perform selection sort 
 void selectionSort() { 
 if (head == NULL || head->next == NULL) return; 
 Node* current = head; 
 while (current) { 
 Node* minNode = current; 
 Node* temp = current->next; 
 // Find the node with the minimum value in the unsorted part of the list  while (temp) { 
 if (temp->data < minNode->data) {
 minNode = temp; 
 } 
 temp = temp->next; 
 } 
 // Instead of swapping nodes, swap their values  if (minNode != current) { 
 int tempData = current->data; 
 current->data = minNode->data;  minNode->data = tempData; 
 } 
 // Move to the next node in the list  current = current->next; 
 
}; 
int main() { 
 LinkedList list; 
  
 list.insert(30); 
 list.insert(3); 
 list.insert(4); 
 list.insert(20); 
 list.insert(5);

 cout << "Original list: ";  list.printList(); 
 list.selectionSort(); 
 cout << "Sorted list: "; 
 list.printList(); 
 return 0; 
} 

----------------------------------------------------------------------------------------------------------------------------------------
insertation sort linklist
----------------------------------------------------------------------------------------------------------------------------------------

class LinkedList { 
public:
 Node* head; 
 LinkedList() : head(nullptr) {} 
 // Function to insert a new node at the end  void insert(int data) { 
 Node* newNode = new Node(data);  if (!head) { 
 head = newNode; 
 } else { 
 Node* temp = head; 
 while (temp->next) { 
 temp = temp->next; 
 } 
 temp->next = newNode; 
 } 
 } 
 // Function to print the list 
 void printList() { 
 Node* temp = head; 
 while (temp) { 
 cout << temp->data << " "; 
 temp = temp->next; 
 } 
 cout << endl; 
 }
 // Function to perform insertion sort 
 void insertionSort() { 
 if (head == NULL || head->next == NULL) return; // If the list is empty or has only one  element, it's already sorted. 
 // Initialize the sorted part of the list with the first node. 
 Node* sorted = nullptr; 
 Node* current = head; 
 while (current) { 
 Node* nextNode = current->next; // Save the next node 
 // If the sorted list is empty or the current node should be placed at the beginning  if (sorted == NULL || current->data <= sorted->data) { 
 current->next = sorted; // Insert the current node at the start of sorted  sorted = current; 
 } else { 
 // Find the correct position to insert current in the sorted part  Node* temp = sorted; 
 while (temp->next && temp->next->data < current->data) {  temp = temp->next; 
 } 
 // Insert the current node after temp 
 current->next = temp->next; 
 temp->next = current;
 } 
 // Move to the next node in the original list  current = nextNode; 
 } 
 // Update the head to point to the sorted list  head = sorted; 
 } 
}; 
int main() { 
 LinkedList list; 
 list.insert(30); 
 list.insert(100); 
 list.insert(4); 
 list.insert(20); 
 list.insert(5); 
 cout << "Original list: "; 
 list.printList(); 
 list.insertionSort(); 
 cout << "Sorted list: "; 
 list.printList();

 return 0; 
} 
----------------------------------------------------------------------------------------------------------------------------------------
wordserach uz cross word
----------------------------------------------------------------------------------------------------------------------------------------
// C++ program to search a word in a 2D grid
#include <iostream>
using namespace std;

bool isSafe(char grid[3][4], int i, int j, char letter){
    return (i >= 0 && j >= 0 && i < 3 && j < 4 && grid[i][j] == letter);
}


bool findWord(string word, char grid[3][4], int i, int j, int x, int y, int index){
    if(index == word.length()){
        return true;
    }
    if(isSafe(grid, i, j, word[index])){
        return findWord(word, grid, i + x, j + y, x, y, index + 1);

    }
    return false;
}


int function(char grid[3][4], string word){
    int count = 0;
    int directionX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int directionY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(grid[i][j] == word[0]){
                for(int k = 0; k < 8; k++){
                    if(findWord(word, grid, i, j, directionX[k], directionY[k], 0))
                        count++;
                }
            }
        }
    }
    return count;
}



int main() {
    char grid[3][4] = {{'a','b','a','b'},
                    {'a','b','e','b'},
                    {'e','b','e','b'}};
    string word = "abe";

    int count = function(grid, word);
    cout << count << endl;
}

----------------------------------------------------------------------------------------------------------------------------------------
palindrome
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;  // Size of the matrix

// Helper function to check if a given string is a palindrome
bool isPalindrome(char str[], int length) {
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

// Recursive function to explore one direction and build the word
void exploreDirection(char matrix[N][N], int x, int y, int dirX, int dirY, char word[], int length) {
    // Base case: if the indices are out of bounds, stop recursion
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return;
    }

    // Add the current character to the word and null-terminate it
    word[length] = matrix[x][y];
    word[length + 1] = '\0';

    // Check if the word is a palindrome
    if (length + 1 > 1 && isPalindrome(word, length + 1)) {
        cout << "Palindrome found: " << word << endl;
    }

    // Move to the next cell in the given direction
    exploreDirection(matrix, x + dirX, y + dirY, dirX, dirY, word, length + 1);
}

// Function to search for palindromes from each position in all directions recursively
void findPalindromesRecursively(char matrix[N][N], int row, int col) {
    // Directions: right, left, down, up, and all 4 diagonals
    int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    char word[N + 1];  // To store the word (up to N characters) in any direction

    // Search in each of the 8 possible directions using recursion
    for (int d = 0; d < 8; ++d) {
        exploreDirection(matrix, row, col, directions[d][0], directions[d][1], word, 0);
    }
}

int main() {
    // 5x5 matrix
    char matrix[N][N] = {
        {'G', 'R', 'O', 'O', 'T'},
        {'B', 'A', 'R', 'R', 'O'},
        {'W', 'R', 'D', 'B', 'S'},
        {'R', 'A', 'D', 'A', 'R'},
        {'W', 'E', 'S', 'T', 'G'}
    };

    // Traverse the matrix to search for palindromes from every position
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            findPalindromesRecursively(matrix, i, j);
        }
    }

    return 0;
}
-----------------------------------------------------------------------------------------
queue array
-----------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
    
    // Constructor to initialize the queue
    Queue(int c)
    {
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    // Destructor to free the allocated memory
    ~Queue() { delete[] queue; }

    // Function to insert an element at the rear of the queue
    void queueEnqueue(int data)
    {
        // Check if the queue is full
        if (rear == capacity - 1) {
            printf("\nQueue is full\n");
            return;
        }

        // Insert element at the rear
        queue[++rear] = data;
    }

    // Function to delete an element from the front 
    // of the queue
    void queueDequeue()
    {
        // If the queue is empty
        if (front > rear) {
            printf("\nQueue is empty\n");
            return;
        }

        // Shift all elements from index 1 till rear to 
        // the left by one
        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        // Decrement rear
        rear--;
    }

    // Function to print queue elements
    void queueDisplay()
    {
        if (front > rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        // Traverse front to rear and print elements
        for (int i = front; i <= rear; i++) {
            printf(" %d <-- ", queue[i]);
        }
        printf("\n");
    }

    // Function to print the front of the queue
    void queueFront()
    {
        if (rear == -1) {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d\n", queue[front]);
    }
};

// Driver code
int main(void)
{
    // Create a queue of capacity 4
    Queue q(4);

    // Print queue elements
    q.queueDisplay();

    // Insert elements in the queue
    q.queueEnqueue(20);
    q.queueEnqueue(30);
    q.queueEnqueue(40);
    q.queueEnqueue(50);

    // Print queue elements
    q.queueDisplay();

    // Insert element in the queue
    q.queueEnqueue(60);

    // Print queue elements
    q.queueDisplay();

    // Dequeue elements
    q.queueDequeue();
    q.queueDequeue();

    printf("\nAfter two node deletions\n");

    // Print queue elements
    q.queueDisplay();
    
    printf("\nAfter one insertion\n");
    q.queueEnqueue(60);
    
    // Print queue elements
    q.queueDisplay();

    // Print front of the queue
    q.queueFront();

    return 0;
}
--------------------------------------------
queue linklist
-----------------------------------------


// C++ program to implement the queue data structure using
// linked list
#include <bits/stdc++.h>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};

// Class to implement queue operations using a linked list
class Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;

public:
    // Constructor to initialize the front and rear
    Queue() { front = rear = nullptr; }

    // Function to check if hte queu is empty
    bool isEmpty()
    {
        // If the front and rear are null, then the queue is
        // empty, otherwise it's not
        if (front == nullptr) {
            return true;
        }
        return false;
    }

    // Function to add an element to the queue
    void enqueue(int new_data) {

        // Create a new linked list node
        Node* new_node = new Node(new_data);

        // If queue is empty, the new node is both the front
        // and rear
        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }

        // Add the new node at the end of the queue and
        // change rear
        rear->next = new_node;
        rear = new_node;
    }

    // Function to remove an element from the queue
    void dequeue() {

        // If queue is empty, return
        if (this->isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Store previous front and move front one node
        // ahead
        Node* temp = front;
        front = front->next;

        // If front becomes nullptr, then change rear also
        // to nullptr
        if (front == nullptr)
            rear = nullptr;

        // Deallocate memory of the old front node
        delete temp;
    }

    // Function to get the front element of the queue
    int getFront() {
      
      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return front->data;
    }

    // Function to get the rear element of the queue
    int getRear() {

      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
      
        return rear->data;
    }
};

// Driver code to test the queue implementation
int main()
{
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    // Dequeue elements from the queue
    q.dequeue();
    q.dequeue();

    // Enqueue more elements into the queue
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue an element from the queue
    q.dequeue();

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}

--------------------------------------------------------------
staack using LinkedList
--------------------------------------------------------------
// C++ program to implement a stack using singly linked list
#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

// Class to implement stack using a singly linked list
class Stack {

    // head of the linked list
    Node* head;

public:
    // Constructor to initialize the stack
    Stack() { this->head = nullptr; }

    // Function to check if the stack is empty
    bool isEmpty() {
      
        // If head is nullptr, the stack is empty
        return head == nullptr;
    }

    // Function to push an element onto the stack
    void push(int new_data) {
      
        // Create a new node with given data
        Node* new_node = new Node(new_data);

        // Check if memory allocation for the new node
        // failed
        if (!new_node) {
            cout << "\nStack Overflow";
        }

        // Link the new node to the current top node
        new_node->next = head;

        // Update the top to the new node
        head = new_node;
    }

    // Function to remove the top element from the stack
    void pop() {

        // Check for stack underflow
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            // Assign the current top to a temporary
            // variable
            Node* temp = head;

            // Update the top to the next node
            head = head->next;

            // Deallocate the memory of the old top node
            delete temp;
        }
    }

    // Function to return the top element of the stack
    int peek() {

        // If stack is not empty, return the top element
        if (!isEmpty())
            return head->data;
        else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
    }
};

// Driver program to test the stack implementation
int main() {
    // Creating a stack
    Stack st;

    // Push elements onto the stack
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
      cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}

-----------------------------------------------------------------------------
stack with array
--------------------------------------------------------------------------
/* C++ program to implement basic stack 
operations */
#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
    int top; 

public: 
    int a[MAX]; // Maximum size of Stack 

    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 

int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 

bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    
    //print top element of stack after popping 
    cout << "Top element is : " << s.peek() << endl; 
    
    //print all elements in stack : 
    cout <<"Elements present in stack : "; 
    while(!s.isEmpty()) 
    { 
        // print top element in stack 
        cout << s.peek() <<" "; 
        // remove top element in stack 
        s.pop(); 
    } 

    return 0; 
}


---------------------------------------------------------------------------------------------------------------------------------------
Super set array
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Solution {
private:
    void solve(int* nums, int* output, int index, int n, int outputIndex, int** ans, int& ansIndex) {
        // base case
        if (index >= n) {
            // Save the current subset into the answer array
            ans[ansIndex] = new int[outputIndex]; // allocate space for current subset
            for (int i = 0; i < outputIndex; i++) {
                ans[ansIndex][i] = output[i];
            }
            ansIndex++;
            return;
        }
        
        // exclude
        solve(nums, output, index + 1, n, outputIndex, ans, ansIndex);
        
        // include
        output[outputIndex] = nums[index];
        solve(nums, output, index + 1, n, outputIndex + 1, ans, ansIndex);
    }

public:
    int subsets(int* nums, int n, int** ans) {
        int* output = new int[n]; // To store current subset
        int outputIndex = 0;
        int ansIndex = 0;
        solve(nums, output, 0, n, outputIndex, ans, ansIndex);
        delete[] output;
        return ansIndex; // Return number of subsets generated
    }
};

int main() {
    Solution sol;
    
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    // The total number of subsets of a set is 2^n
    int totalSubsets = 1 << n; // 2^n
    int** ans = new int*[totalSubsets];

    int count = sol.subsets(nums, n, ans);

    // Printing subsets
    for (int i = 0; i < count; i++) {
        cout << "{ ";
        for (int j = 0; ans[i][j] != '\0'; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < totalSubsets; i++) {
        delete[] ans[i];
    }
    delete[] ans;

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
Super set string
----------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

void solve(string* ans, int& idx, string str, string output, int i) {
    // base case
    if (i >= str.length()) {
        if (output.length() > 0) {
            ans[idx++] = output; // store the subsequence in the array
        }
        return;
    }
    
    // exclude
    solve(ans, idx, str, output, i + 1);

    // include
    output.push_back(str[i]);
    solve(ans, idx, str, output, i + 1);
}

int subsequences(string str, string* ans) {
    string output = "";
    int idx = 0; // index to keep track of current position in the array
    solve(ans, idx, str, output, 0);
    return idx; // return the number of subsequences generated
}

int main() {
    string str = "abc";
    
    // To store the subsequences, we'll use a string array
    // The total number of subsequences of a string is 2^n - 1 (excluding the empty subsequence)
    int max_subsequences = (1 << str.length()) - 1; // 2^n - 1

    string* ans = new string[max_subsequences];
    int count = subsequences(str, ans);

    // Print all subsequences
    for (int i = 0; i < count; i++) {
        cout << ans[i] << endl;
    }

    // Free dynamically allocated memory
    delete[] ans;

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
Permutatuion Array
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

void solve(int nums[], int ans[][3], int& count, int size, int index) {
    // Base case
    if (index >= size) {
        // Copy current permutation to ans
        for (int i = 0; i < size; i++) {
            ans[count][i] = nums[i];
        }
        count++;
        return;
    }

    for (int j = index; j < size; j++) {
        // Swap nums[index] and nums[j]
        int temp = nums[index];
        nums[index] = nums[j];
        nums[j] = temp;

        // Recurse for the next index
        solve(nums, ans, count, size, index + 1);

        // Backtrack (undo swap)
        temp = nums[index];
        nums[index] = nums[j];
        nums[j] = temp;
    }
}

void permute(int nums[], int size) {
    // Estimate the maximum number of permutations (size factorial)
    int maxPermutations = 1;
    for (int i = 1; i <= size; i++) {
        maxPermutations *= i;
    }

    // Output array to store all permutations
    int ans[maxPermutations][3];
    int count = 0;

    solve(nums, ans, count, size, 0);

    // Print all the permutations
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < size; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    permute(nums, size);

    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
permutation string 
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring> // For strlen
using namespace std;

void solve(char str[], char ans[][100], int& count, int size, int index) {
    // Base case
    if (index >= size) {
        // Copy current permutation to ans
        strcpy(ans[count], str);
        count++;
        return;
    }

    for (int j = index; j < size; j++) {
        // Swap str[index] and str[j]
        char temp = str[index];
        str[index] = str[j];
        str[j] = temp;

        // Recurse for the next index
        solve(str, ans, count, size, index + 1);

        // Backtrack (undo swap)
        temp = str[index];
        str[index] = str[j];
        str[j] = temp;
    }
}

void permute(char str[]) {
    int size = strlen(str);

    // Estimate the maximum number of permutations (size factorial)
    int maxPermutations = 1;
    for (int i = 1; i <= size; i++) {
        maxPermutations *= i;
    }

    // Output array to store all permutations (assuming strings have a max length of 100)
    char ans[maxPermutations][100];
    int count = 0;

    solve(str, ans, count, size, 0);

    // Print all the permutations
    for (int i = 0; i < count; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    char str[] = "ABC";  // Input string
    permute(str);

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
Rat in maze
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

bool isSafe(int x, int y, int n, int visited[][100], int m[][100]) {
    // Check if the current cell is within bounds and has not been visited, and is not blocked
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(int m[][100], int n, char ans[][100], int& pathIndex, int x, int y, int visited[][100], char path[], int step) {
    // If the rat reaches the destination (n-1, n-1)
    if (x == n - 1 && y == n - 1) {
        path[step] = '\0';  // Null terminate the path
        strcpy(ans[pathIndex], path);  // Copy the current path into the ans array
        pathIndex++;
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Move Down (D)
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path[step] = 'D';
        solve(m, n, ans, pathIndex, newx, newy, visited, path, step + 1);
    }

    // Move Left (L)
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path[step] = 'L';
        solve(m, n, ans, pathIndex, newx, newy, visited, path, step + 1);
    }

    // Move Right (R)
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path[step] = 'R';
        solve(m, n, ans, pathIndex, newx, newy, visited, path, step + 1);
    }

    // Move Up (U)
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path[step] = 'U';
        solve(m, n, ans, pathIndex, newx, newy, visited, path, step + 1);
    }

    // Backtrack: Unmark the current cell as visited
    visited[x][y] = 0;
}

void ratInMaze(int m[][100], int n) {
    // Array to store all the possible paths
    char ans[100][100];  // Let's assume a maximum of 100 possible paths
    int pathIndex = 0;

    // 2D visited array to mark visited cells
    int visited[100][100] = {0};

    // Path array to store the current path (we assume the maximum length of the path is n*n)
    char path[100];

    // Start solving from (0, 0)
    solve(m, n, ans, pathIndex, 0, 0, visited, path, 0);

    // Print all the possible paths
    for (int i = 0; i < pathIndex; i++) {
        cout << ans[i] << " ";
    }
    if (pathIndex == 0) {
        cout << -1;  // If no path is found, print -1
    }
}

int main() {
    int n = 4;
    int m[100][100] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    ratInMaze(m, n);

    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
Rat in maze
----------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
using namespace std;

bool issafe(char arr[6][6],int x,int y,int vis[6][6])
{
    if(arr[x][y]!='D' && x>=0 && x<6 && y>=0 && y<6 && vis[x][y]!=1 )
    return true;

    return false;
}

void sol(char arr[6][6],int x,int y,int vis[6][6],int energy,int &curr,int solution[6][6])
{
if(x==5 && y==5)
{   
    if(curr<energy){
       for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            solution[i][j] = vis[i][j];
        }
    }
    curr = energy;
    }
}   
    vis[x][y]=1;
    if(issafe(arr,x+1,y,vis)){
        if(arr[x+1][y]== 'H')
        energy--;
    sol(arr,x+1,y,vis,energy,curr,solution);
    if(arr[x+1][y]== 'H')
        energy++;
    }

    if(issafe(arr,x,y+1,vis)){
        if(arr[x][y+1]== 'H')
        energy--;
    sol(arr,x,y+1,vis,energy,curr,solution);
      if(arr[x][y+1]== 'H')
        energy++;
    }

    if(issafe(arr,x-1,y,vis)){
        if(arr[x-1][y]== 'H')
        energy--;
    sol(arr,x-1,y,vis,energy,curr,solution);
       if(arr[x-1][y]== 'H')
        energy++;
   
    }

    if(issafe(arr,x,y-1,vis)){
        if(arr[x][y-1]== 'H')
        energy--;
    sol(arr,x,y-1,vis,energy,curr,solution);
     if(arr[x][y-1]== 'H')
        energy++;
    
    }
    vis[x][y]=0;


}

int main() {
    // Defining a 6x6 2D array based on the image content
    char arr[6][6] = {
        {'S', 'P', 'P', 'D', 'H', 'H'},
        {'P', 'P', 'P', 'D', 'P', 'H'},
        {'P', 'H', 'P', 'P', 'P', 'D'},
        {'P', 'D', 'P', 'D', 'P', 'P'},
        {'P', 'P', 'P', 'H', 'P', 'D'},
        {'P', 'D', 'P', 'P', 'P', 'T'}
    };
    int vis[6][6];
    
     for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            vis[i][j]=0;
        }
    }

    int solution[6][6];
    
     for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            solution[i][j]=0;
        }
    }
    int curr=0;

    sol(arr, 0, 0,vis, 100,curr,solution);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << solution[i][j] << ' ';
        }
        cout << endl;
    }

    return 0; 
}


----------------------------------------------------------------------------------------------------------------------------------------
Quick sort 
----------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
Merge sort
----------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
N Queen 
----------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

// Function to print the solution
void printSolution(int board[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

// Check if a queen can be placed on board[row][col]
bool isSafe(int board[10][10], int row, int col, int n) {
    int i, j;

    // Check the row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens problem
bool solveNQUtil(int board[10][10], int col, int n) {
    // If all queens are placed, return true
    if (col >= n)
        return true;

    // Try placing the queen in all rows, one by one
    for (int i = 0; i < n; i++) {
        // Check if the queen can be placed in board[i][col]
        if (isSafe(board, i, col, n)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place the remaining queens
            if (solveNQUtil(board, col + 1, n))
                return true;

            // If placing the queen doesn't result in a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If no place for the queen in the current column, return false
    return false;
}

// Solve N-Queens problem
bool solveNQ(int n) {
    int board[10][10] = {0};  // Initialize the board with zeros

    if (!solveNQUtil(board, 0, n)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board, n);  // Print the solution
    return true;
}

int main() {
    int n = 10;  // Define the size of the chessboard
    solveNQ(n);  // Solve the N-Queens problem
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
sudoku Solver
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>

using namespace std;

// N is the size of the 2D matrix   N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// Checks whether it will be 
// legal to assign num to the
// given row, col
bool isSafe(int grid[N][N], int row, 
                       int col, int num)
{
    
    // Check if we find the same num 
    // in the similar row , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    // Check if we find the same num in 
    // the similar column , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3, 
            startCol = col - col % 3;
  
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + 
                            startCol] == num)
                return false;

    return true;
}

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool solveSudoku(int grid[N][N], int row, int col)
{
    // Check if we have reached the 8th 
    // row and 9th column (0
    // indexed matrix) , we are 
    // returning true to avoid
    // further backtracking
    if (row == N - 1 && col == N)
        return true;

    // Check if column value  becomes 9 , 
    // we move to next row and
    //  column start from 0
    if (col == N) {
        row++;
        col = 0;
    }
  
    // Check if the current position of 
    // the grid already contains
    // value >0, we iterate for next column
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) 
    {
        
        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we 
        // move to next column
        if (isSafe(grid, row, col, num)) 
        {
            
           /* Assigning the num in 
              the current (row,col)
              position of the grid
              and assuming our assigned 
              num in the position
              is correct     */
            grid[row][col] = num;
          
            //  Checking for next possibility with next
            //  column
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
      
        // Removing the assigned num , 
        // since our assumption
        // was wrong , and we go for 
        // next assumption with
        // diff num value
        grid[row][col] = 0;
    }
    return false;
}

// Driver Code
int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;

    return 0;
    // This is code is contributed by Pradeep Mondal P
}

______________
mergesort linked list
_____________
#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->value < l2->value) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to split the linked list into two halves
ListNode* getMiddle(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort function
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = getMiddle(head);
    ListNode* nextToMid = mid->next;
    mid->next = nullptr;  // Split the linked list

    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(nextToMid);

    return merge(left, right);
}

// Utility function to print the linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
_____________
quick sort linked list 
______________
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};

// Function to partition the linked list
ListNode* partition(ListNode* head, ListNode** newHead, ListNode** newEnd) {
    ListNode* pivot = head;
    ListNode* prev = nullptr, *cur = head, *tail = pivot;
    
    while (cur != nullptr) {
        ListNode* next = cur->next;
        if (cur->val < pivot->val) {
            if (*newHead == nullptr) *newHead = cur;
            prev = cur;
        } else {
            if (prev) prev->next = next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
        }
        cur = next;
    }
    
    if (*newHead == nullptr) *newHead = pivot;
    *newEnd = tail;
    
    return pivot;
}

ListNode* quickSortRecur(ListNode* head, ListNode* end) {
    if (!head || head == end) return head;

    ListNode* newHead = nullptr, *newEnd = nullptr;
    
    ListNode* pivot = partition(head, &newHead, &newEnd);
    
    if (newHead != pivot) {
        ListNode* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

ListNode* quickSort(ListNode* head) {
    return quickSortRecur(head, getTail(head));
}

// Helper function to get the tail node
ListNode* getTail(ListNode* head) {
    while (head != nullptr && head->next != nullptr) head = head->next;
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

	
	
--------------------------------------------------------------------------------------------------------------------
avl insertation
---------------------------------------------------------------------------------------------------------------------
// C++ program to insert a node in AVL tree 
#include <bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
struct Node { 
    int key; 
    Node *left; 
    Node *right; 
    int height; 

    Node(int k) { 
        key = k; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 

// A utility function to 
// get the height of the tree 
int height(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return N->height; 
} 

// A utility function to right 
// rotate subtree rooted with y 
Node *rightRotate(Node *y) { 
    Node *x = y->left; 
    Node *T2 = x->right; 

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = 1 + max(height(y->left), 
                    height(y->right)); 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 

    // Return new root 
    return x; 
} 

// A utility function to left rotate 
// subtree rooted with x 
Node *leftRotate(Node *x) { 
    Node *y = x->right; 
    Node *T2 = y->left; 

    // Perform rotation 
    y->left = x; 
    x->right = T2; 

    // Update heights 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 
    y->height = 1 + max(height(y->left), 
                        height(y->right)); 

    // Return new root 
    return y; 
} 

// Get balance factor of node N 
int getBalance(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in 
// the subtree rooted with node 
Node* insert(Node* node, int key) { 
  
    // Perform the normal BST insertion
    if (node == nullptr) 
        return new Node(key); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 

    // Update height of this ancestor node 
    node->height = 1 + max(height(node->left),
                           height(node->right)); 

    // Get the balance factor of this ancestor node 
    int balance = getBalance(node); 

    // If this node becomes unbalanced, 
    // then there are 4 cases 

    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 

    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 

    // Left Right Case 
    if (balance > 1 && key > node->left->key) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    // Right Left Case 
    if (balance < -1 && key < node->right->key) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    // Return the (unchanged) node pointer 
    return node; 
} 

// A utility function to print 
// preorder traversal of the tree 
void preOrder(Node *root) { 
    if (root != nullptr) { 
        cout << root->key << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

// Driver Code 
int main() { 
    Node *root = nullptr; 
    
    // Constructing tree given in the above figure 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    /* The constructed AVL Tree would be 
              30 
            /   \ 
          20     40 
         /  \      \ 
       10   25     50 
    */
    cout << "Preorder traversal : \n"; 
    preOrder(root); 
    
    return 0; 
} 

--------------------------------------------------------------------------------------------------------------------
avl deletation
---------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// A utility function to get the height 
// of the tree
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// A utility function to right rotate 
// subtree rooted with y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left),
                height(y->right));
    x->height = 1 + (height(x->left),
                height(x->right));

    // Return new root
    return x;
}

// A utility function to left rotate 
// subtree rooted with x
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left),
                height(x->right));
    y->height = 1 + max(height(y->left),
                height(y->right));

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - 
           height(N->right);
}

Node* insert(Node* node, int key) {
    // 1. Perform the normal BST rotation
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), 
                   height(node->right));

    // 3. Get the balance factor of this 
    // ancestor node to check whether this 
    // node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then 
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Given a non-empty binary search tree, 
// return the node with minimum key value 
// found in that tree. Note that the entire 
// tree does not need to be searched.
Node * minValueNode(Node* node) {
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Recursive function to delete a node with 
// given key from subtree with given root. 
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller 
    // than the root's key, then it lies in 
    // left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater 
    // than the root's key, then it lies in 
    // right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then 
    // this is the node to be deleted
    else {
        // node with only one child or no child
        if ((root->left == nullptr) || 
            (root->right == nullptr)) {
            Node *temp = root->left ? 
                         root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of 
                               // the non-empty child
            free(temp);
        } else {
            // node with two children: Get the 
            // inorder successor (smallest in 
            // the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's 
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), 
                   height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS 
    // NODE (to check whether this node 
    // became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then 
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && 
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && 
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && 
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && 
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder 
// traversal of the tree. 
void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver Code
int main() {
    Node *root = nullptr;

    // Constructing tree given in the 
    // above figure
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    preOrder(root);

    return 0;
}

-----------------------------------------------------------------------------------------
avl searching 
----------------------------------------------------------------------------------------

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// AVL tree node
struct AVLwithparent {
    struct AVLwithparent* left;
    struct AVLwithparent* right;
    int key;
    struct AVLwithparent* par;
    int height;
};

// Function to update the height of
// a node according to its children's
// node's heights
void Updateheight(
    struct AVLwithparent* root)
{
    if (root != NULL) {

        // Store the height of the
        // current node
        int val = 1;

        // Store the height of the left
        // and right subtree
        if (root->left != NULL)
            val = root->left->height + 1;

        if (root->right != NULL)
            val = max(
                val, root->right->height + 1);

        // Update the height of the
        // current node
        root->height = val;
    }
}

// Function to handle Left Left Case
struct AVLwithparent* LLR(
    struct AVLwithparent* root)
{
    // Create a reference to the
    // left child
    struct AVLwithparent* tmpnode = root->left;

    // Update the left child of the
    // root to the right child of the
    // current left child of the root
    root->left = tmpnode->right;

    // Update parent pointer of the
    // left child of the root node
    if (tmpnode->right != NULL)
        tmpnode->right->par = root;

    // Update the right child of
    // tmpnode to root
    tmpnode->right = root;

    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;

    // Update the parent pointer
    // of the root
    root->par = tmpnode;

    // Update tmpnode as the left or the
    // right child of its parent pointer
    // according to its key value
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }

    // Make tmpnode as the new root
    root = tmpnode;

    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);

    // Return the root node
    return root;
}

// Function to handle Right Right Case
struct AVLwithparent* RRR(
    struct AVLwithparent* root)
{
    // Create a reference to the
    // right child
    struct AVLwithparent* tmpnode = root->right;

    // Update the right child of the
    // root as the left child of the
    // current right child of the root
    root->right = tmpnode->left;

    // Update parent pointer of the
    // right child of the root node
    if (tmpnode->left != NULL)
        tmpnode->left->par = root;

    // Update the left child of the
    // tmpnode to root
    tmpnode->left = root;

    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;

    // Update the parent pointer
    // of the root
    root->par = tmpnode;

    // Update tmpnode as the left or
    // the right child of its parent
    // pointer according to its key value
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }

    // Make tmpnode as the new root
    root = tmpnode;

    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);

    // Return the root node
    return root;
}

// Function to handle Left Right Case
struct AVLwithparent* LRR(
    struct AVLwithparent* root)
{
    root->left = RRR(root->left);
    return LLR(root);
}

// Function to handle right left case
struct AVLwithparent* RLR(
    struct AVLwithparent* root)
{
    root->right = LLR(root->right);
    return RRR(root);
}

// Function to insert a node in
// the AVL tree
struct AVLwithparent* Insert(
    struct AVLwithparent* root,
    struct AVLwithparent* parent,
    int key)
{

    if (root == NULL) {

        // Create and assign values
        // to a new node
        root = new struct AVLwithparent;

        // If the root is NULL
        if (root == NULL) {
            cout << "Error in memory"
                 << endl;
        }

        // Otherwise
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
        }
    }

    else if (root->key > key) {

        // Recur to the left subtree
        // to insert the node
        root->left = Insert(root->left,
                            root, key);

        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;

        if (root->left != NULL)
            firstheight = root->left->height;

        if (root->right != NULL)
            secondheight = root->right->height;

        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight
                - secondheight)
            == 2) {

            if (root->left != NULL
                && key < root->left->key) {

                // Left Left Case
                root = LLR(root);
            }
            else {

                // Left Right Case
                root = LRR(root);
            }
        }
    }

    else if (root->key < key) {

        // Recur to the right subtree
        // to insert the node
        root->right = Insert(root->right,
                             root, key);

        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;

        if (root->left != NULL)
            firstheight
                = root->left->height;

        if (root->right != NULL)
            secondheight = root->right->height;

        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight - secondheight) == 2) {
            if (root->right != NULL
                && key < root->right->key) {

                // Right Left Case
                root = RLR(root);
            }
            else {

                // Right Right Case
                root = RRR(root);
            }
        }
    }

    // Case when given key is already
    // in the tree
    else {
    }

    // Update the height of the
    // root node
    Updateheight(root);

    // Return the root node
    return root;
}

// Function to print the preorder
// traversal of the AVL tree
void printpreorder(
    struct AVLwithparent* root)
{
    // Print the node's value along
    // with its parent value
    cout << "Node: " << root->key
         << ", Parent Node: ";

    if (root->par != NULL)
        cout << root->par->key << endl;
    else
        cout << "NULL" << endl;

    // Recur to the left subtree
    if (root->left != NULL) {
        printpreorder(root->left);
    }

    // Recur to the right subtree
    if (root->right != NULL) {
        printpreorder(root->right);
    }
}

// Driver Code
int main()
{
    struct AVLwithparent* root;
    root = NULL;

    // Function Call to insert nodes
    root = Insert(root, NULL, 10);
    root = Insert(root, NULL, 20);
    root = Insert(root, NULL, 30);
    root = Insert(root, NULL, 40);
    root = Insert(root, NULL, 50);
    root = Insert(root, NULL, 25);

    // Function call to print the tree
    printpreorder(root);
}


-------------------------------------------------------------
b tree  searching 
-------------------------------------------------------------

struct Node {
	int n;
	int key[MAX_KEYS];
	Node* child[MAX_CHILDREN];
	bool leaf;
};

Node* BtreeSearch(Node* x, int k) {
	int i = 0;
	while (i < x->n && k > x->key[i]) {
		i++;
	}
	if (i < x->n && k == x->key[i]) {
		return x;
	}
	if (x->leaf) {
		return nullptr;
	}
	return BtreeSearch(x->child[i], k);
}


---------------------------------------------------------------------------------------
   
 C++ implementation of search() and traverse() methods
----------------------------------------------------------------------------------------

// C++ implementation of search() and traverse() methods
#include <iostream>
using namespace std;

// A BTree node
class BTreeNode {
	int* keys; // An array of keys
	int t; // Minimum degree (defines the range for number
		// of keys)
	BTreeNode** C; // An array of child pointers
	int n; // Current number of keys
	bool leaf; // Is true when node is leaf. Otherwise false
public:
	BTreeNode(int _t, bool _leaf); // Constructor

	// A function to traverse all nodes in a subtree rooted
	// with this node
	void traverse();

	// A function to search a key in the subtree rooted with
	// this node.
	BTreeNode*
	search(int k); // returns NULL if k is not present.

	// Make the BTree friend of this so that we can access
	// private members of this class in BTree functions
	friend class BTree;
};

// A BTree
class BTree {
	BTreeNode* root; // Pointer to root node
	int t; // Minimum degree
public:
	// Constructor (Initializes tree as empty)
	BTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	// function to traverse the tree
	void traverse()
	{
		if (root != NULL)
			root->traverse();
	}

	// function to search a key in this tree
	BTreeNode* search(int k)
	{
		return (root == NULL) ? NULL : root->search(k);
	}
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _t, bool _leaf)
{
	// Copy the given minimum degree and leaf property
	t = _t;
	leaf = _leaf;

	// Allocate memory for maximum number of possible keys
	// and child pointers
	keys = new int[2 * t - 1];
	C = new BTreeNode*[2 * t];

	// Initialize the number of keys as 0
	n = 0;
}


void BTreeNode::traverse()
{
	// There are n keys and n+1 children, traverse through n
	// keys and first n children
	int i;
	for (i = 0; i < n; i++) {
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	// Print the subtree rooted with last child
	if (leaf == false)
		C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k)
{
	// Find the first key greater than or equal to k
	int i = 0;
	while (i < n && k > keys[i])
		i++;

	// If the found key is equal to k, return this node
	if (keys[i] == k)
		return this;

	// If the key is not found here and this is a leaf node
	if (leaf == true)
		return NULL;

	// Go to the appropriate child
	return C[i]->search(k);
}


bst 


If node == NULL 
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);  
return node;

// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);
}