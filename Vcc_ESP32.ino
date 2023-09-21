
float VCC = 3351.0; // Voltaje de referencia conocido en V+ esp32
byte PIN = 25;

void setup() {
  pinMode(25, INPUT_PULLUP);
  Serial.begin(115200);
  analogReadResolution(12); // Configura la resolución del ADC a 12 bits (0-4095)
}

void loop() {
  int valorADC = analogRead(PIN);

  // Calibración
  float mapa = map(valorADC, 0, 4095, 0, VCC)/1000.0;

  Serial.print("Valor ADC en el pin ");
  Serial.print(PIN);
  Serial.print(": ");
  Serial.print(valorADC);

  Serial.print(", Voltaje medido >> ");
  Serial.print(mapa,2); // Muestra el voltaje con 4 decimales
  Serial.println(" V");


  delay(1000);
}
