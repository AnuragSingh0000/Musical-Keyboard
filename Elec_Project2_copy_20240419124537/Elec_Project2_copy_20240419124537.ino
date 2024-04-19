#define echoPin 12
#define trigPin 11
// Define the pin for the push button
const int buttonPinC = 4;
const int buttonPinD = 5;
const int buttonPinE = 6;
const int buttonPinF = 7;
const int buttonPinG = 8;
const int buttonPinA = 9;
const int buttonPinB = 10;
// Define the pin for the buzzer
const int buzzerPin = 3;


long duration;
int distance;

// Octave frequencies for each 5 cm range of distances
// int f[] = {131, 147, 165, 175, 196, 220, 247};
// int f[] = {520,584,656,696,764,880,976};
int f[] = {1040, 1168, 1312, 1392, 1528, 1760, 1952};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Distance measurement using Arduino Uno.");
  delay(5);

  // Set the button pin as input
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPinE, INPUT);
  pinMode(buttonPinF, INPUT);
  pinMode(buttonPinG, INPUT);
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);

  // Enable internal pull-up resistor for the button pin
  digitalWrite(buttonPinC, HIGH);
  digitalWrite(buttonPinD, HIGH);
  digitalWrite(buttonPinE, HIGH);
  digitalWrite(buttonPinF, HIGH);
  digitalWrite(buttonPinG, HIGH);
  digitalWrite(buttonPinA, HIGH);
  digitalWrite(buttonPinB, HIGH);

  // Set the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}


int getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0344 / 2;
    return distance;
}

int mapDistanceToFrequency(int distance) {
    if (distance <= 5) {
        return 1;
    } else if (distance <= 10) {
        return 4;
    } else if (distance <= 15) {
        return 6;
    } else {
        return 1; // Return 0 if distance is out of range
    }
}


void loop() {
  // Read the state of the button
  int buttonStateC = digitalRead(buttonPinC);
  int buttonStateD = digitalRead(buttonPinD);
  int buttonStateE = digitalRead(buttonPinE);
  int buttonStateF = digitalRead(buttonPinF);
  int buttonStateG = digitalRead(buttonPinG);
  int buttonStateA = digitalRead(buttonPinA);
  int buttonStateB = digitalRead(buttonPinB);
  int measuredDistance = getDistance();
    Serial.print("Distance: ");
    Serial.print(measuredDistance);
    Serial.println(" cm");
    // delay(100);

    // Button C
  if (buttonStateC == LOW) {
    Serial.println("ButtonC pressed!");
    // Activate the buzzer
    int frequency = f[0]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

    // Button D
  if (buttonStateD == LOW) {
    Serial.println("ButtonD pressed!");
    // Activate the buzzer
    int frequency = f[1]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

    // Button E
  if (buttonStateE == LOW) {
    Serial.println("ButtonE pressed!");
    // Activate the buzzer
    int frequency = f[2]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

    // Button F
  if (buttonStateF == LOW) {
    Serial.println("ButtonF pressed!");
    // Activate the buzzer
    int frequency = f[3]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

    // Button G
  if (buttonStateG == LOW) {
    Serial.println("ButtonG pressed!");
    // Activate the buzzer
    int frequency = f[4]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

  // Button A
  if (buttonStateA == LOW) {
    Serial.println("ButtonA pressed!");
    // Activate the buzzer
    int frequency = f[5]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

  // Button B
  if (buttonStateB == LOW) {
    Serial.println("Button pressed!");
    // Activate the buzzer
    int frequency = f[6]*mapDistanceToFrequency(measuredDistance);
    for (int i=frequency-5; i<frequency+5; i++) {
      tone(buzzerPin, i); // 1000 Hz frequency
      delay(10); // Optional debounce delay
    }
    // Stop the buzzer
    noTone(buzzerPin);
  }

  

  // Check if the button is pressed (buttonState is LOW when pressed)
}


