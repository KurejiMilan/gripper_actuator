volatile byte state = LOW;
volatile unsigned long previousMillis = 0;
const long interval = 5000; 
// Inputs
#define OpenHandPin 2
#define CloseHandPin 3
// Outputs
#define MotorEnablePin  8
#define MotorOpenPin  10
#define MotorClosePin  9
const byte ledPin = LED_BUILTIN;

int flag = 0;
// 1 = close 2= open

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
//  unsigned long currentMillis = millis();
//   
//  if (currentMillis - previousMillis >= interval) {
//    digitalWrite(MotorEnablePin, LOW);
//    digitalWrite(MotorOpenPin, LOW);
//    digitalWrite(MotorClosePin, LOW);
//    state=LOW;
//  }
  if(flag == 1){
    Serial.println("close command");
  }
  if(flag == 2){
    Serial.println("open command");
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
  flag = 2;
}

void CloseHand() {
  state=HIGH;
  previousMillis = millis();
  digitalWrite(MotorOpenPin, LOW);
  delayMicroseconds(100);
  digitalWrite(MotorEnablePin, HIGH);
  digitalWrite(MotorClosePin, HIGH);
  flag = 1;
}
