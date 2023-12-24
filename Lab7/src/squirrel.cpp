#include "squirrel.hpp"
#include "druid.hpp"
#include "werewolf.hpp"

Squirrel::Squirrel(const std::string &name, int x, int y) : NPC(SquirrelType, name, x, y) {}
Squirrel::Squirrel(const std::string &name, std::istream &is) : NPC(SquirrelType, name, is) {}

void Squirrel::print() {
    std::cout << *this;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    NPC::save(os);
}

bool Squirrel::is_Squirrel() const {
    return true;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Squirrel>(this,[](Squirrel*){}));
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return true;
}

bool Squirrel::fight(std::shared_ptr<Druid> other) {
    fight_notify(other, true);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, true);
    return false;
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel) {
    os << "squirrel: " << *static_cast<NPC* >(&squirrel) << std::endl;
    return os;
}