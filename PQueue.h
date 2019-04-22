//
// Created by alexc on 4/17/2019.
//

#ifndef ITMO_F_PRIORITY_QUEUE_PQUEUE_H
#define ITMO_F_PRIORITY_QUEUE_PQUEUE_H

#include "string.h"
#include <iostream>

typedef int p_t;

enum {ERR = -1};

class PQueue
{
public:
    PQueue();// _end = 0
    void INSERT(p_t x);
    void MAKENULL();
    p_t DELETEMIN();
    void PRINT() const;
private:
    p_t _arr[10];
    int _end;//последний НЕ занятый элемент
    //функция, которая свапает родителя и элемент до тех пор, пока приоритет родителя не станет <= приоритета узла
    //void nodeSwap(int npos /*Позиция узла, который мы хотим поднять*/, int ppos /*Позиция узла, который мы хотим опустить*/); //свапает узлы
    void swapN(int &p1, int &p2);
    bool swapLeft(int i) const;
    bool swapRight(int i) const;
};

#endif //ITMO_F_PRIORITY_QUEUE_PQUEUE_H
