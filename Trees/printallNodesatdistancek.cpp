//using a hasmap to carry the parent and visited to 
#include<bits/stdc++.h>
void markParent(BinaryTreeNode<int>* node, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(node);
    while(!q.empty())
    {
        BinaryTreeNode<int> *curr = q.front();
        q.pop();
        if(curr->left)
        {
            mp[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right)
        {
            mp[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> track_parent;
    markParent(root, track_parent);
    
    map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*> q;
    int cur_dis = 0;
    q.push(target);
    visited[target] = true;
    int curr_dis = 0;
    while(!q.empty())
    {
        int size = q.size();
        if(curr_dis++ == K) break;
        for(int i = 0; i < size; i++)
        {
            BinaryTreeNode<int>* curr = q.front();
        	q.pop();
            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(track_parent[curr] && !visited[track_parent[curr]])
            {
                q.push(track_parent[curr]);
                visited[track_parent[curr]] = true;
            }
        }
    }
    
    vector<BinaryTreeNode<int>*> res;
    while(!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
    
}