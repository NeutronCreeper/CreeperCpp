#define WOWBIT

#define bitabs(a) ((a)>0?(a):(~a+1))
#define bitneg(a) (~(a)+1)
#define bitodd(a) ((bool)((a)&1))
#define biteven(a) ((bool)(!((a)&1)))
#define bitmul2n(a,b) ((a)<<(b))
#define bitdiv2n(a,b) ((a)>>(b))
#define bitmod2(a,b) ((a)&(b-1))