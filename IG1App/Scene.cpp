#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

//Escena 2D.
void Scene::init2D() {
	// OpenGL basic setting

	//Eliminamos los objetos que habia antes.
	grObjects.clear();


	glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 
	//glEnable(GL_TEXTURE_2D);

	// lights
	// textures  
	// meshes

	// Graphics objects (entities) of the scene
	grObjects.push_back(new EjesRGB(200.0));

	//Escena 2D
	grObjects.push_back(new Poliespiral(dvec2(0, 0), 0, 160, 1, 1, 50));
	grObjects.push_back(new Dragon(3000));
	grObjects.push_back(new TrianguloRGB(50));
	grObjects.push_back(new RectanguloRGB(30, 20));
	grObjects.push_back(new TrianguloAnimado(40, 0, 0, 15));
}


//Escena 3D
void Scene::init3D() {
	// OpenGL basic setting

	grObjects.clear();


	glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 
	//glEnable(GL_TEXTURE_2D);

	// lights
	// textures  
	// meshes
	
	// Graphics objects (entities) of the scene
	grObjects.push_back(new EjesRGB(200.0));

	//Escena 3D

	grObjects.push_back(new RectanguloRGB(500, 200));
	grObjects.push_back(new Cubo3D(60));
	grObjects.push_back(new Estrella3D(60, 6, 30, 30));
	


	

}

//Escena para las texturas
void Scene::initTex() {
	// OpenGL basic setting

	grObjects.clear();


	glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 
	glEnable(GL_TEXTURE_2D);

	// lights
	// textures  
	// meshes
	/*
	// Graphics objects (entities) of the scene
	grObjects.push_back(new EjesRGB(200.0));
	*/

	//grObjects.push_back(new RectanguloTexCor(100, 100, 2, 3));
	//grObjects.push_back(new EstrellaTexCor(60, 6, 30, 30));
	grObjects.push_back(new CajaTexCor(60));


}



//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources   
  
  for (Entity* el: grObjects)
  {
	  delete el;  el = nullptr;
  }
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam)
{
	for (Entity* el: grObjects)
	{
		el->render(cam);
	}
}
//-------------------------------------------------------------------------

void Scene::update()
{
	for (Entity* el : grObjects)
	{
		el->update();
	}
}
//-------------------------------------------------------------------------



