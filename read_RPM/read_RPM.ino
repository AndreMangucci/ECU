const int hallSensorPin = 2;                      // connect the hall effect sensor on pin 2
const unsigned long sampleTime = 1000;
int rpmMaximum = 0;

void setup() 
{
  pinMode(hallSensorPin,INPUT);
  Serial.begin(115200);
  Serial.print("Initializing");
  delay(1000);
}

void loop() 
{
  delay(100);
  int rpm = getRPM();
  if (rpm > rpmMaximum) rpmMaximum = rpm;
  displayRPM(rpm);
}
 
int getRPM()
{
  int count = 0;
  boolean countFlag = LOW;
  unsigned long currentTime = 0;
  unsigned long startTime = millis();
  while (currentTime <= sampleTime)
  {
    if (analogRead(hallSensorPin) == 0)
    {
      countFlag = HIGH;
    }
    if (analogRead(hallSensorPin) > 0 && countFlag == HIGH)
    {
      count++;
      countFlag=LOW;
    }
    currentTime = millis() - startTime;
  }
  int countRpm = int(60000/float(sampleTime))*count;
  return countRpm;
}
    
void displayRPM(int rpm) 
{
  Serial.print("RPM = ");
  Serial.print(rpm);
  Serial.print("  MAX RPM = ");
  Serial.println(rpmMaximum);
}
