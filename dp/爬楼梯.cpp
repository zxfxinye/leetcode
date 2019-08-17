//
// Created by zhuxiaofeng on 2019-08-05.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        int i = 2;
        while(i < n) {
            dp[i] = dp[i-1]+dp[i-2];
            i++;
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(10);
}