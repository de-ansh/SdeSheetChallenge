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

int getMaxWidth(TreeNode<int> *root){
    if(!root)
        return 0;
    int ans=0;
    queue<pair<TreeNode<int>*,int>>q;
    q.push(root,0);
    while(!q.empty()){
        int size= q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id= q.front().second-mmin;
            TreeNode<int>* temp= q.front().first;
            q.pop();
            if(i==0) first= cur_id;
            if(i==size-1) last = cur_id;
            if(temp->left)
                q.push({node->left,cur_id*2+1});
            if(node->right)
                q.push({node->right,cur_id*2+2});
        }
        ans= max(ans,last-first+1);
    } 
    return ans;
}