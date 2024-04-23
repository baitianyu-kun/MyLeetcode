//
// Created by 白天宇 on 2024/4/23.
//
#include "iostream"
#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    void traversal(TreeNode *cur, vector<int> &res) {
        if (cur == nullptr) return;
        res.push_back(cur->val);
        traversal(cur->left, res);
        traversal(cur->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    vector<int> preorderTra_stack(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        st.push(root);
        while (!st.empty()){
            TreeNode *cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if (cur->right){
                st.push(cur->right);
            }
            if (cur->left){
                st.push(cur->left);
            }
        }
        return res;
    }
};

int main() {

}