#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_

#include "memory.h"

#include <string>

class Brainfuck {
public:
  explicit Brainfuck(std::string code);
  bool Run();

private:
  Memory *memory_;
  std::string code_;
  std::string output_;

  bool Run_(unsigned start, unsigned end);
  bool Read_(char &output) const;

};

#endif // BRAINFUCK_H_
