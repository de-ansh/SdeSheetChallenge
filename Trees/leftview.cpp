void leftv(BinaryTreeNode<int> *root,vector<int> &ans,int level)
{
 if(root==NULL)
   return;
   
   if(level==ans.size())
   ans.push_back(root->data);
   
   if(root->left)
   leftv(root->left,ans,level+1);
   if(root->right)
   leftv(root->right,ans,level+1);
}
void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
   if(root==NULL)
   return;
   int level = 0;
   leftv(root,ans,level);
   for(int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";
   //Write your code here
}


//rightView
vector<int> rightView(Node* root) {
    queue<Node*> treeNodes;
    vector<int> treeRightView;
    treeNodes.push(root);
    while (!treeNodes.empty()) {
        int n = treeNodes.size();
        for (int i = 0; i < n; i++) {
            Node* currentNode = treeNodes.front();
            treeNodes.pop();
            if (i == 0) {
                treeRightView.push_back(currentNode->data);
            }
            if (currentNode->right != NULL) {
                treeNodes.push(currentNode->right);
            }
            if (currentNode->left != NULL) {
                treeNodes.push(currentNode->left);
            }
        }
    }
    return treeRightView;
}