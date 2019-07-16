#include "serializable.hpp"

Serializable::Serializable(){}

Serializable::~Serializable(){}

void SerializableContainer::Add(Serializable * newObject){
	data.push_back(newObject);
}

int SerializableContainer::ContainerSize(){
	return data.size();
}

Serializable * SerializableContainer::getElelment(int ind){
	return data[ind];
}