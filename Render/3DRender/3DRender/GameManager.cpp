#include "GameManager.h"

GameManager& GameManager::Instance()
{
	static GameManager gameManager;
	return gameManager;
}

void GameManager::game_start(HWND hwnd,const int WIDTH,const int HEIGHT)
{
	DirectX::instance().initialDirectX(GetModuleHandle(nullptr),hwnd,WIDTH,HEIGHT);
}

void GameManager::game_update()
{
	DirectX &directX = DirectX::instance();
	directX.fillSurface();
	directX.lockSurface();
	//for (int i=0;i<100;++i) {
	//	for (int j=0;j<100;++j) {
	//		directX.drawPixel(i,j,AColor(0,255,0,0));
	//	}
	//}

	//directX.drawLine(10,200,530,30,AColor(0,255,0,0));
	//directX.drawLine(10,10,530,530,AColor(0,255,0,0));
	//directX.drawLine(30,30,60,500,AColor(0,255,0,0));
	//directX.drawLine(60,300,600,500,AColor(0,255,0,0));
	//directX.drawLine(80,80,80,500,AColor(0,255,0,0));

	for (int i=0;i<580;i+=5)
	{
		for (int j=0;j<580;j+=5)
		{
			double v = sqrt(pow(i-350,2)+pow(j-350,2))-200;
			if ( v>=0&&v < 2)
			{
				rasterizer.drawline_bresenham(350,350,i,j,AColor(0,(1+rand()%255)/255.0f,(1+rand()%255)/255.0f,(1+rand()%255)/255.0f));
			}
		}
	}

	/*Vertex v1(Vector3(400,30,0),Vector3(),AColor(0,1.0f,0,0),0,0);
	Vertex v2(Vector3(200,300,0),Vector3(),AColor(0,0,1.0f,0),0,0);
	Vertex v3(Vector3(600,500,0),Vector3(),AColor(0,0,0,1.0f),0,0);
	Vertex v4(Vector3(700,100,0),Vector3(),AColor(0,0,0,1.0f),0,0);
	rasterizer.draw_triangle(v1,v2,v3);*/
	//rasterizer.draw_triangle(v1,v3,v4);
    
	directX.unlockSurface();
	directX.flipSurface();
}

void GameManager::game_end()
{
	cout<<"Game end!"<<endl;
}