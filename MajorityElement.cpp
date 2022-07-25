#include<bits/stdc++.h>
using namespace std;

//basic solution using hashmap

class Solution {
    unordered_map<int, int>dict; // faster than map
    public:
    int majorityElement(vector<int>& nums) {
        int me, maxFreq = 0;
        for (auto i : nums) {
            int t = ++dict[i];
            if (t > maxFreq) {
                maxFreq = t;
                me = i;
            }

        }
        return me;
    }
};

//solotion using sort alg

// class Solution {
//     public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//             return nums[nums.size() / 2];
//     }
// };

//Boyer-Moore Majority Voting Algorithm
//https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], votes = 1, n = nums.size();
        for (int i = 1;i < n;++i) {
            if (votes == 0)
                    candidate = nums[i];
            if (candidate != nums[i])
                votes--;
            else 
                votes++;
        }
        return candidate;
    }
};