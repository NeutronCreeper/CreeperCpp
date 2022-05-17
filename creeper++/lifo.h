#define LIFO

template<typename data>struct lifo{
    data* bottom=nullptr;
    data* top=nullptr;
    unsigned short volume=0;
    inline lifo(unsigned short len){
        bottom= new data[len];
        top=bottom;
        volume=len;
    };
    bool full(){
        return top-bottom==volume-1;
    };
    bool overflow(){
        return top-bottom>volume-1;
    };
    bool empty(){
        return top==bottom;
    };
    bool good(){
        return top-bottom<volume-1;
    };
    void operator+=(const data& dat){
        if(top-bottom>volume-1) throw "Stack overflow!\n";
        *top=dat;
        top++;
    };
    void push(data& dat){
        if(top-bottom>volume-1) throw "Stack overflow!\n";
        *top=dat;
        top++;
    };
    void push(data* dat,unsigned short len){
        if(top+len-bottom>volume-1) throw "Stack overflow!\n";
        for(unsigned short i=0;i<len;i++){
            *top=dat[i];
            top++;
        };
    };
    void operator--(){
        top--;
    };
    void operator-=(unsigned short n){
        top-=n;
    };
    inline ~lifo(){
        delete[] bottom;
    };
};