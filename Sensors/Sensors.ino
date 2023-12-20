int ThermistorPin = A0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int sensorPin = 2;
volatile long pulse;
unsigned long lastTime;

void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
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
    pulse = 0;
    lastTime = millis();
  }
  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   
  Serial.println("--------------- \n");
  Serial.println(volume);
  Serial.println(" L/m \n");

  delay(500);
}
void increase()
{
  pulse++;
}
