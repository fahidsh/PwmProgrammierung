#include "mbed.h"

/*

Puls Weiten Modulation (PWM) Programmierung
https://moodle.its-stuttgart.de/mod/lesson/view.php?id=64351&pageid=3096

*/
PwmOut led2(PA_2);
InterruptIn tasterToch(PA_1); 
// A9

float impulsdauer = 0.5;

void isrTasterHoch()
{
    impulsdauer = impulsdauer + 0.1;
    if (impulsdauer>=1.1) //Tipp: >= wegen Rundungsfehlern beim Float
    {
        impulsdauer = 0;
    }
        led2.write(impulsdauer);
}// end void isrTasterHoch()


int main()
{
    // Initialise the digital pin LED1 as an output
    led2.write(0.5);
    led2.period_ms(1000);

    tasterToch.fall(&isrTasterHoch);
    tasterToch.enable_irq();



    while (true) {
        //tue nichts
    }// end while (true)
}
