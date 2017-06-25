#ifndef MEMORY_H_
#define MEMORY_H_

#include "./memory_slot.h"

class Memory {
public:

  Memory(int size = 10);
  ~Memory();

  bool Prev();
  bool Next();

  void Increment() const;
  void Decrement() const;

  unsigned char Get() const;
  void Set(const unsigned char input) const;

  bool NotNull() const;

  int Size();

private:
  MemorySlot *list_;
  MemorySlot *current_;
};

#endif // MEMORY_H_
