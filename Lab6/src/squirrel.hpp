#pragma once

#include "npc.hpp"
#include "visitor.hpp"

class Squirrel : public NPC {
public:
    Squirrel(const std::string &name, int x, int y);
    Squirrel(const std::string &name, std::istream &is);

    void print() override;
    
    bool isSquirrel() const;

    std::string getType() const override;

    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    void save(std::ostream &os) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);
};