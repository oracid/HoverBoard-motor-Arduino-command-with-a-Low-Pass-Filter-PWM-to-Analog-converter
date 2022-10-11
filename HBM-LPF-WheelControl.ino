// HBM-LPF- HoverBoard LowPass Filter and Wheel Control with ZS-X11H driver - 08/10/2022

const int START_PGM_BT = A0;          // Start pgm button
const int PWM_PIN_OUT = 3;            // 490Hz PWM Output
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
  int PWM = 25;                                           // you must choose your speed
  analogWrite(PWM_PIN_OUT, PWM);                          // write PWM value to output with LowPass Filter
  digitalWrite(DIR_PIN_OUT, digitalRead(DIR_PIN_BT));     // change direction when button actived
  delay(1940);                                            // to make a turn, this value depends on the speed
  PWM = 0;  analogWrite(PWM_PIN_OUT, PWM);                // write PWM value to output with LowPass Filter
  delay(1000);                                            // a break between 2 turns
}
