// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> ans;

        for(int i=0;i<arr.size();i++){
            int n = __builtin_popcount(arr[i]);
            ans.push_back(make_pair(n,arr[i]));
        }

        sort(ans.begin(), ans.end());

        vector<int> answer(arr.size());

        for(int i=0;i<arr.size();i++){
            answer[i] = ans[i].second;
        }
        return answer;
    }
};