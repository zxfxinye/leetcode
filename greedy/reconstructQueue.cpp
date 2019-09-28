/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
思路：先按身高从高到低排序，身高一样的按k从低到高排序,一次循环插入到k对应的位置,vector insert会自动将当前位置后面的元素向后移位(真是方便),一开始自己写这部分还得考虑一堆逻辑
*/
#include <iostream>
#include <queue>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
    }
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	int r = people.size();
        vector<vector<int>> ans = {};
        if(r == 0) return ans;
        ans.resize(r);
        sort(people.begin(), people.end(), cmp);
    	
        for( int i = 0; i < r; i++ ){
            ans.insert(ans.begin() + people[i][1], people[i]);
         }
        return ans;
    }
    
};

int main() {
    vector<int> test;
    // test.insert(test.begin(),3);
    // test.insert(test.begin(),5);
    // test.insert(test.begin()+3,12);
    // test.insert(test.begin()+3,8);
    // // test.insert().
    // for(auto x : test) {
    //     cout << x << endl;
    // }
	vector<vector<int>> testcase = {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}};
	Solution s;
	auto ans = s.reconstructQueue(testcase);
	for(auto u : ans) {
		for(auto v : u) {
			cout << v << ",";
		}
		cout << endl;
	}
}