

#include <Wire.h>
#include <Stepper.h>

int inc=0;
char readf[26]={0};
volatile int yesdo=0;

int wstpr=0;//which stepper
int spd=0;//speed of stpr1
int s1pd=0;//speed of stpr2
int aspd=0;//associate of speed
int hsteps=0;//stpr 1
int h1steps=0;//stpr 2
int ahsteps=0;
int dir1=0;
int dir2=0;

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  if(yesdo==1)
  {
   dopera();
  
   for(inc=0;inc<26;inc++)
   readf[inc]='0';
   inc=0;
   yesdo=0;
  }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    readf[inc] = Wire.read(); // receive byte as a character
    Serial.print(readf[inc]);
    inc++;    
    
  }
  
  
  
  int x = Wire.read();    // receive byte as an integer
  Serial.println();         // print the integer
  yesdo=1;
  
  
}

void dopera(void)
{
  for(inc=0;inc<26;inc++)
  Serial.print(readf[inc]); 
  Serial.println(" ");
  if(readf[13]=='t')
  callsteps();
  if(readf[13]=='p')
  callspeed();
  if(readf[12]=='g')
  callgo();
}

void callsteps(void)
{
  Serial.println("user called for steps");
  wstpr=readf[10]-48;
  Serial.print("the stepper chossen is");
  Serial.println(wstpr);
  
  if(wstpr==1)
  {
    ahsteps=readf[19]-48;
    hsteps=ahsteps*1000;
    
    ahsteps=readf[20]-48;
    hsteps=hsteps+(ahsteps*100);
    
    ahsteps=readf[21]-48;
    hsteps=hsteps+(ahsteps*10);
    
    ahsteps=readf[22]-48;
    hsteps=hsteps+ahsteps;
    
    Serial.print("the no of hsteps");
    Serial.println(hsteps);
  }
  
  if(wstpr==2)
  {
    ahsteps=readf[19]-48;
    h1steps=ahsteps*1000;
    
    ahsteps=readf[20]-48;
    h1steps=h1steps+(ahsteps*100);
    
    ahsteps=readf[21]-48;
    h1steps=h1steps+(ahsteps*10);
    
    ahsteps=readf[22]-48;
    h1steps=h1steps+ahsteps;
    
    Serial.print("the no of h1steps");
    Serial.println(h1steps);
  }
  
  if(readf[18]=='+')
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
  
  if(readf[18]=='-')
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
  wstpr=readf[10]-48;
  Serial.print("the stepper chossen is");
  Serial.println(wstpr);
  
  if(wstpr==1)
  {
    aspd=readf[18]-48;
    spd=aspd*1000;
    
    aspd=readf[19]-48;
    spd=spd+(aspd*100);
    
    aspd=readf[20]-48;
    spd=spd+(aspd*10);
    
    aspd=readf[21]-48;
    spd=spd+aspd;
    
    Serial.print("the speed value");
    Serial.println(spd);
  }
  
  if(wstpr==2)
  {
    aspd=readf[18]-48;
    s1pd=aspd*1000;
    
    aspd=readf[19]-48;
    s1pd=s1pd+(aspd*100);
    
    aspd=readf[20]-48;
    s1pd=s1pd+(aspd*10);
    
    aspd=readf[21]-48;
    s1pd=s1pd+aspd;
    
    Serial.print("the speed 1 value");
    Serial.println(s1pd);
  }
}

void callgo(void)
{
  Serial.println("here the motor will rotate");
  wstpr=readf[10]-48;
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
