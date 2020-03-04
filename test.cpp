// Author : Luke Olson
// Serial Number : 22
// Due Date : 3/3/20
// Programming Assignment Number 2
// Spring 2020 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
// This program  implement stacks and queues ADT using linked
// lists with pointers only

#define _USE_MATH_DEFINES

#include <stack>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Stack class to create stack structure and reverse string
class Stack
{
public:
    int top;
    unsigned capacity;
    char *array;
};

// function to create a stack of given
// capacity. It initializes size of stack as 0
Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new char[(stack->capacity * sizeof(char))];
    return stack;
}

// Stack is full when top is equal to the last index
bool isFull(Stack *stack)
{
 bool status;
 if (top == -1)
 status = true;
 else
 status = false;
 return status;
}

// Function to add an item to stack.
// It increases top by 1
void push(Stack *stack, char item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.
// It decreases top by 1
char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}


// reverses strings entered into console separated by a #
void stackEqual()
{
    string str = "5(12+7)#5+(12+7)";
    replace(str.begin(), str.end(), '#', ' ');  // replace ':' by ' '

    stringstream ss(str);

    do
    {
        // Read a word
        string word;
        ss >> word;
        int n = strlen(word);
        Stack* stack = createStack(n);  
        // Print the read word
        cout << stack << endl;

        // While there is more to read
    }
    while (ss);

    // char str[] = "GeeksQuiz";

    // reverse(str);
    // cout << "Reversed string is " << str;
}

void queueBegin()
{
    cout << "in the queue" << endl;
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
                 << "*** March – 2020 ***\n" << endl;
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
    cout << "hello world" << endl;
    options();
    return 0;
}
