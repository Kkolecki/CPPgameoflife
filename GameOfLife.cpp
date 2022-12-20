#pragma once
#include "GameOfLife.h"




CellMap::CellMap(unsigned int width, unsigned int height) {
    w = width;
    h = height;
    lenbit = w * h;
    cells = new unsigned char[lenbit];
    copycells = new unsigned char[lenbit];
    memset(cells, 0, lenbit);
}
CellMap::~CellMap() {
    delete cells;
    delete copycells;
}
void CellMap::SetCell(unsigned int x, unsigned int y) {
    unsigned char* cell_ptr = cells + (y * w + x);
    int xleft, xright, yup, ydown;
    int width = w, height = h;


    xleft = (x == 0) ? width - 1 : -1;
    xright = (x == (width - 1)) ? -(width - 1) : 1;
    yup = (y == 0) ? lenbit - width : -width;
    ydown = (y == (h - 1)) ? -(int(lenbit - width)) : w;

    *cell_ptr |= 0x01;
    *(cell_ptr + yup + xleft) += 0x02;
    *(cell_ptr + yup) += 0x02;
    *(cell_ptr + yup + xright) += 0x02;
    *(cell_ptr + xleft) += 0x02;
    *(cell_ptr + xright) += 0x02;
    *(cell_ptr + ydown + xleft) += 0x02;
    *(cell_ptr + ydown) += 0x02;
    *(cell_ptr + ydown + xright) += 0x02;

}
void CellMap::ClearCell(unsigned int x, unsigned int y) {
    unsigned char* cell_ptr = cells + (y * w) + x;
    int xleft, xright, yup, ydown;
    int width = w, height = h;

    xleft = (x == 0) ? width - 1 : -1;
    xright = (x == (width - 1)) ? -(width - 1) : 1;
    yup = (y == 0) ? lenbit - width : -width;
    ydown = (y == (height - 1)) ? -(int(lenbit - width)) : w;

    *cell_ptr &= ~0x01;

    *(cell_ptr + yup + xleft) -= 0x02;
    *(cell_ptr + yup) -= 0x02;
    *(cell_ptr + yup + xright) -= 0x02;
    *(cell_ptr + xleft) -= 0x02;
    *(cell_ptr + xright) -= 0x02;
    *(cell_ptr + ydown + xleft) -= 0x02;
    *(cell_ptr + ydown) -= 0x02;
    *(cell_ptr + ydown + xright) -= 0x02;
}
int CellMap::CellState(int x, int y)
{
    unsigned char* cell_ptr = cells + (y * w) + x;

    return *cell_ptr & 0x01;
}

void CellMap::NextGen() {
    unsigned int x, y, live_count;
    unsigned char* cell_ptr;

    memcpy(copycells, cells, lenbit);

    cell_ptr = copycells;
    for (y = 0; y < h; y++) {
        x = 0;
        do {
            while (*cell_ptr == 0) {
                cell_ptr++;

                if (++x >= w)
                    goto NextRow;
            }
            live_count = *cell_ptr >> 1;
            if (*cell_ptr & 0x01) {
                if ((live_count != 2) && (live_count != 3)) {
                    ClearCell(x, y);
                    DrawCell(x, y, 0x00);
                }
            }
            else
            {
                if (live_count == 3) {
                    SetCell(x, y);
                    DrawCell(x, y, 0xFF);
                }
            }
            cell_ptr++;

        } while (++x < w);
    NextRow:;
    }
}

void CellMap::Init()
{
    unsigned int x, y, init_length;

    srand(seed);

    init_length = (w * h) / 2;

    do
    {
        x = rand() % (w - 1);
        y = rand() % (h - 1);
        if (CellState(x, y) == 0)
            SetCell(x, y);
    } while (--init_length);
}