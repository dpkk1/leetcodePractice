/*Problem Link: https://leetcode.com/problems/maximum-subarray */

class Solution {
public:
    // Kadane's Alogorithm
    int maxSubArray(vector<int>& nums) {
        int sum=0, ans = INT_MIN;
        for(auto i:nums){
            sum += i;
            if(sum > ans)
                ans = sum;
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};


/*
    TC:O(n) => n for loop,  
    SC: O(1)
*/