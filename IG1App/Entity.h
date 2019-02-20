//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Mesh.h"

//-------------------------------------------------------------------------

class Entity 
{
public:
	Entity() : modelMat(1.0) { }; 
	virtual ~Entity() { };

	virtual void render(Camera const& cam) = 0;
	virtual void update();


	// modeling matrix
	glm::dmat4 const& getModelMat() const { return modelMat; };

	void setModelMat(glm::dmat4 const& aMat) { modelMat = aMat; }
  
protected:

	Mesh* mesh = nullptr;   // surface mesh
	glm::dmat4 modelMat;    // modeling matrix

	// transfers modelViewMat to the GPU
	virtual void uploadMvM(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity {
public:
	EjesRGB(GLdouble l);
	~EjesRGB();
	virtual void render(Camera const& cam); 
	virtual void update();
};

//-------------------------------------------------------------------------


class Poliespiral : public Entity{
public:
	Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni,
		GLdouble incrLado, GLdouble numVert);
	~Poliespiral();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------

class Dragon : public Entity {
public:
	Dragon(GLuint numVert);
	~Dragon();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------

class TrianguloRGB : public Entity {
public:
	TrianguloRGB(GLdouble r);
	~TrianguloRGB();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------

class RectanguloRGB : public Entity {
public:
	RectanguloRGB(GLdouble w, GLdouble h);
	~RectanguloRGB();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------

class Estrella3D: public Entity {
public:
	Estrella3D(GLdouble re, GLdouble np, GLdouble h, GLdouble ri);
	~Estrella3D();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------


class Caja : public Entity {
public:
	Caja(GLdouble l);
	~Caja();
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------

class TrianguloAnimado : public Entity {
private:
	//definir el centro de giro
	GLdouble x;
	GLdouble y;

	GLdouble grades;
	GLdouble gradeIncr;

public:
	
	TrianguloAnimado(GLdouble r, GLdouble x, GLdouble y, GLdouble gradeIncr);
	~TrianguloAnimado();
	virtual void render(Camera const& cam);
	virtual void update();
};





#endif //_H_Entities_H_