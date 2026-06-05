#include <bits/stdc++.h>
#include <stack>
#include <vector>

// https://leetcode.com/problems/daily-temperatures/
using namespace std;

int main() {

  vector<int> temperatures = {30, 60, 90};

  stack<int> ms;

  vector<int> res(temperatures.size());
  for (int i = temperatures.size() - 1; i >= 0; i--) {
    while (!ms.empty() && temperatures[ms.top()] <= temperatures[i])
      ms.pop();

    if (ms.empty())
      res[i] = 0;
    else
      res[i] = ms.top() - i;

    ms.push(i);
  }

  return 0;
}