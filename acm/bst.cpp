#include <iostream>
#include <stdlib.h>
#include <stack>
#define elemType int
#define keyType int
using namespace std;
//节点内所存数据为int，节点上的键值为int

//二叉排序树的存储结构——二叉链表
typedef struct{
   keyType key;
   elemType content;
}selemType;
typedef struct BSTNode{
   selemType data;
   struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//比较树的节点的键值和要插入节点的键值大小
int compare(BSTree &T,keyType key){
   if(T->data.key==key){
      return 0;
   }else if(T->data.key<key){
      return 1;
   }else{
      return -1;
   }
}

//搜索二叉排序树
bool searchBST(BSTree T, keyType key, BSTree f,BSTree &p){
   if(!T){
      p=f;
      return false;
   }else{
      switch(compare(T,key)){
         case -1:
            return searchBST(T->lchild,key,T,p);
         case 0:
            p=T;
            return true;
         case 1:
            return searchBST(T->rchild,key,T,p);
      }
  }
  return false;
}

//将节点插入二叉排序树
bool insertBST(BSTree &T,selemType e){
   BSTree p;
   if(!searchBST(T,e.key,NULL,p)){
      BSTree s=(BSTree)malloc(sizeof(BSTNode));
      s->data=e;
      s->lchild=s->rchild=NULL;
      if(!p){
         T=s;
        // cout<<"i can't have parents"<<endl;
      }else if(p->data.key<e.key){
         p->rchild=s;
         if(!p->lchild){
           p->lchild=NULL;
         }
        // cout<<"i am his right child"<<endl;
      }else{
         p->lchild=s;
         if(!p->rchild){
           p->rchild=NULL;
         }
        // cout<<"i am his left child"<<endl;
      }
      return true;
   }else{
      return false;
   }
}

//将节点从二叉排序树中删除
bool deleteBST(BSTree &T,keyType key){
   BSTree p;
   if(!T||!searchBST(T,key,NULL,p)){
      return false;
   }else{
      BSTree q;
      if(!p->lchild){
         q=p;
         p=p->rchild;
         free(q);
      }else if(!p->rchild){
         q=p;
         p=p->lchild;
         free(q);
      }else{
         q=p;
         BSTree s=p->lchild;
         while(s->rchild){
            q=s;
            s=s->rchild;
         }
         p->data=s->data;
         if(p==q){
            p->lchild=s->lchild;
         }else{
            q->rchild=s->lchild;
         }
         free(s);
      }
      return true;
   }
}

//中序遍历二叉排序树
bool inOrderTraverse(BSTree T){
   stack<BSTree> s;
   // initStack(s);
   BSTree p;
   if(T->lchild){
      p=T->lchild;
   }else if(T->rchild){
      p=T->rchild;
   }else{
      cout<<"it's a empty tree"<<endl;
      return false;
   }
   while(p||!s.empty()){
      if(p){
         s.push(p);
         cout<<"The tree's node is "<<p->data.key<<endl;
         p=p->lchild;
      }else{
         p = s.top();
         s.pop();
         // cout<<"The tree's right node is "<<p->data.key<<endl;
         p=p->rchild;
      }
   }
   return true;
}

//主函数测试结果
int main(void){
   BSTree myTree;
   myTree->lchild=myTree->rchild=NULL;
   myTree->data.key=0;
   myTree->data.content=0;
   selemType temp[5]={{1,2},{9,2},{8,3},{7,6},{5,0}};
   for(int i=0;i<5;i++){
      insertBST(myTree,temp[i]);
   }
   inOrderTraverse(myTree);
   return 0;
}
