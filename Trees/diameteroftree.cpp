#include<bits/stdc++.h>
int height(TreeNode<int>*node, int &maxi){
    if(!node)
        return 0;
    int lh=height(node->left,maxi);
    int rh=height(node->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int maxi=0;
    height(root,maxi);
    return maxi;
}