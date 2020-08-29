/*

Method 1 : using maths to retrive previous min.                Verdict: Accepted

Complexity Analysis :

Time Complexity: O(1). All operation take constant time so time complexity will be O(1).

Space Complexity: O(1).

*/


stack<int> s;
int minEle;

int getMin()
{
  if (s.empty()) {
    return -1;
  }

  return minEle;
}



int pop()
{
  int top = -1;

  if (s.empty()) {
    return top;
  }

  if (s.top() >= minEle) {
    top = s.top();
    s.pop();
  }
  else {
    top = minEle;
    minEle = 2 * minEle - s.top();
    s.pop();
  }
  return top;
}


void push(int x)
{
  if (s.empty()) {
    s.push(x);
    minEle = x;
    return;
  }

  if (x >= minEle) {
    s.push(x);
  }
  else {
    int tempVal = 2 * x - minEle;
    s.push(tempVal);
    minEle = x;
  }

}



/*

Method 1 : using extra stack to get min.                Verdict: Accepted

Complexity Analysis :

Time Complexity: O(1). All operation take constant time so time complexity will be O(1).

Space Complexity: O(N). N size stack used for keeping  track of min element.

*/



stack<int>s;
stack<int>support;

void push(int a)
{
  s.push(a);

  if (support.empty() || a <= support.top()) {
    support.push(a);
  }
}

int pop()
{
  int answer = s.top();

  if (answer == support.top()) {
    support.pop();
    s.pop();
    return answer;
  }

  s.pop();
  return answer;
}

int getMin()
{
  if (s.size() == 0) {
    return -1;
  }

  return support.top();
}