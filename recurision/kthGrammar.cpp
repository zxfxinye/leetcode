/*
在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001
01101001 10010110
注意：

N 的范围 [1, 30].
K 的范围 [1, 2^(N-1)].
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int kthGrammar(int N, int K) {
        return recursion(N,K);
    }

    int recursion(int N, int K) {
    	if(N == 1) return 0;
    	int prev = recursion(N-1,(K+1)/2);
    	if(prev == 0) {
    		if(K%2 == 0) {
    			return 1;
    		}else {
    			return 0;
    		}
    	}else {
    		if(K%2 == 0) {
    			return 0;
    		}else {
    			return 1;
    		}
    	}
    	
    }
};

int main() {
	Solution s;
	cout << s.kthGrammar(5,15);
}
