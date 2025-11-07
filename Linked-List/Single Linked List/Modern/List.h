#pragma once

template <class t_data>
class List{
    public:
    virtual void insert(const t_Data &data) = 0;
    virtual void remove(const t_Data &data) = 0;
    virtual void traverse_list () const = 0;
    virtual int get_size () const = 0;
};