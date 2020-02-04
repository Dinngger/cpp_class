#include <iostream>
#define FOR(n) for(int i=0; i<n; i++)
#define LINKFOR for(node* n=&head; n!=0; n=n->next)
using namespace std;

struct node
{
    int data;
    node* next=0;
}head;

node* findend()
{
    node* end;
    LINKFOR
    {
        if(!n->next)
            end = n;
    }
    return end;
}

node* findlast(node* _n)
{
    LINKFOR
    {
        if(n->next == _n)
        {
            return n;
        }
    }
    return 0;
}

node* newnode()
{
    node* n = new node;
    findend()->next = n;
    return n;
}

int deletenode(node* _n)
{
    node* last = findlast(_n);
    if(last)
    {
        last->next = _n->next;
        delete _n;
        return 0;
    }
    else
        return -1;
}

int swapnode(node* a, node* b)
{
    node* a_last = findlast(a);
    node* b_last = findlast(b);
    if(a_last && b_last)
    {
        a_last->next = b;
        b_last->next = a;
        node* b_next = b->next;
        b->next = a->next;
        a->next = b_next;
        return 0;
    }
    else
        return -1;
}

int main()
{
}
