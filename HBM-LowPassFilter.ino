// HBM-LowPassFilter- HoverBoard Low Pass Filter with Potentiometer Control - 10/10/2022
// need a multimeter or an oscilloscope to see output value
 
const int START_PGM_BT = A0;          // Start pgm button
const int PWM_PIN_OUT = 3;            // 490Hz PWM Output
const int POT_PIN_IN = A7;            // Analog potentiomer input

void setup() {
  Serial.begin(9600);
  pinMode(START_PGM_BT,INPUT_PULLUP);
  pinMode(PWM_PIN_OUT, OUTPUT);
  Serial.print("\n\t To start pgm, click on the Start button");  while(digitalRead(START_PGM_BT));  delay(400);  Serial.print("\n\t Started");
}

void loop() {
  int potValue = analogRead(POT_PIN_IN);        // read the potentiometer value
  int PWM = map(potValue,0,1023,0,255);         // convert to PWM value
  analogWrite(PWM_PIN_OUT, PWM);                // write PWM value to output with LowPass Filter
}
