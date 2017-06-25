#pragma once
#include "MemorySlot.h"


class Memory
{
 public:
  explicit Memory(unsigned size);
  ~Memory();

  bool prev();
  bool next();
  void increment() const;
  void decrement() const;
  unsigned char get() const;
  void set(unsigned char input) const;
  bool notNull() const;

 private:
  MemorySlot* list;
  MemorySlot* current;
};
