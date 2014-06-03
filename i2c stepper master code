//i2c master code for using with i2c stepper firmware


#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 1 speed 0090 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
   
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 1 steps +0290 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 2 speed 0060 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
    Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 2 steps -0290 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
 
  
}

byte x = 0;



void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 0 go /n ");//both stepper will rotate      
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 1 go /n ");//only stepper one will rotate       
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stepper 2 go /n ");//only stepper two will rotate     
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
}
