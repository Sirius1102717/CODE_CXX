#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

void set_node(TreeNode*& root) {
    set_node(root->left);
    set_node(root->right);
    root = nullptr;
}

bool find_node(TreeNode* root) {
    if (root) {
        if (root->val) return true;
        return find_node(root->left) || find_node(root->right);
    }
    return false;
}

TreeNode* getTree(TreeNode* root) {
    if (!find_node(root->left)) set_node(root->left);
    if (!find_node(root->right)) set_node(root->right);
    if (!root->val) root = nullptr;
    return root;
}

int main(int argc, char *argv[]) {
    
    return 0;
}

