

#include <iostream>
#include <string>

#include "brainfuck.h"

int main() {
  std::string const code =
      ""
      "  +++++ +++++             initialize counter (cell #0) to 10"
      "  [                       use loop to set 70/100/30/10"
      "      > +++++ ++              add  7 to cell #1"
      "      > +++++ +++++           add 10 to cell #2"
      "      > +++                   add  3 to cell #3"
      "      > +                     add  1 to cell #4"
      "  <<<< -                  decrement counter (cell #0)"
      "  ]"
      "  > ++ .                  print 'H'"
      "  > + .                   print 'e'"
      "  +++++ ++ .              print 'l'"
      "  .                       print 'l'"
      "  +++ .                   print 'o'"
      "  > ++ .                  print ' '"
      "  << +++++ +++++ +++++ .  print 'W'"
      "  > .                     print 'o'"
      "  +++ .                   print 'r'"
      "  ----- - .               print 'l'"
      "  ----- --- .             print 'd'"
      "  > + .                   print '!'"
      "  > .                     print '\n'";

  Brainfuck Interpreter(code);

  if (Interpreter.Run()) {
    std::cout << "Success!" << std::endl;
#ifdef _WIN32
    system("pause");
#endif // _WIN32
    return 0;
  }

  std::cout << "Failure!" << std::endl;
#ifdef _WIN32
  system("pause");
#endif // _WIN32
  return 1;
}
