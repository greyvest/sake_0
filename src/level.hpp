#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include <object.hpp>

class Level{
public:
    //getter/setters for the levels name
    std::string getLevelName(){return levelName;};
    std::string setLevelName(char * name){levelName = name;};
    //function to open level from file as a vector of objects
    std::vector<Object> openLevelFromFile();
    //function to save levels vector of objectes to a file
    void saveLevelToFile(std::vector<Object>);

private:
    //Name of level
    std::string levelName;
    //Vector for entities that will only need to change/move when level is changed. Backgrounds/environment details/etc.
    std::vector<Object> staticEntities;
    //Vector for entities that might need to change during playh
    std::vector<Object> dynamicEntities;
};
#endif