/*
  OpenShifter.h - Library for working with OpenShifter by SimRtec.
  Created by Martin Leather, 02/02/2021.
  Released into the public domain.
*/
#ifndef OpenShifter_H
#define OpenShifter_H

#include "Arduino.h"
#include "SoftwareSerial.h"

class openshifter {
  private:
    byte _RX;
    byte _TX;
    int _UARTBAUD;
    int _Data_In;
    SoftwareSerial *OpenShifter;
    
  public:
    openshifter(byte RX, byte TX);
    void begin(int UARTBAUD);
    virtual int read(void);
    virtual int available(void);


    int gear(void);
    int Ready();
    int readvalues(int value);
    

    
    
    
};



#endif





  

    
    



    

      
    
    

    
   


    

