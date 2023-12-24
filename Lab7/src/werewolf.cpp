#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

Werewolf::Werewolf(const std::string &name, int x, int y) : NPC(WerewolfType, name, x, y) {}
Werewolf::Werewolf(const std::string &name, std::istream &is) : NPC(WerewolfType, name, is) {}

void Werewolf::print() {
    std::cout << *this;
}

void Werewolf::save(std::ostream &os) {
    os << WerewolfType << std::endl;
    NPC::save(os);
}

bool Werewolf::isWerewolf() const {
    return true;
}

bool Werewolf::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Werewolf>(this,[](Werewolf*){}));
}

bool Werewolf::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool Werewolf::fight(std::shared_ptr<Druid> other) {
    fight_notify(other, true);
    return false;
}

bool Werewolf::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Werewolf &werewolf) {
    os << "werewolf: " << *static_cast<NPC* >(&werewolf) << std::endl;
    return os;
}