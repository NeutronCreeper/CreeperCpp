#define FACTORIZE

#ifndef PRIME
#include "prime.h"
#endif
#ifndef ARR
#include "arr.h"
#endif

arr<unsigned short> factorize(unsigned long p){
    if(primel(p)) return arr<unsigned short>();
    unsigned short* anss= new unsigned short[32];
    unsigned char count=0;
    unsigned short i=2;
    do{
        if(prime(i)&&(p%i==0)){
            anss[count]=i;
            ++count;
            p/=i;
        }else{
            ++i;
        };
    }while(!primel(p));
    anss[count]=p;
    ++count;
    arr<unsigned short>ans(count);
    for(unsigned char i=0;i<count;++i) ans[i]=anss[i];
    delete[] anss;
    anss=nullptr;
    return ans;
};