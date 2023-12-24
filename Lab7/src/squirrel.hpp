#pragma once

#include "npc.hpp"

class Squirrel : public NPC {
public:
    Squirrel(const std::string &name, int x, int y);
    Squirrel(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_Squirrel() const;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;
    bool fight(std::shared_ptr<Druid> other) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);

};