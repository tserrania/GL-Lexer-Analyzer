#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "(", ")", "+", "*", "val", "end", "error", "expr" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      virtual int GetValeur();
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual int GetValeur();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int v) : Symbole(EXPR), valeur(v) { }
      ~Expr() { }
      virtual int GetValeur();
   protected:
      int valeur;
};