#include <superkarel.h>

#define STEP_DELAY 200

void turn_right();
void turn_north();
void turn_west();
void turn_east();
void turn_south();

void find_marker();
void hold_wall_right();

void go_back();
void hold_wall_left();

int main(){
    turn_on("task_1.kw");
    set_step_delay(STEP_DELAY);
    
    if(beepers_present()){
        pick_beeper();
        return 0;
    }

    put_beeper();
    find_marker();
    pick_beeper();
    go_back();
    pick_beeper();
    turn_west();

    turn_off();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void turn_north(){
    while(not_facing_north()){
        turn_left();
    }  
}

void turn_west(){
    while(not_facing_west()){
        turn_left();
    }
}

void turn_east(){
    while(not_facing_east()){
        turn_left();
    }
}

void turn_south(){
    while(not_facing_south()){
        turn_left();
    }
}

void find_marker(){
    if(front_is_blocked() && right_is_blocked()){
        turn_north();
    }
    else if(facing_east()){
    }
    else{
        turn_right();
    }
    while(front_is_clear() && right_is_blocked()){
        step();
    }
    while(no_beepers_present()){
        hold_wall_right();
    }
}

void go_back(){
    turn_west();
    while(front_is_clear()){
        step();
    }
    while(no_beepers_present()){
        hold_wall_left();
    }
}

void hold_wall_left(){
    while(front_is_clear() && left_is_blocked()){
        if(beepers_present()){
            return;
        }
        step();
    }
    if(front_is_blocked() && left_is_blocked()){
        turn_north();
    }else{
        turn_left();
        step();
    }
}

void hold_wall_right(){
    while(front_is_clear() && right_is_blocked()){
        step();
    }
    if(front_is_blocked() && right_is_blocked()){
        turn_north();
    }
    else{
        turn_right();
        step();
    }

}
