#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::GetValeur() {
   return 0;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::GetValeur() {
   return valeur;
}

void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
int Expr::GetValeur() {
   return valeur;
}