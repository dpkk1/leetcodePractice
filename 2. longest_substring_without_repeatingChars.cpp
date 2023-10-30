/*Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters */

class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int n = st.length();
        set<char>s;
        int ans=0;
        int start=0, end=0;
        while(start < n){
            //If st[start] char not present in set, then ans increase by 1, as start index increased.
            auto it = s.find(st[start]);
            if(it == s.end()){
                if(start-end+1 > ans)
                    ans = start-end+1;
                s.insert(st[start]);
                start++;
            }
            else{
                s.erase(st[end]);
                end++;
            }
        }
        return ans;
    }
};

/*
    TC:O(n * log(n)) => n for loop, log(n) for find method, 
    ref: https://stackoverflow.com/questions/2790993/what-is-time-complexity-for-find-method-in-a-set-in-c
    
    SC: O(n), due to set
*/