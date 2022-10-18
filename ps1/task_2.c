#include <superkarel.h>

#define DELAY 100

bool is_back();
void find_treasure();
void go_back();

void turn_right();
void turn_around();

int main(){
    turn_on("task_2.kw");
    
    set_step_delay(DELAY);

    find_treasure();
    turn_around();
    go_back();

    turn_off();
}

void find_treasure(){
    while(no_beepers_present()){
        while(front_is_clear() && no_beepers_present()){
            step();
        }
        turn_left();
    }
    pick_beeper();
}

void go_back(){
    while(!is_back()){
        turn_right();
        while(front_is_clear()){
            step();
        }
    }
}

bool is_back(){
    if (right_is_blocked() && left_is_blocked()){
        if (front_is_blocked()){
            return true;
        }
    }
    return false;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void turn_around(){
    turn_left();
    step();
}
