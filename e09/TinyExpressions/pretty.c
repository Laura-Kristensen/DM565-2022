#include <stdio.h>
#include "pretty.h"

void prettyEXP(EXP *e)
{ switch (e->kind) {
    case idK:
         printf("%s",e->val.idE);
         break;
    case intconstK:
         printf("%i",e->val.intconstE);
         break;
    case timesK:
         printf("(");
         prettyEXP(e->val.timesE.left);
         printf("*");
         prettyEXP(e->val.timesE.right);
         printf(")");
         break;
    case divK:
         printf("(");
         prettyEXP(e->val.divE.left);
         printf("/");
         prettyEXP(e->val.divE.right);
         printf(")");
         break;
    case plusK:
         printf("(");
         prettyEXP(e->val.plusE.left);
         printf("+");
         prettyEXP(e->val.plusE.right);
         printf(")");
         break;
    case minusK:
         printf("(");
         prettyEXP(e->val.minusE.left);
         printf("-");
         prettyEXP(e->val.minusE.right);
         printf(")");
         break;
  case andK:
    printf("(");
    prettyEXP(e->val.andE.left);
    printf("&&");
    prettyEXP(e->val.andE.right);
    printf(")");
    break;
  case orK:
    printf("(");
    prettyEXP(e->val.orE.left);
    printf("||");
    prettyEXP(e->val.orE.right);
    printf(")");
    break;
  case leqK:
    printf("(");
    prettyEXP(e->val.leqE.left);
    printf("<=");
    prettyEXP(e->val.leqE.right);
    printf(")");
    break;
  case lesK:
    printf("(");
    prettyEXP(e->val.lesE.left);
    printf("<");
    prettyEXP(e->val.lesE.right);
    printf(")");
    break;
  case eqK:
    printf("(");
    prettyEXP(e->val.eqE.left);
    printf("==");
    prettyEXP(e->val.eqE.right);
    printf(")");
    break;
  case notK:
    printf("!");
    prettyEXP(e->val.notE.exp);
    break;
  }
}
