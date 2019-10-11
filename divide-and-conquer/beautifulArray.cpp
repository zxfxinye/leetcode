/*
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：

对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。

那么数组 A 是漂亮数组。

给定 N，返回任意漂亮数组 A（保证存在一个）。
*/
/*
思路比较难想到,这里借鉴网上的.假设B是漂亮数组,那么2*B-1,2*B也符合漂亮数组条件,可以推导出2*B-1 + 2*B也是。所以将N折半进行递归调用,直到N=1返回B={1},递归回退的结果用2*B+2*B-1也都是符合条件的(当然数组元素值不能大于N).
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> beautifulArray(int N) {
    	if(N == 1) {
            vector<int> a = {1};
            return a;
        }
        auto res = beautifulArray((N+1)/2);
        vector<int> vec1,vec2;
        
        for(auto item : res) {
            auto t1 = item * 2 - 1;
            auto t2 = item * 2;
            if(t1 <= N) {
                vec1.push_back(t1);
            }
            if(t2 <= N) {
                vec2.push_back(t2);
            }
        }
        vec1.insert(vec1.end(), vec2.begin(),vec2.end());
        return vec1;
    }
};

int main() {
	Solution s;
    auto ans = s.beautifulArray(6);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}