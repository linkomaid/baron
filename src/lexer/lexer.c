#include <ctype.h>
#include <string.h>

#include "lexer.h"

void LexerInit(Lexer *lexer, const char *source) {

    lexer->source = source;
    lexer->position = 0;
    lexer->length = strlen(source);
}

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
static Token MakeToken(
    Token_type type, 
    const char *lexeme,
    size_t length
) {
    
    return (Token) { type, lexeme, length };
}


static int LexerIdentifierStart(char character) {
    return isalpha((unsigned char)character) || character == '_';
}

static int LexerIdentifierPart(char character) {
    return isalnum((unsigned char)character) || character == '_';
}

typedef struct
{
    const char *name;
    Token_type type;
} Keyword;

static const Keyword keywords[] =
{
    { "var",    TOKEN_VAR },
    { "func",   TOKEN_FUNC },
    { "if",     TOKEN_IF },
    { "loop",   TOKEN_LOOP },
    { "end",    TOKEN_END },
    { "return", TOKEN_RETURN },
    { "as",     TOKEN_AS },
    { "const",  TOKEN_CONST },

    { "str",    TOKEN_TYPE_STR },
    { "int",    TOKEN_TYPE_INT },
    { "float",  TOKEN_TYPE_FLOAT },
    { "bool",   TOKEN_TYPE_BOOL },
    { "char",   TOKEN_TYPE_CHAR },
    { "unique", TOKEN_TYPE_UNIQUE },
    { "None",   TOKEN_TYPE_NONE }
};

static int LexerMatchKeyword(
    const char *lexeme,
    size_t length,
    const char *keyword
) {

    return strlen(keyword) == length &&
        strncmp(lexeme, keyword, length) == 0;
}

static Token_type LexerKeyword(
    const char *lexeme,
    size_t length
) {

    size_t count = sizeof(keywords) / sizeof(keywords[0]);

    for (size_t i = 0; i < count; i++) {

        if (LexerMatchKeyword(
            lexeme,
            length,
            keywords[i].name
        )) {
            return keywords[i].type;
        }
    }

    return TOKEN_IDENTIFIER;
}

static Token LexerReadIdentifier(Lexer *lexer) {

    size_t start = lexer->position;

    while (LexerIdentifierPart(LexerCurrent(lexer)))
        LexerAdvance(lexer);

    size_t length = lexer->position - start;

    const char *lexeme = lexer->source + start;

    Token_type type = LexerKeyword(lexeme, length);

    return MakeToken(type, lexeme, length);
}

Token LexerNextToken(Lexer *lexer) {

    LexerSkipWhitespace(lexer);

    char current = LexerCurrent(lexer);

    if (current == '\0')  
        return (Token) { TOKEN_EOF, "", 0 };

    if (LexerIdentifierStart(current))
        return LexerReadIdentifier(lexer);

    switch (current) {

        case '=':
            if (LexerPeek(lexer) == '=') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_EQUAL_EQUAL, "==", 2);
            }
            
            LexerAdvance(lexer); 
            
            return MakeToken(TOKEN_EQUAL, "=", 1);

        case '!':
            if (LexerPeek(lexer) == '=') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_NOT_EQUAL, "!=", 2);
            }

            break;

        case '%':
            LexerAdvance(lexer);

            return MakeToken(TOKEN_MODULO, "%", 1);
        
        case '|':
            if (LexerPeek(lexer) == '|') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_OR, "||", 2);
            }
            
            break;
        
        case '<':
            if (LexerPeek(lexer) == '>') {

                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_EXPLICIT, "<>", 2);
            }

            break;

        case '-':
            if (LexerPeek(lexer) == '>') {
                LexerAdvance(lexer);
                LexerAdvance(lexer);

                return MakeToken(TOKEN_ARROW, "->", 2);
            }
        
            break;

        
        case ':':
            LexerAdvance(lexer);
            return MakeToken(TOKEN_COLON, ":", 1);
        
        case '{': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LBRACE, "{", 1); 
            
        case '}': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RBRACE, "}", 1); 
            
        case '[': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LBRACKET, "[", 1); 
            
        case ']': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RBRACKET, "]", 1); 
            
        case '(': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_LPAREN, "(", 1); 
            
        case ')': 
            LexerAdvance(lexer); 
            return MakeToken(TOKEN_RPAREN, ")", 1);



        default: 
            break;
    }

    const char *lexeme = lexer->source + lexer->position;
    LexerAdvance(lexer);

    return MakeToken(TOKEN_UNKNOWN, lexeme, 1);
}