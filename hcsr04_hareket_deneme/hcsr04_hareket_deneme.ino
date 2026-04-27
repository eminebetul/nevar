#define ENA 10
#define ENB 11
#define IN1 8
#define IN2 9
#define IN3 2
#define IN4 3
 
#define trigPin 6
#define echoPin 7

int hiz = 170;

#define guvenli_mesafe 25
#define riskli_mesafe 10

float mesafe;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


float olcMesafe() {
  long sure;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);

  return sure * 0.0343 / 2;
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

  mesafe = olcMesafe();
  if (mesafe > guvenli_mesafe) {
    ileri(hiz);
  }
  else if (mesafe <= guvenli_mesage && mesafe > riskli_mesafe) {

    dur();
    delay(80);

    sag(hiz);
    delay(400);
  }

  else {
    
    dur();
    delay(80);

    geri(hiz);
    delay(500);

    sag(hiz);
    delay(500);
  }
}
