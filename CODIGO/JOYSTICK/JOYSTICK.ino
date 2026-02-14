// ==============================
// PROYECTO INDUSTRIAL JOYSTICK
// Joystick KY-023 + RGB KY-016
// Relé KY-019 controlando Láser KY-008
// ==============================

// ---- Joystick Pines ----
int VRx = A0;
int VRy = A1;
int SW  = 2;

// ---- LED RGB KY-016 ----
int redPin   = 9;
int greenPin = 10;
int bluePin  = 11;

// ---- Relé KY-019 ----
int relePin = 8;

// ==============================
void setup() {

  Serial.begin(9600);

  // Joystick botón
  pinMode(SW, INPUT_PULLUP);

  // RGB como salida
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Relé como salida
  pinMode(relePin, OUTPUT);

  // Relé apagado al inicio
  digitalWrite(relePin, LOW);

  Serial.println("=== SISTEMA INDUSTRIAL INICIADO ===");
}

// ==============================
void loop() {

  // Leer joystick
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);

  // Leer botón
  int buttonState = digitalRead(SW);

  // Apagar LED RGB antes de cambiar
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // ==============================
  // CONTROL POR DIRECCIÓN
  // ==============================

  // ARRIBA → Verde (Normal)
  if (yValue > 800) {
    digitalWrite(greenPin, HIGH);
    Serial.println("🟢 DERECHA → LED VERDE");
  }

  // ABAJO → Rojo (Alerta)
  else if (yValue < 200) {
    digitalWrite(redPin, HIGH);
    Serial.println("🔴 IZQUIERDA → LED ROJO");
  }

  // IZQUIERDA → Relé ON + Azul
  else if (xValue < 200) {
    digitalWrite(bluePin, HIGH);

    // Encender relé → láser ON
    digitalWrite(relePin, HIGH);

    Serial.println("🔵 ABAJO→ RELÉ ON → LÁSER ENCENDIDO");
  }

  // DERECHA → Relé OFF
  else if (xValue > 800) {

    // Apagar relé → láser OFF
    digitalWrite(relePin, LOW);

    Serial.println("⚫ ARRIBA → RELÉ OFF → LÁSER APAGADO");
  }

  // CENTRO → Nada
  else {
    Serial.println("⚪ JOYSTICK EN CENTRO");
  }

  // ==============================
  // BOTÓN PRESIONADO
  // ==============================

  if (buttonState == LOW) {

    // Blanco = todos encendidos
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);

    Serial.println("⭐ BOTÓN PRESIONADO → MODO ESPECIAL");
    delay(300);
  }

  delay(200);
}