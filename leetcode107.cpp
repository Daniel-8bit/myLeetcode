#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    queue<TreeNode*> que;
    que.push(root);
    stack<vector<int>> temp;
    while (!que.empty()) {
        int len = que.size();
        temp.push(vector<int>());
        for (int i = 0; i < len; i++) {
            TreeNode* node = que.front();
            que.pop();
            temp.top().push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }

    while (!temp.empty()) {
        res.push_back(temp.top());
        temp.pop();
    }
    return res;
}