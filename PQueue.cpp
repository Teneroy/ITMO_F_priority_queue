//
// Created by alexc on 4/17/2019.
//

#include "PQueue.h"

PQueue::PQueue()
{
    _end = 0;
}

void PQueue::INSERT(p_t x)
{
    _arr[_end] = x;//берем последний НЕ занятый элемент, копируем туда передаваемый узел
    _end++;
    if(_end == 0)
        return;//если _end == 0, то выходим из функции
    int i = _end - 1;
    while(_arr[(i + 1)/2 - 1] > _arr[i]) //повторяем, пока приоритет родителя больше приоритета узла
    {
        swapN(_arr[i], _arr[(i + 1)/2 - 1]); //Меняем родителя и узел местами
        i = (i + 1)/2 - 1;
    }
}

void PQueue::MAKENULL()
{
    _end = 0;
}

p_t PQueue::DELETEMIN()
{
    if(_end == 0)//если _end == 0, возвращаем ERR
        return ERR;
    if(_end - 1 == 0) //если в дереве 1 элемент, то уменьшаем размерность и возвращаем корень
    {
        _end--;
        return _arr[0];
    }
    p_t temp = _arr[0];//копируем корень в темп
    _arr[0] = _arr[_end - 1]; //пишем последний занятый элемент в корень
    _end--; //усеньшаем размерность
    int i = 0;
    if(_end - 1 == 1 && _arr[0] > _arr[_end - 1]) // если в дереве 2 элемента, и родитель больше сына, то меняем их местами
    {
        swapN(_arr[0], _arr[_end - 1]);
        return temp;
    }
    while((_arr[2*(i + 1) - 1] < _arr[i] || _arr[2*(i + 1)] < _arr[i]) && (i < _end) && 2*(i + 1) < _end)
    {//Продолжаем, пока левый или правый сын меньше родителя,и i меньше номера последнего не занятого элемента, и номер правого сына меньше номера последнего не занятого элемента
        if(swapLeft(i)) //Если можем свапнуть вправо
        {
            swapN(_arr[i], _arr[2*(i + 1) - 1]);
            i = 2*(i + 1) - 1;
        } else if(swapRight(i)) //Если можем свапнуть влево
        {
            swapN(_arr[i], _arr[2*(i + 1)]);
            i = 2*(i + 1);
        }
    }
    return temp;
}

void PQueue::PRINT() const
{
    int i = 0;
    for(; i < _end; i++) {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

void PQueue::swapN(int &p1, int &p2)
{
    int x(p1);
    p1 = p2;
    p2 = x;
}

bool PQueue::swapLeft(int i) const
{
    return _arr[2*(i + 1) - 1] < _arr[i] && _arr[2*(i + 1)] >= _arr[2*(i + 1) - 1];
    //Если левый сын меньше родителя и правый сын больше или равен левому сыну
}

bool PQueue::swapRight(int i) const
{
    return _arr[2*(i + 1)] < _arr[i] && _arr[2*(i + 1)] < _arr[2*(i + 1) - 1];
    //Если правый сын меньше родителя и правый сын меньше левому сыну
}