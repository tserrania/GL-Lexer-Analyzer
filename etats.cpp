#include "etats.h"
#include <iostream>

int Etat0::transition(Automate& a) {
    // cout << "ET0" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case OPENPAR:
            e = new Etat2();
            a.PushEtat(e);
            break;
        case INT:
            e = new Etat3();
            a.PushEtat(e);
            break;
        case EXPR:
            e = new Etat1();
            a.PushEtat(e);
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat1::transition(Automate& a) {
    // cout << "ET1" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case PLUS:
            e = new Etat4();
            a.PushEtat(e);
            break;
        case MULT:
            e = new Etat5();
            a.PushEtat(e);
            break;
        case FIN:
            termine = 1;
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat2::transition(Automate& a) {
    // cout << "ET2" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case OPENPAR:
            e = new Etat2();
            a.PushEtat(e);
            break;
        case INT:
            e = new Etat3();
            a.PushEtat(e);
            break;
        case EXPR:
            e = new Etat6();
            a.PushEtat(e);
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat3::transition(Automate& a) {
    // cout << "ET3" << endl;
    Symbole* val = a.PopEtatSymbole();
    a.InterdireConsultation();
    Symbole* expr = new Expr(val->GetValeur());
    a.PushSymbole(expr);
    return 0;
}
int Etat4::transition(Automate& a) {
    // cout << "ET4" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case OPENPAR:
            e = new Etat2();
            a.PushEtat(e);
            break;
        case INT:
            e = new Etat3();
            a.PushEtat(e);
            break;
        case EXPR:
            e = new Etat7();
            a.PushEtat(e);
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat5::transition(Automate& a) {
    // cout << "ET5" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case OPENPAR:
            e = new Etat2();
            a.PushEtat(e);
            break;
        case INT:
            e = new Etat3();
            a.PushEtat(e);
            break;
        case EXPR:
            e = new Etat8();
            a.PushEtat(e);
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat6::transition(Automate& a) {
    // cout << "ET6" << endl;
    int termine = 0;
    a.Avancer();
    Symbole* s = a.DernierSymbole();
    Etat* e;
    switch ((int) (*s)) {
        case PLUS:
            e = new Etat4();
            a.PushEtat(e);
            break;
        case MULT:
            e = new Etat5();
            a.PushEtat(e);
            break;
        case CLOSEPAR:
            e = new Etat9();
            a.PushEtat(e);
            break;
        default:
            termine = 2;
            break;
    }
    return termine;
}
int Etat7::transition(Automate& a) {
    // cout << "ET7" << endl;
    Symbole* s = a.Consulter();
    Etat* e;
    switch ((int) (*s)) {
        case MULT:
            e = new Etat5();
            a.Avancer();
            a.PushEtat(e);
            break;
        default:
            Symbole* val1 = a.PopEtatSymbole();
            a.PopEtatSymbole();
            Symbole* val2 = a.PopEtatSymbole();
            a.InterdireConsultation();
            Symbole* expr = new Expr(val1->GetValeur()+val2->GetValeur());
            a.PushSymbole(expr);
            break;
    }
    return 0;
}
int Etat8::transition(Automate& a) {
    // cout << "ET8" << endl;
    Symbole* val1 = a.PopEtatSymbole();
    a.PopEtatSymbole();
    Symbole* val2 = a.PopEtatSymbole();
    a.InterdireConsultation();
    Symbole* expr = new Expr(val1->GetValeur()*val2->GetValeur());
    a.PushSymbole(expr);
    return 0;
}
int Etat9::transition(Automate& a) {
    // cout << "ET9" << endl;
    a.PopEtatSymbole();
    Symbole* val = a.PopEtatSymbole();
    a.PopEtatSymbole();
    a.InterdireConsultation();
    Symbole* expr = new Expr(val->GetValeur());
    a.PushSymbole(expr);
    return 0;
}
