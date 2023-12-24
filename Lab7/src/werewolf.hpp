#pragma once

#include "npc.hpp"

class Werewolf : public NPC {
public:
    Werewolf(const std::string &name, int x, int y);
    Werewolf(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool isWerewolf() const;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);

};