#include <superkarel.h>

#define DELAY 200

void go_ahead();
void turn_right();
void double_beepers();

int main(){
    turn_on("multiplier.kw");
    set_step_delay(DELAY);
    go_ahead();
    turn_off();
}

void go_ahead(){
    while(1){
        while(front_is_clear()){
           step();
           
           double_beepers();
        }
        if(front_is_blocked() && left_is_blocked()){
            break;
        }
        if(facing_east()){
            turn_left();
            step();
            turn_left();
        }else{
            turn_right();
            step();
            turn_right();
        }
    }
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void double_beepers(){
    if(beepers_present()){
        pick_beeper();
        double_beepers();
        put_beeper();
        put_beeper();
    }
}
