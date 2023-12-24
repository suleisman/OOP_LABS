#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

Squirrel::Squirrel(const std::string &name, int x, int y) : NPC(SquirrelType, name, x, y) {}
Squirrel::Squirrel(const std::string &name, std::istream &is) : NPC(SquirrelType, name, is) {}

void Squirrel::print() {
    std::cout << *this;
}

bool Squirrel::isSquirrel() const {
    return true;
}

std::string Squirrel::getType() const {
    return "Squirrel";
}

bool Squirrel::fight(std::shared_ptr<Druid> other) {
    fightNotify(other, true);
    return true;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Werewolf> other) {
    fightNotify(other, true);
    return true;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    NPC::save(os);
}

bool Squirrel::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel) {
    os << "squirrel: " << *static_cast<NPC *>(&squirrel) << std::endl;
    return os;
}