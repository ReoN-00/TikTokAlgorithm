/*
 * TikTok Stakeholder Power Model: The "Coke vs. Monster" Scenario
 * Author: Reo Nagahama
 */

#include <iostream>
#include <string>

// 1. The Stakeholders
class Advertiser {
public:
    std::string product;
    Advertiser(std::string p) : product(p) {}
};

class Creator {
public:
    std::string content;
    Creator(std::string c) : content(c) {}
};

class User {
public:
    std::string preference;
    User(std::string p) : preference(p) {}
};

// 2. The Legacy Platform (Current Unfair System)
// Problem: Advertiser > User Preference
class LegacyPlatform {
public:
    void runAlgorithm(User& u, Advertiser& a, Creator& c) {
        std::cout << "\n--- Legacy Algorithm Running ---" << std::endl;
        std::cout << "User likes: " << u.preference << " | Advertiser wants: " << a.product << std::endl;

        // The algorithm forces Advertiser content regardless of User preference
        if (a.product != u.preference) {
            std::cout << ">> DECISION: Show " << a.product << " Video (Creator content overridden)" << std::endl;
            std::cout << ">> REASON SHOWN TO USER: [HIDDEN] (User confused)" << std::endl;
        }
    }
};

// 3. Proposed System
// Solution: Transparency and User Priority
class EquitablePlatform {
public:
    void runAlgorithm(User& u, Advertiser& a, Creator& c_monster) {
        std::cout << "\n--- Equitable Algorithm Running ---" << std::endl;
        
        // The algorithm prioritizes User preference
        if (u.preference == "Monster") {
            std::cout << ">> DECISION: Show " << c_monster.content << " Video" << std::endl;
            std::cout << ">> REASON SHOWN TO USER: [TRANSPARENCY] Because you liked Monster Energy." << std::endl;
        } else {
            // Even if ads are shown, the reason is clear
            std::cout << ">> DECISION: Show " << a.product << " Video" << std::endl;
            std::cout << ">> REASON SHOWN TO USER: [TRANSPARENCY] Sponsored by Coke." << std::endl;
        }
    }
};

// 4. Migration Function
EquitablePlatform migrateSystem(LegacyPlatform oldPlatform) {
    std::cout << "\n[System Update] Removing Advertiser Priority..." << std::endl;
    return EquitablePlatform();
}

int main() {
    // Setup: User likes Monster, but Advertiser is Coke
    User myUser("Monster");
    Advertiser mySponsor("Coke");
    Creator cokeCreator("Coke");
    Creator monsterCreator("Monster");

    // Scenario 1: Legacy System
    LegacyPlatform oldSystem;
    // The system takes the Coke Creator's video because the Sponsor pays for it
    oldSystem.runAlgorithm(myUser, mySponsor, cokeCreator);

    // Scenario 2: Fix the System
    EquitablePlatform newSystem = migrateSystem(oldSystem);

    // Scenario 3: Equitable System
    // Now the system respects the user and shows Monster
    newSystem.runAlgorithm(myUser, mySponsor, monsterCreator);

    return 0;
}