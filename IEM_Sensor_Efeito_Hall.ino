#include <LiquidCrystal.h>

// Inicializa o LCD nos pinos especificados
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);

  // Configura o LCD para 16 colunas e 2 linhas
  lcd.begin(16, 2);
} 

void loop() {
  int Vmedido = analogRead(A0);
  // Convertendo a leitura para tensão em mV
  float outputV = Vmedido * 5.0 * 100.0 / 1023.0;

  // Calculando a corrente usando a equação da regressão
  float current_mA = 16.67 * outputV - 4404.12;

  // Limpa o LCD e posiciona o cursor no início
  lcd.clear();
  lcd.setCursor(3, 0);

  // Exibe a tensão no LCD
  lcd.print(outputV);
  lcd.print(" mV");

  // Posiciona o cursor na segunda linha
  lcd.setCursor(3, 1);

  // Exibe a corrente no LCD
  lcd.print(current_mA);
  lcd.print(" mA");

  // Atraso para facilitar a visualização
  delay(1000);
}
