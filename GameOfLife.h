#pragma once
#include "Global.h"
#include <iostream>
using namespace std;
class CellMap {
private:
    unsigned char* cells;
    unsigned char* copycells;
    unsigned int w, h, lenbit;
public:
    CellMap(unsigned int width, unsigned int height);
    ~CellMap();
    void SetCell(unsigned int x, unsigned int y);
    void ClearCell(unsigned int x, unsigned int y);
    int CellState(int x, int y);
    void NextGen();
    void Init();

};
