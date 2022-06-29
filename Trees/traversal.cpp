/************************************************************

    Following is the Binary Tree node structure:

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
    };


************************************************************

vector<int> answer;

void inOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    inOrder(node->left);

    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit right subtree.
    inOrder(node->right);
}

vector<int> getInOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call inOrder function and store inOrder traversal in answer array.
    inOrder(root);

    // Return answer.
    return answer;

}


void preOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }
    // Add data of node to answer.
    answer.push_back(node->data);

    // Visit left subtree.
    preOrder(node->left);

    // Visit right subtree.
    preOrder(node->right);
}

vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call preOrder function and store preOrder traversal in answer array.
    preOrder(root);

    // Return answer.
    return answer;
}


void postOrder(BinaryTreeNode<int> *node) {

    // Base case.
    if (node == NULL) {
        return;
    }

    // Visit left subtree.
    postOrder(node->left);

    // Visit right subtree.
    postOrder(node->right);

    // Add data of node to answer.
    answer.push_back(node->data);

}

vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root) {

    // Clear contents of answer before every test case.
    answer.clear();

    // Call postOrder function and store postOrder traversal in answer array.
    postOrder(root);

    // Return answer.
    return answer;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result(3);

    // Call function to get inOrder Traversal.
    result[0] = getInOrderTraversal(root);

    // Call function to get preOrder Traversal.
    result[1] = getPreOrderTraversal(root);

    // Call function to get postOrder Traversal.
    result[2] = getPostOrderTraversal(root);

    // Return all 3 tree traversals.
    return result;
}
*/
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({
    root,
    1
  });
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({
          it.first -> left,
          1
        });
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({
          it.first -> right,
          1
        });
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right = newNode(3);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  vector < int > pre, in , post;
  allTraversal(root, pre, in , post);

  cout << "The preorder Traversal is : ";
  for (auto nodeVal: pre) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal: in ) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal: post) {
    cout << nodeVal << " ";
  }
  cout << endl;

  return 0;
}