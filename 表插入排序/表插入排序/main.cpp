//
//  main.cpp
//  表插入排序
//
//  Created by legendary on 2018/6/7.
//  Copyright © 2018年 starx. All rights reserved.
//

#include <iostream>

#define SIZE 100

typedef int KeyType;

//typedef struct
//{
//    KeyType ket;
//}RcdType;

typedef struct
{
    int key;
    int next;
}SLNode;

typedef struct
{
    SLNode r[SIZE];
    int length;
}SLinkListType;

template <class Type>
void swap(Type &a,Type &b)
{
    Type c;
    c = a;
    a = b;
    b = c;
}

void Arrange( SLinkListType &SL)
{
    int p = SL.r[0].next;
    
    for(int i=1; i<SL.length; ++i)
    {
        //这里第SL.length不需要排列，因为第SL.length-1排完之后，就已经排完了
        
        while (p < i)
            p = SL.r[p].next;
        
        int q = SL.r[p].next;
        
        if(p != i)
        {
            swap(SL.r[p], SL.r[i]);
            SL.r[i].next = p;
        }
        
        p = q;
    }
    
}

void Sort(SLinkListType &SL)
{
    SL.r[0].next = 1;
    SL.r[1].next = 0;
    
    int prior;
    
    for(int i=2;i<=SL.length;++i)
    {
        prior = 0;
        while(SL.r[i].key > SL.r[SL.r[prior].next].key)
            prior = SL.r[prior].next;
        //此时循环找到要插入元素的前一个
        SL.r[i].next = SL.r[prior].next;
        SL.r[prior].next = i;
    }
}

int main(int argc, const char * argv[]) {
    
    SLinkListType SL;
    SL.r[0].key = INT_MAX;
    SL.r[1].key = 49;
    SL.r[2].key = 38;
    SL.r[3].key = 65;
    SL.r[4].key = 97;
    SL.r[5].key = 76;
    SL.r[6].key = 13;
    SL.r[7].key = 27;
    SL.r[8].key = 49;
    
    SL.length = 8;
    
    Sort(SL);
    
    for(int i=0;i<=SL.length;i++)
    {
        std::cout<<SL.r[i].key<<"  "<<SL.r[i].next<<std::endl;
    }
    
    
    
    std::cout<<std::endl;
    Arrange(SL);
    
    for(int i=1;i<=SL.length;i++)
    {
        std::cout<<SL.r[i].key<<"  "<<SL.r[i].next<<std::endl;
        
    }
    
    return 0;
}
