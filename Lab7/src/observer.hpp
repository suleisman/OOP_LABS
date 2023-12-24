#pragma once

#include <memory>
#include <string>
#include <fstream>
#include <mutex>

#include "npc.hpp"

class ConsoleObserver : public IFightObserver {
public:
    static std::shared_ptr<IFightObserver> get() {
        static ConsoleObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }
    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (win) {
        std::lock_guard<std::mutex> lck(std::mutex print_mutex);
        std::cout << std::endl << "Murder --------" << std::endl;
        attacker->print();
        defender->print();
        std::cout << attacker->getName() << " kills " << defender->getName() << std::endl;
    }
    }
};

class FileObserver : public IFightObserver {
public:
    FileObserver(const std::string &filename) {
        file.open(filename, std::ios_base::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open log file");
        }
    }
    static std::shared_ptr<IFightObserver> get(const std::string &filename) {
        return std::make_shared<FileObserver>(filename);
    }
    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (file.is_open() && win) {
            std::lock_guard<std::mutex> lck(std::mutex print_mutex);
            file << "\nMurder --------" << std::endl;
            file << attacker->getType() << " " << *attacker << std::endl;
            file << defender->getType() << " " << *defender << std::endl;
            file << attacker->getType() << " " << attacker->getName() << " kills " << defender->getType() << " " << defender->getName() << std::endl;
    }
    }
    ~FileObserver() {
        if (file.is_open()) {
            file.close();
        }
    }
private:
    std::ofstream file;
};