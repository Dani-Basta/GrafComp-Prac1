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

void Poliespiral::render(Camera const& cam) {
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		glColor3d(0.0, 0.0, 0.0);	//Ponemos el color.
		mesh->render();
		glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
	}
}
//-------------------------------------------------------------------------

Dragon::Dragon(GLuint numVert) : Entity() { 
	mesh = Mesh::generaDragon(numVert);
}
//-------------------------------------------------------------------------

Dragon::~Dragon() { 
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void Dragon::render(Camera const& cam) {
	if (mesh != nullptr) {
		
		//Mejor opción este orden que el otro.
		dmat4 matAux = cam.getViewMat();
		matAux = scale(translate(matAux, dvec3(-40.0, -170.0, 0.0)), dvec3(40.0, 40.0, 40.0));
		//para que se vea bien cambiamos la traslacion proporcionalmente a la escala
		//matAux = translate(scale(matAux, dvec3(40.0, 40.0, 40.0)), dvec3(-40.0, -170.0, 0.0));
		//matAux = translate(scale(matAux, dvec3(40.0, 40.0, 40.0)), dvec3(-1.0, -170.0/40, 0.0));

		//uploadMvM(cam.getViewMat());
		uploadMvM(matAux);

		//glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		glColor3d(0.0, 0.0, 1.0);	//Ponemos el color.
		glPointSize(2);
		mesh->render();
		
		//glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
		glPointSize(1);

	}
}
//-------------------------------------------------------------------------


TrianguloRGB::TrianguloRGB(GLdouble r) : Entity() {
	mesh = Mesh::generaTrianguloRGB(r);
}
//-------------------------------------------------------------------------

TrianguloRGB::~TrianguloRGB() {
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void TrianguloRGB::render(Camera const& cam) {
	if (mesh != nullptr) {

		uploadMvM(cam.getViewMat());

		//glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		//glColor3d(0.0, 0.0, 1.0);	//Ponemos el color.
		glPointSize(2);

		//glPolygonMode(GL_BACK, GL_LINE);
		//glPolygonMode(GL_BACK, GL_POINT);
			
		mesh->render();

		//glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
		glPointSize(1);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
}
//-------------------------------------------------------------------------