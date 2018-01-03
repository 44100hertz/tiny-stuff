#include <stdio.h>
#include <stdlib.h>

struct sexp {
        char name[256];
        struct sexp *child, *next;
};

static struct sexp *sexp_parse(FILE *f, char close);
static void sexp_print(struct sexp *exp);

int main()
{
        struct sexp *exp = sexp_parse(stdin, ')');
        sexp_print(exp);
}

struct sexp *sexp_parse(FILE *f, char close)
{
        struct sexp *exp = calloc(1, sizeof(struct sexp));
        char *name = exp->name;
        char inspace = 0, firstword = 1;

        for(;;) {
                char c = fgetc(f);
                if (c == close) return exp;
                switch (c) {
                case '(': exp->child = sexp_parse(f, ')'); break;
                case ' ': firstword = 0;
                          inspace = 1;
                          break;
                case ')': if (close == ' ') ungetc(c, f); // fallthru
                case EOF: return exp;
                default :
                          if (inspace) {
                                  ungetc(c, f);
                                  exp->next = sexp_parse(f, ' ');
                          } else if (firstword) {
                                  *(name++) = c;
                          }
                          inspace = 0;
                }
        }
}

static void sexp_print(struct sexp *exp)
{
        printf("%s", exp->name);
        if (exp->next) {
                printf(" ");
                sexp_print(exp->next);
        }
        if (exp->child) {
                printf("(");
                sexp_print(exp->child);
                printf(")");
        }
}
