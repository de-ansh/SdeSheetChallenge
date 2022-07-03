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