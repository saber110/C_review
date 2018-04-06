class Sets
{
// p[i]存储该元素父节点的下标
private:
  int *p, n;
public:
  Sets(int Size) : n(Size)
  {
    p = new int(Size + 1);
    for(int i=0; i <= n; i++)
      p[i] = -1;
  }
  ~Sets()
  {
    delete []p;
  }
  // 以i和j为树根的树求并集
  void SimpleUnion(int i, int j)
  {
    p[i] = j;
  }
  // 从下标i开始，沿着父指针一直找到父指针为-1的节点
  int SimpleFind(int i)
  {
    while(p[i] > 0)
    {
      i = p[i];
    }
    return i;
  }
  // 权重规则
  // 为根节点添加count，方便起见令p[i] = -count
  // 使用权重规则合并以i和j为根的集合，i != j
  // p[i] == -count[i],p[j] == -count[j]
  void WeightedUnion(int i, int j)
  {
    int temp = p[i] + p[j];
    if(p[i] > p[j])
    {
      p[i] = j;
      p[j] = temp;    // 合并之后节点数相加
    }
    else
    {
      p[j] = i;
      p[i] = temp;
    }
  }

  int CollapsingFind(int i)
  {
    int r = i;
    while(p[r] > 0) r = p[r]; // 查找树根
    while(i != r)
    {
      // 令从i到根的所有节点指向根节点
      int s = p[i];
      p[i] = r;
      i = s;
    }
    return r;
  }
};
