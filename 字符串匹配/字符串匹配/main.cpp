//
//  main.cpp
//  字符串匹配
//
//  Created by legendary on 2018/11/13.
//  Copyright © 2018年 legendary. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;


#define MAXSIZE 1000


void get_next(string T, int next[])
{
    int i= 0;//后标
    int j = -1;//前标
    next[0] = -1;
    while(i <= T.length() )
    {
        if(j == -1 || T[i] == T[j])
        {
            ++i;++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}


int KMP(string S,string T, int next[], int pos)
{
    int i= pos; //从S的第pos个位置开始
    int j=-1;
    
    while(i<int(S.length()) && j<int(T.length()))
    {
        if(j == -1 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j >= T.length())
        return int(i-T.length());
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    string S = "defghabaabcac";
    string T = "abaabcac";
    int next[MAXSIZE];
    get_next(T,next);
    cout<<KMP(S,T,next,0);
    
//    for(int i=0;i<T.length();i++)
//        cout<<next[i]<<" ";
    return 0;
}
