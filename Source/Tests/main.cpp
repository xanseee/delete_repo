#include <cassert>
#include "Utils/Math.h"
#include "Game/Character.h"

int main() {
    Character hero("Durden");
    assert(!hero.dead());
    hero.takeDamage(10);

	assert(max(1, 2) == 2);
    assert(sum(1, 2) == 3);
	return 0;
}