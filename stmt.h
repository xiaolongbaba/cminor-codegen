// stmt.h
// John Riordan

#ifndef STMT_H
#define STMT_H

#include "decl.h"
#include "misc.h"

extern struct type* return_type;

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_kind_t;

struct stmt {
	stmt_kind_t kind;
	struct decl* decl;
	struct expr* init_expr;
	struct expr* expr;
	struct expr* next_expr;
	struct stmt* body;
	struct stmt* else_body;
	struct stmt* next;
};

struct stmt* stmt_create( stmt_kind_t kind, struct decl* d, struct expr* init_expr, struct expr* e, struct expr* next_expr, struct stmt* body, struct stmt* else_body, struct stmt* next );

void stmt_indent( int indent );
void stmt_print( struct stmt* s, int indent );
void stmt_resolve( struct stmt* s );
void stmt_typecheck( struct stmt* s );
void stmt_codegen( struct stmt* s );
void stmt_codegen_print( struct expr* e );
int stmt_count_locals( struct stmt* s );

#endif
