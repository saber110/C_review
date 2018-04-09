#include <iostream>
#include <iomanip>
using namespace std;

int board[100][100] = {0}, tile = 1;    // 棋盘，当前可用的填充块

/**
  * @NOTE: 四分棋盘时范围充分覆盖
  *         填充块放在小棋盘的相对位置
  */
void TileBoard(int topRaw, int topColumn, int defectRow, int defectColumn, int size)
// 棋盘左上角行号， 棋盘左上角的列号， 残缺块的行号， 残缺块的列号， 棋盘一边的长度
{
  if (size == 1) {return;}
  int tileToUse = tile ++, quadrantSize = size/2;

  // 填充左上角
  if(defectRow < topRaw + quadrantSize &&
    defectColumn < topColumn + quadrantSize)
    {
      // 残缺块在左上
      TileBoard(topRaw,topColumn,defectRow,defectColumn,quadrantSize);
    }
  else
  {
    // 将填充块放在本棋盘的右下角
    board[topRaw + quadrantSize -1][topColumn + quadrantSize -1] = tileToUse;
    // 填本棋盘的左上剩下的部分
    TileBoard(topRaw,topColumn,topRaw + quadrantSize -1, topColumn + quadrantSize -1,quadrantSize);
  }

  if(defectRow < topRaw + quadrantSize &&
    defectColumn >= topColumn + quadrantSize)
  {
    // 残缺在右上
    TileBoard(topRaw,topColumn + quadrantSize ,defectRow,defectColumn,quadrantSize);
  }
  else
  {
    // 将填充块放在本棋盘的左下角
    board[topRaw + quadrantSize -1][topColumn + quadrantSize] = tileToUse;
    // 填本棋盘的右上剩下的部分
    TileBoard(topRaw,topColumn + quadrantSize,topRaw + quadrantSize -1, topColumn + quadrantSize,quadrantSize);
  }

  if(defectRow >= topRaw + quadrantSize &&
    defectColumn < topColumn + quadrantSize)
    // 残缺在左下
  {
    TileBoard(topRaw + quadrantSize,topColumn,defectRow,defectColumn,quadrantSize);
  }
  else
  {
    // 将填充块放在本棋盘的右上角
    board[topRaw + quadrantSize][topColumn + quadrantSize -1] = tileToUse;
    // 填本棋盘的左下剩下的部分
    TileBoard(topRaw + quadrantSize,topColumn ,topRaw + quadrantSize, topColumn + quadrantSize -1,quadrantSize);
  }

  if(defectRow >= topRaw + quadrantSize &&
    defectColumn >= topColumn + quadrantSize)
  {
    // 残缺在右下
    TileBoard(topRaw + quadrantSize,topColumn + quadrantSize,defectRow,defectColumn,quadrantSize);
  }
  else
  {
    // 将填充块放在本棋盘的左上角
    board[topRaw + quadrantSize][topColumn + quadrantSize] = tileToUse;
    // 填本棋盘的右下剩下的部分
    TileBoard(topRaw + quadrantSize ,topColumn + quadrantSize,topRaw + quadrantSize, topColumn + quadrantSize,quadrantSize);
  }
}

void Print(int size)
{
  int i,j;
  for( i=0;i<size;i++)
  {
      for( j=0;j<size;j++)
          cout<<setw(6)<<board[i][j];//setw(6)//输出量不足6个字符时在左面填充空白
      cout<<endl<<endl;
  }
}

int main()
{
  TileBoard(0,0,0,0,8);
  Print(8);
  return 0;
}
