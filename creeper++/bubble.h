#define BUBBLE

#ifndef EXCHANGE
#include "exchange.h"
#endif

#define sort_bubble(a) (bubble_sort((a),sizeof(a)))
template<typename data>void bubble_sort(data array[],unsigned short len){
    len/=sizeof(data);
    --len;
    data temp;
    unsigned short i,j;
    for(i=0;i<len;++i;){
        for(j=0;j<len;++j;){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            };
        };
    };
};