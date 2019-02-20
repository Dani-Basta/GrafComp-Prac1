#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Entity::update()
{
}

void Entity::uploadMvM(dmat4 const& modelViewMat) const
{ 
	dmat4 aMat = modelViewMat * modelMat;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(aMat));
}
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

void EjesRGB::update() 
{
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
void Poliespiral::update()
{
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

void Dragon::update()
{
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

void TrianguloRGB::update()
{
}

//-------------------------------------------------------------------------


RectanguloRGB::RectanguloRGB(GLdouble w, GLdouble h) : Entity() {
	mesh = Mesh::generaRectanguloRGB(w,h);
}
//-------------------------------------------------------------------------

RectanguloRGB::~RectanguloRGB() {
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void RectanguloRGB::render(Camera const& cam) {
	if (mesh != nullptr) {

		dmat4 matAux = cam.getViewMat();
		//matAux = rotate(matAux, glm::radians(25.0), dvec3(1, 1, 1));
		matAux = rotate(matAux, glm::radians(-25.0), dvec3(0, 0, 100));


		uploadMvM(matAux);

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

void RectanguloRGB::update()
{
}

//-------------------------------------------------------------------------

Estrella3D::Estrella3D(GLdouble re, GLdouble np, GLdouble h, GLdouble ri) : Entity() {
	mesh = Mesh::generaEstrella3D(re, np, h,ri);
}
//-------------------------------------------------------------------------

Estrella3D::~Estrella3D() {
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void Estrella3D::render(Camera const& cam) {
	if (mesh != nullptr) {

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glLineWidth(1); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		glColor3d(0.0, 0.5, 1.0);	//Ponemos un color.

		dmat4 auxMat = modelMat;
		// si la entidad tiene animación y queremos que afecte a todas las partes ->
		// dmat4 auxMat = modelMat * matAnima;
		modelMat = auxMat;
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat
		mesh->render();

		glColor3d(1.0, 0.0, 0.0);	//Ponemos otro color.

		modelMat = rotate(modelMat, radians(180.0), dvec3(0.0, 1.0, 0.0));
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat
		mesh->render();

		modelMat = auxMat;

		
		glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
		//glPointSize(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
}
//------------------------------------------------------------------------

void Estrella3D::update()
{
}

//-------------------------------------------------------------------------

Caja::Caja(GLdouble l) : Entity() {
	mesh = Mesh::generaContCubo(l);
}
//-------------------------------------------------------------------------

Caja::~Caja() {
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void Caja::render(Camera const& cam) {
	if (mesh != nullptr) {

		uploadMvM(cam.getViewMat());
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glLineWidth(2); //Indicamos el grosor de las líneas con la que se renderizará la malla.
		glColor3d(0.0, 0.5, 0.5);	//Ponemos el color.
		//glPointSize(2);

		//glPolygonMode(GL_BACK, GL_POINT);

		mesh->render();

		glLineWidth(1); //Ponemos las opciones gráficas (el grosor de la línea) por defecto. Se hace por establecer un orden. MUY RECOMENDABLE. 
		//glPointSize(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
}
//------------------------------------------------------------------------

void Caja::update()
{
}

//-------------------------------------------------------------------------


TrianguloAnimado::TrianguloAnimado (GLdouble r, GLdouble x, GLdouble y, GLdouble gradeIncr) : Entity() {
	mesh = Mesh::generaTrianguloRGB(r);
	this->gradeIncr = gradeIncr;
	this->grades = 0; //Cambiar para probar distintas opciones.

	//definir el centro de giro
	this->x = x;
	this->y = y;
}
//-------------------------------------------------------------------------

TrianguloAnimado::~TrianguloAnimado() {
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------



void TrianguloAnimado::render(Camera const& cam) {
	if (mesh != nullptr) {

		dmat4 matAux = cam.getViewMat();


		//matAux = rotate(translate(matAux, dvec3(this->x + 15*cos(radians(this->grades)), this->y + 15 * sin(radians(this->grades)), 0.0)),15.0 ,dvec3(0.0, 0.0, 1.0));
		matAux = translate(matAux, dvec3(this->x + 40 * cos(radians(this->grades)), this->y + 40 * sin(radians(this->grades)), 0.0));
		matAux = rotate(matAux,radians(this->grades),dvec3(0.0,0.0,1.0));

		uploadMvM(matAux);

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

void TrianguloAnimado::update()
{
	this->grades = this->gradeIncr + this->grades;
}

//-------------------------------------------------------------------------