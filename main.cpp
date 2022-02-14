#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etats.h"

void parse(string& chaine) {
   Lexer l(chaine);
   Automate a(&l);
   int res = a.Executer(new Etat0());
   if (a.IsErrone()) {
      cout << chaine << " = " << "ERREUR" << endl;
   }
   else {
      cout << chaine << " = " << res << endl;
   }
}

int main(int argc, char* argv[]) {
   int i;
   for (i=1;i<argc;++i) {
      string s(argv[i]);
      parse(s);
   }
   return 0;
}