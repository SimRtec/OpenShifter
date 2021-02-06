//We always have to include the library

// Please download LedControl library from https://github.com/wayoda/LedControl/archive/master.zip
// copy the Led Control folder into your arduino libarays folder along with OpenShifter 
#include "LedControl.h"
#include <OpenShifter.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;
char gear;
openshifter OpenShifter(2,3);

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  OpenShifter.begin(9600);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writegear(char value) {
  /* here is the data for the characters */
  
  byte one[8]={
    B00011000,
  B00111000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B01111110,
  B00000000
    };
  byte two[8]={

    B00111100,
  B01100110,
  B00000110,
  B00011100,
  B00110000,
  B01100110,
  B01111110,
  B00000000
    
    };

    byte three[8]={

    B00111100,
  B01100110,
  B00000110,
  B00011100,
  B00000110,
  B01100110,
  B00111100,
  B00000000
    
    };

    byte four[8]={

    B00011100,
  B00111100,
  B01101100,
  B11001100,
  B11111110,
  B00001100,
  B00011110,
  B00000000
    
    };
    
    byte five[8]={

    B01111110,
  B01100000,
  B01111100,
  B00000110,
  B00000110,
  B01100110,
  B00111100,
  B00000000  
    };

    byte six[8]={

    B00011100,
  B00110000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B00111100,
  B00000000
    
    
    
    };

    byte N[8]={

    B11000011,
  B11100011,
  B11110011,
  B11111011,
  B11011111,
  B11001111,
  B11000111,
  B11000011
    };

    byte R[8]={

    B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110
    };
 
if (value == '1')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,one[i]);
  }
}
if (value == '2')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,two[i]);
  }
}
if (value == '3')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,three[i]);
  }
}
if (value == '4')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,four[i]);
  }
}

if (value == '5')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,five[i]);
  }
}

if (value == '6')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,six[i]);
  }
}

if (value == 'N')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,N[i]);
  }
}

if (value == 'R')
{
  /* now display them one by one with a small delay */
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,R[i]);
  }
}

 
}



void loop() { 

  if(OpenShifter.Ready()> 0)
  {
    gear = OpenShifter.readvalues(1);
    writegear(gear);
  }

}
