#pragma once
class MemorySlot
{
public:
	MemorySlot* prev;
	MemorySlot* next;

	unsigned char data;

	explicit MemorySlot(MemorySlot* prev)
	{
		this->prev = prev;
		this->next = nullptr;
		this->data = 0;
	}
};

