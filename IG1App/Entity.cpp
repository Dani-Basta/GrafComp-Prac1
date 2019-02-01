#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Entity::uploadMvM(dmat4 const& modelViewMat) const
{ 
	dmat4 aMat = modelViewMat * modelMat;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(aMat));
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Entity() 
{
  mesh = Mesh::createRGBAxes(l);
}
//-------------------------------------------------------------------------

EjesRGB::~EjesRGB() 
{ 
	delete mesh; mesh = nullptr; 
};
//-------------------------------------------------------------------------

void EjesRGB::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat()); 
		glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		mesh->render();
		glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
	}
}
//-------------------------------------------------------------------------

Poliespiral::Poliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni,	GLdouble incrLado, GLdouble numVert): Entity()
{
  mesh = Mesh::generaPoliespiral(verIni, angIni,incrAng, ladoIni,
	  incrLado, numVert);
}
//-------------------------------------------------------------------------

Poliespiral::~Poliespiral() 
{ 
	delete mesh; mesh = nullptr; 
};
//-------------------------------------------------------------------------

void Poliespiral::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat()); 
		glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		glColor3d(0.0, 0.0, 0.0);	//Ponemos el color.
		mesh->render();
		glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
	}
}
//-------------------------------------------------------------------------