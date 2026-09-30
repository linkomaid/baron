#include <ctype.h>
#include <string.h>

#include "lexer.h";

static char LexerCurrent(Lexer *lexer) {
    if (lexer->position >= lexer->length)
        return '\0';

    return lexer->source[lexer->position];
}