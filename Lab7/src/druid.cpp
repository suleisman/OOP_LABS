#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

Druid::Druid(const std::string &name, int x, int y) : NPC(DruidType, name, x, y) {}
Druid::Druid(const std::string &name, std::istream &is) : NPC(DruidType, name, is) {}

void Druid::print() {
    std::cout << *this;
}

void Druid::save(std::ostream &os) {
    os << DruidType << std::endl;
    NPC::save(os);
}

bool Druid::isDruid() const {
    return true;
}

bool Druid::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Druid>(this,[](Druid*){}));
}

bool Druid::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Druid> other) {
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Druid &druid) {
    os << "druid: " << *static_cast<NPC* >(&druid) << std::endl;
    return os;
}