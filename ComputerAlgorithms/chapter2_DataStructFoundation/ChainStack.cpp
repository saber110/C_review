#include <iostream>
using namespace std;
template <class Type>
class Stack
{
  private:
    struct node
    {
      Type data;
      struct node *link;
    };
    struct node *top;
  public:
    Stack()
    {
      top = NULL;
    }
    ~Stack()
    {
      struct node * temp;
      while (top)
      {
        temp = top;
        top = top -> link;
        delete temp;
      }
    }
    bool Add(const Type item)
    {
      struct node * temp;
      if(temp)
      {
        temp -> data = item;
        temp -> link = top;   // 将新元素插入栈中
        top = temp;           // 更新新元素为栈顶
        return true;
      }
      else
      {
        cout << "out of space" << endl;
        return false;
      }
    }
    bool Delete(Type& item)
    {
      if(StackEmpty())
      {
        cout << "stack is empty" << endl;
        return false;
      }
      else
      {
        struct node * temp;
        temp -> data = item;
        temp -> link = top;
        top = top -> link;
        delete temp;
        return true;
      }
    }
    bool StackEmpty()
    {
      return top?false:true;
    }
};
