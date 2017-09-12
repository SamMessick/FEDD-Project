  // Sets fan pins and LED to PWM (Pulse Width Modulation) pins on Arduino
const int rotor1 = 9;
const int rotor2 = 10;
const int UVLED = 11;
const int Strobe = 8;
const int fan1 = 12;
const int fan2 = 13;

void setup() {
  /* Set pins as output; overwrite the default INPUT setting
     Set the fan to recieve constant 4W power */
pinMode(rotor1, OUTPUT);
  pinMode(rotor2, OUTPUT);
  pinMode(UVLED, OUTPUT);
  pinMode(Strobe, OUTPUT);
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  digitalWrite(fan2, HIGH);
}

void loop() {
  // Repeats the settings according to preference (1 min loop total)
  for(int i = 0; i <= 1; i += 1) {

    // Motor settings, run for approximately 20s each, gradually reducing bubble size and increasing frequency
    for(int j = 130; j <= 160; j += 10) {
    analogWrite(rotor1, j);
    
      // Dims the LEDs 10 times before changing motor settings (~20s/time)
      for(int k = 0; k <= 10; k += 1) {
      DimLEDs();

      }
    }
  }
}

void DimLEDs() {
    // LED intensity increases
    for (int intensity = 0 ; intensity <= 255 ; intensity += 1) {
      analogWrite(UVLED, intensity);
      // Strobe LED set to full power for each intensity divisible by 5, turned off otherwise
      analogWrite(Strobe, intensity%5 == 0 ? 255: 0);
      delay(25);  
  }

    // LED intensity decreases
    for (int intensity = 255 ; intensity >= 0 ; intensity -= 1) {
      analogWrite(UVLED, intensity);
      // Strobe LED set to full power for each intensity divisible by 5, turned off otherwise
      analogWrite(Strobe, intensity%5 == 0 ? 255: 0);  
      delay(25);
      }
  }
