
class Item
{
private:
    std::string titel;
    std::string description;
    int hpValue;
    int valueGold;

public:
    Item(int id) 
    { 
        titel = itemList[id].titel;
        description = itemList[id].description;
        hpValue = itemList[id].hpValue;
        valueGold = itemList[id].valueGold;
    }
    std::string getTitel() { return titel; }
    std::string getDescription() { return description; }
    int isUsed() 
    { 
        std::cout << ". Recovering " << hpValue << " HP.\n";
        return hpValue; 
    }
    int isSold()
    {
        std::cout << titel << " sold. Got " << valueGold << " Gold.\n";
        return valueGold; 
    }
};

class Character
{
private:
    std::vector<Item> bag;
    std::string Name;
    std::string Description;
    int inventory = 0;
    int nItems = 0;
    int Level;
    int Attack, Defense, Speed, HpCur, HpMax, ManaCur, ManaMax;
    int ClassID;
    bool npc;
    int xpGiven, goldDroped;
    int xpLvl = 50;
    int xpTotal;

public:
    Character(int id, bool npc)
    {
        Name = charList[id].Name;
        Description = charList[id].Name;
        Level = charList[id].Level;
        Attack = charList[id].Attack;
        Defense = charList[id].Defense;
        Speed = charList[id].Speed;
        HpMax = charList[id].HpMax;
        xpGiven = charList[id].xpGiven;
        goldDroped = charList[id].goldDroped;
        HpCur = HpMax;
        this->npc = npc;
    }

    std::string getName() { return Name; }
    std::string getClass() { return Description; }
    int getLevel() { return Level; }
    int getAttack() { return Attack; }
    int getDefense() { return Defense; }
    int getSpeed() { return Speed; }
    int getHpCur() { return HpCur; }
    int getHpMax() { return HpMax; }
    int getManaCur() { return ManaCur; }
    int getManaMax() { return ManaMax; }
    int getXpGiven() { return xpGiven; }
    std::vector<Item> getBag() { return bag; }
    bool isNpc() { return npc; }

    void setName(std::string Name) { this->Name = Name; }
    void addHpCur(int value) {
        HpCur = HpCur + value;
        if (HpCur > HpMax) HpCur = HpMax;    
    }

    void gotItem(Item itemData)
    {
        bag.push_back(itemData);
        nItems++;
    }
    void showItems(bool battle, bool shop);
    void showStats()
    {
        std::cout << "\nStats:";
        std::cout << "\n- Name:    " << Name;
        std::cout << "\n- Class:   " << Description;
        std::cout << "\n- Level:   " << Level;
        std::cout << "\n- Attack:  " << Attack;
        std::cout << "\n- Defense: " << Defense;
        std::cout << "\n- Speed:   " << Speed;
        std::cout << "\n- XP gained:   " << xpTotal;
        std::cout << "\n- next Level:   " << xpLvl;
        std::cout << "\n________________________________________________________";
        std::cout << std::endl;      
    }
    void gotXp(int xp)
    {
        xpTotal+= xp;
        if (xpTotal >= xpLvl) { levelUp(); }
    }
    void levelUp()
    {
        std::cout << "\nL E V E L   U P !\n";
        std::cout << "Lvl(" << Level << ") -> Lvl(" << ++Level << ")\n";
        Attack +=5;
        Defense +=5;
        Speed +=5;
        HpCur +=5;
        HpMax +=5;

        xpLvl += 119;
    }
};

void Character::showItems(bool battle, bool shop)
{
    char action;
    bool back;

    while (back == false)
    {
        if (shop == false) std::cout << "ITEMS | 'u': use | 'd': delete | 'b': back |";
        else std::cout << "ITEMS | 'u': buy | 'b': back |";
        for (int i = 0; i < bag.size(); i++)
        {
            if (i == inventory)
                std::cout << "\no " << bag.at(i).getTitel();
            else
                std::cout << "\n- " << bag.at(i).getTitel();
        }
        std::cout << "\n\n";
        //action = _getch();
        switch (action)
        {
        case 'u':
            if (nItems > 0)
            {
                if (shop == true)
                {
                    /* code */
                }
                
                std::cout << "Using: " << bag.at(inventory).getTitel();
                addHpCur(bag.at(inventory).isUsed());
                bag.erase(bag.begin() + inventory);
                nItems--;
                if (inventory > 0) inventory--;
                if (battle == true)
                {
                    back = true;
                }                
            } 
            break;
        case 'd':
            if (nItems > 0)
            {
                std::cout << "thwrowing away: " << bag.at(inventory).getTitel() << "\n";
                bag.erase(bag.begin() + inventory);
                nItems--;
                if (inventory > 0) inventory--;
            }
            break;
        case '8':
            inventory--;
            if (inventory < 0)
                inventory = nItems - 1;
            break;
        case '2':
            inventory++;
            if (inventory >= nItems)
                inventory = 0;
            break;
        case 'b':
            back = true;
            break;
        default:
            std::cout << "Wrong input!\n";
            break;
        }
        std::cout << "________________________________________________________\n\n";
    }
}