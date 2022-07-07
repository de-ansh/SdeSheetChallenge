/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        TreeNode<int>* root = new TreeNode<int>(postorder[pe]);
        int ri = hm[postorder[pe]];
        TreeNode<int>* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        TreeNode<int>* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    int postStart=0, postend=postOrder.size()-1;
    int inStart=0, inEnd= inOrder.size()-1;
    map<int,int> Mapp;
    for(int i=0;i<inOrder.size();i++)
        Mapp[inOrder[i]]=i;
    return buildTreePostIn(inOrder, inStart, inEnd,postOrder, postStart, postend,Mapp);
}
