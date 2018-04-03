#include <iostream>
#include <string.h>
using namespace std;

// 这次从大到小建立堆
template <class Type>
class Heap
{
  private:
    Type *array;        // 存储堆数据
    int MaxSize, Nel;   // 最大大小及已有元素数目
    void adjust(int i, int n)        // 从i开始检查数组并保持堆性质
    {
      int j = 2*i;          // 教育要从孩子抓起
      Type item = array[i];
      while (j <= n)
      {
        if((array[j] < array[j+1]) && (j < n)) j++; // 大一点的孩子是个榜样
        if(item > array[j]) break;              // 大一点的孩子规矩的话可以认为该子树是规矩的（由insert保证）
        array[j/2] = array[j];                      // 鸟儿大了要成家，自己罩不住孩子就靠孩子罩着
        j *= 2;                             // 再检查孩子的孩子的规矩性
      }
      array[j/2] = item;                        // 找准自己的位置
    }
  public:
    Heap(int MSize):MaxSize(MSize)
    {
      array = new Type[MaxSize + 1];
      Nel = 0;
    }
    ~Heap()
    {
      delete []array;
    }
    // 要求：一个一个的插入堆中
    bool Insert(Type item)
    {
      int i = ++Nel;
      if(i >= MaxSize)
      {
        cout << "Heap size exceeded" << endl;
        return false;
      }
      while ((i > 1) && (array[i/2] < item))
      {
        array[i] = array[i/2];   // 节点置换
        i /= 2;
      }
      array[i] = item;

      return true;
    }
    bool Delete(Type& item)
    {

      return true;
    }
    // 从堆中删除最大的元素并且返回
    bool DeleteMax(Type &item)
    {
      if(Nel <= 0)
      {
        cout << "Heap is empty" << endl;
        return false;
      }
      item = array[1];
      array[1] = array[Nel --];         // 让最小的作为根
      adjust(1, Nel);            // 这样就能检查并维持整个堆特性
      return true;
    }
    // 对n个元素的堆进行排序
    void sort(int n)
    {
      Heap heap[n];
      Type x;
      for(int i = 1; i <= n; i ++)
      {
        heap.Insert(array[i]);
      }
      for(int i = 1; i <= n; i++)
      {
        heap.DeleteMax(x);
        array[n-i+1] = x;
      }
    }
    // 批量建堆
    // 要求： 在堆初始化的时候确定堆的内容
    void Heapify(Type a[], int n)
    {
      Nel = n;
      for(int i = 0; i <=n; i++)
        array[i] = a[i];
      for(int i = n/2; i; i--)
      {
        adjust(i, n);
      }
      cout << endl;
    }
    // a[1:n]为待排序的元素
    void HeapSort(int n)
    {
      Heapify(n);    // 建堆
      // 交换最大和最末尾的元素
      for(int i = n; i > 2; i--)
      {
        Type t = array[i];
        array[i] = array[1];
        array[1] = t;
        adjust(1, i-1);
      }
    }

    void Print(string addition="NULL")
    {
      for(int i = 1; i <= Nel; i++)
      {
        cout << array[i] << ' ';
      }
      cout << endl;
    }
};

void practise1(int a[],int n)
{
  int x = 0;
  Heap<int> heap(n+4);
  heap.Heapify(a, n);
  heap.Print();
  heap.Insert(15);
  heap.Print();
  heap.Insert(20);
  heap.Print();
  heap.Insert(45);
  heap.Print();
  heap.DeleteMax(x);
  // cout << "dm " << x << endl;
  heap.DeleteMax(x);
  // cout << "dm " << x << endl;
  heap.DeleteMax(x);
  // cout << "dm " << x << endl;
  heap.DeleteMax(x);
  // cout << "dm " << x << endl;
  heap.Print();

  cout << endl << endl;
}
int main()
{
  int a[] = {1000,3,5,6,7,20,8,2,9,12,15,30,17};
  int b[] = {1000,10,2,7,6,5,9,12,35,22,15,1,3,4};
  int c[] = {1000,1,2,3,4,5,6,7,8,9,10,12,15,22,35};

  practise1(a, sizeof(a)/sizeof(a[0]) - 1);
  practise1(b, sizeof(b)/sizeof(b[0]) - 1);
  practise1(c, sizeof(c)/sizeof(c[0]) - 1);
  return 0;
}
