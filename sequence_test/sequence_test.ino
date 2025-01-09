// Outputs
#define MotorEnablePin 8
#define MotorOpenPin 10
#define MotorClosePin  9

volatile byte state = LOW;
// volatile unsigned long previousMillis = 0;
// const long interval = 5000; 
void OpenHand();

void CloseHand();

void Lowallport();

void setup() {
  Serial.begin(115200);
  // debug led
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(MotorOpenPin, OUTPUT);
  pinMode(MotorClosePin, OUTPUT);
  pinMode(MotorEnablePin, OUTPUT);

  CloseHand();
  digitalWrite(LED_BUILTIN, state);
  delay(2000);
  OpenHand();
  digitalWrite(LED_BUILTIN, state);
  delay(2000);
  Lowallport();
  digitalWrite(LED_BUILTIN, state);
  delay(2000);
  CloseHand();
  digitalWrite(LED_BUILTIN, state);
  delay(100);
  Lowallport();
  digitalWrite(LED_BUILTIN, state);
  OpenHand();
  digitalWrite(LED_BUILTIN, state);
  delay(100);
  Lowallport();
  digitalWrite(LED_BUILTIN, state);
}

void loop() {
  // unsigned long currentMillis = millis();
}
void OpenHand(){
  state=HIGH;
  // previousMillis = millis();
  digitalWrite(MotorClosePin, LOW);
  delayMicroseconds(100);
  digitalWrite(MotorEnablePin, HIGH);
  digitalWrite(MotorOpenPin, HIGH);
}

void CloseHand(){
  state=HIGH;
  // previousMillis = millis();
  digitalWrite(MotorOpenPin, LOW);
  delayMicroseconds(100);
  digitalWrite(MotorEnablePin, HIGH);
  digitalWrite(MotorClosePin, HIGH);
}

void Lowallport(){
  digitalWrite(MotorEnablePin, LOW);
  digitalWrite(MotorOpenPin, LOW);
  digitalWrite(MotorClosePin, LOW);
  state=LOW;
}