const int irPin = A0;   // Analog pin connected to the IR sensor
const int buzzerPin = 8; // Buzzer connected to PWM pin 9
int sensorValue = 0;    // Variable to store the analog reading
float distance = 0;     // Variable to store the calculated distance

void setup() {
  Serial.begin(9600);    // Start the serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  sensorValue = analogRead(irPin); // Read the analog value from the IR sensor
  distance = map(sensorValue, 0, 1023, 70, 80); // Map the sensor reading to distance (in cm)

  // Alternatively, use a specific conversion equation provided by the sensor's datasheet
  // e.g., distance = 6787 / (sensorValue - 3) - 4;

  // Print the sensor value and calculated distance
  Serial.print("Analog Value:");
  Serial.print(sensorValue);
  Serial.print(" | Distance (cm): ");
  Serial.println(distance);

  // Control the buzzer volume based on distance
  int buzzerVolume = map(distance, 70, 80, 255, 0); // Closer distance = louder buzzer
  buzzerVolume = constrain(buzzerVolume, 0, 255);   // Ensure the PWM value stays within 0-255

  analogWrite(buzzerPin, buzzerVolume); // Output PWM to the buzzer to control the volume

  delay(500); // Wait for half a second before taking the next reading
}
