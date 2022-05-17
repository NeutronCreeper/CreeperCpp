#define WOWMATH

#include<cmath>
#include<stdarg.h>
#ifndef WOWBIT
#include "wowbit.h"
#endif

#define math_pi ((double)3.141592653599)
#define math_e ((double)2.718281828)
#define mathint(a) ((bool)((a)==(int)(a)))
#define mathmax(a,b) ((a)>(b)?(a):(b))
#define mathmin(a,b) ((a)<(b)?(a):(b))
#define mathsgn(a) (((a)==0)?(a):(((a)>0)?(1):(-1)))
#define mathsqr(a) ((a)*(a))
#define mathcub(a) ((a)*(a)*(a))
#define mathdeg(rad) ((rad)*180/math_pi)
#define mathrad(deg) ((deg)*math_pi/180)

namespace math
//
{

long pow_int(const short base,const unsigned char expnt=2){
    if(expnt==0) return 1;
    long ans;
    for(unsigned char i=1;i<expnt;i++) ans*=base;
    return ans;
};

double avrg_arith(const unsigned char argc,...){
    va_list argvs;
    long double ans=0e0;
    va_start(argvs,argc);
    for(unsigned char i=0;i<argc;i++) ans+=va_arg(argvs,int);
    va_end(argvs);
    ans/=argc;
    return ans;
};

double avrg_geom(const unsigned char argc,...){
    va_list argvs;
    long double ans=1;
    va_start(argvs,argc);
    for(unsigned char i=0;i<argc;i++) ans*=va_arg(argvs,int);
    va_end(argvs);
    return pow(ans,((float)1)/argc);    
};

inline double cot(const double& rad){
    return 1/tan(rad);
};

bool ifpow(const long& m,const unsigned char n=2){
    if((m<0)&&(n%2==0)) return false;
    float a=pow(m,(float)((float)1/(float)n));
    return (float)a==(int)a;
};

unsigned short gcd(unsigned short m,unsigned short n){
    if(!n) return m;
    if(!m) return n;
    if(m<n) return gcd(n%m,m);
    return gcd(m%n,n);
};

unsigned long gcdl(unsigned long m,unsigned long n){
    if(!n) return m;
    if(!m) return m;
    if(m<n) return gcdl(n%m,m);
    return gcdl(m%n,n);
};

inline unsigned short lcm(const unsigned short m,const unsigned short n){
    return m*n/gcd(m,n);
};

inline unsigned long lcml(const unsigned long& m,const unsigned long& n){
    return m*n/gcdl(m,n);
};




//
}