#include <queue>
class MyStack {
  // https://leetcode.com/problems/implement-stack-using-queues/description/
public:
  std::queue<int> mq1, mq2;
  int mqSize = 0;
  MyStack() {}

  void push(int x) {
    mq1.push(x);
    mqSize++;
  }

  int pop() {
    while (mq1.size() > 1) {
      mq2.push(mq1.front());
      mq1.pop();
    }
    int pop = mq1.front();

    mq1 = mq2;
    mqSize--;

    return pop;
  }

  int top() {
    int tp = -1;
    while (!mq1.empty()) {
      mq2.push(mq1.front());
      if (mq1.size() == 1)
        tp = mq1.front();
      mq1.pop();
    }

    mq1 = mq2;

    return tp;
  }

  bool empty() { return mqSize == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */