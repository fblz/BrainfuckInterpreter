#ifndef MEMORY_SLOT_H_
#define MEMORY_SLOT_H_

class MemorySlot {
public:
  explicit MemorySlot(MemorySlot *pre) {
    prev = pre;
    next = nullptr;
    data = 0;
  }

  unsigned char data;
  MemorySlot *prev;
  MemorySlot *next;
};

#endif  // MEMORY_SLOT_H_
