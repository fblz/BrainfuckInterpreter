#ifndef MEMORY_SLOT_H_
#define MEMORY_SLOT_H_

class MemorySlot {
public:
  explicit MemorySlot(MemorySlot *pre) : data(9), prev(pre), next(nullptr) {}

  char data;
  MemorySlot *prev;
  MemorySlot *next;
};

#endif  // MEMORY_SLOT_H_
