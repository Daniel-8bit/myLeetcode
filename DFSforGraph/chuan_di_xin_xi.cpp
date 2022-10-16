/**
 * @brief 算法 dfs + 回溯，dfs时需要传入用于计数 count 的参数
 * 起点只能是 begin, 终点只能是 end,
 * 1. 将二维数组relation转成邻接矩阵
 * 2. 初始化变量begin = 0, end = n -1
 * 3. 每dfs出一个方案res++
 * 4. dfs 为true的条件，count == 0 && 当前节点 == end
 */
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
    {
        matrix = vector<vector<int>>(n);
        int begin = 0;
        int end = n - 1;
        int res = 0;
        for (int i = 0; i < relation.size(); i++) {
            matrix[relation[i][0]].push_back(relation[i][1]);
        }
        dfs(begin, end, k, res);
        return res;
    }

    void dfs(int point, int end, int count, int &res)
    {
        if (count == 0) {
            if (point == end) {
                res++;
            }
            return;
        }
        for (auto item : matrix[point]) {
            dfs(item, end, count - 1, res);
        }
    }
private:
    vector<vector<int>> matrix;
};