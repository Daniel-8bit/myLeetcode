/**
 * @brief 核心算法 邻接矩阵 + DFS
 * 1. 将题目中的二维数组edges转成邻接矩阵；
 * 2. 对所有顶点依次遍历
 * 3. dfs: a. 退出条件：当前顶点即是终点；
 * b. 如果相邻顶点未被访问且dfs成功则返回true
 *
 */
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vsited = vector<bool>(n, false);
        matr = vector<vector<int>>(n);

        for (int i = 0; i < edges.size(); i++) {
            matr[edges[i][0]].push_back(edges[i][1]);
            matr[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(source, destination);
    }

    bool dfs(int vex, int destination) {
        visted[vex] = true;
        if (vex == destination) {
            return true;
        }

        for (int i = 0; i < matr[vex].size(); i++) {
            if (vsited[matr[vex][i]] == false && dfs(matr[vex][i], destination)) {
                return true;
            }
        }
        return false;
    }
private:
    // 邻接矩阵
    vector<vector<int>> matr;
    vector<bool> vsited;
};