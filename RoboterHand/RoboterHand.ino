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

//action flag
// 0 = no action
// 1 = open
// 2 = close
uint8_t action_flag =  0;
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(OpenHandPin, INPUT);
  pinMode(CloseHandPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(OpenHandPin), OpenHandISR, RISING);
  attachInterrupt(digitalPinToInterrupt(CloseHandPin), CloseHandISR, RISING);
  pinMode(MotorOpenPin, OUTPUT);
  pinMode(MotorClosePin, OUTPUT);
  pinMode(MotorEnablePin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, state);
  unsigned long currentMillis = millis();

  if(state){
    if (currentMillis - previousMillis >= interval) {
      digitalWrite(MotorEnablePin, LOW);
      digitalWrite(MotorOpenPin, LOW);
      digitalWrite(MotorClosePin, LOW);
      state=LOW;
    } 
  }
  //Serial.print(digitalRead(OpenHandPin));
  if(action_flag == 1){
    state=HIGH;
    previousMillis = millis();
    digitalWrite(MotorClosePin, LOW);
    delayMicroseconds(100);
    digitalWrite(MotorEnablePin, HIGH);
    digitalWrite(MotorOpenPin, HIGH);
    action_flag = 0;
  }else if(action_flag == 2){
    state=HIGH;
    previousMillis = millis();
    digitalWrite(MotorOpenPin, LOW);
    delayMicroseconds(100);
    digitalWrite(MotorEnablePin, HIGH);
    digitalWrite(MotorClosePin, HIGH);
    action_flag = 0;
  }
}
void OpenHandISR(){
  action_flag = 1;
}
void CloseHandISR(){
  action_flag = 2;
}

//void OpenHand() {
//  state=HIGH;
//  previousMillis = millis();
//  digitalWrite(MotorClosePin, LOW);
//  delayMicroseconds(100);
//  digitalWrite(MotorEnablePin, HIGH);
//  digitalWrite(MotorOpenPin, HIGH);
//}
//
//void CloseHand() {
//  state=HIGH;
//  previousMillis = millis();
//  digitalWrite(MotorOpenPin, LOW);
//  delayMicroseconds(100);
//  digitalWrite(MotorEnablePin, HIGH);
//  digitalWrite(MotorClosePin, HIGH);
//}
