#include "print.h"

void kernel_main() {
    print_clear();
    //Set BG Colour
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);
    int line=1;
    while(line<=25){
        print_str("                                                                                \n");
        line++;
    }
    print_set_color(PRINT_COLOR_BLUE, PRINT_COLOR_WHITE);

    cursor_setpos(6, 36);
    print_str(" DAM OS ");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);

    int current_row;
    cursor_setpos(9, 3);
    print_str("An error has occured. To continue:\n\n");
    current_row = get_row();
    cursor_setpos(current_row, 3);
    print_str("Press Enter to return to DAM OS, or\n\n");
    current_row = get_row();
    cursor_setpos(current_row, 3);
    print_str("Press CTRL+ALT+DEL to restart your computer. If you do this,\n   you will lose any unsaved information in all open applications\n\n");
    current_row = get_row();
    cursor_setpos(current_row, 3);
    print_str("Error code: 0x7d9ab3f6\n\n");
    current_row = get_row();
    cursor_setpos(current_row, 26);
    print_str("Press any key to continue");

    cursor_setpos(29, 1);
    print_str("this is a test");
   
}
