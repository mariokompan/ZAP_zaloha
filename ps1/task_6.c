#include <superkarel.h>

#define DELAY 200

void turn_north();
void turn_south();
void turn_west();
void turn_east();

void find_treasure();

bool is_one_beeper();
bool is_two_beepers();
bool is_three_beepers();
bool is_four_beepers();

int main(){
    turn_on("task_6.kw");
    
    set_step_delay(DELAY);
    find_treasure();

    turn_off();
}

void find_treasure(){
    while(true){
        while(no_beepers_present()){
            step();
        }
        if(is_one_beeper()){}
        else if(is_two_beepers()){}
        else if(is_three_beepers()){}
        else if(is_four_beepers()){}
        else{
            pick_beeper();
            break;
        }
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

bool is_one_beeper(){
    pick_beeper();
    if(beepers_present()){
        return false;
    }
    turn_north();
    return true;
}

bool is_two_beepers(){
    pick_beeper();
    if(beepers_present()){
        return false;
    }
    turn_west();
    return true;
}

bool is_three_beepers(){
    pick_beeper();
    if(beepers_present()){
        return false;
    }
    turn_south();
    return true;
}

bool is_four_beepers(){
    pick_beeper();
    if(beepers_present()){
        return false;
    }
    turn_east();
        return true;
}
