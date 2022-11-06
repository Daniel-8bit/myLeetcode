/**
 * @brief https://leetcode.cn/problems/goal-parser-interpretation/
 * Goal解析器
 * 思路：使用共有三种字符，"G", "()", "(al)"，记输出的字符串为res,初始化为空值
 * 1. 从头开始遍历输入的command,如果为G，res新增"G";
 * 2. 如果遍历到'(',先跳过，判断下一个是否为')',是则res新增"o";
 * 否则指针往后移两位，res新增"al"
 *
 *
 */
class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string res = "";
        int index = 0;

        while (index < n) {
            if (command[index] == 'G') {
                res += "G";
                ++index;
                continue;
            }
            if(command[index] == '(') {
                if (command[index + 1] == ')') {
                    res += "o";
                    index += 2;
                    continue;
                } else {
                    res += "al";
                    index += 4;
                    continue;
                }
            }
        }
        return res;
    }
};