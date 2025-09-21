#pragma once

class Terminal {
public:
    bool get() { return false; }
    void printf(const char* fmt, ...) {}
};

class Display {
public:
    void printf(int row, int col, const char* fmt, ...) {}
};

extern Terminal terminal;
extern Display disp;
