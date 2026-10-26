
class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& postIndx, int left, int right) {
        if (left > right)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndx]);
        int inIndx = search(inorder, left, right, postorder[postIndx]);
        postIndx--;

        root->right = helper(inorder, postorder, postIndx, inIndx + 1, right);
        root->left = helper(inorder, postorder, postIndx, left, inIndx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndx = postorder.size() - 1;
        return helper(inorder, postorder, postIndx, 0, inorder.size() - 1);
    }
};
