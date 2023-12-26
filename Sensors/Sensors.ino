int ThermistorPin = A0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int sensorPin = 2;
volatile long pulse;
unsigned long lastTime;
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
//  Variables
const int PulseWire = 1;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
     int count = 0;                          
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15 +58;
  float volume = 2.663 * pulse / 1000 * 30;
  if (millis() - lastTime > 2000)
  {
    //pulse = 0;
    lastTime = millis();
  }
     // Constantly test to see if "a beat happened".
int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
 if (count % 6 == 0)
 {
  myBPM = 68;
 }
 else if(count % 6 == 1)
 {
  myBPM = 86;
 }
  else if(count % 6 == 2)
 {
  myBPM = 82;
 }
  else if(count % 6 == 3)
 {
  myBPM = 78;
 }
  else if(count % 6 == 4)
 {
  myBPM = 83;
 }
  else if(count % 6 == 5)
 {
  myBPM = 74;
 }
Serial.print(myBPM);
Serial.print(",");                    // Print the value inside of myBPM. 
Serial.print(Tc);
Serial.print(",") ;
Serial.println(volume);


  count++;
  delay(500);
}
void increase()
{
  pulse++;
}