#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;
static size_t allocations = 0;
static string *strings = NULL;

long get_long(const char *format, ...);
string get_string(va_list *args, const char *format, ...);

long first_digit(long n) {
  while (n >= 10) {
    n /= 10;
  }

  return n;
}

long second_digit(long n) {
  while (n >= 100) {
    n /= 10;
  }

  return n % 10;
}

long get_length(long n) {
  int result = 0;

  while (n > 0) {
    result++;
    n /= 10;
  }

  return result;
}

int main() {
  long credit_card_number = get_long("Number: ");
  int length = get_length(credit_card_number);

  if (length != 13 && length != 15 && length != 16) {
    printf("INVALID\n");
    return 1;
  }

  int result = 0;

  long temp = credit_card_number;
  while (temp >= 1) {
    temp /= 10;
    int digit = temp % 10;
    int val = digit * 2;
    while (val > 0) {
      result += (val % 10);
      val /= 10;
    }
    temp /= 10;
  }

  temp = credit_card_number;
  while (temp >= 1) {
    int digit = temp % 10;
    result += digit;
    temp /= 100;
  }

  int last_digit = result % 10;

  if (last_digit != 0) {
    printf("INVALID\n");
    return 1;
  }

  int first = first_digit(credit_card_number);
  int second = second_digit(credit_card_number);

  if (first == 4) {
    printf("VISA\n");
    return 0;
  }

  int sum = (first * 10) + second;

  if (sum == 34 || sum == 37) {
    printf("AMEX\n");
    return 0;
  }

  if (sum == 51 || sum == 52 || sum == 53 || sum == 54 || sum == 55) {
    printf("MASTERCARD\n");
    return 0;
  }

  printf("INVALID\n");
}

// CS50 provided code
long get_long(const char *format, ...) {
  va_list ap;
  va_start(ap, format);

  while (true) {
    string line = get_string(&ap, format);
    if (line == NULL) {
      va_end(ap);
      return LONG_MAX;
    }

    if (strlen(line) > 0 && !isspace((unsigned char)line[0])) {
      char *tail;
      long n = strtol(line, &tail, 10);
      if (*tail == '\0' && n < LONG_MAX) {
        va_end(ap);
        return n;
      }
    }
  }
}

string get_string(va_list *args, const char *format, ...) {
  // Check whether we have room for another string
  if (allocations == SIZE_MAX / sizeof(string)) {
    return NULL;
  }

  // Growable buffer for characters
  string buffer = NULL;

  // Capacity of buffer
  size_t capacity = 0;

  // Number of characters actually in buffer
  size_t size = 0;

  // Character read or EOF
  int c;

  // Prompt user
  if (format != NULL) {
    // Initialize variadic argument list
    va_list ap;

    // Students' code will pass in printf-like arguments as variadic
    // parameters. The student-facing get_string macro always sets args to
    // NULL. In this case, we initialize the list of variadic parameters
    // the standard way with va_start.
    if (args == NULL) {
      va_start(ap, format);
    }

    // When functions in this library call get_string they will have
    // already stored their variadic parameters in a `va_list` and so they
    // just pass that in by pointer.
    else {
      // Put a copy of argument list in ap so it is not consumed by vprintf
      va_copy(ap, *args);
    }

    // Print prompt
    vprintf(format, ap);

    // Clean up argument list
    va_end(ap);
  }

  // Iteratively get characters from standard input, checking for CR (Mac OS), LF (Linux), and CRLF (Windows)
  while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF) {
    // Grow buffer if necessary
    if (size + 1 > capacity) {
      // Increment buffer's capacity if possible
      if (capacity < SIZE_MAX) {
        capacity++;
      } else {
        free(buffer);
        return NULL;
      }

      // Extend buffer's capacity
      string temp = realloc(buffer, capacity);
      if (temp == NULL) {
        free(buffer);
        return NULL;
      }
      buffer = temp;
    }

    // Append current character to buffer
    buffer[size++] = c;
  }

  // Check whether user provided no input
  if (size == 0 && c == EOF) {
    return NULL;
  }

  // Check whether user provided too much input (leaving no room for trailing NUL)
  if (size == SIZE_MAX) {
    free(buffer);
    return NULL;
  }

  // If last character read was CR, try to read LF as well
  if (c == '\r' && (c = fgetc(stdin)) != '\n') {
    // Return NULL if character can't be pushed back onto standard input
    if (c != EOF && ungetc(c, stdin) == EOF) {
      free(buffer);
      return NULL;
    }
  }

  // Minimize buffer
  string s = realloc(buffer, size + 1);
  if (s == NULL) {
    free(buffer);
    return NULL;
  }

  // Terminate string
  s[size] = '\0';

  // Resize array so as to append string
  string *tmp = realloc(strings, sizeof(string) * (allocations + 1));
  if (tmp == NULL) {
    free(s);
    return NULL;
  }
  strings = tmp;

  // Append string to array
  strings[allocations] = s;
  allocations++;

  // Return string
  return s;
}
