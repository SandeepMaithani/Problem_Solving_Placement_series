
//Using One stack Approach

class QueueStack {
private:
    queue<int> q1;
public:
    void push(int);
    int pop();
};

/*

Verdict : Accepted

Complexity Analysis:

Time Complexity:

Push operation: O(N).In each insertion we have to bring new push element in front by N elements.
Pop operation: O(1).Same as pop operation in stack.

Space Complexity: O(1).

*/

void QueueStack :: push(int x)
{
    if (q1.empty()) {
        q1.push(x);
    }
    else {

        int size = q1.size();
        q1.push(x);

        for (int i = 0; i < size; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
}


int QueueStack :: pop()
{
    if (q1.empty()) {
        return -1;
    }

    int pop_element = q1.front();
    q1.pop();

    return pop_element;
}




//Using Two stack Approach

class QueueStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

/*

Method 1 :- By making pop operation costly                 Verdict : Accepted

Complexity Analysis:

Time Complexity:

Push operation: O(1). Same as Push operation in stack.
Pop operation: O(N). In the worst case we have empty whole of queue 1 into queue 2.

Space Complexity: O(N). Use of queue for storing values.

*/

void QueueStack :: push(int x)
{
    q1.push(x);
}


int QueueStack :: pop()
{
    if (q1.empty()) {
        return -1;
    }

    int pop_element;

    if (q1.size() == 1) {
        pop_element = q1.front();
        q1.pop();
    }
    else {

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        pop_element = q1.front();
        q1.pop();

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    return pop_element;
}

/*

Method 2 :- By making push operation costly                   Verdict : Accepted

Complexity Analysis:

Time Complexity:

Push operation: O(N).In the worst case we have empty whole of queue 1 into queue 2.
Pop operation: O(1).Same as pop operation in stack.

Space Complexity: O(N).Use of queue for storing values.

*/

void QueueStack :: push(int x)
{
    if (q1.empty()) {
        q1.push(x);
    }
    else {

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
}

int QueueStack :: pop()
{
    if (q1.empty()) {
        return -1;
    }

    int pop_element = q1.front();
    q1.pop();

    return pop_element;
}
