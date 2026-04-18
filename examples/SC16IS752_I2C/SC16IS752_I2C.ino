/*
  SC16IS752 I2C example

  Initializes the shared I2C bus in the sketch and configures
  both UART channels on the SC16IS752.
*/

#include <Wire.h>

#include <SC16IS752.h>

SC16IS752 uart(Wire, SC16IS750_I2C_ADDRESS_AD);

auto& uartA = uart.channelA();
auto& uartB = uart.channelB();

void setup() {
  Serial.begin(115200);
  while (!Serial) {
  }

  Wire.begin();

  uartA.begin(9600);
  uartB.begin(115200);

  Serial.println("SC16IS752 I2C example started");
  uartA.println("Hello from channel A over I2C");
  uartB.println("Hello from channel B over I2C");
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
