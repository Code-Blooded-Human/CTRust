#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include"calc_ast.h"

struct symbol symbtab[999];

unsigned int symhash(char *sym) {
  unsigned int hash=0;
  unsigned c;

  while(c = *sym++) hash=hash*9^c;

  return hash;
}

struct symbol *lookup(char *symb) {
  struct symbol *sp = &symbtab[symhash(symb)%999];
  int scount=999;
  while(--scount >=0) {
    if(sp->name && !strcmp(sp->name,symb)) return sp;

    if(!sp->name) {
      sp->name = strdup(symb);
      sp->value=0;
      return sp;
    }
    
    if(++sp >= symbtab+999) sp=symbtab;
  }
  yyerror("Symbol table overflow");
  exit(1);
}


struct ast *newast(int nodetype,struct ast *l,struct ast *r) {
  struct ast *new = malloc(sizeof(struct ast));
  if (!new) {
    yyerror("out of space");
    exit(0);
  }
  new->nodetype = nodetype;
  new->l=l;
  new->r=r;
  return new;
}

struct ast *newnum(int i) {
  struct numval *new = malloc(sizeof(struct numval));
  if (!new) {
    yyerror("out of space");
    exit(0);
  }
  new->nodetype = 'A';
  new->val=i;
  return (struct ast *)new;
}

struct ast *newref(struct symbol *s){
  struct symref *new = malloc(sizeof(struct symref));
  if (!new) {
    yyerror("out of space");
    exit(0);
  }
  new->nodetype = 'I';
  new->s=s;
  return (struct ast *)new;
}
  

struct ast *newasgn(struct symbol *s,struct ast *exp){
  struct asgnm *new = malloc(sizeof(struct asgnm));
  if (!new) {
    yyerror("out of space");
    exit(0);
  }
  new->nodetype = '=';
  new->s=s;
  new->exp=exp;
  return (struct ast *)new;
}
  

int eval(struct ast *a) {
  int v;

  switch(a->nodetype) {
  case 'A': v=((struct numval *)a)->val;
    break;
  case 'I': v=((struct symref *)a)->s->value;
    break;
  case '=': v = ((struct asgnm *)a)->s->value = eval(((struct asgnm *)a)->exp);
    break;
  case '+': v=eval(a->l)+eval(a->r);
    break;
  case '-': v=eval(a->l)-eval(a->r);
    break;
  case '*': v=eval(a->l)*eval(a->r);
    break;
  case '/': v=eval(a->l)/eval(a->r);
    break;
  case '|': v=eval(a->l); if(v<0) v=-v;
    break;
  default:
    printf("Unknown Character");
  }
  return v;
}

void treefree(struct ast *a) {
  switch(a->nodetype) {
  case '+':
  case '-':
  case '*':
  case '/':
    treefree(a->r);
  case '|':
    treefree(a->l);
    break;
  case '=':
    treefree(((struct asgnm *)a)->exp);
    break;
  }
  free(a);
}
