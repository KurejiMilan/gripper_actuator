volatile byte state = LOW;
volatile unsigned long previousMillis = 0;
const long interval = 5000; 
// Inputs
const byte OpenHandPin = 2;
const byte CloseHandPin = 3;
// Outputs
const byte MotorEnablePin = 8;
const byte MotorOpenPin = 10;
const byte MotorClosePin = 9;
const byte ledPin = LED_BUILTIN;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(OpenHandPin, INPUT);
  pinMode(CloseHandPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(OpenHandPin), OpenHand, RISING);
  attachInterrupt(digitalPinToInterrupt(CloseHandPin), CloseHand, RISING);
  pinMode(MotorOpenPin, OUTPUT);
  pinMode(MotorClosePin, OUTPUT);
  pinMode(MotorEnablePin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, state);
  unsigned long currentMillis = millis();
   
  if (currentMillis - previousMillis >= interval) {
    digitalWrite(MotorEnablePin, LOW);
    digitalWrite(MotorOpenPin, LOW);
    digitalWrite(MotorClosePin, LOW);
    state=LOW;
  }
  //Serial.print(digitalRead(OpenHandPin));
  

}

void OpenHand() {
  state=HIGH;
  previousMillis = millis();
  digitalWrite(MotorClosePin, LOW);
  delayMicroseconds(100);
  digitalWrite(MotorEnablePin, HIGH);
  digitalWrite(MotorOpenPin, HIGH);
}

void CloseHand() {
  state=HIGH;
  previousMillis = millis();
  digitalWrite(MotorOpenPin, LOW);
  delayMicroseconds(100);
  digitalWrite(MotorEnablePin, HIGH);
  digitalWrite(MotorClosePin, HIGH);
}
