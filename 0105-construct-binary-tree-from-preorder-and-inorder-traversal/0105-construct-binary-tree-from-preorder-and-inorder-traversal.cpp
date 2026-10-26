/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>&inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIndx,int left ,int right){
        if(left>right)
        return NULL;
        TreeNode* root=new TreeNode(preorder[preIndx]);
        int inIndx=search(inorder,left, right,preorder[preIndx]);
        preIndx++;
        root->left=helper(preorder ,inorder,preIndx,left,inIndx-1);
        root->right=helper(preorder, inorder,preIndx,inIndx+1,right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndx=0;
        return helper(preorder,inorder,preIndx,0,inorder.size()-1);
        
    }
};