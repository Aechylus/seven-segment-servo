/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo koba, kobb, kobc, kobd, kobe, kobf, kobg; // create servo object to control a servo

void setup()
{
    koba.attach(13);
    kobb.attach(12);
    kobc.attach(11);
    kobd.attach(10);
    kobe.attach(9);
    kobf.attach(8);
    kobg.attach(7);
}
// kita bikin di pin 1-7 arduino ,, kalo ada ganti gw nanti bilangin
void loop()
{

    koba.write(80);
    kobb.write(80);
    kobc.write(80);
    kobd.write(80);
    kobe.write(80);
    kobf.write(80);
    kobg.write(80);
    // kobe.write(0); // sets the servo position according to the scaled value
    delay(1500);

    koba.write(160);
    kobb.write(160);
    kobc.write(160);
    kobd.write(160);
    kobe.write(160);
    kobf.write(160);
    kobg.write(160);
    // kobe.write(90); // sets the servo position according to the scaled value --harusnya udah bener
    delay(1500);

    // kobe.write(0);
    // koba.write(0);
    // kobb.write(0);
    // kobc.write(0);
    // kobd.write(0);
    // kobe.write(0);
    // kobf.write(0);
    // kobg.write(0);
}
