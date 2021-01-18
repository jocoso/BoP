#include "player.h"

int Player::health = 100;
int Player::stamina = 50;
int Player::build[] = {0, 0};
int Player::dexterity[] = {0, 0};
int Player::people[] = {0, 0};
int Player::intelligence[] = {0, 0};

// MANAGEMENT
int Player::get_health() {
    return health;
}

void Player::change_health_by(double hp) {
    health += hp;
}

int Player::get_stamina() {
    return stamina;
}

void Player::change_stamina_by(double st) {
    stamina += st;
}

// BUILD
// -------------------------------------------------
// HEALTH
int Player::get_build_health() {
    return build[0];
}

int Player::increase_build_health_by_one() {
    return build[0]++;
}

bool Player::has_build_health_reached_max_value() {
    return (build[0] >= MAX_LEVEL_OF_UPDATES);
}

// STRENGTH
int Player::get_build_strength() {
    return build[1];
}

int Player::increase_build_strength_by_one() {
    return build[1]++;
}

bool Player::has_build_strength_reached_max_value() {
    return (build[1] >= MAX_LEVEL_OF_UPDATES);
}

// -------------------------------------------------

// DEXTERITY
// -------------------------------------------------
// PRECISION
int Player::get_dexterity_perception() {
    return dexterity[0];
}

int Player::increase_dexterity_perception_by_one() {
    return dexterity[0]++;
}

bool Player::has_dexterity_perception_reached_max_value() {
    return (dexterity[0] >= MAX_LEVEL_OF_UPDATES);
}

// AGILITY
int Player::get_dexterity_agility() {
    return dexterity[1];
}

int Player::increase_dexterity_agility_by_one() {
    return dexterity[1]++;
}

bool Player::has_dexterity_agility_reached_max_value() {
    return( dexterity[1] >= MAX_LEVEL_OF_UPDATES );
}
// -------------------------------------------------


// PEOPLE
// -------------------------------------------------
// COOL
int Player::get_people_cool() {
    return people[0];
}

int Player::increase_people_cool_by_one() {
    return people[0]++;
}

bool Player::has_people_cool_reached_max_value() {
    return (people[0] >= MAX_LEVEL_OF_UPDATES);
}

// BARTER
int Player::get_people_barter() {
    return people[1];
}

int Player::increase_people_barter_by_one() {
    return people[1]++;
}

bool Player::has_people_barter_reached_max_value() {
    return( people[1] >= MAX_LEVEL_OF_UPDATES );
}
// -------------------------------------------------


// INTELLIGENCE
// -------------------------------------------------
// SCIENCE
int Player::get_intelligence_science() {
    return intelligence[0];
}

int Player::increase_intelligence_science_by_one() {
    return intelligence[0]++;
}

bool Player::has_intelligence_science_reached_max_value() {
    return (intelligence[0] >= MAX_LEVEL_OF_UPDATES);
}

// ENGINEERING
int Player::get_intelligence_engineering() {
    return intelligence[1];
}

int Player::increase_intelligence_engineering_by_one() {
    return intelligence[1]++;
}

bool Player::has_intelligence_engineering_reached_max_value() {
    return( intelligence[1] >= MAX_LEVEL_OF_UPDATES );
}
// -------------------------------------------------

