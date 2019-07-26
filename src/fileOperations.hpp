#ifndef FileOperations_h
#define FileOperations_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "serializable.hpp"

class FileOperations{

public:
    //Function to save any vector of serializable object pointers to a file
    template <typename T>
    static bool saveObjectVector(std::vector<T*> inputVector, std::string filename);

    //Function to save any Serializable container object to a file. Called saveObjectVector
    static bool saveObject(SerializableContainer container, std::string Filename);

    //Open a file of type T objects, into a vector of those type objects
    template <typename T>
    static std::vector<T> openObject(std::string Filename);
};


template <typename T>
bool FileOperations::saveObjectVector(std::vector<T*> inputVector, std::string filename){
	if(std::is_base_of<Serializable, T>::value){
		SerializableContainer x;
		for(int i = 0; i < inputVector.size();  i++){
			x.Add(inputVector[i]);
		}
		if(saveObject(x, filename))
			return true;
		else
		{
			return false;
		}
		
	}
	else{
		printf("Serialization in savingObjectVector failed due to base type assertion failure\n");
		return false;
	}
}

template <typename T>
std::vector<T> FileOperations::openObject(std::string Filename){
	std::vector<T> returnVec;
	//create a file buffer
	std::filebuf fb;
	//Open desired file
	fb.open(Filename, std::ios::in);
	//Create instream
	std::istream fs(&fb);
	//Deserialize objects
	T newObj;
	
	while(newObj.deSerialize(fs)){
		returnVec.push_back(newObj);
	}

	fb.close();

	return returnVec;
}
/* #endregion Open Object Vector */

/* #region Save Object Functions */

bool FileOperations::saveObject(SerializableContainer container, std::string Filename){
	//Create a file buffer
	std::filebuf fb;
	//Open desired file
	fb.open(Filename, std::ios::out);
	//Create output stream
	std::ostream fs(&fb);
	//Serialize the object(s)
	
	for(int i = 0; i < container.ContainerSize(); i++){
		container.getElelment(i)->Serialize(fs);
	}
	//Close file buffer
	fb.close();
	//return 
	return true;
}


#endif 