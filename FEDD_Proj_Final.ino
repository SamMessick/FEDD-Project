  // Sets fan pins and LED to PWM (Pulse Width Modulation) pins on Arduino
const int UVLED = 11;
const int rotorPin = 6;
const int fanPin1a = 10;
const int fanPin1b = 9;
const int fanPin2a = 3;
const int fanPin2b = 2;


void setup() {
  // Set pins as output; overwrites the default INPUT setting
  pinMode(rotorPin, OUTPUT);
  pinMode(fanPin1a, OUTPUT);
  pinMode(fanPin1b, OUTPUT);
  pinMode(fanPin2a, OUTPUT);
  pinMode(fanPin2b, OUTPUT);
  pinMode(UVLED, OUTPUT);
}


void loop() {
  //The first settings run 4 times  for ~ 24 seconds
  for(int fast = 0; fast <=4; fast +=1){


    // The rotor is set to normal rotation, and the first fan is set to constant current
    TurnOnFirstFanANDRotor();

    // the UV LED strip dims
    DimLEDs();
      }
      
  //The second settings run 2 times for ~ 12 seconds
  for(int slow = 0; slow <=2; slow +=1) {
    // The rotor is set to a slower rotation, and the second fan is set to constant current
    TurnOnSecondFanANDRotor();

    // The UV LED strip dims
    DimLEDs();
      }
      
//The third settings are run 4 times for ~ 24 seconds
 for(int fast = 0; fast <=2; fast +=1){

    // The rotor is set to normal rotation, and the first fan is set to constant current
    TurnOnFirstFanANDRotor();

    // The UV LED strip dims
    DimLEDs();
      }

  /*Turn off all motors and wait for reset
    while the LEDs continue to dim 30 times*/
  digitalWrite(fanPin1a, LOW);
  digitalWrite(fanPin1b, LOW);
  digitalWrite(fanPin2a, LOW);
  digitalWrite(fanPin2b, LOW);
  digitalWrite(rotorPin, LOW);
  for (int endloop = 0 ; endloop <= 30 ; endloop += 2) {
    DimLEDs();
  }
}

void TurnOnFirstFanANDRotor() {
      digitalWrite(fanPin1a, HIGH);
      digitalWrite(fanPin1b, LOW);
      digitalWrite(fanPin2a, LOW);
      digitalWrite(fanPin2b, LOW);
      analogWrite(rotorPin, 200);
  }

void TurnOnSecondFanANDRotor() {
      digitalWrite(fanPin1a, LOW);
      digitalWrite(fanPin1b, LOW);
      digitalWrite(fanPin2a, HIGH);
      digitalWrite(fanPin2b, LOW);
      analogWrite(rotorPin, 180);
  }

void DimLEDs() {
    //LED intensity increases
    for (float intensity = 30 ; intensity <= 255 ; intensity += 1) {
      analogWrite(UVLED, intensity);
      delay(10);
      }

    //LED intensity decreases
    for (int intensity = 255 ; intensity >= 30 ; intensity -= 1) {
      analogWrite(UVLED, intensity);
      delay(10);
      }
  }
