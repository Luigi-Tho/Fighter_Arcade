#include <iostream>
#include <string>

//TODO: Create formula for critical hit probability


/*All of the data for the player goes in here*/
class Player
{
    private:
    std::string name = "";

    public:
    void Setname(std::string user) { name = user; };
    const std::string& GetName() const { return name; };
    int level = 1;
    int maxhealth = 1000;
    int currenthealth = 0;

    /*All the attacks go in here*/
    struct Attack
    {
        int basic = 10; //basic attack stat.
        bool block = false; //blocking reduces incoming damage to half of its original value
    };

    Player(std::string n)
    {
        Attack attack;

        name = n;
        currenthealth = maxhealth;
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
    int maxhealth = 100 * (id + 1);

    public:
    int currenthealth = 0;

    struct Attack
    {
        int basic = 5; //basic attack stat.
        bool block = false; //blocking reduces incoming damage to half of its original value
    };

    Enemy(std::string n)
    {
        Attack attack;
        
        name = n;
        currenthealth = maxhealth;
    }

    void ResetHealth() { currenthealth = maxhealth; }
    int GetID() { return id; }
    void SetName(std::string n) { name = n; }
    const std::string& GetName() const { return name; }
};

void  UserAttack(std::string u, std::string e)
{
    Enemy enemy = Enemy(e);
    Player player = Player(u);
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
                        std::cout << "Player chose to attack" << std::endl;
                        std::cout << "Player dealt " + std::to_string(pa.basic) + " damage." << std::endl;
                        std::cin.ignore();
                    }
                    done = true; break;
                case 2: pa.block = true; std::cin.ignore(); done = true; break;
                default: "Please choose a response: "; std::cin.ignore();
            }
        }
    }
    else if (enemy.currenthealth <= 0);
}

int main()
{
    UserAttack("u", "e");
    std::cout << "Hello World" << std::endl;
    std::cin.ignore();
}