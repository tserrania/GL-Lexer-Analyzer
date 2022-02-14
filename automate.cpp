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

Symbole* Automate::Consulter() {
   return lexer->Consulter();
}
void Automate::Avancer() {
   if (consultation) {
      Symbole* s = lexer->Consulter();
      lexer->Avancer();
      symboles.push(s);
   }
   consultation = true;
}

void Automate::InterdireConsultation() {
   consultation = false;
}

void Automate::PushEtat(Etat* e) {
   etats.push(e);
}
void Automate::PushSymbole(Symbole* s) {
   symboles.push(s);
}
Symbole* Automate::PopEtatSymbole() {
   etats_supprimes.push(etats.top());
   etats.pop();
   Symbole* s = symboles.top();
   symboles_supprimes.push(s);
   symboles.pop();
   return s;
}
Symbole* Automate::DernierSymbole() {
   return symboles.top();
}
Etat* Automate::DernierEtat() {
   return etats.top();
}
int Automate::Executer(Etat* init) {
   etats.push(init);
   int termine;
   do {
      termine = DernierEtat()->transition(*this);
      viderCache();
      //cout << "Symbole " << (int) (*DernierSymbole()) << " Etats " << symboles.size() << endl;
   } while (!termine);
   if (termine==1) {
      symboles_supprimes.push(symboles.top());
      symboles.pop();
      return symboles.top()->GetValeur();
   } else {
      return 0;
   }
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