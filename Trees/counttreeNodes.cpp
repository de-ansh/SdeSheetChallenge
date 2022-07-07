class Solution {
public:
    void inorder(TreeNode* node,int &count){
        if(node==NULL)
            return;
        inorder(node->left,count);
        count++;
        inorder(node->right,count);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        inorder(root,count);
        return count;
    }
};


//Since No. of nodes = 2^h-1;
