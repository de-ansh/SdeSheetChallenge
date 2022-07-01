/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int minDepth(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int l= 0;
    int r= 0;
    if(root->left)
       l=minDepth(root->left);
     if(root->right)
        r=minDepth(root->right);
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return true;
    int lh=minDepth(root->left);
    int rh=minDepth(root->right);
    if(abs(rh-lh)>1) return false;
    bool left= isBalancedBT(root->left);
    bool right = isBalancedBT(root->right);
    if(!left|| !right) return false;
    return true;
}

//Better approah
int dfsHeight (BinaryTreeNode<int> *root) {

        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);

        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);

        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return dfsHeight (root) != -1;
}