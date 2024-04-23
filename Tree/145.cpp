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
        traversal(cur->left, res);
        traversal(cur->right, res);
        res.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    // 先序遍历是中左右，后续遍历是左右中，
    // 那么我们只需要调整一下先序遍历的代码顺序，
    // 就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了
    vector<int> postorder_st(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        if (root == nullptr) {
            return res;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if (cur->left){
                st.push(cur->left);
            }
            if (cur->right){
                st.push(cur->right);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {

}