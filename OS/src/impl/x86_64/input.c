#include "input.h"
#include "print.h"
#include "interrupts.h"
#include "time.h"

struct scan_code_type {
    uint32_t code;
    char* shifted;
    char* normal;
}; 

struct scan_code_type scan_codes[] = {
    {0x02, "!", "1"},
    {0x03, "@", "2"},
    {0x04, "#", "3"},
    {0x05, "$", "4"},
    {0x06, "%", "5"},
    {0x07, "^", "6"},
    {0x08, "&", "7"},
    {0x09, "*", "8"},
    {0x0A, "(", "9"},
    {0x0B, ")", "0"},
    {0x0C, "_", "-"},
    {0x0D, "+", "="},
    {0x0F, "    ", "    "},
    {0x10, "Q", "q"},
    {0x11, "W", "w"},
    {0x12, "E", "e"},
    {0x13, "R", "r"},
    {0x14, "T", "t"},
    {0x15, "Y", "y"},
    {0x16, "U", "u"},
    {0x17, "I", "i"},
    {0x18, "O", "o"},
    {0x19, "P", "p"},
    {0x1A, "{", "["},
    {0x1B, "}", "]"},
    {0x1C, "\n", "\n"},
    {0x1E, "A", "a"},
    {0x1F, "S", "s"},
    {0x20, "D", "d"},
    {0x21, "F", "f"},
    {0x22, "G", "g"},
    {0x23, "H", "h"},
    {0x24, "J", "j"},
    {0x25, "K", "k"},
    {0x26, "L", "l"},
    {0x27, ":", ";"},
    {0x28, "\"", "'"},
    {0x29, "~", "`"},
    {0x2B, "|", "\\"},
    {0x2C, "Z", "z"},
    {0x2D, "X", "x"},
    {0x2E, "C", "c"},
    {0x2F, "V", "v"},
    {0x30, "B", "b"},
    {0x31, "N", "n"},
    {0x32, "M", "m"},
    {0x33, "<", ","},
    {0x34, ">", "."},
    {0x35, "?", "/"},
    {0x39, " ", " "}
};

void print_input() {
    uint8_t c = inb(0x0060);
    uint8_t oldc =  inb(0x0060);
    bool shift = false;
    for(size_t i=0; i>=0; i++){
        oldc = c;
        c = inb(0x0060);
        if(c == 0x0E) {
            print_str("\b");
            sleep(20);
        }
        if(oldc != c) {
            if(c == 0x36 || c == 0x2A) {
                shift = true;
            }
            if(c == 0xB6 || c == 0xAA) {
                shift = false;
            }
            for (size_t n = 0; n <  sizeof(scan_codes)/sizeof(scan_codes[0]); n++){
                if (scan_codes[n].code == 0){
                    break;
                }
                if (scan_codes[n].code == c) {
                    if (shift){
                        print_str(scan_codes[n].shifted);
                    }
                    else {
                        print_str(scan_codes[n].normal);
                    }
                    break;
                }
            }
        }
    }
}

char* get_input_till_key_pressed(uint8_t key, char* arr) {
    uint8_t c = inb(0x0060);
    uint8_t oldc = inb(0x0060);
    int currentChar = 0;
    bool shift = false;
    for(size_t i=0; i>=0; i++){
        oldc = c;
        c = inb(0x0060);
        if(c == 0x0E) {
            print_str("\b");
            sleep(20);
        }
        if(oldc != c) {
            if(c == 0x36 || c == 0x2A) {
                shift = true;
            }
            if(c == 0xB6 || c == 0xAA) {
                shift = false;
            }
            for (size_t n = 0; n <  sizeof(scan_codes)/sizeof(scan_codes[0]); n++){
                if (scan_codes[n].code == 0){
                    break;
                }

                if (scan_codes[n].code == c) {
                    if (scan_codes[n].code == key){
                        return arr;
                    }
                    if (shift){
                        arr = arr + scan_codes[n].shifted;
                        currentChar++;
                        print_str(scan_codes[n].shifted);
                    }
                    else {
                        arr = arr + scan_codes[n].normal;
                        currentChar++;
                        print_str(scan_codes[n].normal);
                    }
                    break;
                }
            }
        }
    }
}
