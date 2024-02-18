// Define the pins for controlling the signals
const int pinD12 = 12;
const int pinD11 = 11;
const int pinD10 = 10;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the pins as output
  pinMode(pinD12, OUTPUT);
  pinMode(pinD11, OUTPUT);
  pinMode(pinD10, OUTPUT);

}

void loop() {
  // Prompt the user to enter the temperature
  Serial.println("Enter the temperature ");
  // Wait for user input
  while (Serial.available() == 0) {
  ;
  }

  // Read the user input temperature
  int temperature = Serial.parseInt();

  
  // Control the signals based on temperature using if-else statements
  if (temperature > 0 && temperature <= 15) {
    digitalWrite(pinD12, HIGH);
    digitalWrite(pinD11, LOW);
    digitalWrite(pinD10, LOW);
  } else if (temperature >= 16 && temperature <= 25) {
    digitalWrite(pinD12, LOW);
    digitalWrite(pinD11, HIGH);
    digitalWrite(pinD10, LOW);
  } else if (temperature >= 26) {
    digitalWrite(pinD12, LOW);
    digitalWrite(pinD11, LOW);
    digitalWrite(pinD10, HIGH);
  }

  // Wait for a short duration to avoid rapid changes
  delay(1000);
     digitalWrite(pinD12, LOW);
    digitalWrite(pinD11, LOW);
    digitalWrite(pinD10, LOW);
}
