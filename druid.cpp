#include "druid.hpp"


Druid::Druid(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the druid has entered the battle" << std::endl;
}


void Druid::VineWhip(Entity * target)
{
    Attack(target, GetWisdom() * 0.1, "Vine Whip");
}


void Druid::NatureStrike(Entity *target)
{
    Attack(target, GetWisdom() * 0.5, "Nature Strike");
    Attack(target, GetWisdom() * 0.5, "Nature Strike");
    Attack(target, GetWisdom() * 0.5, "Nature Strike");
}


void Druid::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tWisdom: " << this->GetWisdom()
                << std::endl;
                
    PrintInventory();
}

void Druid::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Mace Attack");
}

void Druid::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "vine_whip")
    {
        VineWhip(target);
        return;
    }
    if(spellName == "nature_strike")
    {
        NatureStrike(target);
        return;
    }
    errorFindingAbility(spellName);

}