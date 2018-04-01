#include <iostream>
using namespace std;
/** 顺序栈
 * 使用一个一维数组表示，栈底放在stack[0]
 * top 变量作为指针
 */
template <class Type>
class stack
{
  private:
    int top, MaxSize;
    Type * stack;
  public:
    stack(int MSize) : MaxSize(MSize)      /// 构造函数的同时初始化变量
    {
      stack = new Type[MaxSize];
      top = -1;
    }
    ~stack()
    {
      delete [] stack;
    }
    inline bool Add(const Type item)
    {
      if(StackFull())
      {
        cout << "Stack is full";
        return false;
      }
      stack[++ top] = item;
      return true;
    }
    inline bool Delete(Type & item)
    {
      if(StackEmpty())
      {
        cout << "Stack is empty";
        return false;
      }
      item = stack[top --];
      return true;
    }
    inline bool StackEmpty()
    {
      if(top < 0) return true;
      else return false;
    }
    inline bool StackFull()
    {
      if(top >= (MaxSize - 1)) return true;
      else return false;
    }
};
