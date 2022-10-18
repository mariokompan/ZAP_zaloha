#include <superkarel.h>

void turn_north();
void turn_south();

int main(){
    turn_on("empty.kw");
    set_step_delay(200);
    turn_north();

    while(1){
        if(front_is_clear()){
            step();
        }
        else{
            if(facing_north()){
                turn_south();
            }
            else{
                turn_north();
            }
        }
    }

    turn_off();
}

void turn_north(){
    while(!facing_north()){
        turn_left();
    }
}
void turn_south(){
    turn_north();
    turn_left();
    turn_left();
}
