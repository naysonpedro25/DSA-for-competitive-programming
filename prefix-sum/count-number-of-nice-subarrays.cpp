#include <map>
#include <vector>
//https://leetcode.com/problems/count-number-of-nice-subarrays/
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) { // reduzindo o array a 0 e 1, sendo 0 pares e 1 impares
            nums[i] %= 2;
        }

        int res = 0;
        int pref = 0;

        for (int i = 0; i < n; i++) {
            pref += nums[i];
            if (mp.count(pref - k))
                res += mp[pref - k];

            mp[pref]++;
        }

        return res;
    };
};