#include <string>
#include "random.hpp"
#include "player.hpp"


class MyPlayer1: public Player{
    cpprefjp::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> choiceRandom;
public:
    MyPlayer1(): mt(rd()){
    }

    virtual std::string decideRed(){
        return std::string("BCEH");
    }

    virtual std::string decideHand(std::string res){
        game.setState(res);

        const std::array<Unit, 16>& units = game.allUnit();

        for(const Unit& u: units){
            for(const Unit& enemy: units) {
                if(enemy.color() == UnitColor::unknown || enemy.color() == UnitColor::blue || enemy.color() == UnitColor::red) {
                    if(enemy.x() == 1 && enemy.y() == 4) {
                        if(u.x() == 2 && u.y() == 4) {
                            return Hand(u, Direction::West);
                        }
                    }
                }
            }
        }

        for(const Unit& u: units) {
            if(u.color() == UnitColor::Blue) {
                if(u.x() == 0 && u.y() == 0) {
                    return Hand({u, Direction::West});
                }
                if(u.x() == 5 && u.y() == 0) {
                    return Hand({u, Direction::East});
                }
            }
        }

        for(const Unit& u: units){
            if(u.color() == UnitColor::Blue && u.y() == 0){
                if(u.x() < 3 && u.x() > 0){
                    return Hand({u, Direction::West});
                }
                else if(u.x() < 5){
                    return Hand({u, Direction::East});
                }
            }
        }

        for(const Unit& u: units){
            for(const Unit& enemy: units) {
                if(enemy.color() == UnitColor::unknown || enemy.color() == UnitColor::blue || enemy.color() == UnitColor::red)  {
                    if(enemy.x() == 0 && enemy.y() == 5) {
                        if(u.x() == 1 && u.y() == 5) {
                            return Hand(u, Direction::West);
                        }
                    }
                }
            }
        }

        for(const Unit& u: units){
            for(const Unit& enemy: units) {
                if(enemy.color() == UnitColor::unknown || enemy.color() == UnitColor::blue || enemy.color() == UnitColor::red) {
                    if(enemy.x() == 5 && enemy.y() == 5) {
                        if(u.x() == 4 && u.y() == 5) {
                            return Hand(u, Direction::East);
                        }
                    }
                }
            }
        }

        int mostFrontPos = units[0].y();
        int mostFrontIndex = 0;
        for(int u = 1; u < 8; ++u){
            const Unit& unit = units[u];
            if(unit.color() == UnitColor::Blue && unit.y() <= mostFrontPos && unit.y() > 0){
                if(unit.y() < mostFrontPos || choiceRandom(mt)){
                    mostFrontIndex = u;
                    mostFrontPos = unit.y();
                }
            }
        }

        return Hand({units[mostFrontIndex], Direction::North});
    }

    virtual std::vector<Hand> candidateHand(){
        return game.getLegalMove1st();
    }
};