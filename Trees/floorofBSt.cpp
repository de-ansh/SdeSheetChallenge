
int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    while(root){
        if(root->val==X)
        {
            floor=root->val;
            return floor;
        }
        if(X>root->val){
            floor=root->val;
            root=root->right;
        }
        else
            root=root->left;
    }
    return floor;
}