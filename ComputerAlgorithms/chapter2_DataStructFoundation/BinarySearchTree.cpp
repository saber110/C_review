#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

template <class Type>
class TreeNode
{
  // friend class BSTree;
  public:
    TreeNode *lchild, *rchild;
    Type data;
};

template <class Type>
class BSTree
{
  private:
    TreeNode<Type>* tree;
    TreeNode<Type>* Search(TreeNode<Type> *t, Type x)
    {
      if(t == NULL) return 0;
      else if(x == t->data) return t;
      else if(x > t->data) return (Search(t->rchild,x));
      else return (Search(t->lchild,x));
    }
  public:
    BSTree(){tree = NULL;}
    ~BSTree(){ delete tree; }
    TreeNode<Type>* Search(Type x)   // 递归搜索
    {
      return Search(tree, x);
    }
    TreeNode<Type>* ISearch(Type x)  // 循环搜索
    {
      bool found = false;
      TreeNode<Type>* t = tree;
      while (t && (!found))
      {
        if(t->data == x) {found = true; return t;}
        else if(t->data > x) t = t->lchild;
        else t = t->rchild;
      }
      return NULL;
    }
    void Insert(Type x)
    {
      bool found = false;
      TreeNode<Type>* p = tree, *q;
      // 搜索插入的位置 q是p的父节点
      while(p && (!found))
      {
        q = p;
        if(x == p->data) found = true;
        else if(x < p->data) p = p -> lchild;
        else p = p -> rchild;
      }

      if(!found)
      {
        p = new TreeNode<Type>;
        p -> lchild = p -> rchild = NULL;
        p -> data = x;
        if(tree)
        {
          if(x < (q -> data)) q->lchild = p;
          else q->rchild = p;
        }
        else
          tree = p;
        // delete p;
      }
    }
    void Delete(Type& x)
    {
      bool found = false;
      TreeNode<Type>* p = tree, *q;
      // 搜索插入的位置 q是p的父节点
      while(p && (!found))
      {
        q = p;
        if(x == p->data) found = true;
        else if(x < p->data) p = p -> lchild;
        else p = p -> rchild;
      }

      if(found)
      {
        if(q == p)
        {
          delete tree;
        }
        // 若是叶子结点
        if((p -> lchild == NULL) && (p -> rchild == NULL))
        {
          if(p == q -> lchild)
          {
            q -> lchild = NULL;
          }
          else
          {
            q -> rchild = NULL;
          }
          delete p;
        }
        // 只包含一个孩子的非叶节点
        else if((p -> lchild != NULL) && (p -> rchild != NULL))
        {
          if(p->lchild != NULL)
          {
            p = p->lchild;
            delete p;
          }
          else
          {
            p = p->rchild;
            delete p;
          }
        }
        // 两个孩子的非叶结点
        else
        {
          // 右子树的最左节点或者左子树的最右节点充当p
          // 左子树的最右节点
          TreeNode<Type> * right = p->lchild, *rightParent;
          while (right->rchild)
          {
            rightParent = right;
            right = right -> rchild;
          }

          p = right;
          if(right->lchild)
          {
            rightParent->rchild = right->lchild;
          }

          delete p;
        }
      }
    }
    int GetHeight(TreeNode<Type> * p)
    {
      if((p->lchild == NULL) && (p->rchild == NULL))
        return 1;
      else if((p->lchild != NULL) && (p->rchild == NULL))
        return 1 + GetHeight(p->lchild);
      else if((p->lchild == NULL) && (p->rchild != NULL))
        return 1 + GetHeight(p->rchild);
      else
        return 1 + GetHeight(p->rchild) + GetHeight(p->lchild);
    }

    int getHeight()
    {
      return GetHeight(tree);
    }
};
int generateRand()
{
  return rand()%50000;
}

void practise2(int n)
{
  int x = n, temp;
  BSTree<int> Bs;
  while(n --)
  {
    temp = generateRand();
    // cout << temp << ' ';
    Bs.Insert(temp);
  }

  cout << Bs.getHeight() << " "<<log2(x) <<" "<<x<< endl;
  cout << Bs.getHeight()/log2(x) << endl;
}

int main()
{
  practise2(100);
  practise2(500);
  practise2(1000);
  practise2(2000);
  practise2(3000);
  practise2(4000);
  practise2(5000);
  practise2(6000);
  practise2(7000);
}
