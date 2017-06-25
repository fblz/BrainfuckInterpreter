#include "./brainfuck.h"

#include <iostream>

bool Brainfuck::Run_(unsigned start, unsigned end) {

  char cell;
  char input;
  char comp;

  int brackets{1};
  bool match {false};

  unsigned closingPos{};


  for (unsigned i{start}; i < end; ++i) {
    comp = code_.at(i);
    switch(comp) {
    case '<':
      if (!memory_->Prev()) { return false; }
      break;
    case '>':
      if (!memory_->Next()) { return false; }
      break;
    case '-':
      memory_->Decrement();
      break;
    case '+':
      memory_->Increment();
      break;
    case '.':
      cell = memory_->Get();
      if (cell == 10) {
        output_ += "\n";
      } else {
        output_ += cell;
      }
      break;
    case ',':
      while (!Read_(input)) {}
       memory_->Set(input);
       break;
    case '[':
      closingPos = ++i;
      for (; closingPos < end; ++closingPos) {
         if (code_.at(closingPos) == '[') {
           ++brackets;
         } else if (code_.at(closingPos) == ']') {
           --brackets;
           match = brackets == 0;
           break;
         }
       }
       if (!match) {
         std::cout << "Could not find a matching bracket for pos " << i
                   << std::endl;
         return false;
       }

       while (memory_->NotNull()) {
         if (!Run_(i + 1, closingPos)) {
           return false;
         }
       }
       i = closingPos;
    }
  }
  return true;
}

bool Brainfuck::Read_(char &output) const {
  std::string byte;

  std::cout << "Input one byte as hex [FF]: ";
  std::getline(std::cin, byte);

  if (byte.length() != 2) {
    return false;
  }

  if (byte[0] >= '0' && byte[0] <= '9') {
    output += (byte[0] - '0') * 16;
  } else if (byte[0] >= 'A' && byte[0] <= 'F') {
    output += (byte[0] - 'A' + 10) * 16;
  } else if (byte[0] >= 'a' && byte[0] <= 'f') {
    output += (byte[0] - 'a' + 10) * 16;
  } else {
    std::cout << "Invalid input" << std::endl;
    return false;
  }

  if (byte[1] >= '0' && byte[1] <= '9') {
    output += byte[1] - '0';
  } else if (byte[1] >= 'A' && byte[1] <= 'F') {
    output += byte[1] - 'A' + 10;
  } else if (byte[1] >= 'a' && byte[1] <= 'f') {
    output += byte[1] - 'a' + 10;
  } else {
    std::cout << "Invalid input" << std::endl;
    return false;
  }

  return true;
}

Brainfuck::Brainfuck(std::string code) { code_ = code; }

bool Brainfuck::Run() {
  this->memory_ = new Memory(100);
  this->output_ = "";

  if (Run_(0, static_cast<unsigned int>(code_.length()))) {
    std::cout << output_ << std::endl;
    return true;
  }

  delete memory_;
  return false;
}
