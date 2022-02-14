#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etats.h"

void parse(string& chaine) {
   Lexer l(chaine);
   Automate a(&l);
   cout << chaine << " = " << a.Executer(new Etat0()) << endl;
}

int main(int argc, char* argv[]) {
   int i;
   for (i=1;i<argc;++i) {
      string s(argv[i]);
      parse(s);
   }
   return 0;
}