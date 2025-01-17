#include "Brainfuck.h"
#include <iostream>
#include <string>


bool Brainfuck::run(unsigned start, unsigned end)
{
  for (int i = start; i < end; ++i)
  {
    switch (code[i])
    {
    case '<':
    {
      if (!memory->prev())
      {
        return false;
      }
      break;
    }
    case '>':
    {
      if (!memory->next())
      {
        return false;
      }
      break;
    }
    case '-':
    {
      memory->decrement();
      break;
    }
    case '+':
    {
      memory->increment();
      break;
    }
    case '.':
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
      break;
    }
    case ',':
    {
      unsigned char input;
      while (!read(input)) continue;
      memory->set(input);
      break;
    }
    case '[':
    {
      unsigned brackets = 1;
      unsigned closingPos = ++i;
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
        std::cout << "Could not find a matching bracket for pos " << i - 1 << std::endl;
        return false;
      }

      while (memory->notNull())
      {
        if (!run(i, closingPos))
        {
          return false;
        }
      }

      i = closingPos;
      break;
    }
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

  if (run(0, code.length()))
  {
    std::cout << output << std::endl;
    return true;
  }

  delete this->memory;
  return false;
}

