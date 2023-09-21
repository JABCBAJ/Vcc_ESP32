
float referenciaConocida = 3.350; // Voltaje de referencia conocido en V
byte PIN = PIN;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // Configura la resolución del ADC a 12 bits (0-4095)
}

void loop() {
  int valorADC = analogRead(PIN);

  // Calibración: Calcula el factor de escala
  float factorDeEscala = referenciaConocida / valorADC;

  // Aplica el factor de escala para obtener el voltaje calibrado
  float voltajeCalibrado = valorADC * factorDeEscala;

  Serial.print("Valor ADC en el pin ");
  Serial.print(PIN);
  Serial.print(": ");
  Serial.print(valorADC);
  Serial.print(", factorDeEscala: ("); Serial.print(factorDeEscala, 4); Serial.print(")");
  Serial.print(", Voltaje Calibrado: ");
  Serial.print(voltajeCalibrado, 4); // Muestra el voltaje con 4 decimales
  Serial.println(" V");

  delay(1000);
}
