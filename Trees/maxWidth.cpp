//Number of nodes present between two nodes at any level
//level order traversal
//idea is to count the number of total nodes and then substract the index of last node with first node+1

// for ith if 1 based left node = 2*i and right nod =2*i+1, zero based left based 2*i+1 and right 2*i+2  
int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int n = q.size();
        cnt = max(cnt, n);
        
        for(int i = 0; i < n; i++){
            TreeNode<int> *tmp = q.front();
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
    
    return cnt;
}