// Pin Definitions
const int windPin = A0;   // DC motor (wind sensor) connected here

int windValue = 0;

void setup() {
  Serial.begin(9600);   // For HC-05 Bluetooth
}

void loop() {

  // Read voltage from DC motor (acts as generator)
  windValue = analogRead(windPin);

  // Send value to Bluetooth
  Serial.print("Wind Value: ");
  Serial.println(windValue);

  // Simple wind condition status
  if (windValue < 50) {
    Serial.println("No Wind");
  } 
  else if (windValue < 200) {
    Serial.println("Low Wind");
  } 
  else if (windValue < 500) {
    Serial.println("Medium Wind");
  } 
  else {
    Serial.println("High Wind");
  }

  delay(500);
}