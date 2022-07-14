#include<bits/stdc++.h>
bool solve(BinaryTreeNode<int> *root ,int k,unordered_set<int>&s){
    if(!root)return 0;
    
    if(s.find(k-root->data)!=s.end())return true;
    s.insert(root->data);
    return solve(root->left,k,s) or solve(root->right,k,s);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int>s;
    return solve(root,k,s);
    // Write your code here
}