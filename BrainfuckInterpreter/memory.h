#ifndef MEMORY_H_
#define MEMORY_H_

#include "./memory_slot.h"

class Memory {
public:
  explicit Memory(int size);

  explicit Memory();

  ~Memory();

  bool prev();
  bool next();

  void increment() const;
  void decrement() const;

  unsigned char get() const;
  void set(unsigned char input) const;

  bool notNull() const;

private:
  MemorySlot *list_;
  MemorySlot *current_;
  const int DEFAULT_SIZE = 10;
};

#endif // MEMORY_H_
