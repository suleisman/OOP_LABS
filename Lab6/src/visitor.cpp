#include "npc.hpp"
#include "visitor.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"
#include "druid.hpp"

NPCVisitor::NPCVisitor(std::shared_ptr<NPC> attacker) : attacker_(attacker) {}

bool NPCVisitor::visit(Druid& druid) {
    return attacker_->fight(std::make_shared<Druid>(druid));
}

bool NPCVisitor::visit(Squirrel& squirrel) {
    return attacker_->fight(std::make_shared<Squirrel>(squirrel));
}

bool NPCVisitor::visit(Werewolf& werewolf) {
    return attacker_->fight(std::make_shared<Werewolf>(werewolf));
}