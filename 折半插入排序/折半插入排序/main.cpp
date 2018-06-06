//
//  main.cpp
//  折半插入排序
//
//  Created by legendary on 2018/6/6.
//  Copyright © 2018年 starx. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
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
    if(a<b) return true;
    else return false;
}

void  BInsertSort(SqList &L)
{
    //对顺序表L作折半插入排序
    for(int i=2; i<= L.length ;i++)
    {
        L.r[0] = L.r[i];
        
        int low = 1;
        int high = i-1;
        while(low<=high)
        {
            int m = (low + high)/2;
            if(LT(L.r[0].key,L.r[m].key))
                high = m-1;
            else
                low = m+1;
        }
        for(int j = i-1; j >= high+1;j-- )
        {
            L.r[j+1] = L.r[j];
        }
        L.r[high+1] = L.r[0];
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
    
    BInsertSort(L);
    
    for(int i=1;i<=L.length;i++)
        cout<<L.r[i].key<<endl;
    
    
    return 0;
}
