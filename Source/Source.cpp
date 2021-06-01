#include <iostream>
#include <string>

//TODO: Create formula for critical hit probability
//TODO: Create formula for blocked attack damage


/*All of the data for the player goes in here*/
class Player
{
    private:
    std::string name = "";

    public:
    void Setname(std::string user) { name = user; }
    const std::string& GetName() const { return name; }

    int level = 1;
    int maxhealth = 1000;
    int currenthealth = 0;
    
    int outcome = -1; //-1 is default, 0 is lose, 1 is win

    /*All the attacks go in here*/
    struct Attack
    {
        int basic = 10; //basic attack stat.
        bool block = false; //blocking reduces incoming damage to half of its original value
    };

    Player(std::string n)
    {
        Attack attack;

        if (n != "no change")
        name = n;
        else if (n == "no change")
        {}

        attack.basic = attack.basic * level;
    }
};

/*All of the enemy data goes here.
Note: The enemy class is going to be a lot more complicated
when it is fully fleshed out and finished.*/
class Enemy
{
    private:
    std::string name = "";
    int id = 0;

    public:
    int maxhealth = 100 * (id + 1);
    int currenthealth = 0;

    struct Attack
    {
        int basic = 5; //basic attack stat.
        bool block = false; //blocking reduces incoming damage to half of its original value
    };

    Enemy(std::string n)
    {
        Attack attack;
        
        if (n != "no change")
        name = n;
        else if(n == "no change")
        {}

    }

    void ResetHealth() { currenthealth = maxhealth; }
    int GetID() { return id; }
    void SetName(std::string n) { name = n; }
    const std::string& GetName() const { return name; }
};

void  UserAttack()
{
    Enemy enemy = Enemy("no change");
    Player player = Player("no change");
    Player::Attack pa;
    Enemy::Attack ea;

    int choice = -1;
    bool done = false;

    if (enemy.currenthealth > 0)
    {
        std::cout << "<player> vs <enemy>" << std::endl;
        std::cout << "Press the number that corresponds to the choice you want to make." << std::endl;
        std::cout << "_____________________________________________________";
        std::cout << "\n\n";
        std::cout << "_____________________________________________________\n";
        std::cout << "1: Attack\n" << "2: Block\n" "Choice: " << std::endl;
        while (!done)
        {
            std::cin >> choice;
            switch(choice)
            {
                case 1:
                    if (!ea.block)
                    {
                        std::cout << "Player chose to attack." << std::endl;
                        std::cout << "Player dealt " + std::to_string(pa.basic) + " damage." << std::endl;
                        enemy.currenthealth -= pa.basic;
                        std::cout << "Enemy now has " + std::to_string(enemy.currenthealth) + " health." << std::endl;
                        std::cin.ignore();
                    }
                    else if (ea.block)
                    {
                        std::cout << "Player has chosen to attack, but enemy chose to block on their previous turn!" << std::endl;
                        std::cout << "Player dealt " + std::to_string(pa.basic / 2) + " damage." << std::endl;
                        enemy.currenthealth -= (pa.basic / 2);
                         std::cout << "Enemy now has " + std::to_string(enemy.currenthealth) + " health." << std::endl;
                         std::cin.ignore();
                    }
                    done = true; break;
                case 2:
                    std::cout << "Player chose to block." << std::endl;
                    pa.block = true; std::cin.ignore(); done = true; break;
                default: "Please choose a response: "; std::cin.ignore(); break;
            }
        }
    }
    else if (enemy.currenthealth <= 0)
    player.outcome = 1;
}

void EnemyAttack()
{
    Enemy enemy = Enemy("no change");
    Player player = Player("no change");
    Player::Attack pa;
    Enemy::Attack ea;

    int choice; // attack is 0, block is 1.
    bool done = false;

    
    if (player.currenthealth > 0)
    {
        while (!done)
        {
            choice = rand() % 2;
            switch(choice)
            {
                case 0:
                if (!pa.block)
                {
                    std::cout << "Enemy chose to attack." << std::endl;
                    std::cout << "Enemy dealt " + std::to_string(ea.basic) + " damage." << std::endl;
                    player.currenthealth -= ea.basic;
                    std::cout << "Player now has " + std::to_string(player.currenthealth) + " health." << std::endl;
                    std::cin.ignore();
                }
                else if (pa.block)
                {
                    std::cout << "Enemy chose to attack, but player has chosen to block on their previous turn!" << std::endl;
                    std::cout << "Enemy dealt " + std::to_string(ea.basic / 2) + " damage." << std::endl;
                    player.currenthealth -= ea.basic;
                    std::cout << "Player now has " + std::to_string(player.currenthealth) + " health." << std::endl;
                    std::cin.ignore();
                }
                done = true; break;
                case 1:
                    pa.block = true; done = true; break;
               default: std::cout << "Error: number outside of scope."; break;
            }
       }
    }
    else if (player.currenthealth <= 0)
    player.outcome = 0;
}

int main()
{
    Player player = Player("no change");
    Enemy enemy = Enemy("no change");
    
    player.currenthealth = player.maxhealth;
    enemy.currenthealth = enemy.maxhealth;

    do
    {
        UserAttack();
        EnemyAttack();
    } while (player.outcome == -1);
    
    std::cout << "Hello World" << std::endl;
    std::cin.ignore();
}