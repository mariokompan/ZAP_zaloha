#include <superkarel.h>

void turn_right();

int main(){

    turn_on("training.kw");
    set_step_delay(300);
    while(no_beepers_present()){
        if(right_is_blocked() && facing_north()){
            step();
        }
        else if(front_is_blocked() && right_is_blocked()){
            turn_left();
        }
        else if(right_is_clear() && facing_north()){
           turn_right();
           step();
            while(right_is_blocked() && front_is_clear()){
                step();
            }
            turn_right();
            step();
        }
       else if(right_is_blocked() && facing_south()){
            while(front_is_clear()){
                step();
            }
            turn_left();
        }
        else{
            step();
        }
    }
    turn_off();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
