#ifndef NODE_H
#define NODE_H


class node
{
    public:
        node(int element);
        node *next;
        int getData();

    protected:

    private:
        int data;
};

#endif // NODE_H
