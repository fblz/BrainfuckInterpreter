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

Memory::~Memory() {
  for (MemorySlot *ptr = list_; ptr != nullptr;) {
    MemorySlot *tmp = ptr;
    ptr = ptr->next;
    delete tmp;
  }
}

bool Memory::Prev() {
  if (current_->prev != nullptr) {
    current_ = current_->prev;
    return true;
  }

  return false;
}

bool Memory::Next() {
  if (current_->next != nullptr) {
    current_ = current_->next;
    return true;
  }

  current_->next = new MemorySlot(current_);
  current_ = current_->next;
  return true;
}

void Memory::Increment() const { current_->data++; }

void Memory::Decrement() const { current_->data--; }

char Memory::Get() const { return current_->data; }

void Memory::Set(char input) const { current_->data = input; }

bool Memory::NotNull() const { return current_->data != 0; }
