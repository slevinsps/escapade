//
// Taken 26.11.2018 from https://habr.com/post/342478/
//  BodyParser.h
//
//  Created by Jason Xu.
//
//

#pragma once

#include <string>
#include "cocos2d.h"
USING_NS_CC;
#include "json/document.h"

class BodyParser {
    BodyParser(){}
    rapidjson::Document doc;
public:
    static BodyParser* getInstance();
    bool parseJsonFile(const std::string& pFile);
    bool parse(unsigned char* buffer, long length);
    void clearCache();
    PhysicsBody* bodyFormJson(Node* pNode, const std::string& name, PhysicsMaterial material);
};
