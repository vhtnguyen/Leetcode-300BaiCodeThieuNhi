//https://leetcode.com/problems/minimum-time-to-complete-trips/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

/*
Input: time = [1,1,2,3], totalTrips = 12
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,1,0,0].= 2*(1/1)+1*(1/2)+1*(1/3)=2
- At time t = 2, the number of trips completed by each bus are [2,2,1,0].=[1,1,0,0]+[1,1,1,0] = 2*2+1
- At time t = 3, the number of trips completed by each bus are [3,3,1,1]=2*(3/1)+1*(3/2)+1*(3/3)
- At time t = 4, the number of trips completed by each bus are [4,4,2,1]=2*(4/1)+1*(4/2)+1*(4/3)
- At time t = 5, the number of trips completed by each bus are [5,5,2,1]=2*(5/1)+1*(4/2)+1*(4/3)=10+2+1=13

  T
*/

class Solution {
    public:
    map<long long, long long>om;
    long long sumAt(long long t, vector<int>& time) {
        long long ans = 0;
        for (const auto& bus : om) {
            if (bus.first > t) {
                break;
            }
            ans += bus.second * (t / bus.first);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        for (long long i = 0;i < time.size();++i) {
            om[time[i]]++;
        }
        long long l = 1, r = time[0];
        r *= totalTrips;

        //[9,3,10,5]=[3,5,9,10]
        //2
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long sum = sumAt(mid, time);
            if (sum >= totalTrips && sumAt(mid - 1, time) < totalTrips) {
                return mid;
            }
            else if (sum < totalTrips) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};