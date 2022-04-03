# Ludum Dare 50

## Delay the Inevitable

## Concept

Capital Ship Defense

## Another Day in Space

```
The invaders are attacking your space station - as they do.
You must defend it for as long as possible.
You've been promised reinforcements, but you know how this goes.
Destruction is inevitable.
```

Inevitable destruction

Key Mechanics:
* Flying around
* Shooting using the mouse
* Enemies attacking your space station
* Enemies attacking you
* Shields need recharging
* Armor loss leads to death

## Mechanics

* Player can fly ship
* Player can shoot at mouse location
	- Multiple weapon types (beam - antishield, laser - normal, missile - antihull)
	- Weapons have a rate of fire
* Weapons fire damages ships
	- Shields exist
	- Shileds regenerate
* Ships may be destroyed
* Enemies spawn in waves
	- Number increases each wave
* Enemies attack
	- One weapon type per enemy
	- Moves towards station
	- Attacks player if in range
	- Attacks station if in range
* If player or station is destroyed, game over
* Player can statuses on HUD
	- Ship health and shield
	- Ship weapon status
	- Station health and shield
	- Enemy health and shield
	- Wave count and enemies remaining
	- Next wave count

## Assets

* Player ship
	- Turrets
	- Shield
	- Shield anim
		+ Down + sound
		+ Up + sound
		+ Recharge? + sound
	- Destruction anim + sound
	- Flying anim + sound
* Player station
	- Turrets?
	- Destruction anim + sound
* Enemy ship(s)
	- Three models?
	- Turrets
	- Shield
	- Shield anim + sound
	- Destruction anim + sound
	- Flying anim + sound
* Weapons
	- Lasers
		+ Fire
		+ Bolt
		+ Impact
	- Beam weapon
		+ Fire
		+ Bolt
		+ Impact
	- Missile
		+ Fire
		+ Bolt
		+ Explode
* Music

## Schedule

### Friday Night
* Design
* Ships/station initial

### Saturday Morning
* Movement
* Camera
* Shooting, three weapons

### Saturday Afternoon
* Enemy AI

### Saturday Evening
* Destruction
* Wave management/scoring
* UI

### Sunday Morning
* Rest

### Sunday Afternoon
* As much art as possible
* Music if possible

### Sunday Evening
* Fill in missing menus
* Testing

## Attribution

### Fonts

https://www.fontspace.com/orbitron-font-f19177