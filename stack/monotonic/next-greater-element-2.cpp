#include <bits/stdc++.h>
#include <climits>


//https://leetcode.com/problems/next-greater-element-ii/description/
using namespace std;
int main() {

  vector<int> nums = {-3,-2,-2,-3};
  stack<int> ms;
  vector<int> res(nums.size(), INT_MIN);

  
  for (int i = nums.size() * 2 - 1; i >= 0; i--) {
    while (!ms.empty() && nums[ms.top()] <= nums[i % nums.size()])
      ms.pop();

    if (ms.empty())
      res[i % nums.size()] = -1;
    else
      res[i % nums.size()] = res[i % nums.size()] != -1
                                 ? max(nums[ms.top()], res[i % nums.size()])
                                 : nums[ms.top()];

    ms.push(i % nums.size());
  }


  for (int i : res)
    cout << i << " ";
  return 0;


}

// reaproveita os elementos que ficaram na pilha na primeira iteração até nums.size() -1 e 
// na segunda reaproveita comparadno com o primeiro (claro, na direção da direita para esquerda)