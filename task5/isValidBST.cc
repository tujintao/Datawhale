class Solution {
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inorder(root);
        for (int i = 0; i < res.size() - 1; ++i) {
            if (res[i] >= res[i + 1])return false;
        }
        return true;
    }
private:
    vector<int> res;
};
