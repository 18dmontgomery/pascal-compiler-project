#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PGMNAME 1
#define PGMPARM 2
#define AREAL 3
#define AINT 4

#define FUNPINT 5
#define FUNPREAL 6
#define FUNPAINT 7
#define FUNPAREAL 8

#define FUNNAME 9

#define PROG 11
#define ID 12
#define OP 13
#define COMMA 14
#define CP 15
#define SEMICOLON 16
#define VAR 17
#define COLON 18
#define OB 19
#define DOT 20
#define DOTDOT 21
#define CB 22
#define INTNUM 23
#define REAL 24
#define FUNCTION 25
#define PROC 26
#define BEGIN 27
#define END 28
#define ASSIGNOP 29
#define IF 30
#define THEN 31
#define ELSE 32
#define WHILE 33
#define DO 34
#define RELOP 35
#define EQ 36
#define NEQ 37
#define LT 38
#define LE 39
#define GE 40
#define GT 41
#define NOT 42
#define ARRAY 43
#define OF 44
#define INTEGER 45
#define WS 46
#define LONGREAL 47
#define PLUS 48
#define ENDFILE 49
#define NIL 50
#define MINUS 51
#define MULTIPLY 52
#define DOLLAR 53
#define EPSILON 54
#define NUM 55
#define ADDOP 56
#define MULOP 57
#define OR 58
#define DIVIDE 59
#define DIV 60
#define AND 61
#define MOD 62
#define REALNUM 63
#define GREENNODE 64
#define BLUENODE 65
#define BOOL 66
#define OK 67

#define LEXERR 999
#define ERR1 901
#define ERR2 902
#define ERR3 903
#define ERR4 904
#define ERR5 905
#define ERR6 906
#define ERR7 907
#define ERR8 908
#define ERR9 911
#define SEMERR 909
#define ERR 910
#define ERRSTAR 911
#define ERRSTARSTAR 912


typedef struct token token;

struct token {
    char lex[20];
    char tokenname[10];
    int type;
    char attname[10];
    union tokenattr{
        int att;
        void* address;
    }types;
    token* next;
    token* nextGreen;
    token* prev;
    int colorNode;
    char parm[10];
    int resType;

};

void prog();
void progTail();
void progTailTail();
void idlst();
void idlstTail();
void decs();
void decsTail();
int type();
int stype();
void sdecs();
void sdecsTail();
void sdec();
void sdecTail();
void sdecTailTail();
void shead();
void sheadTail();
void args();
void plist();
void plistTail();
void cstmt();
void cstmtTail();
void ostmts();
void slist();
void slistTail();
int stmt();
void stmtTail();
int variable();
int variableTail();
int elist();
int elistTail();
int expr();
int exprTail();
int sexpr();
int sexprTail();
int term();
int termTail();
int fctr();
int fctrTail();
void sign();





token *tokenList;
token *idList;
token *nodeList;
int err2 = 0;
int err3 = 0;
int err4 = 0;
int err5 = 0;
int err6 = 0;
int err7 = 0;
int err8 = 0;
int err9 = 1;
int endOfLine = 0;
FILE *address;
FILE *listing;
FILE *tokenOutput;
FILE *input;
char tempLet = 'a';
int test = 0;
token *tok;
char* globFront;
char* globBack;
int count = 0;
int eofCheck = 0;
int c;
int i = 1;
int b = 0;
int nLine = 0;
char buffer[72];
char *ptr;
int nL = 1;
int newLine = 1;
int i2 = 0;
char lex2[20];
int t = 0;
token *eye;
int parmCount = 0;
int funType = 0;
int func = 0;
char param[10];
int parmCheck = 0;
char paramList[10];
int elistOutput;
int expectedParms;
int offset;
int offset2;
token *lastGreenNode;
int arrayParam = 0;
int eListCheck = 0;
int addopCheck = 0;


