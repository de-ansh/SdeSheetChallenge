#include <bits/stdc++.h>
using namespace std;
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preOrder(vector<int> & ans, TreeNode *root){
    if(root ==NULL)
        return;
    ans.push_back(root->data);
    preOrder(ans,root->left);
    preOrder(ans, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    preOrder(ans, root);
    return ans;
}

/*
vector<int> getPreOrderTraversal(TreeNode *root)
{
     vector<int>preorder;
    if(root==NULL)
        return preorder;
    stack<TreeNode *>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL)
            st.push(root->right);
        if(root->left!=NULL)
            st.push(root->left);
    }
    return preorder;
}
*/