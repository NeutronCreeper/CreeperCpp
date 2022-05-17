#define TREE

#ifndef CHAIN
#include "chain.h"
#endif

template<typename data>struct treeNode{
    chain<treeNode*> sons;
    treeNode* father;
    unsigned char height;
    data value;
};
template<typename data>struct tree{
    treeNode<data>* root;
    tree(){
        root= new treeNode<data>;
    };
    tree(const data& value){
        root= new treeNode<data>;
        root->value=value;
    };
    tree(const tree<data>& tree2){
        root= new treeNode<data>;
        root->sons.head=tree2.root;
    };
};