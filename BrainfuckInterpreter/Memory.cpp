#include "Memory.h"

Memory::Memory(int size)
{
	this->list = new MemorySlot(nullptr);
	this->current = this->list;
	MemorySlot* tmp = this->list;
	
	for (int i = 1; i < size; i++)
	{
		MemorySlot* next = new MemorySlot(tmp);
		tmp->next = next;
		tmp = next;
	}
}

Memory::Memory()
{
	this->list = new MemorySlot(nullptr);
	this->current = this->list;
	MemorySlot* tmp = this->list;

	for (int i = 1; i < this->DEFAULT_SIZE; i++)
	{
		MemorySlot* next = new MemorySlot(tmp);
		tmp->next = next;
		tmp = next;
	}
}

Memory::~Memory()
{
	for (MemorySlot* ptr = this->list; ptr !=nullptr; )
	{
		MemorySlot* tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
}

bool Memory::prev()
{
	if (this->current->prev != nullptr)
	{
		this->current = this->current->prev;
		return true;
	}

	return false;
}

bool Memory::next()
{
	if (this->current->next != nullptr)
	{
		this->current = this->current->next;
		return true;
	}

	this->current->next = new MemorySlot(this->current);
	this->current = this->current->next;
	return true;
}

void Memory::increment() const
{
	this->current->data++;
}

void Memory::decrement() const
{
	this->current->data--;
}

unsigned char Memory::get() const
{
	return this->current->data;
}

void Memory::set(unsigned char input) const
{
	this->current->data = input;
}

bool Memory::notNull() const
{
	return this->current->data != 0;
}
