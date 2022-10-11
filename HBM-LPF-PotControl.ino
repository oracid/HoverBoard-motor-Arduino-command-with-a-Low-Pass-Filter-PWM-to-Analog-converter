// HBM-LPF- HoverBoard LowPass Filter and Potentiometer Control with ZS-X11H controller - 08/10/2022

const int START_PGM_BT = A0;          // Start pgm button
const int PWM_PIN_OUT = 3;            // 490Hz PWM Output
const int POT_PIN_IN = A7;            // Analog potentiomer input
const int DIR_PIN_BT = A2;            // Direction button
const int DIR_PIN_OUT = 2;            // Direction Output

void setup() {
  Serial.begin(9600);
  pinMode(START_PGM_BT,INPUT_PULLUP);
  pinMode(DIR_PIN_BT,INPUT_PULLUP);
  pinMode(DIR_PIN_OUT, OUTPUT);
  pinMode(PWM_PIN_OUT, OUTPUT);
  Serial.print("\n\t To start pgm, click on the Start button");  while(digitalRead(START_PGM_BT));  delay(400);  Serial.print("\n\t Started");
}

void loop() {
  int potValue = analogRead(POT_PIN_IN);                // read the potentiometer value
  int PWM = map(potValue,0,1023,0,255);                 // convert potentiometer value to PWM value
  analogWrite(PWM_PIN_OUT, PWM);                        // write PWM value to output with LowPass Filter
  digitalWrite(DIR_PIN_OUT, digitalRead(DIR_PIN_BT));   // change direction when button actived
}
