#include "print.h"
#include "input.h"
#include "time.h"
#include "string.h"

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
    // print_input();
    while(true){
        print_str(">");
        char arr[4096];
        get_input_till_key_pressed(0x1C, arr);
        //implement console
        int index=0;
        if(strstr1(arr, "help")){
            print_str("test");
            print_str("\n")
            return;
        } else if(strstr1(arr, "ping")){
            print_str("pong");
            print_str("\n")
            return;
        } else {
            print_str(arr);
            print_str("\n");
            return;
        }
    }
}
