#define CHAIN

#include<iostream>

template<typename data>struct chainNode{
    chainNode* up=nullptr;
    data value;
    inline ~chainNode(){
        value.~value();
    };
};

template<typename data>struct chain{
    chainNode<data>* head=nullptr;
    chainNode<data>* tail=nullptr;
    unsigned short len=0;
    inline chain(){
        head=nullptr;
        tail=head;
        len=0;
    };
    inline chain(const data& value){
        head= new chainNode<data>;
        head->value=value;
        tail=head;
        len=1;
    };
    inline chain(const data* arr,unsigned short length){
        len=0;
        chainNode<data>* here=head;
        for(unsigned short i=0;i<length;i++){
            if(!here) here= new chainNode<data>;
            here->value=arr[i];
            tail=here;
            here=here->up;
            len++;
        };
    };
    inline ~chain(){
        chainNode<data>* here=head;
        chainNode<data>* next_one=head->up;
        do{
            here->~chainNode();
            delete here;
            here=next_one;
            next_one=next_one->up;
        }while(next_one);
    };
    void operator+=(const data& value){
        if(!len){
            head= new chainNode<data>;
            head->value=value;
            tail=head;
            len++;
            return;
        };
        tail->up= new chainNode<data>;
        tail=tail->up;
        tail->value=value;
        len++;
    };
    void operator+=(const chain<data>& chain2){
        chainNode<data>* here=chain2.head;
        if(!len){
            head= new chainNode<data>;
            head->value=here->value;
            tail=head;
            here=here->up;
            len++;
        };
        if(!here) return;
        do{
            tail->up= new chainNode<data>;
            tail=tail->up;
            tail->value=here->value;
            here=here->up;
            len++;
        }while(here);
    };
    chain<data> operator+(const chain<data>& chain2){
        chain<data> ans=*this;
        chainNode<data> here=chain2.head;
        do{
            ans.tail->up= new chainNode<data>;
            ans.tail=ans.tail->up;
            ans.tail->value=here->value;
            here=here->up;
        }while(here);
        return ans;
    };
    bool operator-=(const data& value){
        chainNode<data>* here=head;
        chainNode<data>* previous=nullptr;
        bool deleted=false;
        if(head->value==value){
            head=head->up;
            delete here;
            deleted=true;
            len--;
        };
        previous=here;
        here=head->up;
        do{
            if(here->value==value){
                previous->up=here->up;
                delete here;
                here=previous->up;
                deleted=true;
                len--;
            }else{
                previous=here;
                here=here->up;
            }
        }while(here);
        return deleted;
    };
    void operator=(const chain<data>& chain2){
        chainNode<data>* here=chain2.head;
        len=0;
        tail=head;
        do{
            tail->value=here->value;
            if(!tail->up&&here->up) tail->up= new chainNode<data>;
            tail=tail->up;
            here=here->up;
            len++;
        }while(here);
    };
    bool operator==(const chain<data>& chain2){
        chainNode<data>* here=head;
        chainNode<data>* here2=chain2.head;
        do{
            if(here->value!=here2->value) return false;
            here=here->up;
            here2=here2->up;
        }while(here&&here2);
        if(here!=here2) return false;
        return true;
    };
    const data& operator[](unsigned short index){
        if(index>len) std::cerr<<"Chain overflow!\n";
        chainNode<data>* here=head;
        for(unsigned short i=0;i<index;i++) here=here->up;
        return here->value;
    };
    // unfixed!
    chain<data> operator&&(const chain<data>& chain2){
        chain<data> ans;
        if(!(len&&chain2.len)) return ans;
        chainNode<data>* here=head;
        chainNode<data>* here2=chain2.head;
        do{
            do{
                if(here->value==here2->value){
                    ans+=here->value;
                    break;
                };
                here2=here2->up;
            }while(here2);
            here=here->up;
        }while(here);
        return ans;
    };
    // unfixed!
    chain<data> operator||(const chain<data>& chain2){
        chain<data> ans(head->value);
        chainNode<data>* here=head;
        do{
            bool exist_yet=false;
            chainNode<data>* here2=chain2.head;
            do{
                if(here2->value==here->value){
                    exist_yet=true;
                    break;
                };
                here2=here2->up;
            }while(here2);
            if(exist_yet) continue;
            here2=ans.head;
            do{
                if(here2->value==here->value){
                    exist_yet=true;
                    break;
                };
                here2=here2->up;
            }while(here2);
            if(exist_yet) continue;
            ans+=here->value;
            here=here->up;
        }while(here);
        return ans;
    };
    template<typename func>void operator()(const func& fun){
        chainNode<data>* here=head;
        do{
            fun(here->value);
            here=here->up;
        }while(here);
    };
    bool searchfor(const data& value){
        chainNode<data>* here=head;
        do{
            if(here->value==value) return true;
            here=here->up;
        }while(here);
        return false;
    };
    template<typename func>bool testfor(const func& fun){
        chainNode<data>* here=head;
        do{
            if(fun(here->value)) return true;
            here=here->up;
        }while(here);
        return false;
    };
    void print(std::ostream& output=std::cout,char placeholder=' '){
        chainNode<data>* here=head;
        if(!here) return;
        do{
            output<<here->value<<placeholder;
            here=here->up;
        }while(here);
    };
};