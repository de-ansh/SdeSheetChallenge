//Approach
/*

The algorithm approach can be stated as:

Create a map to store the inorder indexes.
Call the function constructTree with all 7 parameters as shown above.
In the recursive function, first check the base case, if (preStart,>preEnd || inStart> inEnd) then return NULL.
Construct a node (say root) with the root value( first element of preorder). 
Find the index of the root, say elem from the hashmap.
Find the number of elements ( say nElem) in the left subtree  = elem – inStart
 Call recursively for the left subtree with correct values (shown in the above table) and store the answer received in root->left.
Call recursively for the right subtree with correct values (shown in the above table) and store the answer received in root->right.
Return root

*/
/*#include<bits/stdc++.h>
TreeNode<int>* makeBT(vector<int>& inorder, vector<int>& preorder,int li,int hi,int lp,int hp,map<int,int> &mpp){
    if(lp<0 || lp>hp)return NULL;
// 	cout<<postOrder[hp]<<endl;
    int rootData=preorder[lp];
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int index = mpp[rootData];
    int numLeft=lp+index-li;
    root->left=makeBT(inorder,preorder,li,index-1,lp+1,numLeft,mpp);
    root->right=makeBT(inorder,preorder,index+1,hi,numLeft+1,hp,mpp);
    return root;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int n=inorder.size();
	map<int,int> mpp;
	for(int i=0;i<n;i++){
		mpp[inorder[i]]=i;
	}
	return makeBT(inorder,preorder,0,n-1,0,n-1,mpp);
}*/

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  node * root = newNode(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

node * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}