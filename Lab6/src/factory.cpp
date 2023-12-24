#include "factory.hpp"
#include "visitor.hpp"
#include "observer.hpp"
#include "druid.hpp"
#include "squirrel.hpp"
#include "werewolf.hpp"

std::shared_ptr<NPC> factory(const std::string &name, std::istream &is, const std::string &filename) {
    std::shared_ptr<NPC> result;
    int type = 0;
    if (is >> type) {
        switch (type) {
            case DruidType:
                result = std::make_shared<Druid>(name, is);
                break;
            case SquirrelType:
                result = std::make_shared<Squirrel>(name, is);
                break;
            case WerewolfType:
                result = std::make_shared<Werewolf>(name, is);
                break;
            default:
                break;
        }
    } else {
        std::cerr << "wrong NPC type: " << type << std::endl;
    }
    if (result) {
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get(filename));
    }
    return result;
}

std::shared_ptr<NPC> factory(NpcType type, const std::string &name, int x, int y, const std::string &filename) {
    std::shared_ptr<NPC> result;
    switch (type) {
        case DruidType:
            result = std::make_shared<Druid>(name, x, y);
            break;
        case SquirrelType:
            result = std::make_shared<Squirrel>(name, x, y);
            break;
        case WerewolfType:
            result = std::make_shared<Werewolf>(name, x, y);
            break;
        default:
            break;
    }
    if (result) {
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get(filename));
    }
    return result;
}

set_t fight(const set_t &array, size_t distance) {
    set_t deadList;
    for (const auto &attacker : array) {
        for (const auto &defender : array) {
            if ((attacker != defender) && (attacker->isClose(defender, distance))) {
                NPCVisitor visitor(attacker);
                bool success = defender->accept(visitor);
                if (success) {
                    deadList.insert(defender);
                }
            }
        }
    }
    return deadList;
}

void save(const set_t &array, const std::string &filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &name, const std::string &filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(name, is, filename));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

std::ostream &operator<<(std::ostream &os, const set_t &array) {
    for (auto &n : array)
        n->print();
    return os;
}