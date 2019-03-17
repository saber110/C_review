#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct Node {
	struct Node * lchild;
	struct Node * rchild;
	char ch;
} node, *BTree;

node * createNode(char ch) {
	node *p = new node();
	p->lchild = p->rchild = NULL;
	p->ch = ch;
	return p;
}

void createBTree(BTree &root, string str1, string str2) {
	// str1 : preorder£» str2 : Inorder
	root = createNode(str1[0]);

	if(str1.length() > 1) {
		// split Inorder into 2 string ; first is lchild
		string e1, e2, s1, s2;
		e1 = str2.substr(0, str2.find(str1[0]));
		e2 = str2.substr(str2.find(str1[0]) + 1, str2.length());
		// split Preorder into 2 string ; first is lchild
		for(int i = 1; i < str1.length(); i ++) {
			if(e1.find(str1[i]) != -1)	s1 += str1[i];
			else s2 += str1[i];
		}
//		cout << "e\tlchild\t" << e1 << "\trchild\t" << e2 << endl;
//		cout << "s\tlchild\t" << s1 << "\trchild\t" << s2 << endl;

		if(s1.length() > 0) {
			createBTree(root->lchild, s1, e1);
		}
		if(s2.length() > 0) {
			createBTree(root->rchild, s2, e2);
		}
	}

}
//void destory(node * root){
////	node *p = root
//	if(root->lchild == NULL && root->rchild == NULL){
//		free(root);
//	}
//	else{
//		if(root->lchild)	destory(root->lchild);
//		if(root->rchild)	destory(root->rchild);
//	}
//}


void freeTree(node* root) {
	if (root!=NULL) {

		if (root->lchild) {
			freeTree(root->lchild);
			root->lchild = NULL;
		}
		if (root->rchild) {
			freeTree(root->rchild);
			root->rchild = NULL;
		}
		if (root!=NULL) {
			free(root);
			root=NULL;
		}
	}
}

void AfterOrder(BTree  root) {
	if(root->lchild != NULL) {
		AfterOrder(root->lchild);
	}
	if(root->rchild) {
		AfterOrder(root->rchild);
	}
	cout << root->ch;
}
int main()	{
	string str1, str2;
	while(cin >> str1 >> str2) {
		// create binTree
		BTree root ;
		createBTree(root, str1, str2);
//		cout << "done" << endl;
		AfterOrder(root);
		
		cout << endl;
		freeTree(root);
	}
	return 0;
}
