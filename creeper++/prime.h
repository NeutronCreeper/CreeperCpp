#define PRIME

#include<cmath>
#include<stdlib.h>
#ifndef WOWBIT
#include "wowbit.h"
#endif

#ifndef PRIMES8
bool prime(const unsigned short p){
    unsigned char i=2;
    if(p<2) return false;
    do{
        if((p%i==0)&&(p!=i)) return false;
        ++i;
    }while(i<0xff);
    return true;
};
#endif
#ifdef PRIMES8
bool prime(const unsigned short p){
    unsigned char i=2;
    if(p<2) return false;
    do{
        if((p%primes8[i]==0)&&(p!=primes8[i]))  return false;
        ++i;
    }while((i<54)&&(primes8[i]<p));
    return true;
};
#endif
#ifdef PRIMES16
#define fn_primel
bool primel(const unsigned long& p){
    unsigned short i=2;
    if(p<2) return false;
    if(p==2) return true;
    do{
        if((p%primes16[i]==0)&&(p!=primes16[i])) return false;
        ++i;
    }while((i<6542)&&(primes16[i]<p));
    return true;
};
#else
bool primel(const unsigned long& p){
    if(p<2) return false;
    if(p==2) return true;
    unsigned short i=2;
    unsigned short m=std::sqrt(p)+1;
    do{
        if(prime(i)) if((p%i==0)&&(p!=i)) return false;
        ++i;
    }while(i<m);
    return true;
};
#endif