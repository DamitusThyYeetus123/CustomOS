#include "print.h"
#include "time.h"
const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character, color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;


void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    struct Char cursor = (struct Char) {
        character: '_',
        color: color,
    };
    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void scroll(size_t rows) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    struct Char cursor = (struct Char) {
        character: '_',
        color: color,
    };
    for (size_t i = 0; i < NUM_COLS * NUM_ROWS; i++){
        if(i >= NUM_COLS * (NUM_ROWS - rows)) {
            buffer[i] = empty;
        }
        else
        {
            buffer[i] = buffer[i + NUM_COLS * rows];
        }
    }

}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    struct Char cursor = (struct Char) {
        character: '_',
        color: color,
    };
    buffer[col + NUM_COLS * row] = empty;
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        buffer[col + NUM_COLS * row] = cursor;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
}

void print_char(char character) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    struct Char cursor = (struct Char) {
        character: '_',
        color: color,
    };
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };
    buffer[col + NUM_COLS * row + 1] = (struct Char) {
        character: (uint8_t) 0x5F,
        color: color,
    };
    col++;
}

void print_str(char* str) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    struct Char cursor = (struct Char) {
        character: '_',
        color: color,
    };
    if (row > NUM_ROWS - 1)
    {
        scroll(row - NUM_ROWS - 1);
        row = NUM_ROWS - 1;
    }
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];
        if (character == '\b') {
            while (buffer[col + NUM_COLS * row].character == ' ') {
                col = col - 1;
            }
            if (buffer[col + NUM_COLS * row].character != ' ') {
                buffer[col + NUM_COLS * row - 1] = cursor;
                buffer[col + NUM_COLS * row] = empty;
                if(col != 0) {
                    col = col - 1;
                }
                else if (row != 0) {
                    row = row - 1;
                    col = NUM_COLS;
                }
                else {
                    buffer[col + NUM_COLS * row] = cursor;
                    return;
                }
                return;
            }

        }

        if (character == '\0') {
            return;
        }

        print_char(character);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

void cursor_setpos(size_t ROW, size_t COL) {
    row = ROW;
    col = COL;
}

int get_row() {
    return row;
}

int get_col() {
    return col;
}