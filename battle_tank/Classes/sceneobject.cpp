#include "sceneobject.h"

static void problemLoading(std::string filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool SceneObject::has_sprite() const {
	return sprite != nullptr;
}

SceneObject::SceneObject(Position position,
	std::string filename, bool physic) {
	position_ = position;

	std::string filename_png = filename + ".png";
	std::string filename_json = filename + ".json";

	sprite = cocos2d::Sprite::create(filename_png);
	// Проверяем - существует ли json-файл
	if (sprite) {
		if (physic) {
			if (BodyParser::getInstance()->parseJsonFile(filename_json))
			{
				// Создаём физическое тело. Второй параметр - имя тела(не путать с именем файла)
				auto spriteBody = BodyParser::getInstance()->bodyFormJson(sprite,
					filename, PhysicsMaterial(1.0f, 0.7f, 0.5f));
				if (spriteBody != nullptr)
				{
					// Устанавливаем тело для спрайта
					spriteBody->setGravityEnable(false);
					spriteBody->setLinearDamping(0.5);
					sprite->setPhysicsBody(spriteBody);
					CCLOG("%s connected", filename_json);
				}
				else
				{
					CCLOG("%s not connected", filename_json);
				}
			}
			else
			{
				CCLOG("%s not found", filename_json);
			}
		}
		sprite->setPosition(position_.toVec2());
	} else {
		CCLOG("%s not found", filename_png);
	}
}

Position::Position(int x, int y) : x_(x), y_(y){}

Position::~Position(){}

cocos2d::Vec2 Position::toVec2() {
	return cocos2d::Vec2(x_, y_);
}

Position::Position(cocos2d::Vec2 v) {
	x_ = v.x;
	y_ = v.y;
}

int Position::get_x() const {
    return x_;
}
void Position::set_x(int x) {
    x_ = x;
}

int Position::get_y() const {
    return y_;
}

void Position::set_y(int y) {
    y_ = y;
}

bool Position::operator == (const Position &other) const
{
    return (this->get_x() == other.get_x());
}

bool Position::operator != (const Position &other) const
{
    return this->get_y() != other.get_y();
}
