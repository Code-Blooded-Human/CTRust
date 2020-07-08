extern int yylineno;
void yyerror(char *s);

struct symbol {
  char *name;
  int value;
};

struct symbol *lookup(char *);

struct ast {
  int nodetype;
  struct ast *l;
  struct ast *r;
};

struct numval {
  int nodetype;
  int val;
};

struct symref {
  int nodetype;
  struct symbol *s;
};

struct asgnm {
  int nodetype;
  struct symbol *s;
  struct ast *exp;
};

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(int num);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s,struct ast *exp);

int eval(struct ast *);

void treefree(struct ast *);

