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
void inorder(vector<int>&ans,TreeNode * root){
    if(root==NULL)
        return;
    inorder(ans,root->left);
    ans.push_back(root->data);
    inorder(ans,root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    
    vector<int> ans;
    inorder(ans, root);
    return ans;
}
//iterative
/*

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>inOrder;
    stack<TreeNode *> st;
    TreeNode * node= root;
    while(true){
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()==true)
                break;
            node=st.top();
            st.pop();
            inOrder.push_back(node->data);
            node=node->right;
        }
    }
    return inOrder;
}
*/


/*

vector<int> getPostOrderTraversal(TreeNode *root){
    vector<int> postOrder;
    if(root==NULL)
        return postOrder;
    stack<TreeNode*> st;
    while(root!=NULL || !st.empty()){
        if(root!=NULL){
            st.push(root);
            root=root->left;
            }
        else{
            TreeNode * temp= st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else root=temp;
        }
    }
    return postOrder;
}
*/