#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_

#include "memory.h"

#include <string>

class Brainfuck {
public:
  explicit Brainfuck(std::string code);
  bool run();

private:
  Memory *memory;
  std::string code;
  std::string output;

  bool run(int start, int end);
  bool read(unsigned char &output) const;

};

#endif // BRAINFUCK_H_
