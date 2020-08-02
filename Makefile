Heroes: Archer.o BlackDragon.o Creature.o Hero.o Main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o
	g++ Archer.o BlackDragon.o Creature.o Hero.o Main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o -o Heroes

Archer.o: Archer.cpp Archer.h CreaturesHeader.h Creature.h Zombie.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Archer.cpp

BlackDragon.o: BlackDragon.cpp BlackDragon.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h
	g++ -c BlackDragon.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

Hero.o: Hero.cpp Hero.h Exception.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Hero.cpp

Main.o: Main.cpp Warrior.h Hero.h Exception.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h BlackDragon.h Thief.h Necromancer.h
	g++ -c Main.cpp

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Exception.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Necromancer.cpp

Thief.o: Thief.cpp Thief.h Hero.h Exception.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Thief.cpp

Vampire.o: Vampire.cpp Vampire.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h BlackDragon.h
	g++ -c Vampire.cpp

Warrior.o: Warrior.cpp Warrior.h Hero.h Exception.h CreaturesHeader.h Creature.h Zombie.h Archer.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Warrior.cpp

Wizard.o: Wizard.cpp Wizard.h CreaturesHeader.h Creature.h Zombie.h Archer.h Vampire.h BlackDragon.h
	g++ -c Wizard.cpp

Zombie.o: Zombie.cpp Zombie.h CreaturesHeader.h Creature.h Archer.h Wizard.h Vampire.h BlackDragon.h
	g++ -c Zombie.cpp

clean:

	rm -f *.o rm -f Heroes
