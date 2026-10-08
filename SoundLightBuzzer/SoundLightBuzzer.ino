	
#define BUZZER 5
#define LED 6

int sound_sensor = A2;
 
void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED,OUTPUT);
	
  Serial.begin(9600);
}
 
void loop() {

  int soundValue = 0;

  for (int i = 0; i < 32; i++) { 
    soundValue += analogRead(sound_sensor);  
    }
 
  soundValue >>= 5; //bitshift operation 
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

  delay(50); //a shorter delay between readings
  noTone(BUZZER);
}