// Given a set of directions, L (left), R (right), U (up), D (down)
// determine if a vacuum cleaner will end up in its original position

#include <cassert>
#include <string>

bool vacuum_back_at_start(std::string directions){

    int horizontal = 0;
    int vertical = 0;

    for(const auto &direction:directions){
        switch (direction){
        case 'L':
            horizontal--;
            break;
        case 'R':
            horizontal++;
            break;
        case 'U':
            vertical++;
            break;
        case 'D':
            vertical--;
            break;
        }
    }

    if(horizontal == 0 && vertical == 0){
        return true;
    }else{
        return false;
    }

}

int main(){
    assert(vacuum_back_at_start("LR") == true);
    assert(vacuum_back_at_start("LLR") == false);
    assert(vacuum_back_at_start("UD") == true);
    assert(vacuum_back_at_start("UDD") == false);
    assert(vacuum_back_at_start("LLRRRUUDDDUL") == true);
}