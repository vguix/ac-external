#ifndef OFFSETS_HPP
#define OFFSETS_HPP

#include <cstdint>

/*
	Credit to Silme94 for offsets, I've reverse engineered this game before, 
	but I truly dont feel like doing it again.

	LocalPlayer               [ac_client.exe + 0x0017E0A8]
	Entity List               [ac_client.exe + 0x18AC04]
	FOV                       [ac_client.exe + 0x18A7CC]
	PlayerCount               [ac_client.exe + 0x18AC0C]

	Position X                [0x2C]
	Position Y                [0x30]
	Position Z                [0x28]

	Head Position X           [0x4]
	Head Position Y           [0xC]
	Head Position Z           [0x8]

	Player Camera X           [0x34]
	Player Camera Y           [0x38]

	Assault Rifle Ammo        [0x140]
	Submachine Gun Ammo       [0x138]
	Sniper Ammo               [0x13C]
	Shotgun                   [0x134]
	Pistol Ammo               [0x12C]
	Grenade Ammo              [0x144]

	Fast fire Assault Rifle   [0x164]
	Fast fire Sniper          [0x160]
	Fast fire Shotgun         [0x158]

	Auto shoot                [0x204]
	Health Value              [0xEC]
	Armor Value               [0xF0]
	Player Name               [0x205]
*/

uintptr_t moduleBase = 0x400000;
uintptr_t entityList;

namespace offsets
{
	uintptr_t entityCount = 0x18AC0C;
	uintptr_t entityList = 0x18AC04;
	uintptr_t localPlayer = 0x0017E0A8;
	uintptr_t health = 0xEC;
	uintptr_t armor = 0xF0;
	uintptr_t name = 0x205;

	// pos
	uintptr_t posX = 0x2C;
	uintptr_t posY = 0x30;
	uintptr_t posZ = 0x28;
}

#endif