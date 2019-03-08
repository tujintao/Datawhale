#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//朴素的字符串匹配算法
//O((len2 - len1 + 1) * len 1)
bool find(string &pat, string &txt) {
    const int len1 = pat.length();
    const int len2 = txt.length();
    for (int i = 0; i <= abs(len2-len1); ++i) {
        int j;
        for (j = 0; j < len1; ++j) {
            if (pat[i + j] != pat[j]) break;
        }
        if (j == len2){
            //返回找到的下标
            return i;
        }
    }
    return -1;
}
int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    cout << find(pat, txt) << endl;
    return 0;
}