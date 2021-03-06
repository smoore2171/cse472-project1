#pragma once
#include "ShaderWnd/ShaderWnd.h"

const int NumVertices = 36;
typedef  vec4  point4;typedef  vec4  color4;


class CCube
{
public:
	point4 vertex_positions[8];
	point4  points[NumVertices];
	color4  colors[NumVertices];
	vec3 normals[NumVertices];
	vec2   tex_coords[NumVertices];

	GLuint vao, vbo;

	mat4 m_translation;
	mat4 m_rotation;
	vec3 c, v, w;
	quat q;
	int m_cornerIndex;
	vec3 m_impulse;

public:
	CCube(double size=1.);
	CCube(double size, bool drawFrontFace);
	~CCube(void);

	void quad(int a, int b, int c, int d, point4 *vertex_positions, int& Index);

	void setCornerIndex(int index) { m_cornerIndex = index; }
	void addImpulse(int direction);


	void InitGL(GLuint program);
	void RenderGL(GLuint program);

	void Update(double dt);
};

const vec3 operator* (double dt, vec3 v); 
const quat operator+ (quat, quat);
const quat operator* (vec3 v, quat q);
const quat operator* (float s, quat q);