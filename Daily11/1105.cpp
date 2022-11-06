/**
 * @brief https://leetcode.cn/problems/parsing-a-boolean-expression/description/
 *  解析bool表达式，前缀形式
 * 思路：主要字符：'&', '|', '!', '(', ')', 't', 'f'， ','
 * 1. 使用 栈 对表达式做存储，遇到','时跳过，遇到')'时开始 pop，直到遇到'(';
 * 2. 对t和f计数，
 *  a. & 运算，f 个数为0时，表达式为true,否则为false;
 *  b. | 运算，t 个数为0时，表达式为false,否则为true;
 *  c. ! 运算，t 个数为1时，表达式为false,否则为true;
 * 3. 最终判断栈内剩下的是t还是f，如果为t返回true,否则为false.
 */


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> help;

        for (auto c : expression) {
            if (c == ',') {
                continue;
            } else if (c != ')') {
                help.push(c);
            } else {
                int numT = 0;
                int numF = 0;
                char temp = help.top();
                help.pop();
                while (temp != '(') {
                    if (temp == 't') {
                        ++numT;
                    } else if (temp == 'f') {
                        ++numF;
                    }
                    temp = help.top();
                    help.pop();
                }
                char op = help.top();
                help.pop();
                char item;
                switch(op) {
                    case '&' :
                        item = numF == 0 ? t : f;
                        break;
                    case '|' :
                        item = numT == 0 ? f : t;
                        break;
                    case '!' :
                        item = numT == 1 ? f : t;
                        break;
                }
                help.push(item);
            }

        }
        return help.top() == 't';
    }
};