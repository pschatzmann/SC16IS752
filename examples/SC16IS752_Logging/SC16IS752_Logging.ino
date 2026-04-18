/*
  SC16IS752 logging example

  Initializes the shared I2C bus in the sketch, attaches an
  SC16IS752Logger to the driver, and configures both UART channels.
*/

#include <Wire.h>

#include <SC16IS752.h>
#include <SC16IS752Logger.h>

SC16IS752 uart(Wire, SC16IS750_ADDRESS_AD);
SC16IS752Logger log(Serial, SC16IS752Logger::LEVEL_DEBUG);

auto& uartA = uart.channelA();
auto& uartB = uart.channelB();

void setup() {
  Serial.begin(115200);
  while (!Serial) {
  }

  Wire.begin();

  uart.setLogger(&log);
  uartA.begin(9600);
  uartB.begin(115200);

  log.info("SC16IS752 logging example started");
  uartA.println("Hello from channel A with logging enabled");
  uartB.println("Hello from channel B with logging enabled");
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
