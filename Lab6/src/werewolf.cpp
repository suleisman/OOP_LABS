#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

Werewolf::Werewolf(const std::string &name, int x, int y) : NPC(WerewolfType, name, x, y) {}
Werewolf::Werewolf(const std::string &name, std::istream &is) : NPC(WerewolfType, name, is) {}

void Werewolf::print() {
    std::cout << *this;
}

bool Werewolf::isWerewolf() const {
    return true;
}

std::string Werewolf::getType() const {
    return "Werewolf";
}

bool Werewolf::fight(std::shared_ptr<Druid> other) {
    fightNotify(other, true);
    return true;
}

bool Werewolf::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, false);
    return false;
}

bool Werewolf::fight(std::shared_ptr<Werewolf> other) {
    fightNotify(other, false);
    return false;
}

void Werewolf::save(std::ostream &os) {
    os << WerewolfType << std::endl;
    NPC::save(os);
}

bool Werewolf::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::ostream &operator<<(std::ostream &os, Werewolf &werewolf) {
    os << "werewolf: " << *static_cast<NPC *>(&werewolf) << std::endl;
    return os;
}