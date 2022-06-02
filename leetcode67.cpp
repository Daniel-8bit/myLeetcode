class Trie {
public:
    Trie()
    {
        memset(next, 0, sizeof(next));
    }

    void insert(int num)
    {
        Trie *node = this;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->next[bit] == nullptr) {
                node->next[bit] = new Trie();
            }
            node = node->next[bit];
        }
    }

    int check(int num)
    {
        Trie *node = this;
        int x = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (node->next[1]) {
                    node = node->next[1];
                    x = x * 2 + 1;
                } else {
                    node = node->next[0];
                    x = x * 2;
                }
            } else {
                if (node->next[0]) {
                    node = node->next[0];
                    x = x * 2 + 1;
                } else {
                    node = node->next[1];
                    x = x * 2;
                }
            }
        }
        return x;

    }

private:
    Trie *next[2];
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int res = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            trie.insert(nums[i-1]);
            res = max(res, trie.check(nums[i]));
        }
        return res;
    }
};

int main()
{

    return 0;
}