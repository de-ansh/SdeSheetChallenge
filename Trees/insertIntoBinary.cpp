TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    if(root == NULL){
        return new TreeNode<int>(val);
    } 
       TreeNode<int> *curr = root;
    while(curr!=NULL){
        if(curr->val > val){
            if(curr->left!=NULL){
                curr = curr->left;
            }
            else{
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
        else{
            if(curr->right != NULL){
                curr = curr->right;
            }
            else{
                curr ->right = new TreeNode<int>(val);
                break;
            }
        }
    }
    return root;
}