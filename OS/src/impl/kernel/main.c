#include "print.h"
#include "input.h"
#include "time.h"

void kernel_main() {
    print_clear();
    //Set BG Colour
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLUE);
    int line=1;
    while(line<=25){
        print_str("                                                                                \n");
        line++;
    }
    cursor_setpos(0,0);
    // print_input();
    char arr[1] = "";
    get_input_till_key_pressed(0x1C, arr);
    for (size_t i=0; i < 1; i++){
        print_str(arr[i]);
    }
}
