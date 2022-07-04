#include<bits/stdc++.h>

//Naive Approach

/*

int getDepth(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int leftSubtreeDepth = getDepth(root->left);
    int rightSubtreeDepth = getDepth(root->right);
    return max(leftSubtreeDepth, rightSubtreeDepth) + 1;
}
int getDiameter(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftSubtreeDiameter = getDiameter(root->left);
    int rightSubtreeDiameter = getDiameter(root->right);
    int diameter = getDepth(root->left) + getDepth(root->right);
    diameter = max(diameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
    return diameter;
}
*/
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