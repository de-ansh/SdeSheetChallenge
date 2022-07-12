TreeNode<int>* formBST(vector<int> &pre, int &idx, int bound){
    if(idx == pre.size() || pre[idx] > bound) return NULL;
    TreeNode<int> *root = new TreeNode<int>(pre[idx++]);
    root->left = formBST(pre, idx, root->data);
    root->right = formBST(pre, idx, bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int idx = 0;
    return formBST(preOrder, idx, 1e9+1);
}