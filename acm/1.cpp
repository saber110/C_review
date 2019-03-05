#include <iostream>
using namespace std;

char * replaceSpace(char *str,int length);
char bak[255] = {0};
int main(){
    char ch[] = "hello world";
    cout << replaceSpace(ch, 11);
    cout << "ch " << ch << endl;
    return 0;
}
char * replaceSpace(char *str,int length) {
    int j = 0;
    for(int i = 0; i < length; i++){
        if(str[i] != ' ')
            bak[j++] = str[i];
        else{
            bak[i] = '%';
            bak[i+1] = '2';
            bak[i+2] = '0';
            j = i + 3;
        }
    }
    return bak;
}
