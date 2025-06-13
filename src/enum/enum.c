#include <stdio.h>

enum Door_State {
    DOOR_OPEN,
    DOOR_CLOSED
};

union Data
{
    int number;
    char *color;   
};

struct Door_Generic
{
    enum Door_State door;
    union Data type;
};

void check_door(struct Door_Generic door) {
    if (door.type.color == "Color") printf("teste 1");
}

int main() {
    enum Door_State door_state = DOOR_CLOSED;

    union Data data;
    data.number = 129;
    data.color = "Color";

    struct Door_Generic door_1;
    door_1.door = door_state;
    door_1.type = data;
    
    check_door(door_1);

    return 0;
}