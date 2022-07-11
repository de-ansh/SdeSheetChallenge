/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

//1) Node to be deleted is the leaf: Simply remove from the tree. 
//2) Node to be deleted has only one child: Copy the child to the node and delete the child 
/*
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder
 successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
*/
BinaryTreeNode<int>* findLastRight(BinaryTreeNode<int>* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
 BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            BinaryTreeNode<int>* rightChild = root->right;
            BinaryTreeNode<int>* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }
    

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
     if (root == NULL) {
            return NULL;
        }
        if (root->data == key) {
            return helper(root);
        }
        BinaryTreeNode<int> *dummy = root;
        while (root != NULL) {
            if (root->data > key) {
                if (root->left != NULL && root->left->data == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->data == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
}

   