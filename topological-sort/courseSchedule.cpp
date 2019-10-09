/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prev(numCourses);
        vector<vector<int>> next(numCourses);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); ++i) {
        	prev[prerequisites[i][0]]++;
        	next[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses;++i) {
        	if(prev[i] == 0) q.push(i);
        }
        while(!q.empty()) {
        	auto cur = q.front();
        	q.pop();
        	for(int j = 0; j < next[cur].size(); ++j) {
        		if(--prev[next[cur][j]] == 0) {
        			q.push(next[cur][j]);
        		}
        	}
        }
        for(int i = 0; i < numCourses;++i) {
        	if(prev[i] > 0) return false;
        }
        return true;
    }
};

int main() {
	Solution s;
	vector<vector<int>> testcase = {{1,0},{0,1}};
	int n = 2;
	cout << s.canFinish(2,testcase);
}