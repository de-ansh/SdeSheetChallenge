bool isIdentical(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL || root2 == NULL) return root1==root2;
    return ((root1->data == root2->data) && isIdentical(root1->left, root2->right) && isIdentical(root1->right, root2->left));
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return isIdentical(root->left, root->right);
}

/*
bool isSymmetric(Node* root) {
    queue<Node*> treeNodes;
    treeNodes.push(root);
    treeNodes.push(root);
    while (!treeNodes.empty()) {
        Node* leftChild = treeNodes.front();
        treeNodes.pop();
        Node* rightChild = treeNodes.front();
        treeNodes.pop();
        if (leftChild->data != rightChild->data) {
            return false;
        }
        if(leftChild->left != NULL && rightChild->right != NULL) {
            treeNodes.push(leftChild->left);
            treeNodes.push(rightChild->right);
        }
        else if(leftChild->left != NULL || rightChild->right != NULL) {
            return false;       
        }
        if(leftChild->right != NULL && rightChild->left != NULL) {
            treeNodes.push(leftChild->right);
            treeNodes.push(rightChild->left);
        }
        else if(leftChild->right != NULL || rightChild->left != NULL) {
            return false;
        }
    }
    return true;
}
*/