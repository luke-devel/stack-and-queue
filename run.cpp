// Author : Luke Olson
//
// This program  implement stacks and queues ADT using linked
// lists with pointers only

#define _USE_MATH_DEFINES

#include <stack>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
string test;

int options();

// Stack class to create stack structure and compare stacks
class IntStack
{
private:
    struct Node
    {
        string data;
        struct Node *link;
    };
    struct Node *top;

public:
    void push(string);
    string pop();
    void compare();
    int isEmpty();
};

//*************************************************
// Member function push pushes the argument onto *
// the stack. *
//*************************************************
void IntStack::push(string data)
{
    // create new node temp and allocate memory
    struct Node *temp;
    temp = new Node();

    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // initialize data into temp data field
    temp->data = data;

    // put top pointer reference into temp link
    temp->link = top;

    // make temp as top of Stack
    top = temp;

}

//****************************************************
// Member function pop pops the value at the top *
// of the stack off, and returns it. *
//*****************************************************
string IntStack::pop()
{
    struct Node *temp;

    // check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        // top assign into temp
        temp = top;

        // assign second node to top
        top = top->link;

        // destroy connection between first and second
        temp->link = NULL;

        // release memory of top node
        free(temp);
    }

}

int IntStack::isEmpty()
{
    return top == NULL;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise. *
//****************************************************

//****************************************************
// Member function makeEmpty makes the stack an *
// empty stack. *
//*****************************************************

void IntStack::compare()
{

    struct Node *temp;

    // check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            // print node data
            string test =   temp->data;
            //cout <<  "\nYour Stack input was: "<< test << endl;
            string delimiter = "#";
            string test1 = test.substr(0, test.find(delimiter));
            string test2 = test.substr(test.find(delimiter) + 1, test.length());

            if(test1 == test2)
            {
                cout << "\nStrings are identical\n" << endl;
            }
            else
            {
                cout << "\nStrings are not identical\n" << endl;
            }
            // assign temp link to temp
            temp = temp->link;
            options();
        }
    }

}

struct Node
{
    string data;
    Node *next;
};

class Queue
{
public:
    Node *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    void insert(string str);
    void deleteitem();
    void display();
    void queueFlip();
    ~Queue();
};

void Queue::insert(string str)
{
    Node *temp = new Node;
    if(temp == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    temp->data = str;
    temp->next = NULL;

    //for first node
    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

}

void Queue::display()
{
    if(front == NULL)
    {
        cout << "Underflow." << endl;
        return;
    }
    Node *temp = front;
    //will check until NULL is not found
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Queue :: deleteitem()
{
    if (front == NULL)
    {
        cout << "underflow" << endl;
        return;
    }

    cout << front->data << " is being deleted " << endl;
    if(front == rear) //if only one node is there
        front = rear = NULL;
    else
        front = front->next;
}

Queue ::~Queue()
{
    while(front != NULL)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}


void stackEqual()
{
    IntStack stack1;
    string input;
    cout << "\nEnter Stack Values : ";
    cin >> input;
    stack1.push(input);
    //stack1.display();
    stack1.compare();
    options();
}

// reverses strings entered into console separated by a #
void Queue::queueFlip()
{
    if(front == NULL)
    {
        cout << "Underflow." << endl;
        return;
    }
    Node *temp = front;
    //will check until NULL is not found
    while(temp)
    {
        string data = temp->data;
        string delimiter = "#";
        string test1 = data.substr(0, data.find(delimiter));
        string test2 = data.substr(data.find(delimiter) + 1, data.length());

        // reverses test2 string
        reverse(test2.begin(), test2.end());

        if(test1 == test2)
        {
            cout << "\nSTRING2 is reversed of STRING1." << endl;
        }
        else
        {
            cout << "\nSTRING2 is not reversed of STRING1." << endl;
        }
        temp = temp->next;

    }
    cout << endl;
}

void queueBegin()
{
    Queue newQueue;
    string input;
    cout << "\nEnter Queue Values : ";
    cin >> input;
    newQueue.insert(input);
    newQueue.queueFlip();
    options();
}

int options()
{
    bool valid;
    do
    {
        char x;

        cout << "Select from the following menu" << endl
             << "1. Enter Stack Values" << endl
             << "2. Enter Queue Values." << endl
             << "9. Terminate the program. ";

        cin >> x;

        switch(x)
        {
        case '1':
            stackEqual();
            valid = true;
            break;
        case '2':

            queueBegin();
            valid = true;
            break;
        case '9':
            cout << "\n*** End of the program. ***" << endl
                 << "*** Written by Luke Olson ***" << endl
                 << "*** March - 2020 ***\n" << endl;
            return 0;
            break;
        default:
            cout << "\nInvalid Option.\n" << endl;
            valid = false;
        }
    }
    while(!valid);
}

int main()
{
    // displays options
    options();
    // program ends
    return 0;
}
