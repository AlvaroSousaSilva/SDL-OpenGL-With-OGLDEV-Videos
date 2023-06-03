#include <iostream> //biblioteca padão de entrada e saida de terminal.
#include <SDL2/SDL.h> //biblioteca para janela de contexto OpenGL.
#include <glad/glad.h> //biblioteca para uso de funções OpenGL.
#include <string>
#include <vector>

using namespace std;

//Window pointer variable.
SDL_Window* 	window_application = nullptr;
	
//OpenGL context variable.
SDL_GLContext   opengl_context = nullptr;

int screem_w = 640;
int screem_h = 480;
bool close_program = false;

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
	window_application = SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screem_w, screem_h,SDL_WINDOW_OPENGL);
	
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
		close_program = true;
	}
}

//Destroy program.
void CleanUP(){
	SDL_DestroyWindow(window_application);
	SDL_Quit();
}

//Main function.
int main(int argc, char * argv[]){
	InitProgram();
	MainLoop();
	CleanUP();
	
	return 0;
}
