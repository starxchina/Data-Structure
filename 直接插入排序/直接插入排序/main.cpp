//
//  main.cpp
//  直接插入排序
//
//  Created by legendary on 2018/6/5.
//  Copyright © 2018年 starx. All rights reserved.
//

#include <iostream>

#define MAXSIZE 20

typedef int KeyType;

typedef struct
{
    KeyType key;
    
}RedType;

typedef struct
{
    RedType r[MAXSIZE+1];
    int length;
    
}SqList;

bool LT(KeyType a, KeyType b)
{
    //小于
    if(a<b)
        return true;
    else
        return false;
}

void InsertSort( SqList &L)
{
    for (int i=2; i<=L.length; i++)
    {
        if(LT(L.r[i].key,L.r[i-1].key))
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i-1];
            
            int j = i-2;
            
            for( ; LT(L.r[0].key , L.r[j].key);--j)
            {
                L.r[j+1] = L.r[j];
            }
            L.r[j+1] = L.r[0];
        }
    }
}




int main(int argc, const char * argv[]) {
    
    SqList L;
    L.length = 5;
    L.r[1].key = 5;
    L.r[2].key = 4;
    L.r[3].key = 3;
    L.r[4].key = 2;
    L.r[5].key = 1;
    
    InsertSort(L);
    for(int i=1;i<=L.length;i++)
        std::cout<<L.r[i].key;
    
    return 0;
}
