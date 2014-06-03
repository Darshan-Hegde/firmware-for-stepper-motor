


#include <SPI.h>
#include <Stepper.h>

char buf [26];
volatile byte pos;
volatile boolean process_it;

int inc=0;
int wstpr=0;//which stepper
int spd=0;//speed of stpr1
int s1pd=0;//speed of stpr2
int aspd=0;//associate of speed
int hsteps=0;//stpr 1
int h1steps=0;//stpr 2
int ahsteps=0;
int dir1=0;
int dir2=0;

void setup (void)
{
  Serial.begin (9600);   // debugging

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  
  // get ready for an interrupt 
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.attachInterrupt();

}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;  // grab byte from SPI Data Register
  
  // add to buffer if room
  if (pos < sizeof buf)
    {
    buf [pos++] = c;
    
    // example: newline means time to process buffer
    if (c == '\n')
      process_it = true;
      
    }  // end of room available
}  // end of interrupt routine SPI_STC_vect

// main loop - wait for flag set in interrupt routine
void loop (void)
{
  if (process_it)
    {
    buf [pos] = 0;  
    Serial.println (buf);
    pos = 0;
    process_it = false;
    gopera();
    }  // end of flag set
    
    
}  // end of loop

void gopera(void)
{
  for(inc=0;inc<26;inc++)
  Serial.print(buf[inc]); 
  Serial.println(" ");
  if(buf[13]=='t')
  callsteps();
  if(buf[13]=='p')
  callspeed();
  if(buf[12]=='g')
  callgo();
  for(inc=0;inc<26;inc++)
  {
    buf[inc]='0';
  }
}

void callsteps(void)
{
  Serial.println("user called for steps");
  wstpr=buf[10]-48;
  Serial.print("the stepper chossen is");
  Serial.println(wstpr);
  
  if(wstpr==1)
  {
    ahsteps=buf[19]-48;
    hsteps=ahsteps*1000;
    
    ahsteps=buf[20]-48;
    hsteps=hsteps+(ahsteps*100);
    
    ahsteps=buf[21]-48;
    hsteps=hsteps+(ahsteps*10);
    
    ahsteps=buf[22]-48;
    hsteps=hsteps+ahsteps;
    
    Serial.print("the no of hsteps");
    Serial.println(hsteps);
  }
  
  if(wstpr==2)
  {
    ahsteps=buf[19]-48;
    h1steps=ahsteps*1000;
    
    ahsteps=buf[20]-48;
    h1steps=h1steps+(ahsteps*100);
    
    ahsteps=buf[21]-48;
    h1steps=h1steps+(ahsteps*10);
    
    ahsteps=buf[22]-48;
    h1steps=h1steps+ahsteps;
    
    Serial.print("the no of h1steps");
    Serial.println(h1steps);
  }
  
  if(buf[18]=='+')
  {
   Serial.println("its clock wise direction");
   if(wstpr==1)
   {
    dir1=1;
   }
   else
   {
    dir2=1;
   }
  }
  
  if(buf[18]=='-')
  {
   Serial.println("its aclock wise direction");
   if(wstpr==1)
   {
    dir1=2;
   }
   else
   {
    dir2=2;
   }
  }
}

void callspeed(void)
{
  Serial.println("user called for speed");
  wstpr=buf[10]-48;
  Serial.print("the stepper chossen is");
  Serial.println(wstpr);
  
  if(wstpr==1)
  {
    aspd=buf[18]-48;
    spd=aspd*1000;
    
    aspd=buf[19]-48;
    spd=spd+(aspd*100);
    
    aspd=buf[20]-48;
    spd=spd+(aspd*10);
    
    aspd=buf[21]-48;
    spd=spd+aspd;
    
    Serial.print("the speed value");
    Serial.println(spd);
  }
  
  if(wstpr==2)
  {
    aspd=buf[18]-48;
    s1pd=aspd*1000;
    
    aspd=buf[19]-48;
    s1pd=s1pd+(aspd*100);
    
    aspd=buf[20]-48;
    s1pd=s1pd+(aspd*10);
    
    aspd=buf[21]-48;
    s1pd=s1pd+aspd;
    
    Serial.print("the speed 1 value");
    Serial.println(s1pd);
  }
}

void callgo(void)
{
  Serial.println("here the motor will rotate");
  wstpr=buf[10]-48;
  Serial.println(wstpr);
  if(wstpr==1)
  {
    Serial.println("go for stpper 1 and its variable are hsteps sped dir");
    Serial.print(hsteps);
    Serial.print(spd);
    Serial.println(dir1);
    Stepper Stepper1(hsteps, 17,16,15,14);
    Stepper1.setSpeed(spd);
    if(dir1==1)
    Stepper1.step(hsteps);
    if(dir1==2)
    Stepper1.step(-hsteps);
  }
  if(wstpr==2)
  {
    Serial.println("go for stpper 2 and its variable are hsteps sped dir");
    Serial.print(h1steps);
    Serial.print(s1pd);
    Serial.println(dir2);
    Stepper Stepper2(h1steps, 5,6,7,8);
    Stepper2.setSpeed(s1pd);
    if(dir2==1)
    Stepper2.step(h1steps);
    if(dir2==2)
    Stepper2.step(-h1steps);
  }
  if(wstpr==0)
  {
    Serial.println("go for both");
    Serial.print(hsteps);
    Serial.print(spd);
    Serial.println(dir1);
    Serial.print(h1steps);
    Serial.print(s1pd);
    Serial.println(dir2);
    
    Stepper Stepper1(hsteps, 17,16,15,14);
    Stepper1.setSpeed(spd);
    if(dir1==1)
    Stepper1.step(hsteps);
    if(dir1==2)
    Stepper1.step(-hsteps);
    
    Stepper Stepper2(h1steps, 5,6,7,8);
    Stepper2.setSpeed(s1pd);
    if(dir2==1)
    Stepper2.step(h1steps);
    if(dir2==2)
    Stepper2.step(-h1steps);
  }
  
  
  
}
