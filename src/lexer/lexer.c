#include <ctype.h>
#include <string.h>

#include "lexer.h"

static char LexerCurrent(Lexer *lexer) {

    if (lexer->position >= lexer->length)
        return '\0';

    return lexer->source[lexer->position];
}

static char LexerPeek(Lexer *lexer) {

    if (lexer->position + 1>= lexer->length)
        return '\0';

    return lexer->source[lexer->position + 1];
}

static void LexerAdvance(Lexer *lexer) {
    
    if (lexer->position < lexer->length)
        lexer->position++;
}

static void LexerSkipWhitespace(Lexer *lexer) {

    while(
        isspace(
            (unsigned char)
            LexerCurrent(lexer)
        )
    )

    LexerAdvance(lexer);
}


// Helper - Makes the code prettier.
static Token MakeToken(Token_type type, const char *lexeme) {
    
    return (Token) { type, lexeme };
}


void LexerInit(Lexer *lexer, const char *source) {

    lexer->source = source;
    lexer->position = 0;
    lexer->length = strlen(source);
}


Token LexerNextToken(Lexer *lexer) {

    LexerSkipWhitespace(lexer);

    char current = LexerCurrent(lexer);

    if (current == '\0')  
        return (Token) { TOKEN_EOF, "" };

    switch (current) {

        case '=':
            if (LexerPeek(lexer) == '=') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_EQUAL_EQUAL, "==");
            }
            
            LexerAdvance(lexer); 
            
            return MakeToken(TOKEN_EQUAL, "=");

        case '!':
            if (LexerPeek(lexer) == '=') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_NOT_EQUAL, "!=");
            }

            break;

        case '%':
            LexerAdvance(lexer);

            return MakeToken(TOKEN_MODULO, "%");
        
        case '|':
            if (LexerPeek(lexer) == '|') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_OR, "||");
            }
            
            break;
        
        case '<':
            if (LexerPeek(lexer) == '>') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_EXPLICIT, "<>");
            }

            break;

        case '-':
            if (LexerPeek(lexer) == '>') {
                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_ARROW, "->");
            }
        
            break;

        
        case ':':
            LexerAdvance(lexer);
            return MakeToken(TOKEN_COLON, ":");
        
        case '{': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LBRACE, "{"); 
            
        case '}': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RBRACE, "}"); 
            
        case '[': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LBRACKET, "["); 
            
        case ']': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RBRACKET, "]"); 
            
        case '(': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LPAREN, "("); 
            
        case ')': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RPAREN, ")");



        default:
            break;
    }


    // Handles UNKNOWN character

    LexerAdvance(lexer);

    return MakeToken(TOKEN_EOF, "");

}