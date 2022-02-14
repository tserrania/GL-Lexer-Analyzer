#pragma once

#include "automate.h"
using namespace std;

class Etat {
   public:
      Etat() {  }
      virtual ~Etat() { }
      virtual int transition(Automate& a) = 0;

   protected:
};
