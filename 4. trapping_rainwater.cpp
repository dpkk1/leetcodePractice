/*Problem Link: https://leetcode.com/problems/trapping-rain-water */

class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = -1;
        int n = height.size();
        vector<int>right(n, 0), left(n, 0);
        for(int i=0; i<n; i++){
            if(height[i] > maxi){
                maxi = height[i];
            }
            left[i] = maxi;
        }
        maxi = -1;
        for(int i=n-1; i>=0; i--){
            if(height[i] > maxi){
                maxi = height[i];
            }
            right[i] = maxi;
        }

        int ans=0;
        for(int i=0; i<n; i++){
            ans += abs(min(right[i], left[i])-height[i]);
        }
        return ans;
    }
};

/*
    TC: O(N), for n loop
    Ref: https://youtu.be/UZG3-vZlFM4?si=7YdErBkkUq4v8wr0

    SC: O(N), for taking two arrays
*/