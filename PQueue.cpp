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
    while(_arr[(i + 1)/2 - 1] > _arr[i])
    {
        swapN(_arr[i], _arr[(i + 1)/2 - 1]); // использовать std::swap возможно будет нецелесообразно, проверь
         i = (i + 1)/2 - 1;
    }
}

void PQueue::MAKENULL()
{
    _end = 0;
}

p_t PQueue::DELETEMIN()
{
    if(_end == 0)
        return ERR;//если _end == 0, возвращаем ERR
    if(_end - 1 == 0)
    {
        _end--;
        return _arr[0];
    }//если _end - 1 == 0, то _end-- и возвращаем корень
    p_t temp = _arr[0];//копируем корень в темп
    _arr[0] = _arr[_end - 1]; //пишем последний занятый элемент в корень
    _end--;
    int i = 0;
    if(_end - 1 == 1 && _arr[0] > _arr[_end - 1])
    {
        swapN(_arr[0], _arr[_end - 1]);
    }
    //std::cout << "___________________________" << std::endl;
    //std::cout << "END: " << _end << std::endl;
    while((_arr[2*(i + 1) - 1] < _arr[i] || _arr[2*(i + 1) - 1 + 1] < _arr[i]) && (i < _end))
    {
        if((2*(i + 1) - 1 + 1) >= _end)
            break;
        if(swapLeft(i))
        {
            swapN(_arr[i], _arr[2*(i + 1) - 1]);
            i = 2*(i + 1) - 1;
        } else if(swapRight(i))
        {
            swapN(_arr[i], _arr[2*(i + 1) - 1 + 1]);
            i = 2*(i + 1) - 1 + 1;
        } else if(_arr[2*(i + 1) - 1] < _arr[i] && _arr[2*(i + 1) - 1] == _arr[2*(i + 1) - 1 + 1])
        {
            swapN(_arr[i], _arr[2*(i + 1) - 1]);
        }
        //std::cout << "<<" << std::endl;
        //std::cout << "I: " << i << std::endl;
        //PRINT();
        //std::cout << ">>" << std::endl;
    }
    //std::cout << "---------------------" << std::endl;
    return temp;
//вернуть темп
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
    return _arr[2*(i + 1) - 1] < _arr[i] && _arr[2*(i + 1) - 1 + 1] > _arr[2*(i + 1) - 1];
}

bool PQueue::swapRight(int i) const
{
    return _arr[2*(i + 1) - 1 + 1] < _arr[i] && _arr[2*(i + 1) - 1 + 1] < _arr[2*(i + 1) - 1];
}