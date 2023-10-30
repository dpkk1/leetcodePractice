/*Problem Link: https://leetcode.com/problems/two-sum */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            //If {target-nums[i]} is in mp(map) or not 
            if(mp.find(target-nums[i]) != mp.end()){
                return {i, mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {-1, -1};
    }
};

/*
    TC:O(n * log(n)) => n for loop, log(n) for find method, 
    ref: https://stackoverflow.com/questions/9961742/time-complexity-of-find-in-stdmap
    
    SC: O(n), due to map
*/