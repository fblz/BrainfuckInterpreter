#include "Brainfuck.h"
#include <iostream>

bool Brainfuck::run(int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		if (code[i] == '<')
		{
			if (!memory->prev())
			{
				return false;
			}
		}
		else if (code[i] == '>')
		{
			if (!memory->next())
			{
				return false;
			}
		}
		else if (code[i] == '-')
		{
			memory->decrement();
		}
		else if (code[i] == '+')
		{
			memory->increment();
		}
		else if (code[i] == '.')
		{
			unsigned char cell = memory->get();
			if (cell == 10)
			{
				output += "\n";
			}
			else
			{
				output += cell;
			}
		}
		else if (code[i] == ',')
		{
			unsigned char input;
			while (!read(input)){}
			memory->set(input);
		}
		else if (code[i] == '[')
		{
			int brackets = 1;
			int closingPos = i + 1;
			bool match = false;

			for (; closingPos < end; ++closingPos)
			{
				if (code[closingPos] == '[')
				{
					++brackets;
				}
				else if (code[closingPos] == ']')
				{
					--brackets;
					match = brackets == 0;
					break;
				}
			}

			if (!match)
			{
				std::cout << "Could not find a matching bracket for pos " << i << std::endl;
				return false;
			}

			while (memory->notNull())
			{
				if (!run(i + 1, closingPos))
				{
					return false;
				}
			}

			i = closingPos;
		}
	}

	return true;
}

bool Brainfuck::read(unsigned char& output) const
{
	std::string byte;

	std::cout << "Input one byte as hex [FF]: ";
	std::getline(std::cin, byte);

	if (byte.length() != 2)
	{
		return false;
	}

	if (byte[0] >= '0' && byte[0] <= '9')
	{
		output += (byte[0] - '0') * 16;
	}
	else if (byte[0] >= 'A' && byte[0] <= 'F')
	{
		output += (byte[0] - 'A' + 10) * 16;
	}
	else if (byte[0] >= 'a' && byte[0] <= 'f')
	{
		output += (byte[0] - 'a' + 10) * 16;
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		return false;
	}

	if (byte[1] >= '0' && byte[1] <= '9')
	{
		output += byte[1] - '0';
	}
	else if (byte[1] >= 'A' && byte[1] <= 'F')
	{
		output += byte[1] - 'A' + 10;
	}
	else if (byte[1] >= 'a' && byte[1] <= 'f')
	{
		output += byte[1] - 'a' + 10;
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		return false;
	}

	return true;
}

Brainfuck::Brainfuck(std::string code)
{
	this->code = code;
}

bool Brainfuck::run()
{
	this->memory = new Memory(100);
	this->output = "";

	if(run(0, code.length()))
	{
		std::cout << output << std::endl;
		return true;
	}

	delete this->memory;
	return false;
}

