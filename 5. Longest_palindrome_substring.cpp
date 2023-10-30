/*Problem Link: https://leetcode.com/problems/longest-palindromic-substring */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0)
            return "";
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++) //length of 1 string is palindrome
            dp[i][i]=true;
        int maxLen = 1;
        int start = 0;
        for(int i=0; i<n-1; i++){ //Updating length of 2 string is palindrome or not
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i; //updating the start
                maxLen = 2;
            }
        }
        for(int k=3; k<=n; k++){    //substring of length k
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j]){
                    dp[i][j] = 1;
                    if(k > maxLen){
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};

/*
    TC: O(N*K), for n*k loop
    Ref: https://youtu.be/UflHuQj6MVA?si=J-dVPzWBvPtC687w

    SC: O(N*N), for taking 2-D Array
*/

