#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etats.h"

void parse(string& chaine) {
   Lexer l(chaine);
   Automate a(&l);
   cout << chaine << " = " << a.Executer(new Etat0()) << endl;
}

void test1() {
   string chaine("6*7");
   parse(chaine);
}

void test2() {
   string chaine("6*7+4");
   parse(chaine);
}

void test3() {
   string chaine("4+6*7");
   parse(chaine);
}

void test4() {
   string chaine("(4+6)*7");
   parse(chaine);
}
void test5() {
   string chaine("4+(6*7)");
   parse(chaine);
}
void test6() {
   string chaine("7+4*((10*11+67*2)*4+4+(6*7))+2*5+(52*86)+2");
   parse(chaine);
}
void test7() {
   string chaine("(((3+4))))");
   parse(chaine);
}
void test8() {
   string chaine("4+*6");
   parse(chaine);
}
void test9() {
   string chaine("6+*4");
   parse(chaine);
}
void test10() {
   string chaine(")(");
   parse(chaine);
}
void test11() {
   string chaine("()");
   parse(chaine);
}
void test12() {
   string chaine("(3&6)");
   parse(chaine);
}
void test13() {
   string chaine("(3.1+1)");
   parse(chaine);
}
void test14() {
   string chaine("2+3(");
   parse(chaine);
}

int main(void) {
   test1();
   test2();
   test3();
   test4();
   test5();
   test6();
   test7();
   test8();
   test9();
   test10();
   test11();
   test12();
   test13();
   test14();
   return 0;
}