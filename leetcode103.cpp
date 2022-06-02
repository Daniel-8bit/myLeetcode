#include <iostream>
#include <vector>
#include <deque>

#include "TreeNode.h"

using namespace std;

// 锯齿形层序遍历
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> que;
    if (root == nullptr) return res;

    que.push_back(root);
    bool flag = false;
    while (!que.empty()) {
        int len = que.size();
        deque<int> temp;
        for (int i = 0; i < len; i++) {
            TreeNode* node = que.front();
            que.pop_front();
            if (flag) temp.push_front(node->val);
            else temp.push_back(node->val);
            if (node->left) que.push_back(node->left);
            if (node->right) que.push_back(node->right);
        }
        res.emplace_back(vector<int>(temp.begin(), temp.end()));
        flag = !flag;
    }
    return res;
}