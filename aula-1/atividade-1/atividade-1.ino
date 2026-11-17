
// C++ code
//

const int vermelho = 8;
const int verde = 9;
const int amarelo = 10;
const int botao = 2;

int estado = 0;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  Serial.begin(9600);

  atualizarSemaforo();
}

void loop() {
  if (digitalRead(botao) == LOW) {
    delay(50);

    if (digitalRead(botao) == LOW) {
      estado++;

      if (estado > 2) {
        estado = 0;
      }

      atualizarSemaforo();

      while (digitalRead(botao) == LOW) {
        delay(10);
      }
    }
  }
}

void atualizarSemaforo() {
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);

  if (estado == 0) {
    digitalWrite(vermelho, HIGH);
    Serial.println("VERMELHO");
  }
  else if (estado == 1) {
    digitalWrite(verde, HIGH);
    Serial.println("VERDE");
  }
  else {
    digitalWrite(amarelo, HIGH);
    Serial.println("AMARELO");
  }
}
