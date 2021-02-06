

#include "OpenShifter.h"
#include "Arduino.h"

int Index;
int Data_In[2];
int Gear;



openshifter::openshifter(byte RX, byte TX){
  _RX = RX;
  _TX = TX;
  OpenShifter = new SoftwareSerial(RX, TX); 
   
}


void openshifter::begin(int UARTBAUD){
  _UARTBAUD = UARTBAUD;
  OpenShifter->begin(_UARTBAUD);
  
}

int openshifter::read()
{
  
    return OpenShifter->read();
}

int openshifter::available()
{
    return OpenShifter->available();
}



int openshifter::readvalues(int value)
{
  if (OpenShifter->available() !=0)
  {
    
    
    Data_In[Index] = OpenShifter->read(); 
    

   

   

    if(Index > 2)
    {
    
        if (Data_In[0] == 'G')
          {
             Gear = Data_In[1];
             
          }
          
      Index = 0;    

    }
    
    Index++;

    if (value == 1)
    {
      return Gear;
    }

  }
  
  
   
}

int openshifter::Ready()
{
    if (Index > 6)
    {
      return 1;
    }
}



