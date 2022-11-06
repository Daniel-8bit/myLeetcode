/**
 * @file minimum-depth-of-binary-tree.cpp
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 * @version 0.1
 * @date 2022-11-02
 *
 * @copyright Copyright (c) 2022
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int depth = 0;
        using Node = pair<TreeNode*, int>;
        Node node(root, depth);

        queue<Node> que;
        que.push(node);

        while(!empty()) {
            Node temp = que.front();
            que.pop();
            if (temp.first->left == nullptr && temp.first->right == nullptr) {
                return temp.second;
            }
            if (temp.first->left) {
                Node left(temp.first->left, temp.second++);
                que.push(left);
            }
            if (temp.first->right) {
                Node right(temp.first->right, temp.second++);
                que.push(right);
            }
        }
        return 0;
    }
};