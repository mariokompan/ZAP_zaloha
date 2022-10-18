#include <karel.h>

#define DELAY 500

void turn_right();
bool right_is_blocked();
bool backward_is_blocked();

int main(){
    turn_on("stairs3.kw");
    set_step_delay(500);
    while(1){
        step();
        while(beepers_present()){
            pick_beeper();
        }
        turn_left();
        while(right_is_blocked()){
            step();
        }
        turn_right();
        if(backward_is_blocked()){
            break;
        }
    }
    while(beepers_in_bag()){
        put_beeper();
    }
    turn_off();
}

void turn_right(){
    for(int i = 0; i < 3; i++){
        turn_left();
    }
}

bool right_is_blocked(){
    set_step_delay(100);
    turn_right();

    if(!front_is_clear()){
        turn_left();
        set_step_delay(DELAY);
        return true;
    }
    else{
        turn_left();
        set_step_delay(DELAY);
        return false;
    }
}

bool backward_is_blocked(){
    set_step_delay(100);
    turn_right();

    if(!front_is_clear()){
        turn_left();
        set_step_delay(DELAY);
        return true;
    }
    else{
        turn_left();
        set_step_delay(DELAY);
        return false;
    }
}
