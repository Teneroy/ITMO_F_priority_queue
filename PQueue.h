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
    void swapN(int &p1, int &p2); //меняем значения узлов местами
    bool swapLeft(int i) const; //Выполнение условия для смены местами левого сына и родителя
    bool swapRight(int i) const;//Выполнение условия для смены местами правого сына и родителя
};

#endif //ITMO_F_PRIORITY_QUEUE_PQUEUE_H
