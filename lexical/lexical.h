#pragma once

#include <stdio.h>
#include <iostream>

class Lexical {
public:
  enum State {
    S0 = '0',
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    UNKNOWN,
    STATE_COUNT
  };

  Lexical(void) {
    output_ = "Lexical Analysis Result\n\nCategoryNo.\tValue\n";
  }

  ~Lexical(void) {  }

  friend std::istream& operator>>(std::istream& is, Lexical& lexcial) {
    is >> lexcial.buffer_;
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Lexical& lexcial) {
    os << lexcial.output_.c_str();
    return os;
  }

  char* usage() {
    static char usage[] = "This Lexical Program could analysis simple sequence made up of"
      " digit and operators.\nIn this demo we use std::cin to grap the input,\n"
      "please don't use blankspace within the input. Have a nice day:)\n";
    return usage;
  }

  char operator_category(char o) const {
    // op  +  -  *  /  (  )
    // key  2  3  4  5  6  7
    //code 43 45 42 47 40 41
    // index 3  5  2  7  0  1
    static const int op_hash[8] = { '6', '7', '4', '2', -1, '3', -1, '5' };
    const int index = o - 40;
    if (index > 7 || index < 0)
      return -1;
    return op_hash[index];
  }

  State NextState(State cur, char c) const {
    static const State operator_hash_map[7][9] = {
      { S1, S3, S0, S0, S0, S0, S0, S0, UNKNOWN },
      { S1, S2, S0, S0, S0, S0, S0, S0, S4 },
      { S1, UNKNOWN, S0, S0, S0, S0, S0, S0, S4 },
      { S2, UNKNOWN, S0, S0, S0, S0, S0, S0, UNKNOWN },
      { S6, UNKNOWN, S5, S5, S0, S0, S0, S0, UNKNOWN },
      { S6, UNKNOWN, S0, S0, S0, S0, S0, S0, UNKNOWN },
      { S6, UNKNOWN, S0, S0, S0, S0, S0, S0, UNKNOWN },
    };

    int row = cur - S0;
    int col = -1;
    if (c >= '0' && c <= '9')
      col = 0;
    else if (c == '.')
      col = 1;
    else if (c == '+')
      col = 2;
    else if (c == '-')
      col = 3;
    else if (c == '*')
      col = 4;
    else if (c == '/')
      col = 5;
    else if (c == '(')
      col = 6;
    else if (c == ')')
      col = 7;
    else if (c == 'E')
      col = 8;

    if (row >= 0 && row < 7 && col >= 0 && col < 9)
      return operator_hash_map[row][col];
    return UNKNOWN;
  }

  void Analysis() {
    int input_len = strlen(buffer_);
    if (!input_len)
      return;

    State state = S0;
    int prev_i = 0;  // for digit more than one bit
    int i = 0;
    for (; i < input_len;/* ++i*/) {
      if (state == UNKNOWN)
        break;

      state = NextState(state, buffer_[i]);

      if (buffer_[i] == '+' || buffer_[i] == '-' || buffer_[i] == '*' ||
        buffer_[i] == '/' || buffer_[i] == '(' || buffer_[i] == ')') {
          if (i - prev_i > 0) {
            output_ += "1\t\t";
            for (int j = prev_i; j < i; ++j)
              output_ += buffer_[j];
            output_ += '\n';
          }
          output_ += operator_category(buffer_[i]);
          output_ += "\n";
          prev_i = ++i;
      } else {
        ++i;
      }
    }

    if (state == UNKNOWN) {
      output_ = "\n";
      output_ += "This Lexical Program only could process\nDigits And Operators\nPlease check your input!\n";
      output_ += "Finished!";
    } else if (i - prev_i > 0) {
      output_ += "1\t\t";
      for (int j = prev_i; j < i; ++j)
        output_ += buffer_[j];
      output_ += '\n';
    }
  }

private:
  static const int kInputBufferSize = 100;

  std::string output_;
  char buffer_[kInputBufferSize];
};

