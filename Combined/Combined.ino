#include "Arduino_SensorKit.h"
 
#define BUZZER 5
#define LED 6
#define BUTTON 4 
#define Environment Environment_I2C

int sound_sensor = A2;
int light_sensor = A3; 
int button_state = 0;
 
void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(BUTTON, INPUT);

  Wire.begin(); 
  Environment.begin();
	
  Serial.begin(9600);
}
 
void loop() {

  int soundValue = 0;
  int raw_light = analogRead(light_sensor); // read the raw value from light_sensor pin (A3)
  int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
 
  Serial.print("Light level: "); 
  Serial.println(light); // print the light value in Serial Monitor

  for (int i = 0; i < 32; i++) { 
    soundValue += analogRead(sound_sensor);  
    }
 
  soundValue >>= 5; //bitshift operation 
  Serial.print("Sound value: "); 
  Serial.println(soundValue);
 
  if (soundValue > 500) { 
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");

    tone(BUZZER, 85);
    digitalWrite(LED, HIGH); //Sets the voltage to high 
  }
  else
  {
    digitalWrite(LED, LOW);  //Sets the voltage to low
  }

  button_state = digitalRead(BUTTON);

  if (button_state == HIGH) {
    Serial.print("Temperature = ");
    Serial.print(Environment.readTemperature()); //print temperature
    Serial.println(" C");
    Serial.print("Humidity = ");
    Serial.print(Environment.readHumidity()); //print humidity
    Serial.println(" %");
    Serial.println(" ");
    Serial.println("-----");
    Serial.println(" ");
  }  

  button_state = 0;

  delay(500); //a shorter delay between readings
  noTone(BUZZER);
}