//
//  Material.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#include "material.hpp"

/* #region Constructors/Destructors */
Material::Material()
{
    matName = "default";
    specularIntensity = 0.0f;
    shininess = 0.0f;
}

Material::Material(char * fileName){
	//create a file buffer
	std::filebuf fb;
	//Open desired file
	fb.open(fileName, std::ios::in);
	//Create instream
	std::istream fs(&fb);
	//Deserialize objects
	fs >> matName >> specularIntensity >> shininess;

	fb.close();
}

Material::Material(std::string inName, GLfloat sIntensity, GLfloat shine)
{
    matName = inName;
    specularIntensity = sIntensity;
    shininess = shine;
}

Material::~Material()
{
}
/* #endregion */

/* #region MaterialMap */
std::map<std::string, Material> Material::MaterialMap;
/* #endregion */

/* #region Use Material */
void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
    glUniform1f(specularIntensityLocation, specularIntensity);
    glUniform1f(shininessLocation, shininess);
}
/* #endregion */

/* #region serialize Material */
void Material::serializeMaterial(char * fileName){
    
    //create a file buffer
	std::filebuf fb;
	//Open desired file
	fb.open(fileName, std::ios::out);
	//Create instream
	std::ostream fs(&fb);
	//Deserialize objects
	fs << matName << '\n' << specularIntensity << '\n' << shininess;

	fb.close();
}