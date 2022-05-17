#define ARR

#define arrlen(a) ((sizeof(a))/(sizeof((a)[0])))
#define arrset(a,b) (array_set((a),(b),arrlen(a)))
#define arrcpy(a) (array_copy((a),arrlen(a)))
#define arreql(a,b) ((bool)array_equals((a),(b),arrlen(a),arrlen(b)))

template<typename data>class arr{
    private:
    data* value=nullptr;
    public:
    unsigned short len=0;
    inline arr(){
        len=0;
        value=nullptr;
    };
    inline arr(const unsigned short len_){
        if(len_==0) throw "Unable to create arr with length 0!\n";
        len=len_;
        value= new data[len];
    };
    inline arr(data* array,const unsigned short len_){
        value=array;
        len=len_;
    };
    data& operator[](const unsigned short index){
        if(!len) throw "Empty arr used!\n";
        if(index>len-1) throw "Index out of bound!\n";
        return value[index];
    };
    void operator=(const arr<data>& arr_){
        delete[] value;
        value=arr_.value;
        len=arr_.len;
    };
    bool empty(){
        return !len;
    };
    inline ~arr(){
        len=0;
        delete[] value;
        value=nullptr;
    };
};




template<typename data>void array_set(data* arr,data value,unsigned short len){
    for(unsigned short i=0;i<len;i++) arr[i]=value;
};
template<typename data>data* array_copy(data* arr,unsigned short len){
    data* ans= new data[len];
    for(unsigned short i=0;i<len;i++) ans[i]=arr[i];
    return ans;
};
template<typename data>bool array_equals(data* arr1,data* arr2,unsigned short len1,unsigned short len2){
    if(len1!=len2) return false;
    for(unsigned short i=0;i<len1;i++) if(arr1[i]!=arr2[i]) return false;
    return true;
};