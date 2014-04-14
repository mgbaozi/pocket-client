#include "scene.h"
#include "ViewObject.h"
#include "../model/card.h"
#include "CardObject.h"
using namespace pocket;
using namespace view;
using namespace model;

Scene::Scene()
{
	init();
}

Scene::~Scene()
{

}

void Scene::init()
{
	Card *card = new Card(1);
	//FIXME:内存泄露,仅供测试用
	ViewObject *view_obj = new CardObject(*card);
	object_list_.push_back(view_obj);
}
