#ifndef DRUID_HPP
#define DRUID_HPP

#include "JsonEntityBuilder.hpp"
#include "entity.hpp"


class Druid : public Entity
{
private:

    void VineWhip(Entity * target);
    void NatureStrike(Entity * target);


public:
    Druid(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;

    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;


};



#endif