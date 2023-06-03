#include <iostream> //biblioteca padão de entrada e saida de terminal.
#include <SDL2/SDL.h> //biblioteca para janela de contexto OpenGL.
#include <glad/glad.h> //biblioteca para uso de funções OpenGL.
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int start_timer= time(NULL);

//Window pointer variable.
SDL_Window* 	window_application = nullptr;
	
//OpenGL context variable.
SDL_GLContext   opengl_context = nullptr;

int screem_w = 640;
int screem_h = 480;
bool close_program = false;

float obj_vertex[9] = {
	-0.8f,-0.8f,0.0f,
	 0.8f,-0.8f,0.0f,
	 0.0f, 0.8f,0.0f
	};
GLuint VBO;

//================================================== 4

void CreateObject(){
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(obj_vertex), obj_vertex, GL_STATIC_DRAW);
}

//================================================== 3

void CleanWindow(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Draw(){
	glEnable(GL_CULL_FACE);
	
	CreateObject();
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 1);
	glDisableVertexAttribArray(0);
}

//================================================== 2

void ProgramInputs(){
	
}

void ProgramDraw(){
	CleanWindow();
	Draw();
}

//================================================== 1

//Initialize program.
void InitProgram(){
	
	//Initialize SDL video system.
	if(SDL_Init(SDL_INIT_VIDEO) < 0){cout << "SDL init error" << SDL_GetError(); exit(1);}
	
	//Set OpenGL attibuts.
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	//create window.
	window_application = SDL_CreateWindow("SDL OpenGl OGLDEV",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screem_w, screem_h,SDL_WINDOW_OPENGL);
	if(window_application == nullptr){cout << "window creation error\n"; exit(1);}
	
	//OpenGL context.
	opengl_context = SDL_GL_CreateContext(window_application);
	if(opengl_context == nullptr){cout << "OpenGl context error\n"; exit(1);}
	
	//Glad initialize.
	if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){cout << "glad init error\n"; exit(1);}
}

//Window/Program loop.
void MainLoop(){
	while(close_program !=true){
		ProgramDraw();
		SDL_GL_SwapWindow(window_application);
		
		if(time(NULL) - start_timer >= 5){close_program = true;};
		
	}
}

//Destroy program.
void CleanProgram(){
	SDL_DestroyWindow(window_application);
	SDL_Quit();
}

//================================================== Main

//Main function.
int main(int argc, char * argv[]){
	InitProgram();
	MainLoop();
	CleanProgram();
	
	return 0;
}
