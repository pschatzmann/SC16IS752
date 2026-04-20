/*
SC16IS752 driver for Arduino
*/

#pragma once

#include <SPI.h>
#include <Wire.h>

#include "Arduino.h"
#include "SC16IS752Logger.h"

#define SC16IS752_SERIAL_CONFIG(data_bits, parity_code, stop_bits) \
  ((((data_bits) - 5) & 0x03) | (((parity_code) & 0x03) << 2) |    \
   ((((stop_bits) - 1) & 0x01) << 4))

#ifndef SERIAL_5N1
#define SERIAL_5N1 SC16IS752_SERIAL_CONFIG(5, 0, 1)
#endif
#ifndef SERIAL_6N1
#define SERIAL_6N1 SC16IS752_SERIAL_CONFIG(6, 0, 1)
#endif
#ifndef SERIAL_7N1
#define SERIAL_7N1 SC16IS752_SERIAL_CONFIG(7, 0, 1)
#endif
#ifndef SERIAL_8N1
#define SERIAL_8N1 SC16IS752_SERIAL_CONFIG(8, 0, 1)
#endif
#ifndef SERIAL_5N2
#define SERIAL_5N2 SC16IS752_SERIAL_CONFIG(5, 0, 2)
#endif
#ifndef SERIAL_6N2
#define SERIAL_6N2 SC16IS752_SERIAL_CONFIG(6, 0, 2)
#endif
#ifndef SERIAL_7N2
#define SERIAL_7N2 SC16IS752_SERIAL_CONFIG(7, 0, 2)
#endif
#ifndef SERIAL_8N2
#define SERIAL_8N2 SC16IS752_SERIAL_CONFIG(8, 0, 2)
#endif
#ifndef SERIAL_5E1
#define SERIAL_5E1 SC16IS752_SERIAL_CONFIG(5, 2, 1)
#endif
#ifndef SERIAL_6E1
#define SERIAL_6E1 SC16IS752_SERIAL_CONFIG(6, 2, 1)
#endif
#ifndef SERIAL_7E1
#define SERIAL_7E1 SC16IS752_SERIAL_CONFIG(7, 2, 1)
#endif
#ifndef SERIAL_8E1
#define SERIAL_8E1 SC16IS752_SERIAL_CONFIG(8, 2, 1)
#endif
#ifndef SERIAL_5E2
#define SERIAL_5E2 SC16IS752_SERIAL_CONFIG(5, 2, 2)
#endif
#ifndef SERIAL_6E2
#define SERIAL_6E2 SC16IS752_SERIAL_CONFIG(6, 2, 2)
#endif
#ifndef SERIAL_7E2
#define SERIAL_7E2 SC16IS752_SERIAL_CONFIG(7, 2, 2)
#endif
#ifndef SERIAL_8E2
#define SERIAL_8E2 SC16IS752_SERIAL_CONFIG(8, 2, 2)
#endif
#ifndef SERIAL_5O1
#define SERIAL_5O1 SC16IS752_SERIAL_CONFIG(5, 1, 1)
#endif
#ifndef SERIAL_6O1
#define SERIAL_6O1 SC16IS752_SERIAL_CONFIG(6, 1, 1)
#endif
#ifndef SERIAL_7O1
#define SERIAL_7O1 SC16IS752_SERIAL_CONFIG(7, 1, 1)
#endif
#ifndef SERIAL_8O1
#define SERIAL_8O1 SC16IS752_SERIAL_CONFIG(8, 1, 1)
#endif
#ifndef SERIAL_5O2
#define SERIAL_5O2 SC16IS752_SERIAL_CONFIG(5, 1, 2)
#endif
#ifndef SERIAL_6O2
#define SERIAL_6O2 SC16IS752_SERIAL_CONFIG(6, 1, 2)
#endif
#ifndef SERIAL_7O2
#define SERIAL_7O2 SC16IS752_SERIAL_CONFIG(7, 1, 2)
#endif
#ifndef SERIAL_8O2
#define SERIAL_8O2 SC16IS752_SERIAL_CONFIG(8, 1, 2)
#endif

static constexpr uint8_t SC16IS750_I2C_ADDRESS_AA =
    0x48;  ///< 7-bit I2C address option AA.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_AB =
    0x49;  ///< 7-bit I2C address option AB.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_AC =
    0x4A;  ///< 7-bit I2C address option AC.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_AD =
    0x4B;  ///< 7-bit I2C address option AD.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_BA =
    0x4C;  ///< 7-bit I2C address option BA.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_BB =
    0x4D;  ///< 7-bit I2C address option BB.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_BC =
    0x4E;  ///< 7-bit I2C address option BC.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_BD =
    0x4F;  ///< 7-bit I2C address option BD.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_CA =
    0x50;  ///< 7-bit I2C address option CA.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_CB =
    0x51;  ///< 7-bit I2C address option CB.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_CC =
    0x52;  ///< 7-bit I2C address option CC.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_CD =
    0x53;  ///< 7-bit I2C address option CD.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_DA =
    0x54;  ///< 7-bit I2C address option DA.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_DB =
    0x55;  ///< 7-bit I2C address option DB.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_DC =
    0x56;  ///< 7-bit I2C address option DC.
static constexpr uint8_t SC16IS750_I2C_ADDRESS_DD =
    0x57;  ///< 7-bit I2C address option DD.

/**
 * @enum SC16IS750_IIR
 * @brief Decoded interrupt event types returned by `interruptEventTest()`.
 */
enum SC16IS750_IIR {
  SC16IS750_RECEIVE_LINE_STATUS_ERROR,  ///< Receiver line status error.
  SC16IS750_RECEIVE_TIMEOUT_INTERRUPT,  ///< Receiver timeout interrupt.
  SC16IS750_RHR_INTERRUPT,              ///< RX holding register interrupt.
  SC16IS750_THR_INTERRUPT,              ///< TX holding register interrupt.
  SC16IS750_MODEM_INTERRUPT,            ///< Modem status interrupt.
  SC16IS750_INPUT_PIN_CHANGE_STATE,     ///< GPIO input pin state change.
  SC16IS750_RECEIVE_XOFF,               ///< XOFF character received.
  SC16IS750_CTS_RTS_CHANGE              ///< CTS/RTS state change.
};

static constexpr uint32_t SC16IS752_DEFAULT_SPEED =
    9600;  ///< Default UART baud rate.
static constexpr uint32_t SC16IS752_DEFAULT_CONFIG =
    SERIAL_8N1;  ///< Default UART frame format.
static constexpr uint32_t SC16IS752_DEFAULT_SPI_CLOCK =
    4000000;  ///< Default SPI clock in Hz.

/**
 * @class SC16IS752
 * @brief Driver for the NXP SC16IS752 dual UART bridge over I2C or SPI.
 *
 * The SC16IS752 provides two independent UART channels (A and B) and optional
 * GPIO/interrupt capabilities. This class wraps register-level access and
 * exposes:
 * - Channel-oriented UART APIs (`read()`, `write()`, `available()`, ...)
 * - Per-channel Stream adapters via `channelA()` and `channelB()`
 * - Optional RS485 and interrupt helper methods
 *
 * Construction selects the transport layer:
 * - `SC16IS752(TwoWire&, address)` for I2C
 * - `SC16IS752(SPIClass&, ssPin)` for SPI
 *
 * Typical usage:
 * @code
 * SC16IS752 uart(Wire, SC16IS750_I2C_ADDRESS_AD);
 * uart.channelA().begin(9600);
 * uart.channelB().begin(115200);
 * uart.channelA().write('H');
 * @endcode
 *
 * Optionally, attach a logger with `setLogger()` to receive debug output.
 */
class SC16IS752 {
 public:
  /**
   * @enum SC16IS752_Channel
   * @brief UART channel selector used by channel-specific APIs.
   */
  enum SC16IS752_Channel : uint8_t {
    SC16IS752_CHANNEL_A = 0x00,     ///< UART channel A.
    SC16IS752_CHANNEL_B = 0x01,     ///< UART channel B.
    SC16IS752_CHANNEL_BOTH = 0x00,  ///< Broadcast for global/shared registers.
  };

  /**
   * @class ChannelStream
   * @brief Per-channel `Stream` adapter for one SC16IS752 UART.
   *
   * This nested class exposes a standard Arduino `Stream` interface for a
   * single UART channel and forwards all operations to its parent
   * `SC16IS752` instance. It allows sketches to use `channelA()` and
   * `channelB()` like regular stream objects while still exposing selected
   * channel-specific helpers such as `begin()`, `linestate()`,
   * `interruptPendingTest()`, `enableRs485()`, and `interruptControl()`.
   */
  class ChannelStream : public Stream {
   public:
    /// Creates a stream adapter bound to the selected UART channel
    ChannelStream(SC16IS752& parent, SC16IS752_Channel channel)
        : parent_(parent), channel_(channel) {}

    // Stream interface
    /// Returns the number of bytes available for reading on this channel
    int available() override { return parent_.available(channel_); }
    /// Reads one byte from this channel
    int read() override { return parent_.read(channel_); }
    /// Peeks one byte from this channel without removing it
    int peek() override { return parent_.peek(channel_); }
    /// Waits until pending transmission on this channel is complete
    void flush() override { parent_.flush(channel_); }
    /// Writes one byte to this channel
    size_t write(uint8_t val) override { return parent_.write(channel_, val); }
    using Print::write;

    /**
     * @brief Initializes this channel with the specified baud rate and serial
     * configuration.
     * @param baudrate UART baud rate.
     * @param config Arduino-style serial format. Supported values are:
     * - `SERIAL_5N1`
     * - `SERIAL_6N1`
     * - `SERIAL_7N1`
     * - `SERIAL_8N1` (default)
     * - `SERIAL_5N2`
     * - `SERIAL_6N2`
     * - `SERIAL_7N2`
     * - `SERIAL_8N2`
     * - `SERIAL_5E1`
     * - `SERIAL_6E1`
     * - `SERIAL_7E1`
     * - `SERIAL_8E1`
     * - `SERIAL_5E2`
     * - `SERIAL_6E2`
     * - `SERIAL_7E2`
     * - `SERIAL_8E2`
     * - `SERIAL_5O1`
     * - `SERIAL_6O1`
     * - `SERIAL_7O1`
     * - `SERIAL_8O1`
     * - `SERIAL_5O2`
     * - `SERIAL_6O2`
     * - `SERIAL_7O2`
     * - `SERIAL_8O2`
     */
    void begin(uint32_t baudrate = SC16IS752_DEFAULT_SPEED,
               uint32_t config = SC16IS752_DEFAULT_CONFIG) {
      parent_.beginChannel(channel_, baudrate, config);
    }
    /// Gracefully closes this channel
    void end() { parent_.endChannel(channel_); }
    /// Returns the line status register for this channel
    uint8_t linestate() { return parent_.linestate(channel_); }
    /// Tests whether an interrupt is pending for this channel
    uint8_t interruptPendingTest() {
      return parent_.interruptPendingTest(channel_);
    }
    /// Returns the decoded interrupt event for this channel
    int interruptEventTest() { return parent_.interruptEventTest(channel_); }
    /// Enables RS485 mode for this channel
    void enableRs485(bool invert_rts) {
      parent_.enableRs485(channel_, invert_rts);
    }

    /// Enables or disables transmission for this channel
    void enableTransmit(uint8_t tx_enable) {
      parent_.enableTransmit(channel_, tx_enable);
    }

    /// Controls interrupt enable bits for this channel
    void interruptControl(uint8_t int_ena) {
      parent_.interruptControl(channel_, int_ena);
    }

   private:
    SC16IS752& parent_;
    SC16IS752_Channel channel_;
  };

  /// Constructs an SC16IS752 instance using I2C transport
  SC16IS752(TwoWire& wire, uint8_t addr = SC16IS750_I2C_ADDRESS_AD,
            uint32_t crystal_freq_hz = SC16IS750_CRYSTCAL_FREQ)
      : channel_a_stream(*this, SC16IS752_CHANNEL_A),
        channel_b_stream(*this, SC16IS752_CHANNEL_B) {
    device_address_sspin = addr;
    wire_bus = &wire;
    spi_bus = nullptr;
    crystal_freq = crystal_freq_hz;
    timeout = 1000;
    peek_buf[SC16IS752_CHANNEL_A] = -1;
    peek_buf[SC16IS752_CHANNEL_B] = -1;
    peek_flag[SC16IS752_CHANNEL_A] = 0;
    peek_flag[SC16IS752_CHANNEL_B] = 0;
  }

  /// Constructs an SC16IS752 instance using SPI transport
  SC16IS752(SPIClass& spi, uint8_t ss_pin,
            uint32_t crystal_freq_hz = SC16IS750_CRYSTCAL_FREQ)
      : channel_a_stream(*this, SC16IS752_CHANNEL_A),
        channel_b_stream(*this, SC16IS752_CHANNEL_B) {
    device_address_sspin = ss_pin;
    wire_bus = nullptr;
    spi_bus = &spi;
    crystal_freq = crystal_freq_hz;
    timeout = 1000;
    peek_buf[SC16IS752_CHANNEL_A] = -1;
    peek_buf[SC16IS752_CHANNEL_B] = -1;
    peek_flag[SC16IS752_CHANNEL_A] = 0;
    peek_flag[SC16IS752_CHANNEL_B] = 0;
  }

  /// Prevent copying and moving of the driver instance
  SC16IS752(const SC16IS752&) = delete;
  /// Prevent copying and moving of the driver instance
  SC16IS752& operator=(const SC16IS752&) = delete;
  /// Prevent copying and moving of the driver instance
  SC16IS752(SC16IS752&&) = delete;
  /// Prevent copying and moving of the driver instance
  SC16IS752& operator=(SC16IS752&&) = delete;

  /// Returns channel A stream adapter
  ChannelStream& channelA() { return channel_a_stream; }
  /// Returns channel B stream adapter
  ChannelStream& channelB() { return channel_b_stream; }

  /// Set logger for debug output
  void setLogger(SC16IS752Logger* log) { logger = log; }
  /// Sets read timeout in milliseconds
  void setTimeout(uint32_t time_out) { timeout = time_out; }

  /// Gracefully closes both UART channels and resets the device
  void end() {
    endChannel(SC16IS752_CHANNEL_A);
    endChannel(SC16IS752_CHANNEL_B);
    resetDevice();
    is_active = false;
  }


  friend class ChannelStream;

 protected:
  // General Registers
  static constexpr uint8_t SC16IS750_REG_RHR =
      0x00;  ///< Receive Holding Register.
  static constexpr uint8_t SC16IS750_REG_THR =
      0x00;  ///< Transmit Holding Register.
  static constexpr uint8_t SC16IS750_REG_IER =
      0x01;  ///< Interrupt Enable Register.
  static constexpr uint8_t SC16IS750_REG_FCR =
      0x02;  ///< FIFO Control Register.
  static constexpr uint8_t SC16IS750_REG_IIR =
      0x02;  ///< Interrupt Identification Register.
  static constexpr uint8_t SC16IS750_REG_LCR =
      0x03;  ///< Line Control Register.
  static constexpr uint8_t SC16IS750_REG_MCR =
      0x04;  ///< Modem Control Register.
  static constexpr uint8_t SC16IS750_REG_LSR = 0x05;  ///< Line Status Register.
  static constexpr uint8_t SC16IS750_REG_MSR =
      0x06;  ///< Modem Status Register.
  static constexpr uint8_t SC16IS750_REG_SPR = 0x07;  ///< Scratchpad Register.
  static constexpr uint8_t SC16IS750_REG_TCR =
      0x06;  ///< Transmission Control Register.
  static constexpr uint8_t SC16IS750_REG_TLR =
      0x07;  ///< Trigger Level Register.
  static constexpr uint8_t SC16IS750_REG_TXLVL =
      0x08;  ///< TX FIFO Level Register.
  static constexpr uint8_t SC16IS750_REG_RXLVL =
      0x09;  ///< RX FIFO Level Register.
  static constexpr uint8_t SC16IS750_REG_IODIR =
      0x0A;  ///< GPIO Direction Register.
  static constexpr uint8_t SC16IS750_REG_IOSTATE =
      0x0B;  ///< GPIO State Register.
  static constexpr uint8_t SC16IS750_REG_IOINTENA =
      0x0C;  ///< GPIO Interrupt Enable Register.
  static constexpr uint8_t SC16IS750_REG_IOCONTROL =
      0x0E;  ///< GPIO/IO Control Register.
  static constexpr uint8_t SC16IS750_REG_EFCR =
      0x0F;  ///< Extra Features Control Register.

  // Special Registers
  static constexpr uint8_t SC16IS750_REG_DLL = 0x00;  ///< Divisor Latch LSB.
  static constexpr uint8_t SC16IS750_REG_DLH = 0x01;  ///< Divisor Latch MSB.

  // Enhanced Registers
  static constexpr uint8_t SC16IS750_REG_EFR =
      0x02;  ///< Enhanced Features Register.
  static constexpr uint8_t SC16IS750_REG_XON1 =
      0x04;  ///< XON1 flow-control character.
  static constexpr uint8_t SC16IS750_REG_XON2 =
      0x05;  ///< XON2 flow-control character.
  static constexpr uint8_t SC16IS750_REG_XOFF1 =
      0x06;  ///< XOFF1 flow-control character.
  static constexpr uint8_t SC16IS750_REG_XOFF2 =
      0x07;  ///< XOFF2 flow-control character.

  // Interrupt Enable Register
  static constexpr uint8_t SC16IS750_INT_CTS =
      0x80;  ///< CTS change interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_RTS =
      0x40;  ///< RTS change interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_XOFF =
      0x20;  ///< XOFF interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_SLEEP =
      0x10;  ///< Sleep mode interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_MODEM =
      0x08;  ///< Modem status interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_LINE =
      0x04;  ///< Line status interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_THR =
      0x02;  ///< TX holding register interrupt enable bit.
  static constexpr uint8_t SC16IS750_INT_RHR =
      0x01;  ///< RX holding register interrupt enable bit.

  // Application related
  // static constexpr uint32_t SC16IS750_CRYSTCAL_FREQ = 14745600UL;  ///<
  // Optional crystal frequency (Hz).
  static constexpr uint32_t SC16IS750_CRYSTCAL_FREQ =
      1843200UL;  ///< Default crystal frequency (Hz).
  // static constexpr uint32_t SC16IS750_CRYSTCAL_FREQ = 16000000UL;  ///<
  // Optional crystal frequency (Hz).

  bool is_active = false;
  uint8_t device_address_sspin; // i2c address or spi ss pin
  TwoWire* wire_bus;
  SPIClass* spi_bus;
  SPISettings spi_settings{SC16IS752_DEFAULT_SPI_CLOCK, MSBFIRST, SPI_MODE0};
  uint32_t crystal_freq = SC16IS750_CRYSTCAL_FREQ;
  uint32_t timeout;
  ChannelStream channel_a_stream;
  ChannelStream channel_b_stream;
  int peek_buf[2];
  uint8_t peek_flag[2];
  SC16IS752Logger* logger = nullptr;

  /**
   * @brief Initializes a specific UART channel with the given baud rate and
   * serial configuration.
   * @param channel Target UART channel.
   * @param baudrate UART baud rate.
   * @param config Arduino-style serial format. Supported values are:
   * - `SERIAL_5N1`
   * - `SERIAL_6N1`
   * - `SERIAL_7N1`
   * - `SERIAL_8N1` (default)
   * - `SERIAL_5N2`
   * - `SERIAL_6N2`
   * - `SERIAL_7N2`
   * - `SERIAL_8N2`
   * - `SERIAL_5E1`
   * - `SERIAL_6E1`
   * - `SERIAL_7E1`
   * - `SERIAL_8E1`
   * - `SERIAL_5E2`
   * - `SERIAL_6E2`
   * - `SERIAL_7E2`
   * - `SERIAL_8E2`
   * - `SERIAL_5O1`
   * - `SERIAL_6O1`
   * - `SERIAL_7O1`
   * - `SERIAL_8O1`
   * - `SERIAL_5O2`
   * - `SERIAL_6O2`
   * - `SERIAL_7O2`
   * - `SERIAL_8O2`
   */
  void beginChannel(SC16IS752_Channel channel, uint32_t baudrate,
                    uint32_t config = SC16IS752_DEFAULT_CONFIG) {
    initializeDevice();
    fifoEnable(channel, 1);
    setBaudrate(channel, baudrate);
    setLine(channel, config);
  }

  /// Gracefully closes a specific UART channel
  void endChannel(SC16IS752_Channel channel) {
    if (channel > SC16IS752_CHANNEL_B) {
      return;
    }
    flush(channel);
    fifoReset(channel, 0);  // reset RX FIFO
    fifoReset(channel, 1);  // reset TX FIFO
    fifoEnable(channel, 0);
  }

  /// Reads a byte from the specified channel
  int read(SC16IS752_Channel channel) {
    if (channel > SC16IS752_CHANNEL_B) {
      return -1;
    }
    if (peek_flag[channel] == 0) {
      return readByte(channel);
    } else {
      peek_flag[channel] = 0;
      return peek_buf[channel];
    }
  }

  /// Writes a byte to the specified channel
  size_t write(SC16IS752_Channel channel, uint8_t val) {
    writeByte(channel, val);
    return 1;
  }

  /// Returns number of bytes available to read from the channel
  int available(SC16IS752_Channel channel) {
    return fifoAvailableData(channel);
  }

  /// Returns line status register for the channel
  uint8_t linestate(SC16IS752_Channel channel) {
    return readRegister(channel, SC16IS750_REG_LSR);
  }
  /// Verifies device communication (returns 1 if successful)
  uint8_t ping() {
    writeRegister(SC16IS752_CHANNEL_A, SC16IS750_REG_SPR, 0x55);
    if (readRegister(SC16IS752_CHANNEL_A, SC16IS750_REG_SPR) != 0x55) {
      return 0;
    }

    writeRegister(SC16IS752_CHANNEL_A, SC16IS750_REG_SPR, 0xAA);
    if (readRegister(SC16IS752_CHANNEL_A, SC16IS750_REG_SPR) != 0xAA) {
      return 0;
    }

    writeRegister(SC16IS752_CHANNEL_B, SC16IS750_REG_SPR, 0x55);
    if (readRegister(SC16IS752_CHANNEL_B, SC16IS750_REG_SPR) != 0x55) {
      return 0;
    }

    writeRegister(SC16IS752_CHANNEL_B, SC16IS750_REG_SPR, 0xAA);
    if (readRegister(SC16IS752_CHANNEL_B, SC16IS750_REG_SPR) != 0xAA) {
      return 0;
    }

    return 1;
  }

  /// Reads a byte without removing it from the buffer
  int peek(SC16IS752_Channel channel) {
    if (channel > SC16IS752_CHANNEL_B) {
      return -1;
    }
    if (peek_flag[channel] == 0) {
      peek_buf[channel] = readByte(channel);
      if (peek_buf[channel] >= 0) {
        peek_flag[channel] = 1;
      }
    }

    return peek_buf[channel];
  }

  /// Waits for transmission to complete on the channel
  void flush(SC16IS752_Channel channel) {
    if (channel > SC16IS752_CHANNEL_B) {
      return;
    }

    uint8_t tmp_lsr;
    uint32_t start = millis();

    do {
      tmp_lsr = readRegister(channel, SC16IS750_REG_LSR);
      if ((tmp_lsr & 0x20) != 0) {
        return;
      }
    } while ((millis() - start) < timeout);

    if (logger) {
      logger->warn("flush timeout ch=%d", channel);
    }
  }

  /// Tests if an interrupt is pending on the channel
  uint8_t interruptPendingTest(SC16IS752_Channel channel) {
    return (readRegister(channel, SC16IS750_REG_IIR) & 0x01);
  }

  /// Returns the type of interrupt event for the channel
  int interruptEventTest(SC16IS752_Channel channel) {
    uint8_t irq_src;

    irq_src = readRegister(channel, SC16IS750_REG_IIR);
    // irq_src = (irq_src >> 1);
    // irq_src &= 0x3F;
    irq_src &= 0x3E;

    switch (irq_src) {
      case 0x06:  // Receiver Line Status Error
        return SC16IS750_RECEIVE_LINE_STATUS_ERROR;
      case 0x0c:  // Receiver time-out interrupt
        return SC16IS750_RECEIVE_TIMEOUT_INTERRUPT;
      case 0x04:  // RHR interrupt
        return SC16IS750_RHR_INTERRUPT;
      case 0x02:  // THR interrupt
        return SC16IS750_THR_INTERRUPT;
      case 0x00:  // modem interrupt;
        return SC16IS750_MODEM_INTERRUPT;
      case 0x30:  // input pin change of state
        return SC16IS750_INPUT_PIN_CHANGE_STATE;
      case 0x10:  // XOFF
        return SC16IS750_RECEIVE_XOFF;
      case 0x20:  // CTS,RTS
        return SC16IS750_CTS_RTS_CHANGE;
      default:
        return -1;
    }
    return -1;
  }

  /// Configures GPIO pin interrupt settings
  void setPinInterrupt(uint8_t io_int_ena) {
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOINTENA, io_int_ena);
    return;
  }

  /// Enables RS485 mode on the specified channel
  /// @param invert_rts true to invert RTS signal, false for normal RTS signal
  void enableRs485(SC16IS752_Channel channel, bool invert_rts) {
    uint8_t temp_efcr;
    temp_efcr = readRegister(channel, SC16IS750_REG_EFCR);
    if (!invert_rts) {
      temp_efcr |= 0x20;
    } else {
      temp_efcr |= 0x30;
    }
    writeRegister(channel, SC16IS750_REG_EFCR, temp_efcr);

    return;
  }

  /// Enables or disables transmission on the specified channel
  void enableTransmit(SC16IS752_Channel channel, uint8_t tx_enable) {
    uint8_t temp_efcr;
    temp_efcr = readRegister(channel, SC16IS750_REG_EFCR);
    if (tx_enable == 0) {
      temp_efcr |= 0x04;
    } else {
      temp_efcr &= 0xFB;
    }
    writeRegister(channel, SC16IS750_REG_EFCR, temp_efcr);

    return;
  }

  /// Initializes the SC16IS752 device state on an already configured bus
  void initializeDevice() {
    if (!is_active) {
      if (spi_bus != nullptr) {
        ::pinMode(device_address_sspin, OUTPUT);
        ::digitalWrite(device_address_sspin, HIGH);
      }
      resetDevice();
      is_active = true;
    }
  }

  /// Returns the current state of all GPIO pins as a bitmask.
  uint8_t gpioGetPortState(void) {
    return readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOSTATE);
  }

  /// Writes interrupt enable flags for the selected UART channel.
  void interruptControl(SC16IS752_Channel channel, uint8_t int_ena) {
    writeRegister(channel, SC16IS750_REG_IER, int_ena);
  }

  /// Selects whether upper IO pins operate as modem pins or GPIO pins.
  void modemPin(uint8_t gpio) {  // gpio == 0, gpio[7:4] are modem pins, gpio ==
                                 // 1 gpio[7:4] are gpios
    uint8_t temp_iocontrol;

    temp_iocontrol =
        readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL);
    if (gpio == 0) {
      temp_iocontrol |= 0x02;
    } else {
      temp_iocontrol &= 0xFD;
    }
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL,
                  temp_iocontrol);

    return;
  }

  /// Enables or disables GPIO output latching behavior.
  void gpioLatch(uint8_t latch) {
    uint8_t temp_iocontrol;

    temp_iocontrol =
        readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL);
    if (latch == 0) {
      temp_iocontrol &= 0xFE;
    } else {
      temp_iocontrol |= 0x01;
    }
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL,
                  temp_iocontrol);

    return;
  }

  /// Configures baud rate divisor and returns error in parts-per-thousand.
  int16_t setBaudrate(
      SC16IS752_Channel channel,
      uint32_t baudrate) {  // return error of baudrate parts per thousand
    uint16_t divisor;
    uint8_t prescaler;
    uint32_t actual_baudrate;
    int16_t error;
    uint8_t temp_lcr;
    if ((readRegister(channel, SC16IS750_REG_MCR) & 0x80) ==
        0) {  // if prescaler==1
      prescaler = 1;
    } else {
      prescaler = 4;
    }

    divisor = (crystal_freq / prescaler) / (baudrate * 16);

    temp_lcr = readRegister(channel, SC16IS750_REG_LCR);
    temp_lcr |= 0x80;
    writeRegister(channel, SC16IS750_REG_LCR, temp_lcr);
    // write to DLL
    writeRegister(channel, SC16IS750_REG_DLL, (uint8_t)divisor);
    // write to DLH
    writeRegister(channel, SC16IS750_REG_DLH, (uint8_t)(divisor >> 8));
    temp_lcr &= 0x7F;
    writeRegister(channel, SC16IS750_REG_LCR, temp_lcr);

    actual_baudrate = (crystal_freq / prescaler) / (16 * divisor);
    error = ((float)actual_baudrate - baudrate) * 1000 / baudrate;
    if (logger) {
      logger->debug("Desired baudrate: %d", baudrate);
      logger->debug("Calculated divisor: %d", divisor);
      logger->debug("Actual baudrate: %d", actual_baudrate);
      logger->debug("Baudrate error: %d", (int)error);
    }

    return error;
  }

  /// Reads one register byte from the selected channel via I2C or SPI.
  uint8_t readRegister(SC16IS752_Channel channel, uint8_t reg_addr) {
    uint8_t result;
    if (wire_bus != nullptr) {  // register read operation via I2C
      wire_bus->beginTransmission(device_address_sspin);
      wire_bus->write((reg_addr << 3 | channel << 1));
      wire_bus->endTransmission(0);
      wire_bus->requestFrom(device_address_sspin, (uint8_t)1);
      result = wire_bus->read();
    } else if (spi_bus != nullptr) {  // register read operation via SPI
      spi_bus->beginTransaction(spi_settings);
      ::digitalWrite(device_address_sspin, LOW);
      delayMicroseconds(10);
      spi_bus->transfer(0x80 | ((reg_addr << 3 | channel << 1)));
      result = spi_bus->transfer(0xff);
      delayMicroseconds(10);
      ::digitalWrite(device_address_sspin, HIGH);
      spi_bus->endTransaction();
    } else {
      result = 0;
    }
    if (logger) {
      logger->debug("ReadRegister ch=%X reg=%X res=%X", channel,
                    (reg_addr << 3 | channel << 1), result);
    }
    return result;
  }

  /// Writes one register byte to the selected channel via I2C or SPI.
  void writeRegister(SC16IS752_Channel channel, uint8_t reg_addr, uint8_t val) {
    if (logger) {
      logger->debug("WriteRegister ch=%X reg=%X val=%X", channel,
                    (reg_addr << 3 | channel << 1), val);
    }

    if (wire_bus != nullptr) {  // register write operation via I2C
      wire_bus->beginTransmission(device_address_sspin);
      wire_bus->write((reg_addr << 3 | channel << 1));
      wire_bus->write(val);
      wire_bus->endTransmission(1);
    } else {  // register write operation via SPI
      spi_bus->beginTransaction(spi_settings);
      ::digitalWrite(device_address_sspin, LOW);
      delayMicroseconds(10);
      spi_bus->transfer((reg_addr << 3 | channel << 1));
      spi_bus->transfer(val);
      delayMicroseconds(10);
      ::digitalWrite(device_address_sspin, HIGH);
      spi_bus->endTransaction();
    }
    return;
  }

  /// Configures line format by data bits, parity mode, and stop bits.
  void setLine(SC16IS752_Channel channel, uint8_t data_length,
               uint8_t parity_select, uint8_t stop_length) {
    uint8_t temp_lcr;
    temp_lcr = readRegister(channel, SC16IS750_REG_LCR);
    temp_lcr &= 0xC0;  // Clear the lower six bit of LCR (LCR[0] to LCR[5]
    if (logger) {
      logger->debug("LCR Register: %d", temp_lcr);
    }
    switch (data_length) {  // data length settings
      case 5:
        break;
      case 6:
        temp_lcr |= 0x01;
        break;
      case 7:
        temp_lcr |= 0x02;
        break;
      case 8:
        temp_lcr |= 0x03;
        break;
      default:
        temp_lcr |= 0x03;
        break;
    }

    if (stop_length == 2) {
      temp_lcr |= 0x04;
    }

    // parity selection length settings
    switch (parity_select) {
      case 0:  // no parity
        break;
      case 1:  // odd parity
        temp_lcr |= 0x08;
        break;
      case 2:  // even parity
        temp_lcr |= 0x18;
        break;
      case 3:  // force '1' parity
        temp_lcr |= 0x03;
        break;
      case 4:  // force '0' parity
        break;
      default:
        break;
    }

    writeRegister(channel, SC16IS750_REG_LCR, temp_lcr);
  }

  /// Configures data bits, parity, and stop bits from an Arduino SERIAL_* value
  void setLine(SC16IS752_Channel channel, uint32_t config) {
    uint8_t data_length = 8;
    uint8_t parity_select = 0;
    uint8_t stop_length = 1;

    if (!decodeSerialConfig(config, &data_length, &parity_select,
                            &stop_length)) {
      if (logger) {
        logger->warn("Unsupported serial config %lu, using SERIAL_8N1",
                     (unsigned long)config);
      }
    }

    setLine(channel, data_length, parity_select, stop_length);
  }

  /// Sets GPIO pin as input or output (OUTPUT or INPUT)
  void pinMode(uint8_t pin, uint8_t io) { gpioSetPinMode(pin, io); }

  /// Sets GPIO pin output level (HIGH or LOW)
  void digitalWrite(uint8_t pin, uint8_t value) { gpioSetPinState(pin, value); }

  /// Reads GPIO pin level (returns 0 or 1)
  uint8_t digitalRead(uint8_t pin) { return gpioGetPinState(pin); }

  /// Sets one GPIO pin direction (`OUTPUT` or `INPUT`).
  void gpioSetPinMode(uint8_t pin_number, uint8_t i_o) {
    uint8_t temp_iodir;

    temp_iodir = readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IODIR);
    if (i_o == OUTPUT) {
      temp_iodir |= (0x01 << pin_number);
    } else {
      temp_iodir &= (uint8_t)~(0x01 << pin_number);
    }

    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IODIR, temp_iodir);
    return;
  }

  /// Sets one GPIO output pin state (`HIGH` or `LOW`).
  void gpioSetPinState(uint8_t pin_number, uint8_t pin_state) {
    uint8_t temp_iostate;

    temp_iostate = readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOSTATE);
    if (pin_state == 1) {
      temp_iostate |= (0x01 << pin_number);
    } else {
      temp_iostate &= (uint8_t)~(0x01 << pin_number);
    }

    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOSTATE, temp_iostate);
    return;
  }

  /// Reads one GPIO pin state and returns 0 or 1.
  uint8_t gpioGetPinState(uint8_t pin_number) {
    uint8_t temp_iostate;

    temp_iostate = readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOSTATE);
    if ((temp_iostate & (0x01 << pin_number)) == 0) {
      return 0;
    }
    return 1;
  }

  /// Sets direction of all GPIO pins using a bitmask.
  void gpioSetPortMode(uint8_t port_io) {
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IODIR, port_io);
    return;
  }

  /// Sets output state of all GPIO pins using a bitmask.
  void gpioSetPortState(uint8_t port_state) {
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOSTATE, port_state);
    return;
  }

  /// Issues a software reset to the SC16IS752 device.
  void resetDevice() {
    uint8_t reg;

    reg = readRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL);
    reg |= 0x08;
    writeRegister(SC16IS752_CHANNEL_BOTH, SC16IS750_REG_IOCONTROL, reg);

    return;
  }

  /// Enables or disables FIFO for the selected channel.
  void fifoEnable(SC16IS752_Channel channel, uint8_t fifo_enable) {
    uint8_t temp_fcr;

    temp_fcr = readRegister(channel, SC16IS750_REG_FCR);

    if (fifo_enable == 0) {
      temp_fcr &= 0xFE;
    } else {
      temp_fcr |= 0x01;
    }
    writeRegister(channel, SC16IS750_REG_FCR, temp_fcr);

    return;
  }

  /// Resets RX or TX FIFO for the selected channel.
  void fifoReset(SC16IS752_Channel channel, uint8_t rx_fifo) {
    uint8_t temp_fcr;

    temp_fcr = readRegister(channel, SC16IS750_REG_FCR);

    if (rx_fifo == 0) {
      temp_fcr |= 0x04;
    } else {
      temp_fcr |= 0x02;
    }
    writeRegister(channel, SC16IS750_REG_FCR, temp_fcr);

    return;
  }

  /// Sets RX or TX FIFO trigger level for interrupt generation.
  void fifoSetTriggerLevel(SC16IS752_Channel channel, uint8_t rx_fifo,
                           uint8_t length) {
    uint8_t temp_reg;

    temp_reg = readRegister(channel, SC16IS750_REG_MCR);
    temp_reg |= 0x04;
    writeRegister(channel, SC16IS750_REG_MCR,
                  temp_reg);  // SET MCR[2] to '1' to use TLR register or
                              // trigger level control in FCR register

    temp_reg = readRegister(channel, SC16IS750_REG_EFR);
    writeRegister(
        channel, SC16IS750_REG_EFR,
        temp_reg | 0x10);  // set ERF[4] to '1' to use the  enhanced features
    if (rx_fifo == 0) {
      writeRegister(channel, SC16IS750_REG_TLR,
                    length << 4);  // Tx FIFO trigger level setting
    } else {
      writeRegister(channel, SC16IS750_REG_TLR,
                    length);  // Rx FIFO Trigger level setting
    }
    writeRegister(channel, SC16IS750_REG_EFR,
                  temp_reg);  // restore EFR register

    return;
  }

  /// Returns number of bytes currently available in RX FIFO.
  uint8_t fifoAvailableData(SC16IS752_Channel channel) {
    uint8_t avail = readRegister(channel, SC16IS750_REG_RXLVL);
    if (logger) {
      logger->debug("Available data: %d", avail);
    }
    return avail;
  }

  /// Returns free space currently available in TX FIFO.
  uint8_t fifoAvailableSpace(SC16IS752_Channel channel) {
    return readRegister(channel, SC16IS750_REG_TXLVL);
  }

  /// Writes one byte to TX holding register when transmitter is ready.
  void writeByte(SC16IS752_Channel channel, uint8_t val) {
    uint8_t tmp_lsr;

    do {
      tmp_lsr = readRegister(channel, SC16IS750_REG_LSR);
    } while ((tmp_lsr & 0x20) == 0);

    writeRegister(channel, SC16IS750_REG_THR, val);
  }

  /// Reads one byte from RX holding register, or -1 when no data is available.
  int readByte(SC16IS752_Channel channel) {
    volatile uint8_t val;
    if (fifoAvailableData(channel) == 0) {
      if (logger) {
        logger->debug("No data available");
      }
      return -1;
    } else {
      if (logger) {
        logger->debug("Data available");
      }
      val = readRegister(channel, SC16IS750_REG_RHR);
      return val;
    }
  }

  /// Decodes Arduino `SERIAL_*` format into data bits, parity, and stop bits.
  bool decodeSerialConfig(uint32_t config, uint8_t* data_length,
                          uint8_t* parity_select, uint8_t* stop_length) {
    switch (config) {
      case SERIAL_5N1:
        *data_length = 5;
        *parity_select = 0;
        *stop_length = 1;
        return true;
      case SERIAL_6N1:
        *data_length = 6;
        *parity_select = 0;
        *stop_length = 1;
        return true;
      case SERIAL_7N1:
        *data_length = 7;
        *parity_select = 0;
        *stop_length = 1;
        return true;
      case SERIAL_8N1:
        *data_length = 8;
        *parity_select = 0;
        *stop_length = 1;
        return true;
      case SERIAL_5N2:
        *data_length = 5;
        *parity_select = 0;
        *stop_length = 2;
        return true;
      case SERIAL_6N2:
        *data_length = 6;
        *parity_select = 0;
        *stop_length = 2;
        return true;
      case SERIAL_7N2:
        *data_length = 7;
        *parity_select = 0;
        *stop_length = 2;
        return true;
      case SERIAL_8N2:
        *data_length = 8;
        *parity_select = 0;
        *stop_length = 2;
        return true;
      case SERIAL_5E1:
        *data_length = 5;
        *parity_select = 2;
        *stop_length = 1;
        return true;
      case SERIAL_6E1:
        *data_length = 6;
        *parity_select = 2;
        *stop_length = 1;
        return true;
      case SERIAL_7E1:
        *data_length = 7;
        *parity_select = 2;
        *stop_length = 1;
        return true;
      case SERIAL_8E1:
        *data_length = 8;
        *parity_select = 2;
        *stop_length = 1;
        return true;
      case SERIAL_5E2:
        *data_length = 5;
        *parity_select = 2;
        *stop_length = 2;
        return true;
      case SERIAL_6E2:
        *data_length = 6;
        *parity_select = 2;
        *stop_length = 2;
        return true;
      case SERIAL_7E2:
        *data_length = 7;
        *parity_select = 2;
        *stop_length = 2;
        return true;
      case SERIAL_8E2:
        *data_length = 8;
        *parity_select = 2;
        *stop_length = 2;
        return true;
      case SERIAL_5O1:
        *data_length = 5;
        *parity_select = 1;
        *stop_length = 1;
        return true;
      case SERIAL_6O1:
        *data_length = 6;
        *parity_select = 1;
        *stop_length = 1;
        return true;
      case SERIAL_7O1:
        *data_length = 7;
        *parity_select = 1;
        *stop_length = 1;
        return true;
      case SERIAL_8O1:
        *data_length = 8;
        *parity_select = 1;
        *stop_length = 1;
        return true;
      case SERIAL_5O2:
        *data_length = 5;
        *parity_select = 1;
        *stop_length = 2;
        return true;
      case SERIAL_6O2:
        *data_length = 6;
        *parity_select = 1;
        *stop_length = 2;
        return true;
      case SERIAL_7O2:
        *data_length = 7;
        *parity_select = 1;
        *stop_length = 2;
        return true;
      case SERIAL_8O2:
        *data_length = 8;
        *parity_select = 1;
        *stop_length = 2;
        return true;
      default:
        *data_length = 8;
        *parity_select = 0;
        *stop_length = 1;
        return false;
    }
  }
};

using SC16IS752_Channel = SC16IS752::SC16IS752_Channel;
