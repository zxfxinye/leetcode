/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(grid.size() == 0) return 0;
        vector<vector<int>> paths(grid.size());
        for(int i = 0; i < paths.size(); i++) {
        	paths[i].resize(grid[0].size());
        }
        paths[0][0] = grid[0][0];
        for(int col = 1; col < grid[0].size(); ++col) {
        	paths[0][col] = paths[0][col-1] + grid[0][col];
        }
        for(int row = 1; row < grid.size(); ++row) {
        	paths[row][0] = paths[row-1][0] + grid[row][0];
        }
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 1; i < row; ++i) {
        	for(int j = 1; j < col; ++j) {
        		int min = 0;
        		if(paths[i-1][j] < paths[i][j-1]) {
        			min = paths[i-1][j];
        		}else {
        			min = paths[i][j-1];
        		}
        		paths[i][j] = min+grid[i][j];
        	}
        }
        return paths[row-1][col-1];
    }
};

int main() {
	Solution s;
	vector<vector<int>> testcase = {{1,4,8,6,2,2,1,7},{4,7,3,1,4,5,5,1},{8,8,2,1,1,8,0,1},{8,9,2,9,8,0,8,9},{5,7,5,7,1,8,5,5},{7,0,9,4,5,6,5,6},{4,9,9,7,9,1,9,0}};
	cout << s.minPathSum(testcase);
}