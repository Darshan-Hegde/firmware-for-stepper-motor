//example code for using with spi stepper firmware


#include <SPI.h>
char c;
void setup (void)
{

  digitalWrite(SS, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  
   

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10

  
  for (const char * p = "$ stepper 1 speed 0090 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    
  for (const char * p = "$ stepper 1 steps +0290 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
    // enable Slave Select
  digitalWrite(SS, LOW);    

  for (const char * p = "$ stepper 2 speed 0060 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    // SS is pin 10

  for (const char * p = "$ stepper 2 steps -0290 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    // SS is pin 10

  for (const char * p = "$ stepper 0 go \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
}  // end of setup


void loop (void)
{

 delay(3000);
  
  digitalWrite(SS, LOW);    // SS is pin 10
  for (const char * p = "$ stepper 0 go \n" ; c = *p; p++)//rotates both stepper
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);

   delay(3000);
  
  digitalWrite(SS, LOW);    // SS is pin 10
  for (const char * p = "$ stepper 1 go \n" ; c = *p; p++)//rotates stepper 1
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    // SS is pin 10
  for (const char * p = "$ stepper 2 go \n" ; c = *p; p++)//rotates stepper 2
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
}  // end of loop
