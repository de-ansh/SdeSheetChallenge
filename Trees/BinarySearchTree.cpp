/*
In binary Search tree: Its a node based tree which means

 Logic: Left<Root<Right

      10
   9	  13
 1. Entire left subtree is a bst
 2. entire right subtree is a bst
Height of Bst is log n generally
Traversal is Log n=> Binary search (Hint)


*/

//Search

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root!=NULL && root->data!=x ){
        root=x<root->data ?root->left: root->right;
    }
    return root;
}