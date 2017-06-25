#include "./memory.h"

Memory::Memory(int size) {
  list_ = new MemorySlot(nullptr);
  current_ = list_;
  MemorySlot *tmp = list_;

  for (int i = 1; i < size; i++) {
    MemorySlot *next = new MemorySlot(tmp);
    tmp->next = next;
    tmp = next;
  }
}

Memory::Memory() {
  list_ = new MemorySlot(nullptr);
  current_ = list_;
  MemorySlot *tmp = list_;

  for (int i = 1; i < DEFAULT_SIZE; i++) {
    MemorySlot *next = new MemorySlot(tmp);
    tmp->next = next;
    tmp = next;
  }
}

Memory::~Memory() {
  for (MemorySlot *ptr = list_; ptr != nullptr;) {
    MemorySlot *tmp = ptr;
    ptr = ptr->next;
    delete tmp;
  }
}

bool Memory::prev() {
  if (current_->prev != nullptr) {
    current_ = current_->prev;
    return true;
  }

  return false;
}

bool Memory::next() {
  if (current_->next != nullptr) {
    current_ = current_->next;
    return true;
  }

  current_->next = new MemorySlot(current_);
  current_ = current_->next;
  return true;
}

void Memory::increment() const { current_->data++; }

void Memory::decrement() const { current_->data--; }

unsigned char Memory::get() const { return current_->data; }

void Memory::set(unsigned char input) const { current_->data = input; }

bool Memory::notNull() const { return current_->data != 0; }
