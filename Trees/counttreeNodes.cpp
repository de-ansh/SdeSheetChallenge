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
class Solution {
public:
    int leftheight(TreeNode *node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int rightheight(TreeNode *node){
        int height=0;
        while(node){
            height++;
            node=node->right;
            }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};