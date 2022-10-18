#include <superkarel.h>

#define DELAY 100

void fill_holes();
void fill_empty();
void fill_to_wall();

void turn_south();
void turn_north();
void turn_east();
void turn_right();

bool back_is_clear();

int main(){
    turn_on("task_4.kw");
    set_step_delay(DELAY);
    fill_holes();
    turn_off();
}

void fill_holes(){
    while(true){
        fill_empty();
        if(left_is_blocked() && front_is_blocked()){
            break;
        }
        turn_east();
        if(front_is_clear()){
            step();
        }
    }
    turn_east();
}

void fill_empty(){
    if(right_is_blocked()){
        turn_north();
    }
    if(front_is_clear() && no_beepers_present()){
        step();
        fill_empty();
    }
    else if(front_is_blocked()){
        turn_south();
        if(front_is_clear()){
            step();
        }
        else{
            return;
        }
        fill_empty();
    }
    else{
        if(!back_is_clear()){
            turn_north();
            fill_to_wall();
            turn_south();
            while(front_is_clear()){
                step();
            }
            return;
        }
        else{
            turn_south();
            fill_to_wall();
            turn_north();
            fill_empty();
        }
    }
}

void turn_south(){
    while(not_facing_south()){
        turn_left();
    }
}

void turn_north(){
    while(not_facing_north()){
        turn_left();
    }
}

void turn_east(){
    while(not_facing_east()){
        turn_left();
    }
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

bool back_is_clear(){
    turn_north();
    turn_left();
    turn_left();
    if(front_is_clear()){
        turn_north();
        return true;
    }
    else{
        turn_north();
        return false;
    }
}

void fill_to_wall(){
    while(front_is_clear()){
        step();
        if(no_beepers_present()){
            put_beeper();
        }
    }
}
