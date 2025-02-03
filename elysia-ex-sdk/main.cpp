#include <iostream>
#include <string>
#include <array>
#include "memory.hpp"
#include "entity.hpp"
#include "features.hpp"
#include "offsets.hpp"

Entity obtainEntityInfo(Mem& process, unsigned int index)
{
    uintptr_t entityAddress;
    std::array<float, 3> entityPos;
    char entityNameBuffer[64];  // Adjust size as needed
    int entityHealth;

    // Ent, Health, Name
    process.read(entityList + (0x4 * index), &entityAddress, sizeof(entityAddress));
    process.read(entityAddress + offsets::health, &entityHealth, sizeof(entityHealth));
    process.read(entityAddress + offsets::name, entityNameBuffer, sizeof(entityNameBuffer));

    // Positions
    process.read(entityAddress + offsets::posX, &entityPos[0], sizeof(float));
    process.read(entityAddress + offsets::posY, &entityPos[1], sizeof(float));
    process.read(entityAddress + offsets::posZ, &entityPos[2], sizeof(float));

    std::string entityName(entityNameBuffer);
    return Entity(entityName, entityHealth, entityPos);
}

int main()
{
    Mem assaultCube(L"ac_client.exe");
    if (!assaultCube.validityCheck()) {
        std::cerr << "Failed to open process!" << std::endl;
        return 1;
    }

    int entCount;
    assaultCube.read(moduleBase + offsets::entityList, &entityList, sizeof(uintptr_t));
    assaultCube.read(moduleBase + offsets::entityCount, &entCount, sizeof(entCount));

    for (int i = 0; i < entCount; ++i)  // Start from 0
    {
        Entity current = obtainEntityInfo(assaultCube, i);
        current.display();
    }

    return 0;
}