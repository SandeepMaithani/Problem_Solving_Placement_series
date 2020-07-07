/*

METHOD 1 :          Verdict : Accepted

Complexity Analysis

Time Complexity: O(n) where n is the number of nodes in the given list.

Space Complexity: O(1).

*/


struct node *reverse (struct node *head, int k)
{
    node* curr = head;
    node* end = NULL;

    int t = 0;

    while (curr) {

        t = k;

        node* start = curr;
        node* prev = NULL;

        while (curr && t--) {
            node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        if (end) {
            end -> next = prev;
        }
        else {
            head = prev;
        }

        end = start;
    }

    return head;
}


/*

METHOD 2 : By using stack           Verdict : Accepted

Complexity Analysis

Time Complexity: O(n) where n is the number of nodes in the given list.

Space Complexity: O(k) which is the space used by stack tpo store k nodes which is size of group.

*/

struct node *reverse (struct node *head, int k)
{

    node* curr = head;
    node* prev = NULL;

    stack<node*>mystack;

    if (head == NULL || head -> next == NULL) {
        return head;
    }

    while (curr) {

        int count = 0;

        while (curr && count < k) {
            mystack.push(curr);
            curr = curr -> next;
            count++;
        }

        while (mystack.size() > 0) {
            if (prev == NULL) {
                prev = mystack.top();
                head = prev;
                mystack.pop();
            }
            else {
                prev -> next = mystack.top();
                prev = prev -> next;
                mystack.pop();
            }
        }
    }

    prev -> next = NULL;

    return head;
}