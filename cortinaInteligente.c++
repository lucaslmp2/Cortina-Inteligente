#include <IRremote.h>
#include <Stepper.h>


#define receptor 3
#define STEP_PIN 8
#define DIR_PIN 9

const int passosPorGiroMotor = 200;

IRrecv irrecv(receptor);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode()) {
    unsigned long armazenavalor = irrecv.decodedIRData.decodedRawData;

    if (armazenavalor == 0xFFFFFFFF) {
      irrecv.resume();
      return;
    }

    Serial.println(armazenavalor, HEX);

    switch(armazenavalor) {
      case 0x5DA2FF00:
        Serial.println("Comando: POWER (Parar Motor)");
        break;
      case 0xCF30FF00:
        Serial.println("Comando: 1 (1 Giro Horário)");
        motorMove(1, 1, 1500);
        delay(1000);
        break;
      case 0xE718FF00:
        Serial.println("Comando: 2 (1 Giro Anti-Horário)");
        motorMove(1, -1, 1500);
        delay(1000);
        break;
      case 0x857AFF00:
        Serial.println("Comando: 3 (3 Giros Horário)");
        motorMove(3, 1, 1000);
        delay(1000);
        break;
      case 0xEF10FF00:
        Serial.println("Comando: 4 (3 Giros Anti-Horário)");
        motorMove(3, -1, 1000);
        delay(1000);
        break;
      case 0xC738FF00:
        Serial.println("Comando: 5 (Ação Personalizada)");
        break;
      case 0xA55AFF00:
        Serial.println("Comando: 6 (Ação Personalizada)");
        break;
      case 0xBD42FF00:
        Serial.println("Comando: 7 (Ação Personalizada)");
        break;
      case 0xB54AFF00:
        Serial.println("Comando: 8 (Ação Personalizada)");
        break;
      case 0xAD52FF00:
        Serial.println("Comando: 9 (Ação Personalizada)");
        break;
      default:
        Serial.print("Comando IR não mapeado: ");
        Serial.println(armazenavalor, HEX);
        break;
    }
    irrecv.resume();
  }
}

void motorMove(int turns, int direction, int stepDelayUs) {
  if (direction == 1) {
    digitalWrite(DIR_PIN, HIGH);
  } else {
    digitalWrite(DIR_PIN, LOW);
  }

  long totalSteps = (long)turns * passosPorGiroMotor;

  for (long i = 0; i < totalSteps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(stepDelayUs);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(stepDelayUs);
  }
}