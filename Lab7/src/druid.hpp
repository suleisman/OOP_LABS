#pragma once

#include "npc.hpp"

class Druid : public NPC {
public:
    Druid(const std::string &name, int x, int y);
    Druid(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool isDruid() const;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);

};