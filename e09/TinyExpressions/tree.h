#ifndef __tree_h
#define __tree_h

typedef struct EXP {
  int lineno;
  enum {idK,intconstK,timesK,divK,plusK,minusK,andK,orK,notK,lesK,leqK,eqK} kind;
  union {
    char *idE;
    int intconstE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
    struct {struct EXP *left; struct EXP *right;} andE;
    struct {struct EXP *left; struct EXP *right;} orE;
    struct {struct EXP *left; struct EXP *right;} lesE;
    struct {struct EXP *left; struct EXP *right;} leqE;
    struct {struct EXP *left; struct EXP *right;} eqE;
    struct {struct EXP *exp;} notE;
  } val;
} EXP;
 
EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP *makeEXPand(EXP *left, EXP *right);

EXP *makeEXPor(EXP *left, EXP *right);

EXP *makeEXPles(EXP *left, EXP *right);

EXP *makeEXPleq(EXP *left, EXP *right);

EXP *makeEXPeq(EXP *left, EXP *right);

EXP *makeEXPnot(EXP *exp);

#endif
