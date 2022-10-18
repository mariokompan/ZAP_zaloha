#include <superkarel.h>

#define DELAY 200

void turn_right();
void fill_hole();
void repair_road_left();
void repair_road_right();

void turn_north();
void turn_south();

int main(){
    turn_on("highway.kw");

    set_step_delay(DELAY);

    if(facing_east()){
        repair_road_left();
    }
    else{
        repair_road_right();
    }

    turn_off();
}

void repair_road_left(){
    while(true){
        if(right_is_blocked() && front_is_clear()){
            step();
        }
        else if(right_is_blocked() && front_is_blocked()){
            break;
        }
        else{
            fill_hole();
            turn_right();
            if(front_is_clear()){
                step();
            }
            else{
                break;
            }
        }
    }
}

void repair_road_right(){
    while(true){
        if(left_is_blocked() && front_is_clear()){
            step();
        }
        else if(left_is_blocked() && front_is_blocked()){
            break;
        }
        else{
            fill_hole();
            turn_left();
            if(front_is_clear()){
                step();
            }
            else{
                break;
            }
        }
    }
}

void fill_hole(){
    turn_south();
    if(front_is_clear()){
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

