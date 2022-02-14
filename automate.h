#pragma once

#include "lexer.h"
#include <stack>
using namespace std;

class Etat;

class Automate {
   public:
      Automate(Lexer* l) : lexer(l), consultation(true) {  }
      virtual ~Automate();
      void InterdireConsultation();
      Symbole* Consulter();
      void Avancer();
      void PushEtat(Etat* e);
      void PushSymbole(Symbole* s);
      Symbole* PopEtatSymbole();
      Symbole* DernierSymbole();
      Etat* DernierEtat();
      int Executer(Etat* init);

   protected:
      void viderCache();
      
      Lexer* lexer;
      stack<Etat*> etats; 
      stack<Symbole*> symboles; 
      stack<Etat*> etats_supprimes; 
      stack<Symbole*> symboles_supprimes; 
      bool consultation;
};
