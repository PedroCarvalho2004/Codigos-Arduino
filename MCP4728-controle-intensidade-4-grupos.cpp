#include <Wire.h>
#include <Adafruit_MCP4728.h>

String command;
Adafruit_MCP4728 mcp1;

void setup() {
  Serial.begin(115200);
  delay(2000);

  if (!mcp1.begin(0x60)) {
    Serial.println("Erro: MCP4728 (0x60) não encontrado!");
    while (1);
  }

  Serial.println("MCP4728 inicializados!");
  Serial.println("Digite no formato: <LED>,<intensidade>");
  Serial.println("Exemplo: 0,50 (LED 0 com 50% de intensidade)");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();

    int led;
    float intensity;

    // Divide a string com base na vírgula
    int commaIndex = command.indexOf(',');
    if (commaIndex > 0) {
      String ledStr = command.substring(0, commaIndex);
      String intensityStr = command.substring(commaIndex + 1);

      led = ledStr.toInt();
      intensity = intensityStr.toFloat();

      // Verifica se os valores são válidos
      if (led >= 0 && led <= 3 && intensity >= 0 && intensity <= 100) {
        int value = map(intensity, 0, 100, 0, 2048); 

        Serial.print("LED ");
        Serial.print(led);
        Serial.print(" ajustado para ");
        Serial.print(intensity);
        Serial.println("%");

        // Ajusta o canal correto do MCP4728
        switch (led) {
          case 0: mcp1.setChannelValue(MCP4728_CHANNEL_A, value); break;
          case 1: mcp1.setChannelValue(MCP4728_CHANNEL_B, value); break;
          case 2: mcp1.setChannelValue(MCP4728_CHANNEL_C, value); break;
          case 3: mcp1.setChannelValue(MCP4728_CHANNEL_D, value); break;
        }

        mcp1.saveToEEPROM();
      } else {
        Serial.println("Erro: LED inválido (0-3) ou intensidade fora do intervalo (0-100%)");
      }
    } else {
      Serial.println("Erro: Formato inválido! Use: <LED>,<intensidade>");
    }
  }
}
