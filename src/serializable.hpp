
/*#region Instructios for serializable */
/*INSTRUCTIONS ON HOW TO USE SERIALIZABLE CLASSES */
/*
To be able to write objects to disk, they must be derive from this Serializable class. The must also implement the Serialize and deSerializae functions, and implement the >> and << overloads. 

REPEAT: MUST IMPLEMENT << AND >> OPERATOR OVERLOADS FOR SERIALIZABLE FUNCTIONALITY TO WORK. 

Subobjects of objects that you want to serialize must implement the operator overloads as well, though those objects do not need to derive from Serializable.

************Example objects: *******************


***This model object is not serialized, but is a subobject of the serialized contestant object. Note the operator overloads and how they're implemnented.*** 
class Model{
	std::string farcry = "null";
public:
	friend std::ostream& operator<<(std::ostream& os, const Model& dt);
	friend std::istream & operator >> (std::istream &in, Model &c);
};

****All the values you want to save and load in on opening need to be << in and >> out in the operator overloads **** 

std::ostream& operator<<(std::ostream& os, const Model& dt)
{
    os << dt.farcry;
    return os;
}

std::istream & operator >> (std::istream &in, Model &c){
	in >> c.farcry;
	return in;
}

****This is an example of a serialized object. ****
class Contestant : public Serializable
{ 
public: 
    Contestant();
    Contestant(std::string, int, int);
	Contestant(std::string, int, int, std::string);
	// Instance variables 
	std::string Name; 
	int Age, Ratings; 
	Model mod;

	//Implementations
	virtual bool Serialize(std::ostream&);
	virtual bool deSerialize(std::istream&);
	//Operator overloads
	friend std::ostream& operator<<(std::ostream& os, const Contestant& dt);
	friend std::istream & operator >> (std::istream &in, Contestant &c);

}; 

***NOTE: make sure that you stream in the exact amount of values you stream out and vice versa. Otherwise reading in will fail.****
bool Contestant::Serialize(std::ostream&  stream){
	if(stream << ' ' << Age << ' ' << Name << ' ' << Ratings << ' ' <<  mod << '\n')
	{
		return true;
	}
	else{
		return false;
	}

}

bool Contestant::deSerialize(std::istream & stream){
	if(stream >> Age >> Name >> Ratings >> mod){
		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Contestant& dt)
{
    os << dt.Name << dt.Age << dt.Ratings << dt.mod;
    return os;
}

std::istream & operator >> (std::istream &in, Contestant &c){
	in >> c.Name >> c.Age >> c.Ratings >> c.mod;
	return in;
}

 */
/* #endregion */

#ifndef Serializable_h
#define Serializable_h

#include <iostream>
#include <vector>


class Serializable{
public: 
	Serializable();
	~Serializable();

	virtual bool Serialize(std::ostream& stream) = 0;
	virtual bool deSerialize(std::istream& stream) = 0;
};

class SerializableContainer{
private:
	std::vector<Serializable*> data;
public:
	void Add(Serializable*);
	int ContainerSize();
	Serializable * getElelment(int);
};

#endif