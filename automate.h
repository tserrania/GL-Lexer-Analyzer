#pragma once

#include "lexer.h"
#include <stack>
using namespace std;

class Etat;

class Automate {
   public:
      Automate(Lexer* l) : lexer(l), reduction(false), erreur(false), dernier_symbole(nullptr) {  }
      int Executer(Etat* init);
      bool IsErrone();
      void Reduire();
      void Avancer();
      void PushEtat(Etat* e);
      void PushSymbole(Symbole* s);
      Symbole* PopEtatSymbole();
      Symbole* DernierSymbole();
      Etat* DernierEtat();
      virtual ~Automate();

   protected:
      void viderCache();
      
      Lexer* lexer;
      stack<Etat*> etats; 
      stack<Symbole*> symboles; 
      stack<Etat*> etats_supprimes; 
      stack<Symbole*> symboles_supprimes; 
      Symbole* dernier_symbole;
      bool reduction;
      bool erreur;
};
