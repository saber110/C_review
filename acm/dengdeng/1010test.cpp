#include<iostream>

using namespace std;
char map[15][15];
int w, h;//U��,��D��,��L��,��R��
bool isCanGo(int x, int y, char d){
    if (d == 'L'){
        if (y - 1 >= 0 && map[x][y - 1] != '*')
            return true;
    }
    else if (d == 'R'){
        if (y + 1 < h && map[x][y + 1] != '*')
            return true;
    }
    else if (d == 'U'){
        if (x - 1 >= 0 && map[x-1][y] != '*')
            return true;
    }
    else if (d == 'D'){
        if (x + 1 < w && map[x+1][y] != '*')
            return true;
    }
    return false;
}
int main(){
    while (cin >> w >> h){
        char d;
        int posx, posy;
        for (int i = 0; i < w; i++){
//            cin >> map[i];//���������̫���ˣ�û�пո�ÿ�о���һ������
            // R****  *****��ע�����������
            for (int j = 0; j < h; j++){
                cin >> map[i][j];
                if (map[i][j] == 'U' || map[i][j] == 'D' || map[i][j] == 'L' || map[i][j] == 'R'){
                    posx = i;
                    posy = j;
                    d = map[i][j];
                }
            }
        }
        int num = 1,time=1;
        while (1){
            if (isCanGo(posx, posy, d)){//��һ������ˢ��time��ֵ,�߹����ӵļ�һ
                time = 1;
                num += 1;
                map[posx][posy] = '*';
                if (d == 'U'){
                    posx = posx - 1;
                }
                else if (d == 'D'){
                    posx = posx + 1;
                }
                else if (d == 'L'){
                    posy -= 1;
                }
                else if (d == 'R'){
                    posy += 1;
                }
                //cout << posx << " " << posy << endl;
            }
            else if(time==1){//��������time��һ
                time--;
                if (d == 'U'){
                    d = 'R';
                }
                else if (d == 'D'){
                    d = 'L';
                }
                else if (d == 'L'){
                    d = 'U';
                }
                else if (d == 'R'){
                    d = 'D';
                }
                //cout << "convert!" << d << endl;
            }
            else{
                break;
            }
        }
        cout << num << endl;
    }
    return 0;
}
