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
void postOrder(vector<int> & ans, TreeNode * root){
    if(root==NULL)
        return;
    postOrder(ans,root->left);
    postOrder(ans,root->right);
        ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    postOrder(ans, root);
    return ans;
}

/*

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>postOrder;
    if(root==NULL)
        return postOrder;
    stack<TreeNode *> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL)
            st1.push(root->right);
    }
    while(!st2.empty())
    {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrder;
}

*/