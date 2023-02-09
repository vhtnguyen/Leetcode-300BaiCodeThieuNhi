//https://leetcode.com/problems/naming-a-company

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
//they are two cases need to focus:
//- same prefix
//- same suffix
class Solution {
    public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long res = 0;
        vector<unordered_set<string>>arr(26);
        //process same prefix cases
        for (string idea : ideas) {
            arr[idea[0] - 'a'].insert(idea.substr(1));
        }

        for (int i = 0;i < 25;++i) {
            for (int j = i + 1;arr[i].size() != 0 && j < 26;++j) {
                if (arr[j].size() == 0) {
                    continue;
                }
                //precess same suffix case
                unordered_set<string>suff;
                //union arr[i] and arr[j] to discard same suffix string
                suff.insert(arr[i].begin(), arr[i].end());
                suff.insert(arr[j].begin(), arr[j].end());
                //suff.size()-arr[i].size() : number of disctinct suffix-strings in arr[j] ;
                //the number of new valid created names from arr[i] and arr[j] = (number of disctinct suffix-strings in arr[i])*(number of disctinct suffix-strings in arr[j])
                res += ((suff.size() - arr[i].size()) * (suff.size() - arr[j].size())) * 2;
                // x2 because a pair of ideaA-IdeaB is not equal to ideaB-IdeaA

            }

        }

        return res;
    }
};