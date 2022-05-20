#include "mbed.h"

/*

Puls Weiten Modulation (PWM) Programmierung
https://moodle.its-stuttgart.de/mod/lesson/view.php?id=64351&pageid=3096

*/


// zwei Interups 
// Ein: A1
// Aus: A2
InterruptIn tasterAuf(PA_1); 
InterruptIn tasterZu(PA_4); 
// PWM: A9
PwmOut schrank(PC_7);
DigitalOut led(PA_6);

int aenderung = 500;
bool istSchrankAuf = false;

void isrSchrankAuf()
{
    if(!istSchrankAuf){
        led = 1;
        schrank.pulsewidth_us(500);
        istSchrankAuf = true;
    }
}// end void isrSchrankAuf()

void isrSchrankZu()
{
    if(istSchrankAuf){
        led = 0;
        schrank.pulsewidth_us(1500);
        istSchrankAuf = false;
    }
}// end void isrSchrankZu()

int main()
{
    // Initialise the digital pin LED1 as an output
    //schrank.write(500);
    schrank.period_ms(20);

    tasterAuf.rise(&isrSchrankAuf);
    tasterAuf.enable_irq();

    tasterZu.rise(&isrSchrankZu);
    tasterZu.enable_irq();



    while (true) {
        //tue nichts
    }// end while (true)
}
