#ifndef TinyQueue_h
#define TinyQueue_h
#include "WProgram.h"

template <typename T>
class TinyQueue
{
    public:
        TinyQueue(int size);
        ~TinyQueue();
        void enqueue(T val);
        T dequeue();
        int size();
    private:
        T * _buffer;
        int _bufsiz;
        int _head;
        int _tail;
};

template <typename T>
TinyQueue<T>::TinyQueue(int size)
{
    _bufsiz = size + 1;
    _head = 0;
    _tail = 0;
    _buffer = (T *) malloc(sizeof(T) * _bufsiz);
}

template <typename T>
TinyQueue<T>::~TinyQueue()
{
    free(_buffer);
    _head = 0;
    _tail = 0;
    _bufsiz = 0;
}

template <typename T>
void TinyQueue<T>::enqueue(T val)
{
    int i = (_head + 1) % _bufsiz;
    if( i != _tail )
    {
        _buffer[_head] = val;
        _head = i;
    }
}

template <typename T>
T TinyQueue<T>::dequeue()
{
    if( _head == _tail )
    {
        return -1;
    }
    else
    {
        T c = _buffer[_tail];
        _tail = (_tail + 1) % _bufsiz;
        return c;
    }
}

template <typename T>
int TinyQueue<T>::size()
{
    return (_bufsiz + _head - _tail ) % _bufsiz;
}

#endif
