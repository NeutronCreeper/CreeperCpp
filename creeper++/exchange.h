#define EXCHANGE

template<typename data>void exchange(data& a,data& b){
    data c=a;
    a=b;
    b=c;
};