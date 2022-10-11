#include "print.h"
#include "input.h"
#include "time.h"

extern "C" void kernel_main() {
    print_clear();
    //Set BG Colour
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);
    int line=1;
    while(line<=25){
        print_str("                                                                                \n");
        line++;
    }
    cursor_setpos(0,0);
    print_input();
}
