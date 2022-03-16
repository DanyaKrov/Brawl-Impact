#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
using namespace std;

class Component;
class Entity;
using ComponentID = size_t;


inline ComponentID getComponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr size_t maxComponents = 32;

using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component
{
	Entity* entity;
	virtual void init() {}
	virtual void update() {}
	virtual ~Component() {}
};

class Entity
{
private:
	bool active = true;
	vector<unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
public:
	void update() {
		//for (auto& c : components) c->update();
		//for (auto& c : components) c->draw();
	}
	void draw() {}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentID<T>];
	}
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(forward<TArgs>(mArgs)...);
		c->entity = this;
		unique_ptr<Component> uPtr{ c };
		components.emplace_back(move(uPtr));
		componentArray[getComponentTypeID<T>()] = c;
		CcomponentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};
class Manager
{
private:
	vector<unique_ptr<Entity>> entities;
public:
	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}
	void refresh() {
		//entities.erase(remove_if(egin(entities), end(entities),
		//	[](const unique_ptr<Entuty>& Entity)
		//	{
		//		return Entity;
		//	}
	}
};
