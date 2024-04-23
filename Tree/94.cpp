//
// Created by 白天宇 on 2024/4/23.
//
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    void traversal(TreeNode *cur, vector<int> &res) {
        if (cur == nullptr) return;
        traversal(cur->left, res);
        res.push_back(cur->val);
        traversal(cur->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    vector<int> inorderTra_stack(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left; // 遍历到左边的最下面
            } else {
                cur = st.top(); // 左孩子出栈
                st.pop(); // 最左边的出去了，然后把最左边的放进去
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() {

}