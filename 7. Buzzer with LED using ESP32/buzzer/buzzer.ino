const int buzzerpin = 9;
int led = 8;
int gled = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerpin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(gled, OUTPUT);
  while(!Serial);
}

void loop() {
  green_light();
  buzzer();
}

void green_light(){
  digitalWrite(gled, LOW);
  delay(150);
  
  digitalWrite(gled, HIGH);
  delay(50);

  digitalWrite(gled, LOW);
  delay(150);

  digitalWrite(gled, HIGH);
  delay(50);

  digitalWrite(gled, LOW);
  delay(500);
}

void buzzer(){
  digitalWrite(led, HIGH);
  pinMode(buzzerpin, HIGH);
  delay(100);
  
  digitalWrite(led, LOW);
  pinMode(buzzerpin, LOW);
  delay(50);
  
  digitalWrite(led, HIGH);
  pinMode(buzzerpin, HIGH);
  delay(100);

  digitalWrite(led, LOW);
  pinMode(buzzerpin, LOW);
  delay(10); 
}
