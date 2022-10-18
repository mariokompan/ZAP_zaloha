#include <superkarel.h>

void go_to_corner();
void go_while_clear();
void make_border();


void find_hor_mid();
void find_vert_mid();

void turn_north();

int main(){
    turn_on("task_5.kw");
    set_step_delay(200);
    
    make_border();
    find_hor_mid();
    find_vert_mid();
    turn_north();

    turn_off();
}

void make_border(){
    go_to_corner();
    while(no_beepers_present()){
        while(front_is_clear() && no_beepers_present()){
            put_beeper();
            step();
        }
        turn_left();
    }
}

void find_hor_mid(){
    if(front_is_clear()){
        step();
        step();
        find_hor_mid();
        while(not_facing_west()){
            turn_left();
        }
        step();
    }
}

void find_vert_mid(){
    if(front_is_clear()){
        while(not_facing_north()){
            turn_left();
        }
        step();
        step();
        find_vert_mid();
        while(not_facing_south()){
            turn_left();
        }
        step();
    }
}

void go_to_corner(){
    while(not_facing_west()){
        turn_left();
    }
    go_while_clear();
    go_while_clear();
}

void go_while_clear(){
    while(front_is_clear()){
        step();
    }
    turn_left();
}

void turn_north(){
    while(not_facing_north()){
        turn_left();
    }
}
