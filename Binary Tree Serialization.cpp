#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct RESULT {
  int nmaxDepth;
  int nmaxPath;
  
};

class Codec {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    void serializeHelp(TreeNode *root, ostringstream &ss) {
      if(root == NULL) {
        ss << "# ";
      }
      else {
        ss << root->val << " ";
        serializeHelp(root->left, ss);
        serializeHelp(root->right, ss);
      }
    }
    string serialize(TreeNode *root) {
        // write your code here
      ostringstream out;
      serializeHelp(root, out);
      string res = out.str();
      return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
     TreeNode *deserializeHelp(istringstream &in) {
        string val;
        in >> val;
        if(val == "#") return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserializeHelp(in);
        root->right = deserializeHelp(in);
        return root;
     }

    TreeNode *deserialize(string data) {
        // write your code here
      istringstream in(data);
      return deserializeHelp(in);
    }
};

TreeNode *buildTree(int depth, int &val) {
	TreeNode *root = new TreeNode(val);
	if(depth == 0) {
		return root;
	}
	root->left = buildTree(depth - 1, ++val);
	root->right = buildTree(depth - 1, ++val);
	return root;
}

int main() {
  int val = 1;
  TreeNode *tree = buildTree(3, val);
  Solution s;
  vector<vector<int> > res;
  res = s.zigzagLevelOrder(tree);
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}