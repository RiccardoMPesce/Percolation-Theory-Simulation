#ifndef UF_H
#define UF_H

class UF
{
    public:
        virtual void do_union(int p, int q);
        virtual int do_find(int p);
        virtual bool are_connected(int p, int q);
        virtual int get_count();
};

#endif