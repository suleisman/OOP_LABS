#pragma once

#include <memory>

class NPC;
class Druid;
class Squirrel;
class Werewolf;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual bool visit(Druid& druid) = 0;
    virtual bool visit(Squirrel& squirrel) = 0;
    virtual bool visit(Werewolf& werewolf) = 0;
};

class NPCVisitor : public Visitor {
public:
    NPCVisitor(std::shared_ptr<NPC> attacker);
    
    bool visit(Druid& druid) override;
    bool visit(Squirrel& squirrel) override;
    bool visit(Werewolf& werewolf) override;

private:
    std::shared_ptr<NPC> attacker_;
};