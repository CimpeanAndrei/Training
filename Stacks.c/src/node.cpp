#include "node.h"
#include<iostream>

node::node(int element)
{
    data=element;
    next=NULL;
}

int node::getData()
{
    return(data);
}
