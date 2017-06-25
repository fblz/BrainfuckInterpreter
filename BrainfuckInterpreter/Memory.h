#pragma once
#include "MemorySlot.h"

class Memory
{

	MemorySlot* list;
	MemorySlot* current;
	const int DEFAULT_SIZE = 10;

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

};

