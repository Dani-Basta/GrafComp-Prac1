#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque) --> Cuando se tenga una escena vacía.
  glEnable(GL_DEPTH_TEST);  // enable Depth test 
     
  // lights
  // textures  
  // meshes

  // grObjects.push_back(); 

  // Graphics objects (entities) of the scene


  //Ejes de la escena.
  //grObjects.push_back(new EjesRGB(200.0)); 

  //Poliespirales.

  //grObjects.push_back(new Poliespiral( dvec2(0.0, 0.0), 0.0, 160.0, 1.0, 1.0, 50.0) );
  //grObjects.push_back(new Poliespiral(dvec2(0.0, 0.0), 0.0, 72.0, 30.0, 0.001, 6.0)); //pentágono
  //grObjects.push_back(new Poliespiral(dvec2(0.0, 0.0), 0.0, 60.0, 0.5, 0.5, 100.0));

  //Dragon
  //grObjects.push_back(new Dragon(3000));
  
  //Rectangulo  
  //grObjects.push_back(new RectanguloRGB(200, 100));
  
  //Triangulo
  //grObjects.push_back( new TrianguloRGB(300) );

  //Estrella 3D
  //grObjects.push_back( new Estrella3D(64,4,32,32));

  //Caja 3D

  grObjects.push_back(new Caja(60));


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

