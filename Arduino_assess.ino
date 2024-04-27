/* Arduino Logical Challenge - Sensor Calibration and Timing Simulator */

// Variables for sensor calibration simulator
int virtualSensorValue = 0;
int calibrationOffset = 0;

// Variables for timing challenge
unsigned long startTime = 0;
bool timerRunning = false;
unsigned long timerDuration = 10000; // default timer duration of 10 seconds

// Setup function runs once when you reset or power the board
void setup() {
  Serial.begin(9600);
}

// Main program loop
void loop() {
  
  // Call sensor calibration function
  calibrateSensor();

  // Check if timer should be running
  if (timerRunning) {
    manageTimer();
  }
  
  // Add a delay for readability of simulation
  delay(1000);
}

/* Sensor Calibration Simulator Functions */

// Simulates reading a sensor value and returns it
int readVirtualSensor() {
  // Simulation of reading a sensor: just increment the value
  virtualSensorValue++;
  return virtualSensorValue;
}

// Adjusts the calibration setting based on some conditions (e.g., target value)
void adjustCalibration() {
  // Simple simulation of adjustment: reset if value exceeds 10
  if (virtualSensorValue > 10) {
    calibrationOffset--;
    virtualSensorValue += calibrationOffset; // Adjust sensor value
  } else {
    calibrationOffset++;
  }
  // Display the new calibration setting
  Serial.print("New calibration offset: ");
  Serial.println(calibrationOffset);
}

// Displays the calibration status
void displayCalibrationStatus() {
  Serial.print("Virtual Sensor Value: ");
  Serial.print(virtualSensorValue);
  Serial.print(" | Calibration Offset: ");
  Serial.println(calibrationOffset);
}

// Runs the entire calibration process
void calibrateSensor() {
  readVirtualSensor();
  adjustCalibration();
  displayCalibrationStatus();
}

/* Timing Challenge Functions */

// Starts the timer
void startTimer() {
  if (!timerRunning) {
    timerRunning = true;
    startTime = millis();
    Serial.println("Timer started!");
  }
}

// Stops the timer
void stopTimer() {
  if (timerRunning) {
    timerRunning = false;
    Serial.println("Timer stopped!");
  }
}

// Resets the timer
void resetTimer() {
  timerRunning = false;
  startTime = millis();
  Serial.println("Timer reset!");
}

// Adjust the timer's duration
void adjustTimerDuration(unsigned long newDuration) {
  timerDuration = newDuration;
  Serial.print("Timer duration adjusted to: ");
  Serial.print(timerDuration);
  Serial.println(" ms");
}

// Manage the timer, including checking if it's finished
void manageTimer() {
  if (millis() - startTime >= timerDuration) {
    Serial.println("Timer complete!");
    timerRunning = false;
  }
}
