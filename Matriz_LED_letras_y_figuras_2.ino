/*
  8x8 LED Matrix MAX7219
  by Dejan Nedelkovski, www.HowToMechatronics.com
  Based on the following library:
  GitHub | riyas-org/max7219  https://github.com/riyas-org/max7219

- ATtiny85 PB0 - CS
- ATtiny85 PB1 - CLK
- ATtiny85 PB2 - DIN
*/

#include <MaxMatrix.h>

int CS = 0;    // CS pin of MAX7219 module
int CLK = 1;   // CLK pin of MAX7219 module
int DIN = 2;   // DIN pin of MAX7219 module
int maxInUse = 1;


MaxMatrix m(DIN, CS, CLK, maxInUse); 

// char A[] = {4, 8,
//             B01111110,
//             B00010001,
//             B00010001,
//             B01111110,
//            };

// char B[] = {4, 8,
//             B01111111,
//             B01001001,
//             B01001001,
//             B00110110,
//            };

// char smile01[] = {8, 8,
//                   B00111100,
//                   B01000010,
//                   B10010101,
//                   B10100001,
//                   B10100001,
//                   B10010101,
//                   B01000010,
//                   B00111100
//                  };
// char smile02[] = {8, 8,
//                   B00111100,
//                   B01000010,
//                   B10010101,
//                   B10010001,
//                   B10010001,
//                   B10010101,
//                   B01000010,
//                   B00111100
//                  };
// char smile03[] = {8, 8,
//                   B00111100,
//                   B01000010,
//                   B10100101,
//                   B10010001,
//                   B10010001,
//                   B10100101,
//                   B01000010,
//                   B00111100
//                  };

void setup()
{
  m.init(); // MAX7219 initialization
  m.setIntensity(8); // Initial led matrix intensity, 0-15
}

void loop()
{
  // Seting the LEDs On or Off at x,y or row,column position
  m.setDot(0,0,true);
  delay(500);
  m.setDot(7,7,true);
  delay(500);
  m.setDot(0,7,true);
  delay(500);
  m.setDot(7,0,true);
  delay(500);
  m.clear();            // Clears the matrix
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
  m.clear();            // Clear the matrix
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