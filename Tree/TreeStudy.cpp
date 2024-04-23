//
// Created by 白天宇 on 2024/4/22.
//
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Bainli{
public:
    // 前序遍历，vec用来存储遍历结果，中左右
    void pretraversal(TreeNode* cur, vector<int>& vec){
        if (cur== nullptr){
            return;
        }
        vec.push_back(cur->val);
        pretraversal(cur->left,vec);
        pretraversal(cur->right,vec);
    }
    // 左中右
    void middletraversal(TreeNode* cur, vector<int>& vec){
        if (cur== nullptr){
            return;
        }
        pretraversal(cur->left,vec);
        vec.push_back(cur->val);
        pretraversal(cur->right,vec);
    }

    // 左右中
    void backtraversal(TreeNode* cur, vector<int>& vec){
        if (cur== nullptr){
            return;
        }
        pretraversal(cur->left,vec);
        pretraversal(cur->right,vec);
        vec.push_back(cur->val);
    }

};

int main() {


}