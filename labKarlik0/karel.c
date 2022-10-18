#include <karel.h>

void turn_right();

int main(){
    turn_on("world.kw");
        while(1){
            if(front_is_clear()){
                break;
            }
            while(!facing_north()){
                turn_left();
            }
            while(beepers_present()){
                pick_beeper();
            }
            step();
            turn_right();
            step();
        }
        while(beepers_in_bag()){
            put_beeper();
        }
    turn_off();
}

void turn_right(){
    for (int i = 0; i < 3; i++) {
        turn_left();
    }
}
