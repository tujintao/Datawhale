#include <iostream>
#include <memory>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    TreeNode ():val(0), left(nullptr), right(nullptr){}
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void preorderTraversal (TreeNode *root) {
    if (!root) return;
    cout << root->val << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal (TreeNode *root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}
void postTraversal (TreeNode* root) {
    if (!root) return;
    postTraversal(root->left);
    postTraversal(root->right);
    cout << root->val << endl;
}
class BTree {
public:
    BTree():_root(new TreeNode()), root(_root.get()){}
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) 
            return new TreeNode(val);
        if (val > root->val)
            root->right = insert(root->right, val);
        else 
            root->left = insert(root->left, val);
        return root;
    }
    TreeNode* search(TreeNode *root, int val) {
        if (root == nullptr) return nullptr;
        if (val == root->val) return root;
        else if (val > root->val)
            return search(root->right, val);
        return search(root->left,  val);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      if (root->left != nullptr && root->right != nullptr) {
        TreeNode* min = root->right;
        while (min->left != nullptr) min = min->left;
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
      } else {
        TreeNode* new_root = root->left == nullptr ? root->right : root->left;
        root->left = root->right = nullptr;
        delete root;
        return new_root;
      }
    }    
    return root;
    }
    // void dfs(TreeNode* root){
    //     if (!root) return;
    //     dfs(root->left);
    //     cout << root->val << endl;
    //     dfs(root->right);
    // }
    TreeNode* getroot(){return _root.get();}
    void insert(int val){
        insert(root, val);
    }
    TreeNode* search(int val) {
        return search(root, val);
    }
    TreeNode* deleteNode(int val) {
        return deleteNode(root, val);
    }
private:
    unique_ptr<TreeNode> _root;
    TreeNode *root;
};

int main()
{
    BTree a;
    a.insert(5);
    a.insert(6);
    a.insert(1);

    inorderTraversal(a.getroot());
    cout << (a.search(6)->val == 6) << endl;
    
    a.deleteNode(5);
    inorderTraversal(a.getroot());
    //然后发了个bug。。我根节点偷懒用的unique_ptr然后根节点我给初始化成0了。。

    return 0;
}