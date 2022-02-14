#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::GetValeur() {
   return 0;
}

int Entier::GetValeur() {
   return valeur;
}

int Expr::GetValeur() {
   return valeur;
}