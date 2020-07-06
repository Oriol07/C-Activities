#include <iostream>
#include <string>
#include <ctime>

const int MAX_ENEMIES = 5;

	//1. 
enum EnemyType {ZOMBIE, VAMPIRE, GHOST, WITCH, LAST};

	//2. 
struct Enemy
{
	//Atributes
	std::string name;
	int health;
	EnemyType type;

	//Constructors
	Enemy() {  };

	Enemy(std::string n, int h, EnemyType t)
	{
		name = n;
		health = h;
		type = t;
	}
};

	//3
//Compare if the enemies have the same name and type.
bool equalEnemies(Enemy a, Enemy b)
{
	return ((a.name == b.name) && (a.type == b.type));
}

	//4.
//Generate a random enemy
Enemy createRandomEnemy()
{
	//Possibles names
	std::string randomNames[] = { "Gloria", "Perpetua" };
	
	//Random name + health + type
	std::string name = randomNames[rand() % (sizeof(randomNames) / sizeof(*randomNames))];
	int health = (rand() % 100)+90;
	EnemyType type = EnemyType(rand() % LAST);
	
	//Creation of the enemy
	Enemy enemyRand(name, health, type);

	return enemyRand;
}


	//5.
//Get a string of the type of the enemy
std::string getEnemyTypeString(EnemyType type)
{
	std::string names[4] = { "zombie", "vampire", "ghost", "witch" };

	return names[type];	
}

int main()
{
	std::string value;
	do{
		//random is reset.
		srand(time(NULL));

		//Variables
			//6.
		Enemy enemies[MAX_ENEMIES];

			//7.
		//init enemies
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i] = createRandomEnemy();
			for (int j = 0; j <= i; j++)
			{
				if (i != j)
					if (equalEnemies(enemies[i], enemies[j]))
					{
						enemies[i] = createRandomEnemy();
						i--;
					}
			}
		}


			//8.
		//PRINT
		std::cout << "List of Enemies: " << std::endl;
		for (Enemy n : enemies)
		{
			std::cout << "	* " << n.name << " is a " << getEnemyTypeString(n.type) << " whose life is " << n.health << std::endl;
		}


	}while (system("pause"));


	
	return 0;
}