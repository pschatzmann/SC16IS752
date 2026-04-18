/*
  SC16IS752 SPI example

  Initializes the shared SPI bus in the sketch and configures
  both UART channels on the SC16IS752.
*/

#include <SPI.h>

#include <SC16IS752.h>

constexpr uint8_t SC16IS752_CS_PIN = 10;

SC16IS752 uart(SPI, SC16IS752_CS_PIN);

auto& uartA = uart.channelA();
auto& uartB = uart.channelB();

void setup() {
  Serial.begin(115200);
  while (!Serial) {
  }

  SPI.begin();

  uartA.begin(9600);
  uartB.begin(115200);

  Serial.println("SC16IS752 SPI example started");
  uartA.println("Hello from channel A over SPI");
  uartB.println("Hello from channel B over SPI");
}

void loop() {
  while (uartA.available()) {
    Serial.write(uartA.read());
  }

  while (uartB.available()) {
    Serial.write(uartB.read());
  }

  delay(10);
}
