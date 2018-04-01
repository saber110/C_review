#include <iostream>
using namespace std;

template <class Type>
class Queue
{
  private:
    Type * q;
    int front, rear, MaxSize;
  public:
    Queue(int MSize) : MaxSize(MSize)
    {
      q = new Type[MaxSize];
      front = rear = 0;
    }
    ~Queue()
    {
      delete [] q;
    }
    bool Add(const Type item)
    {
      rear = (++ rear) % MaxSize;
      // 挪动之后才能判断
      if(rear == front)
      {
        cout << "Queue is full" << endl;
        // 将之前挪动的rear回位
        if(!front) rear = MaxSize - 1;
        else rear --;
        return false;
      }
      else
      {
        q[rear] = item;
        return true;
      }
    }
    bool Delete(Type& item)
    {
      if(rear == front)
      {
        cout << "" << endl;
        return false;
      }
      else
      {
        front = (++ front) % MaxSize; // 将front向前移动
        item = q[front];              // 返回新的头
        return true;
      }
    }
};
