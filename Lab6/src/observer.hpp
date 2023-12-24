#pragma once

#include <memory>
#include <string>
#include <fstream>

class NPC;

class IFightObserver {
public:
    virtual ~IFightObserver() = default;
    virtual void onFight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class TextObserver : public IFightObserver {
public:
    static std::shared_ptr<IFightObserver> get();
    void onFight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};

class FileObserver : public IFightObserver {
private:
    std::ofstream file;
public:
    FileObserver(const std::string &filename);
    static std::shared_ptr<IFightObserver> get(const std::string &filename);
    void onFight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
    ~FileObserver();
};