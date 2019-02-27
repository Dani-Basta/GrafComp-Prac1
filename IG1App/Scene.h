//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Entity.h"
//#include "Mesh.h"

#include <vector>

//-------------------------------------------------------------------------

class Scene	
{ 
public:
    Scene() { };
	~Scene();
	void init2D();
	void init3D();
	void initTex(); //Escenario creado para visualizar las figuras con las texturas y no deshacer las escenas 2D y 3D.

    void render(Camera const& cam);
	void update();

protected:

	  std::vector<Entity*> grObjects;  // Entities (graphics objects) of the scene
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

