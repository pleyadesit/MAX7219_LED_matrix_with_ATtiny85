/*
MAX7219 LED matrix with ATtiny85
- ATtiny85 PB0 - CS
- ATtiny85 PB1 - CLK
- ATtiny85 PB2 - DIN
Download the library MaxMatrix --> https://github.com/riyas-org/max7219
*/

#include <MaxMatrix.h>

int CS = 0;    // CS pin
int CLK = 1;   // CLK pin
int DIN = 2;   // DIN pin
int maxInUse = 1;

MaxMatrix m(DIN, CS, CLK, maxInUse); 

void setup()
{
  m.init();           // Inicializa la matriz LED (MAX7219 IC)
  m.setIntensity(8);  // Nivel de brillo (0-15)
}

void loop()
{
  m.setDot(0,0,true);
  delay(500);
  m.setDot(7,7,true);
  delay(500);
  m.setDot(0,7,true);
  delay(500);
  m.setDot(7,0,true);
  delay(500);
  m.clear();            // Apaga todos los LED
  for (int i=0; i<8; i++)
  {
    m.setDot(i,i,true);
    delay(200);
  }
  int e = 0;
  for (int i=7; i>=0; i--)
  {
    m.setDot(i,e,true);
    e = e + 1;
    delay(200);
  }
  delay(800);
  m.clear();
  delay(800);

  m.setDot(0,0,true);
  m.setDot(7,7,true);
  m.setDot(0,7,true);
  m.setDot(7,0,true);
  delay(500);
  m.clear();            // Apaga todos los LED
  m.setDot(1,1,true);
  m.setDot(6,6,true);
  m.setDot(1,6,true);
  m.setDot(6,1,true);
  delay(500);
  m.clear();
  m.setDot(2,2,true);
  m.setDot(5,5,true);
  m.setDot(2,5,true);
  m.setDot(5,2,true);
  delay(500);
  m.clear();
  m.setDot(3,3,true);
  m.setDot(4,4,true);
  m.setDot(3,4,true);
  m.setDot(4,3,true);
  delay(1000);
  
  for (int i=0; i<8; i++)
  {
    m.shiftLeft(false,false);
    delay(300);
  }
  m.clear();
  delay(300);
  for (int i=0; i<8; i++)
  {
    for (int e=0; e<8; e++)
    {
      m.setDot(i,e,true);
      delay(75);
    }
  }
  delay(300);
  for (int i=0; i<8; i++)
  {
    m.shiftLeft(false,false);
    delay(300);
  }
  delay(2000);
}