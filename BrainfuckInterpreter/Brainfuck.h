#pragma once
#include <string>
#include "Memory.h"


class Brainfuck
{
 public:
  explicit Brainfuck(std::string code);

  bool run();
 private:
  Memory* memory;
  std::string code;
  std::string output;

  bool run(unsigned start, unsigned end);
  bool Brainfuck::read(unsigned char& output) const;
};

