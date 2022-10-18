#include <superkarel.h>

#define DELAY 200

void turn_right();
void fill_hole();
void repair_road();

void turn_north();
void turn_south();

int main(){
    turn_on("highway.kw");

    set_step_delay(DELAY);
    repair_road();

    turn_off();
}

void repair_road(){
    while(true){
        if(right_is_blocked()){
            step();
        }
        else{
            fill_hole();
            turn_right();
            if(front_is_clear()){
                step();
            }
        }
        if(front_is_blocked() && right_is_blocked()){
            break;
        }
    }
}

void fill_hole(){
    if(front_is_clear()){
        turn_south();
        step();
        if(no_beepers_present()){
            put_beeper();
        }
        fill_hole();
        turn_north();
        step();
    }
}

void turn_north(){
    while(not_facing_north()){
        turn_left();
    }
}

void turn_south(){
    while(not_facing_south()){
        turn_left();
    }
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

