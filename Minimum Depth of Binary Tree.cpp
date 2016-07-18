#include <queue>
#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
struct Tree {
    TreeNode *root;
    int level;
    Tree(TreeNode *troot, int tlevel) {
        level = tlevel;
        root = troot;
    }
 };
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        Tree *troot = new Tree(root, 1);
        queue<Tree *> q;
        q.push(troot);
        int res = 0;
        while(!q.empty()) {
            Tree *tmp = q.front();
            q.pop();
            if(tmp->root->left == NULL && tmp->root->right == NULL) {
                res = tmp->level;
                break;
            }
            else {
                if(tmp->root->left != NULL) q.push(new Tree(tmp->root->left, tmp->level + 1));
                if(tmp->root->right != NULL) q.push(new Tree(tmp->root->right, tmp->level + 1));
            }
        }
        return res;
    }
};

int main() {

}