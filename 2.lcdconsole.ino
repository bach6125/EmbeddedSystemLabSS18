#include <MI0283QT2.h>
#include <DisplaySPI.h>

MI0283QT2 lcd;


void setup() {
  lcd.begin();
  lcd.led(30);
}
int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 1000;
float R2= 0;
float buffer= 0;


void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
lcd.drawText( 0, 0, "                                                                                                                                                                                                    ", 0,  RGB(0,  0,  0),  RGB(0,  0,  0));

// IF NO RESISTANCE INSERTED THEN ASK USER TO INSERT RESISTANCE TO MEASURE

if (R2 > 40000) {

lcd.setCursor(0, 0);
lcd.print("Please insert unknown resistance");
delay(1000);
}

// IF RESISTANCE LESS THAN 500 OHM THEN IT WILL GIVE USER AN WARNING MESSAGE

else if (R2 < 500) {

lcd.setCursor(0, 0);
lcd.print("Cannot measure resistance<500 Ohm");
delay(1000);
}

// IF RESISTANCE MORE THAN 2700 OHM THEN IT WILL GIVE USER AN WARNING MESSAGE

else if (R2 > 2700) {

lcd.setCursor(0, 0);
lcd.print("Cannot measure resistance>2700 Ohm");
delay(1000);
}

// IF RESISTANCE IS BETWEEN 500 AND 2700 OHM THEN IT WILL GIVE THE READING OF RESISTANCE IN THE LCD SCREEN

else {

lcd.setCursor(0, 0);
lcd.print("Unknown Resistance (in Ohm) is: ");
lcd.print(R2);
delay(1000);
}
}
}
