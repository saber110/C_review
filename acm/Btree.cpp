#include <iostream>
#include <string>
#include <stack>
#define ElemType char

using namespace std;

typedef struct BNode{
  ElemType data;
  struct BNode * lchild, *rchild;
}BiTNode, *BTree1;

void CreateBTree1(BTree1 &T){
  ElemType ch;
  cin >> ch;
  if(ch == '|') T = NULL;
  else{
    try{
      T = new BiTNode();
    }
    catch(bad_alloc){
      exit(EOVERFLOW);
    }
    T->data = ch;
    CreateBTree1(T->lchild);
    CreateBTree1(T->rchild);
  }
}

void PostTraverse(BiTNode* root){
  if(root != NULL)
  {
    // cout<<root->data;         // 前序便利
    PostTraverse(root->lchild);
    cout<<root->data;         // 中序便利
    PostTraverse(root->rchild);
    // cout<<root->data;         // 后序便利
  }
}

int main(int argc, char const *argv[]) {
  BTree1 T;
  CreateBTree1(T);
  PostTraverse(T);
  cout << endl;
  // InOrder(T);
  return 0;
}
