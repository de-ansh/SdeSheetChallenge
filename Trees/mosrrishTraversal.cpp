vector<int> getinotdrt(TreeNode * root ){
	vector<int> inorder;
	TreeNode * cur=root;
	while(cur!= NULL){
		if(cur->left==NULL){
			inorder.push_back(cur->val);
			cur=cur->right;
		}
		else{
			TreeNode *prev= cur->left;
			while(prev->right && prev->right!= cur){
				prev=prev->right;
			}
			if(prev->right==NULL){
				prev->right=curr;
				cur=cur->left;
			}else{
				prev->right=NULL;
				inorder.push_back(cur->val);
				cur=cur->right;
			}

		}

	}
	return inorder;
}