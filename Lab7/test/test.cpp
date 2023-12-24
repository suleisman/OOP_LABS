#include <gtest/gtest.h>

#include "src/npc.hpp"
#include "src/observer.hpp"
#include "src/squirrel.hpp"
#include "src/werewolf.hpp"
#include "src/druid.hpp"

TEST(FightTest1, WerewolfVsSquirrel) {
    auto werewolf = factory(WerewolfType, "Werewolf", 0, 0, "test_fight.txt");
    auto squirrel = factory(SquirrelType, "Squirrel", 1, 1, "test_fight.txt");
    ASSERT_FALSE(werewolf->accept(squirrel));
    ASSERT_TRUE(squirrel->is_alive());
}

TEST(FightTest2, WerewolfVsDruid) {
    testing::internal::CaptureStdout();

    auto werewolf = factory(WerewolfType, "Werewolf", 0, 0, "test_fight.txt");
    auto druid = factory(DruidType, "Druid", 1, 1, "test_fight.txt");
    ASSERT_TRUE(druid->accept(werewolf));
    druid->mustDie();

    ASSERT_TRUE(werewolf->is_alive());
    ASSERT_FALSE(druid->is_alive());

    testing::internal::GetCapturedStdout();
}

TEST(FightTest3, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t NPCs;
    NPCs.insert(factory(WerewolfType, "Werewolf1", 15, 15, "test_fight.txt")); 
    NPCs.insert(factory(WerewolfType, "Werewolf2", 10, 10, "test_fight.txt")); 
    NPCs.insert(factory(SquirrelType, "Squirrel1", 50, 50, "test_fight.txt")); 
    NPCs.insert(factory(SquirrelType, "Squirrel2", 30, 30, "test_fight.txt"));
    NPCs.insert(factory(DruidType, "Druid1", 40, 40, "test_fight.txt"));
    NPCs.insert(factory(DruidType, "Druid2", 5, 5, "test_fight.txt")); 
    ASSERT_EQ(6, NPCs.size());

    set_t NPCsKilled;

    for (auto& attacker : NPCs) {
        for (auto& defender : NPCs) {
            if (attacker->is_alive())
                if (defender->is_alive())
                    if (defender->accept(attacker)) {
                        defender->mustDie();
                        NPCsKilled.insert(defender);
                    }
        }
    }
    for (const auto& npc : NPCsKilled) {
        NPCs.erase(npc);
    }

    testing::internal::GetCapturedStdout();
    ASSERT_EQ(2, NPCs.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}