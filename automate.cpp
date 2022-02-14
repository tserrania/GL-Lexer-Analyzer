#include "automate.h"
#include "etat.h"
#include <iostream>

Automate::~Automate(){
   while (!etats.empty()) {
      delete etats.top();
      etats.pop();
   }
   while (!symboles.empty()) {
      delete symboles.top();
      symboles.pop();
   }
   viderCache();
}

int Automate::Executer(Etat* init) {
   etats.push(init);
   int termine;
   do {
      dernier_symbole = lexer->Consulter();
      termine = DernierEtat()->transition(*this);
      viderCache();
      Avancer();
      // cout << "Symbole " << (int) (*DernierSymbole()) << " Etats " << symboles.size() << endl;
   } while (!termine);
   if (termine==1) {
      erreur = false;
      return DernierSymbole()->GetValeur();
   } else {
      erreur = true;
      return 0;
   }
}
bool Automate::IsErrone() {
   return erreur;
}
void Automate::Reduire() {
   reduction = true;
}
void Automate::Avancer() {
   if (!reduction) {
      Symbole* s = lexer->Consulter();
      lexer->Avancer();
      PushSymbole(s);
   }
   reduction = false;
}

void Automate::PushEtat(Etat* e) {
   etats.push(e);
}
void Automate::PushSymbole(Symbole* s) {
   // cout << "SYMB PUSH " << Etiquettes[(int) *s] << endl;
   symboles.push(s);
   dernier_symbole = s;
}
Symbole* Automate::PopEtatSymbole() {
   etats_supprimes.push(etats.top());
   etats.pop();
   Symbole* s = symboles.top();
   // cout << "SYMB POP  " << Etiquettes[(int) *s] << endl;
   symboles_supprimes.push(s);
   symboles.pop();
   return s;
}
Symbole* Automate::DernierSymbole() {
   return dernier_symbole;
}
Etat* Automate::DernierEtat() {
   return etats.top();
}

void Automate::viderCache() {
   while (!etats_supprimes.empty()) {
      delete etats_supprimes.top();
      etats_supprimes.pop();
   }
   while (!symboles_supprimes.empty()) {
      delete symboles_supprimes.top();
      symboles_supprimes.pop();
   }
}