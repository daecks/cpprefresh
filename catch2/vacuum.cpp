#include <string>

bool vacuum(std::string directions);

bool vacuum(std::string directions){
    int horizontal = 0;
    int vertical = 0;

    for(auto direction:directions){
        switch(direction){
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

    if(horizontal == 0 && vertical == 0) return true;
    return false;
}
