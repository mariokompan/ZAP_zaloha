#include <superkarel.h>

void find_middle();

int main(){
    turn_on("multiplier.kw");
    find_middle();
    turn_off();
}

void find_middle(){
    if(front_is_clear()){
        step();
        step();
        find_middle();
        while(not_facing_west()){
            turn_left();
        }
        step();
    }
}

