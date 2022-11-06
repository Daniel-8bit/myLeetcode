/**
 * @file 17.cpp
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/letter-combinations-of-a-phone-number/?favorite=2cktkvj
 * @version 0.1
 * @date 2022-11-06
 * 思路：数字的长度最大为4，回溯，属于排列组合类型的题目
 * 1. 将题目中的数字与字符串用map存储；
 * 2. 递归得到每一个答案
 *  a.
 * @copyright Copyright (c) 2022
 *
 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        int index = 0;
        dfs(index, digits);
        return res;
    }
    void dfs(int index, string digits)
    {
        if (index == digits.length()) {
            res.push_back(temp);
            return;
        }
        char c = digits[index];
        for (auto item : phone[c]) {
            temp.push_back(item);
            dfs(index + 1, digits);
            temp.pop_back();
        }
        return;
    }
private:
    map<char, string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> res;
    string temp;
};