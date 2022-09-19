#include "input.h"
#include "print.h"
#include "interrupts.h"
#include "time.h"
void print_input() {
    uint8_t c = inb(0x0060);
    uint8_t oldc =  inb(0x0060);
    bool shift = false;
    for(size_t i=0; i>=0; i++){
        oldc = c;
        c = inb(0x0060);
        if(c == 0x0E) {
            print_str("\b");
            sleep(10);
        }
        if(oldc != c) {
            if(c == 0x36 || c == 0x2A) {
                shift = true;
            }
            if(c == 0xB6 || c == 0xAA) {
                shift = false;
            }
            // find better solution
            if(shift == true){
                if(c == 0x02) {
                    print_str("!");
                }
                if(c == 0x03) {
                    print_str("@");
                }
                if(c == 0x04) {
                    print_str("#");
                }
                if(c == 0x05) {
                    print_str("$");
                }
                if(c == 0x06) {
                    print_str("%");
                }
                if(c == 0x07) {
                    print_str("^");
                }
                if(c == 0x08) {
                    print_str("&");
                }
                if(c == 0x09) {
                    print_str("*");
                }
                if(c == 0x0A) {
                    print_str("(");
                }
                if(c == 0x0B) {
                    print_str(")");
                }
                if(c == 0x0C) {
                    print_str("_");
                }
                if(c == 0x0D) {
                    print_str("+");
                }
                if(c == 0x0F) {
                    print_str("    ");
                }
                if(c == 0x10) {
                    print_str("Q");
                }
                if(c == 0x11) {
                    print_str("W");
                }
                if(c == 0x12) {
                    print_str("E");
                }
                if(c == 0x13) {
                    print_str("R");
                }
                if(c == 0x14) {
                    print_str("T");
                }
                if(c == 0x15) {
                    print_str("Y");
                }
                if(c == 0x16) {
                    print_str("U");
                }
                if(c == 0x17) {
                    print_str("I");
                }
                if(c == 0x18) {
                    print_str("O");
                }
                if(c == 0x19) {
                    print_str("P");
                }
                if(c == 0x1A) {
                    print_str("{");
                }
                if(c == 0x1B) {
                    print_str("}");
                }
                if(c == 0x1C) {
                    print_str("\n");
                }
                if(c == 0x1E) {
                    print_str("A");
                }
                if(c == 0x1F) {
                    print_str("S");
                }
                if(c == 0x20) {
                    print_str("D");
                }
                if(c == 0x21) {
                    print_str("F");
                }
                if(c == 0x22) {
                    print_str("G");
                }
                if(c == 0x23) {
                    print_str("H");
                }
                if(c == 0x24) {
                    print_str("J");
                }
                if(c == 0x25) {
                    print_str("K");
                }
                if(c == 0x26) {
                    print_str("L");
                }
                if(c == 0x27) {
                    print_str(":");
                }
                if(c == 0x28) {
                    print_str("\"");
                }
                if(c == 0x29) {
                    print_str("~");
                }
                if(c == 0x2B) {
                    print_str("|");
                }
                if(c == 0x2C) {
                    print_str("Z");
                }
                if(c == 0x2D) {
                    print_str("X");
                }
                if(c == 0x2E) {
                    print_str("C");
                }
                if(c == 0x2F) {
                    print_str("V");
                }
                if(c == 0x30) {
                    print_str("B");
                }
                if(c == 0x31) {
                    print_str("N");
                }
                if(c == 0x32) {
                    print_str("M");
                }
                if(c == 0x33) {
                    print_str("<");
                }
                if(c == 0x34) {
                    print_str(">");
                }
                if(c == 0x35) {
                    print_str("?");
                }
                if(c == 0x39) {
                    print_str(" ");
                }
            }
            else if(shift == false){
                if(c == 0x02) {
                    print_str("1");
                }
                if(c == 0x03) {
                    print_str("2");
                }
                if(c == 0x04) {
                    print_str("3");
                }
                if(c == 0x05) {
                    print_str("4");
                }
                if(c == 0x06) {
                    print_str("5");
                }
                if(c == 0x07) {
                    print_str("6");
                }
                if(c == 0x08) {
                    print_str("7");
                }
                if(c == 0x09) {
                    print_str("8");
                }
                if(c == 0x0A) {
                    print_str("9");
                }
                if(c == 0x0B) {
                    print_str("0");
                }
                if(c == 0x0C) {
                    print_str("-");
                }
                if(c == 0x0D) {
                    print_str("=");
                }
                if(c == 0x0F) {
                    print_str("    ");
                }
                if(c == 0x10) {
                    print_str("q");
                }
                if(c == 0x11) {
                    print_str("w");
                }
                if(c == 0x12) {
                    print_str("e");
                }
                if(c == 0x13) {
                    print_str("r");
                }
                if(c == 0x14) {
                    print_str("t");
                }
                if(c == 0x15) {
                    print_str("y");
                }
                if(c == 0x16) {
                    print_str("u");
                }
                if(c == 0x17) {
                    print_str("i");
                }
                if(c == 0x18) {
                    print_str("o");
                }
                if(c == 0x19) {
                    print_str("p");
                }
                if(c == 0x1A) {
                    print_str("[");
                }
                if(c == 0x1B) {
                    print_str("]");
                }
                if(c == 0x1C) {
                    print_str("\n");
                }
                if(c == 0x1E) {
                    print_str("a");
                }
                if(c == 0x1F) {
                    print_str("s");
                }
                if(c == 0x20) {
                    print_str("d");
                }
                if(c == 0x21) {
                    print_str("f");
                }
                if(c == 0x22) {
                    print_str("g");
                }
                if(c == 0x23) {
                    print_str("h");
                }
                if(c == 0x24) {
                    print_str("j");
                }
                if(c == 0x25) {
                    print_str("k");
                }
                if(c == 0x26) {
                    print_str("l");
                }
                if(c == 0x27) {
                    print_str(";");
                }
                if(c == 0x28) {
                    print_str("'");
                }
                if(c == 0x29) {
                    print_str("`");
                }
                if(c == 0x2B) {
                    print_str("\\");
                }
                if(c == 0x2C) {
                    print_str("z");
                }
                if(c == 0x2D) {
                    print_str("x");
                }
                if(c == 0x2E) {
                    print_str("c");
                }
                if(c == 0x2F) {
                    print_str("v");
                }
                if(c == 0x30) {
                    print_str("b");
                }
                if(c == 0x31) {
                    print_str("n");
                }
                if(c == 0x32) {
                    print_str("m");
                }
                if(c == 0x33) {
                    print_str(",");
                }
                if(c == 0x34) {
                    print_str(".");
                }
                if(c == 0x35) {
                    print_str("/");
                }
                if(c == 0x39) {
                    print_str(" ");
                }
            }
        }
    }
}