/**
 * @brief leetcode 547 省份数量
 * https://leetcode.cn/problems/number-of-provinces/description/
 * 算法：dfs
 * 题目的输入：所有城市组成的邻接矩阵
 * 输出：省份的数量，即连通图的数量
 * 思路：1. 构造一个数组用于标记节点是否被访问过；
 * 2. 对所有节点做dfs，一次dfs可以访问到所有与遍历到节点相联通的部分，计算dfs的次数，即连通图的数量
 */

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int index)
    {
        int size = isConnected.size();
        for (int i = 0; i < size; i++) {
            if (isConnected[i][index] == 1 && visited[i] == false) {
                visited[i] = true;
                dfs(isConnected, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int len = isConnected.size();
        visited = vector<bool>(len, false);
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (visited[i] == false) {
                dfs(isConnected, i);
                ++num;
            }
        }
        return num;
    }
private:
    vector<bool> visited;
};