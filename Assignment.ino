const int ledPin = 13; // OnBoard LED
const int lm35Pin = A0; // LM35 sensor connected to analog pin A0
unsigned long previousMillis = 0;
int ledState = LOW; // Intial state of the Onboard LED
unsigned long blinkInterval = 250; //Intial blink Interval in Milliseconds

void setup() {
  pinMode(ledPin,OUTPUT); // Making the pin as a Output pin
  Serial.begin(9600); 
}

void loop() {
  unsigned long currentMillis = millis(); //Current program running time
  if(currentMillis - previousMillis >= blinkInterval)
  {
    previousMillis = currentMillis;
    int temperature = readTemperature();
    if(temperature<30){
      blinkInterval = 250;
      }else {
        blinkInterval = 500;
      }
      toggleLED();

  }

}
int readTemperature (){ // A Function to read temperature
  int rawValue = analogRead(lm35Pin); // Reading Input
  float milliVolts = (rawValue/1024.0)*5000; // Convert to mv
  float temperatureC = (milliVolts - 500)/10; // Convert to Celsius
  return temperatureC;
}
void toggleLED(){ // Toggling Input
  if(ledState == LOW){
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin,ledState);
}
