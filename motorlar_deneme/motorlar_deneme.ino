#define ENA 10
#define ENB 11
#define IN1 8
#define IN2 9
#define IN3 2
#define IN4 3
int hiz=170;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void ileri(int hiz) {
  analogWrite(ENA, hiz);
  analogWrite(ENB, hiz);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void geri(int hiz) {
  analogWrite(ENA, hiz);
  analogWrite(ENB, hiz);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void sag(int hiz) {
  analogWrite(ENA, hiz);
  analogWrite(ENB, hiz);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void sol(int hiz) {
  analogWrite(ENA, hiz);
  analogWrite(ENB, hiz);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void dur() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
  ileri(150);
  delay(2000);

  sag(150);
  delay(1000);

  sol(150);
  delay(1000);

  geri(150);
  delay(2000);

  dur();
  delay(2000);
}
