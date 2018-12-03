#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

#include "sceneobject.h"
#include "bonus.h"
#include "ComponentProgressBar.h"

class UnitComponent : public SceneObject
{
public:
    // Component абстрактный класс, поэтому без дефолтных
    // значений
	UnitComponent(Position position,
		std::string texture,
        std::string name,
		bool physic);

	// Вынесено из протектеда, поскольку нужно ставить тег
	ComponentProgressBar* bar_;

	UnitComponent::~UnitComponent() {
		;
	}

protected:
    std::string name_;

    virtual void applyBonus(Bonus bonus);
};

#endif // COMPONENT_H
