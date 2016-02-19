#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1  2

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, RELAY_OFF);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);              // wait for a second
  //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  //delay(5000);              // wait for a second
  int sensorValue1 = analogRead(A0);
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  int sensorValue2 = analogRead(A1);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);
  float diff = abs(voltage2 - voltage1);
  if (diff < 1.5){
  digitalWrite(RELAY_1, RELAY_ON);
  delay(100);
  digitalWrite(RELAY_1, RELAY_OFF);}
  Serial.println(diff);
  //delay(1000);
}
