int charId = 0;
int itemId = 0;

struct characterData
{
    int ID;
    std::string Name;
    int Level;
    int Attack, Defense, Speed, HpMax;
    int xpGiven, goldDroped;
};

std::vector<characterData> charList {
    {++charId, "Class1", 1, 70, 60, 80, 100,  1,   1},
    {++charId, "Class2", 1, 60, 80, 70, 100,  1,   1},
    {++charId, "Class3", 1, 80, 70, 60, 100,  1,   1},
    {++charId, "Fitzli", 1, 50, 40, 60,  80, 33,   9},
    {++charId, "Putzli", 1, 60, 50, 40,  80, 33,   9},
    {++charId, "Morshu", 1, 60, 60, 60, 100,  1, 999},
};

struct itemData
{
    int ID;
    std::string titel;
    std::string description;
    int hpValue;
    int valueGold;
};

std::vector<itemData> itemList {
    {++itemId, "Apple", "Heals 5 HP", 5, 1},
    {++itemId, "Nuts", "Heals 5 HP", 5, 1},
    {++itemId, "Bread", "Heals 20 HP", 20, 3},
    {++itemId, "Lesser healing potion", "Heals 50 HP", 75, 10},
    {++itemId, "Normal healing potion", "Heals 150 HP", 150, 30},
    {++itemId, "Greater healing potion", "Heals 300 HP", 300, 90},
};