#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <random>
#include <fstream>
#include <set>
#include <cmath>
#include <shared_mutex>

class NPC;
class Werewolf;
class Druid;
class Squirrel;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    DruidType = 1,
    WerewolfType = 2,
    SquirrelType = 3
};

class IFightObserver {
public:
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC {
private:
    std::mutex mtx;

    NpcType type;
    std::string name;
    int x{0};
    int y{0};
    bool alive{true};

    std::vector<std::shared_ptr<IFightObserver>> observers;
public:
    NPC(NpcType t, const std::string &_name, int _x, int _y);
    NPC(NpcType t, const std::string &_name, std::istream &is);
    
    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance);

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;

    virtual bool fight(std::shared_ptr<Werewolf> other) = 0;
    virtual bool fight(std::shared_ptr<Druid> other) = 0;
    virtual bool fight(std::shared_ptr<Squirrel> other) = 0;

    virtual void print() = 0;
    std::pair<int, int> position();
    const std::string& getName() const;
    NpcType getType();

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    void move(int shift_x, int shift_y, int max_x, int max_y);
    bool is_alive();
    void mustDie();

    ~NPC() = default;
};

std::shared_ptr<NPC> factory(const std::string &name, std::istream &is, const std::string &filename);
std::shared_ptr<NPC> factory(NpcType type, const std::string &name, int x, int y, const std::string &filename);

void save(const set_t &array, const std::string &filename);
set_t load(const std::string &name, const std::string &filename);
set_t fight(const set_t &array, size_t distance);

std::ostream &operator<<(std::ostream &os, const set_t &array);
