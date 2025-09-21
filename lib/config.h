#pragma once

// Dummy-Pins
#define m1_cw 0
#define m1_ccw 0
#define m1_pwm 0
#define m4_cw 0
#define m4_ccw 0
#define m4_pwm 0

// Dummy LEDs / Buttons
class Digital {
public:
    enum Event { ACTIVATED, RELEASED };
    Event getEvent() { return RELEASED; }
    void set(int) {}
};

extern Digital btnA;
extern Digital btnB;
extern Digital led0;
extern Digital led1;
