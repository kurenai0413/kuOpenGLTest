#pragma once
#include <iostream>

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <opencv2/opencv.hpp>

#include "kuShaderHandler.h"

#define pi 3.1415926

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opencv_world310d.lib")

using namespace std;
using namespace cv;

GLuint	CreateTexturebyImage(char * filename);

int  main()
{
	GLfloat	vertices[]
		= {
		// Frontal Face
		// Positions          // Colors           // Texture Coords
		-0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // 0: Top Left  
		 0.5f,  0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // 1: Top Right
		 0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // 2: Bottom Right
		 0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // Bottom Right
		-0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // 3: Bottom Left
		-0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // Top Left
		
		// Back face
		 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,

		// Left Face
		 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,

		// Right Face
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,

		// Up Face
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,

		// Down Face
		-0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f
	};

	//GLuint indices[]
	//	= { 
	//		// Frontal 
	//		0, 1, 3,
	//		1, 2, 3,

	//		// Back
	//		4, 5, 7,
	//		5, 6, 7,

	//		// Left
	//		4, 5, 0,
	//		5, 1, 0
	//	  };

	if (!glfwInit())
	{
		cout << "GLFW initialization failed." << endl;
		return 1;
	}

	GLFWwindow * window = glfwCreateWindow(640, 480, "GLFW window", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		cout << "GLFW window creation failed." << endl;
	}

	glfwMakeContextCurrent(window);

	// need to create OpenGL window before glew initialization.
	//glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		//Problem: glewInit failed, something is seriously wrong.
		cout << "glewInit failed, aborting." << endl;
	}

	// Define the viewport dimensions
	glViewport(0, 0, 640, 480);

	// Setup OpenGL options (z-buffer)
	glEnable(GL_DEPTH_TEST);

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER);
	// get renderer string (graphic card)
	const GLubyte* version = glGetString(GL_VERSION);
	// version as a string (OpenGL supported version and graphic card driver version)
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	kuShaderHandler ShaderHandler;
	ShaderHandler.Load("VertexShader.vert", "FragmentShader.frag");
	ShaderHandler.Use();

	GLuint VertexArray = 0;
	glGenVertexArrays(1, &VertexArray);
	GLuint VertexBuffer = 0;				// Vertex Buffer Object (VBO)
	glGenBuffers(1, &VertexBuffer);			// give an ID to vertex buffer
	//GLuint ElementBuffer = 0;				// Element Buffer Object (EBO)
	//glGenBuffers(1, &ElementBuffer);

	glBindVertexArray(VertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer); // Bind buffer as array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	GLuint TextureID = CreateTexturebyImage("TexImage.jpg");
	
	GLuint		ModelMatLoc, ViewMatLoc, ProjMatLoc;
	glm::mat4	ModelMat, ProjMat;

	ProjMat = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 100.0f);
	ProjMatLoc = glGetUniformLocation(ShaderHandler.ShaderProgramID, "ProjMat");
	glUniformMatrix4fv(ProjMatLoc, 1, GL_FALSE, glm::value_ptr(ProjMat));

	ModelMatLoc = glGetUniformLocation(ShaderHandler.ShaderProgramID, "ModelMat");
	glUniformMatrix4fv(ModelMatLoc, 1, GL_FALSE, glm::value_ptr(ModelMat));

	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBindTexture(GL_TEXTURE_2D, TextureID);
	
		glm::mat4 ViewMat;
		ViewMat = glm::translate(ViewMat, glm::vec3(0.0f, 0.0f, -2.0f));
		ViewMat = glm::rotate(ViewMat, (GLfloat)pi * (GLfloat)glfwGetTime() * 20.0f / 180.0f,
							  glm::vec3(1.0, 1.0, 0.0)); // mat, degree, axis. (use radians)
		ViewMatLoc = glGetUniformLocation(ShaderHandler.ShaderProgramID, "ViewMat");
		glUniformMatrix4fv(ViewMatLoc, 1, GL_FALSE, glm::value_ptr(ViewMat));
		
		//glBindVertexArray(VertexArray);
		//glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);

		glBindVertexArray(VertexArray);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VertexArray);
	glDeleteBuffers(1, &VertexBuffer);
	//glDeleteBuffers(1, &ElementBuffer);

	glfwTerminate();

	return 0;
}

GLuint CreateTexturebyImage(char * filename)
{
	GLuint	texture;
	Mat		TexImage = imread(filename, 1);

	for (int i = 0; i < TexImage.cols; i++)
	{
		for (int j = 0; j < TexImage.rows; j++)
		{
			int		PixelIdx = TexImage.cols * j + i;
			uchar	temp;

			temp = TexImage.data[3 * PixelIdx];
			TexImage.data[3 * PixelIdx] = TexImage.data[3 * PixelIdx + 2];
			TexImage.data[3 * PixelIdx + 2] = temp;
		}
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TexImage.cols, TexImage.rows, 0, GL_RGB, GL_UNSIGNED_BYTE, TexImage.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}
