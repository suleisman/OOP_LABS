#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

Druid::Druid(const std::string &name, int x, int y) : NPC(DruidType, name, x, y) {}
Druid::Druid(const std::string &name, std::istream &is) : NPC(DruidType, name, is) {}

void Druid::print() {
    std::cout << *this;
}

bool Druid::isDruid() const {
    return true;
}

std::string Druid::getType() const {
    return "Druid";
}

bool Druid::fight(std::shared_ptr<Werewolf> other) {
    fightNotify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Druid> other) {
    fightNotify(other, false);
    return false;
}

void Druid::save(std::ostream &os) {
    os << DruidType << std::endl;
    NPC::save(os);
}

bool Druid::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::ostream &operator<<(std::ostream &os, Druid &druid) {
    os << "druid: " << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}