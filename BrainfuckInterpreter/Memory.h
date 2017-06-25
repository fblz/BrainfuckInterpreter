#pragma once
#include "MemorySlot.h"

class Memory
{
  explicit Memory(unsigned size);

	MemorySlot* list;
	MemorySlot* current;
	const int DEFAULT_SIZE = 10;

public:

	~Memory();

	bool prev();
	bool next();

	void increment() const;
	void decrement() const;

	unsigned char get() const;
	void set(unsigned char input) const;

	bool notNull() const;

};

