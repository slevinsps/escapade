//
// Taken 26.11.2018 from https://habr.com/post/342478/ 
//
//  BodyParser.cpp
//
//  Created by Jason Xu.
//
//
#include "BodyParser.h"

BodyParser* BodyParser::getInstance()
{
    static BodyParser* sg_ptr = nullptr;
    if (nullptr == sg_ptr)
    {
        sg_ptr = new BodyParser;
    }
    return sg_ptr;
}

bool BodyParser::parse(unsigned char *buffer, long length)
{
    bool result = false;
    std::string js((const char*)buffer, length);
    doc.Parse<0>(js.c_str());
    if(!doc.HasParseError())
    {
        result = true;
    }
    return result;
}

void BodyParser::clearCache()
{
    doc.SetNull();
}

bool BodyParser::parseJsonFile(const std::string& pFile)
{
    auto content = FileUtils::getInstance()->getDataFromFile(pFile);
    bool result = parse(content.getBytes(), content.getSize());
    return result;
}

//从json文件加载正确的body
PhysicsBody* BodyParser::bodyFormJson(cocos2d::Node *pNode, const std::string& name, PhysicsMaterial material)
{
    Size sz(pNode->getContentSize());
    Size vs(Director::getInstance()->getVisibleSize());
    PhysicsBody* body = nullptr;
    rapidjson::Value &bodies = doc["rigidBodies"];
    if (bodies.IsArray())
    {
        //遍历文件中的所有body
        for (int i=0; i<bodies.Size(); ++i)
        {
            //找到了请求的那一个
            if (0 == strcmp(name.c_str(), bodies[i]["name"].GetString()))
            {
                rapidjson::Value &bd = bodies[i];
                if (bd.IsObject())
                {
                    //创建一个PhysicsBody, 并且根据node的大小来设置
                    body = PhysicsBody::create();
                    float width = pNode->getContentSize().width;
                    float offx = - pNode->getAnchorPoint().x*sz.width;// - vs.width/2;
                    float offy = - pNode->getAnchorPoint().y*sz.height;// - vs.height/2;

                    Point origin( bd["origin"]["x"].GetDouble(), bd["origin"]["y"].GetDouble());
                    rapidjson::Value &polygons = bd["polygons"];
                    for (int i = 0; i<polygons.Size(); ++i)
                    {
                        int pcount = polygons[i].Size();
                        Point* points = new Point[pcount];
                        for (int pi = 0; pi<pcount; ++pi)
                        {
                            points[pi].x = offx + width * polygons[i][pcount-1-pi]["x"].GetDouble();
                            points[pi].y = offy + width * polygons[i][pcount-1-pi]["y"].GetDouble();
                        }
                        body->addShape(PhysicsShapePolygon::create(points, pcount, material));
                        delete [] points;
                    }
                }
                else
                {
                    CCLOG("body: %s not found!", name.c_str());
                }
                break;
            } else { CCLOG("body: %s not found!", name.c_str()); 

			CCLOG("way: %s compare", bodies[i]["name"].GetString());
			}
        }
    }
    return body;
}
