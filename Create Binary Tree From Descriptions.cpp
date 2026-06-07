/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int parent = descriptions[i][0];
            int isleft = descriptions[i][2];
            int child = descriptions[i][1];
            st.insert(child);
            if (mpp.find(parent) == mpp.end()) {
                TreeNode* baap = new TreeNode(parent);
                mpp[parent] = baap;
            }
            if (mpp.find(child) == mpp.end()) {
                TreeNode* baccha = new TreeNode(child);
                mpp[child] = baccha;
            }
            if (isleft) {
                mpp[parent]->left = mpp[child];
            } else {
                mpp[parent]->right = mpp[child];
            }
        }
        TreeNode* root;
        for (int i = 0; i < n; i++) {
            if (st.find(descriptions[i][0]) == st.end()) {
                root = mpp[descriptions[i][0]];
            }
        }
        return root;
    }
};
