//example code for using serial stepper firmware

void setup()
{
  Serial.begin(9600);
  
  Serial.println("$ stepper 1 speed 0060 /n");
  delay(3000);
  
  Serial.println("$ stepper 1 steps +0200 /n");//clock wise
  delay(3000);
  
  Serial.println("$ stepper 2 speed 0060 /n");
  delay(3000);
  
  Serial.println("$ stepper 2 steps -0200 /n");//anti clock wise
  delay(3000);
}

void loop()
{
  Serial.println("$ stepper 0 go /n");//both stepper 1 and 2 will rotate for the set speed and step
  delay(3000);
  
  Serial.println("$ stepper 1 go /n");//only stepper 1 will rotate
  delay(3000);
  
  Serial.println("$ stepper 2 go /n");//stepper 2 will rotate
  delay(3000);
  
}
