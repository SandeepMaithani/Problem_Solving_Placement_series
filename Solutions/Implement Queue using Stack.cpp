/*

Method 1 :- By making deQueue operation costly                 Verdict : Accepted

Complexity Analysis:

Time Complexity:

Push operation: O(1). Same as Push operation in stack.
Pop operation: O(N). In the worst case we have empty whole of stack 1 into stack 2.

Space Complexity: O(N). Use of stack for storing values.

*/

void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    if (s1.empty()) {
        return -1;
    }

    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    int poped_element = s2.top();
    s2.pop();

    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    return poped_element;
}


/*

Method 2 :- By making enQueue operation costly                   Verdict : Accepted

Complexity Analysis:

Time Complexity:

Push operation: O(N).In the worst case we have empty whole of stack 1 into stack 2.
Pop operation: O(1).Same as pop operation in stack.

Space Complexity: O(N).Use of stack for storing values.

*/


void StackQueue :: push(int x)
{
    if (s1.empty()) {
        s1.push(x);
    }
    else {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
}


int StackQueue :: pop()
{
    if (s1.empty()) {
        return -1;
    }

    int poped_element = s1.top();
    s1.pop();

    return poped_element;
}