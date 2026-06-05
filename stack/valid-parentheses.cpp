#include "bits/stdc++.h"
//https://leetcode.com/problems/valid-parentheses/
using namespace std;
int main() {

  string s = "[";
  
  stack<char> st;
  for (char c : s) {
    if (c == '{' || c == '(' || c == '[') {
      st.push(c);
    } else {
      char tp = st.top();

      if (tp == '{' && c != '}') {
        cout << "false";
        return 0;
      }

      if (tp == '[' && c != ']') {
        cout << "false";
        return 0;
      }

      if (tp == '(' && c != ')') {
        cout << "false";
        return 0;
      }
    }
  }
  cout << true;
  return 0;
}