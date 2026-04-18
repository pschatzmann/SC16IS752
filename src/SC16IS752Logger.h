/*
SC16IS752 Logger - Logging utility for SC16IS752 dual UART
*/

#pragma once

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Arduino.h"

/// Simple logger for SC16IS752 channels with variadic parameter support and log levels
class SC16IS752Logger {
 public:
  /// Log levels
  enum LogLevel {
    LEVEL_DEBUG = 0,
    LEVEL_INFO = 1,
    LEVEL_WARNING = 2,
    LEVEL_ERROR = 3,
    LEVEL_CRITICAL = 4,
    LEVEL_NONE = 5
  };

  SC16IS752Logger(Stream& stream, LogLevel level = LEVEL_INFO) 
      : stream_(stream), log_level_(level) {}

  /// Set the current log level
  void setLogLevel(LogLevel level) { log_level_ = level; }

  /// Get the current log level
  LogLevel getLogLevel() { return log_level_; }

  /// Log a formatted debug message
  void debug(const char* format, ...) {
    if (log_level_ <= LEVEL_DEBUG) {
      write("[DEBUG] ");
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      newline();
    }
  }

  /// Log a formatted info message
  void info(const char* format, ...) {
    if (log_level_ <= LEVEL_INFO) {
      write("[INFO] ");
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      newline();
    }
  }

  /// Log a formatted warning message
  void warn(const char* format, ...) {
    if (log_level_ <= LEVEL_WARNING) {
      write("[WARN] ");
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      newline();
    }
  }

  /// Log a formatted error message
  void error(const char* format, ...) {
    if (log_level_ <= LEVEL_ERROR) {
      write("[ERROR] ");
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      newline();
    }
  }

  /// Log a formatted critical message
  void critical(const char* format, ...) {
    if (log_level_ <= LEVEL_CRITICAL) {
      write("[CRITICAL] ");
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      newline();
    }
  }

  /// Log a formatted message with variadic parameters (respects log level LEVEL_DEBUG)
  void log(const char* format, ...) {
    if (log_level_ <= LEVEL_DEBUG) {
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
    }
  }

  /// Log with newline (respects log level LEVEL_DEBUG)
  void logln(const char* format, ...) {
    if (log_level_ <= LEVEL_DEBUG) {
      va_list args;
      va_start(args, format);
      vlog(format, args);
      va_end(args);
      stream_.write('\n');
    }
  }

  /// Log a simple string
  void write(const char* str) { stream_.write((const uint8_t*)str, strlen(str)); }

  /// Log a single character
  void write(char c) { stream_.write(c); }

  /// Log an integer
  void write(int value) { stream_.print(value); }

  /// Log an unsigned integer
  void write(unsigned int value) { stream_.print(value); }

  /// Log a long integer
  void write(long value) { stream_.print(value); }

  /// Log an unsigned long integer
  void write(unsigned long value) { stream_.print(value); }

  /// Log a floating point number
  void write(float value) { stream_.print(value); }

  /// Log a floating point number with precision
  void write(float value, int precision) { stream_.print(value, precision); }

  /// Log a newline
  void newline() { stream_.write('\n'); }

 private:
  Stream& stream_;
  LogLevel log_level_;

  /// Internal variadic logging implementation
  void vlog(const char* format, va_list args) {
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    stream_.write((const uint8_t*)buffer, strlen(buffer));
  }
};
