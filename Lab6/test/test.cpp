#include <gtest/gtest.h>

#include "src/npc.hpp"
#include "src/visitor.hpp"
#include "src/factory.hpp"
#include "src/werewolf.hpp"
#include "src/squirrel.hpp"
#include "src/druid.hpp"

TEST(FightTest1, Fighting) {
    Druid druid("Druid", 9, 36);
    Squirrel squirrel("Squirrel", 10, 12);
    Werewolf werewolf("Werewolf", 0, 50);

    EXPECT_TRUE(squirrel.fight(std::make_shared<Druid>(druid)));
    EXPECT_FALSE(squirrel.fight(std::make_shared<Squirrel>(squirrel)));
    EXPECT_FALSE(druid.fight(std::make_shared<Squirrel>(squirrel)));
    EXPECT_FALSE(druid.fight(std::make_shared<Werewolf>(werewolf)));
    EXPECT_TRUE(werewolf.fight(std::make_shared<Druid>(druid)));
    EXPECT_FALSE(werewolf.fight(std::make_shared<Squirrel>(squirrel)));
}

TEST(VisitorTest, Visitor) {
    auto druid = std::make_shared<Druid>("Druid", 0, 5);
    auto squirrel = std::make_shared<Squirrel>("Squirrel", 10, 20);
    auto werewolf = std::make_shared<Werewolf>("Werewolf", 5, 10);

    auto npcVisitor = std::make_shared<NPCVisitor>(druid);

    EXPECT_FALSE(druid->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));
    EXPECT_FALSE(werewolf->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(squirrel);

    EXPECT_TRUE(druid->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));
    EXPECT_TRUE(werewolf->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(werewolf);

    EXPECT_TRUE(druid->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));
    EXPECT_FALSE(werewolf->accept(*npcVisitor));
}

TEST(ObserverTest, Observer) {
    auto werewolf = std::make_shared<Werewolf>("Werewolf", 0, 5);
    auto druid = std::make_shared<Druid>("Druid", 5, 10);
    
    testing::internal::CaptureStdout();

    auto textObserver = std::make_shared<TextObserver>();
    werewolf->subscribe(textObserver);
    werewolf->fight(druid);

    std::string textOutput = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "\nMurder: --------\nwerewolf: Werewolf {0, 5} \ndruid: Druid {5, 10} \nWerewolf killed Druid\n";

    EXPECT_EQ(textOutput, expectedOutput);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}