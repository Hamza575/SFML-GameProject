
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
#include<sstream>
#define WIDTH 700
#define HEIGHT 600
#define circle 3
#define polygon 2
#define triangle 1
#define diamond 0
#define cyan 0
#define blue 1
#define green 2
#define yellow 3
#define red 4
int score = 0;


int ypos = 0;
int Arrsh[5] = { 0,1,2,3,4};//randomshape
int ArrXpos[4] = { 0,150,310,460 };
int fshr = Arrsh[rand() % 4];
int fclr = Arrsh[rand() % 4];
int sha1 = Arrsh[rand() % 4];
int cl1r = Arrsh[rand() % 4];
bool flag=1;
using namespace std;
using namespace sf;
class shape
{
	int  posx; int posy; int radius; int round;
	CircleShape shapes[4];
	Color colors[5];
public:
	shape()
	{
		shapes[0] = CircleShape(70, 4);//diamond
		shapes[1] = CircleShape(90, 3);//triangle
		shapes[2] = CircleShape(70, 5);//polygon
		shapes[3] = CircleShape(70, 360);//circle
		colors[0] = { Color::Cyan };
		colors[1] = { Color::Blue };
		colors[2] = { Color::Green };
		colors[3] = { Color::Yellow };
		colors[4] = { Color::Red };
	}
	CircleShape getshape(int num, int numcolor = 0)
	{
		CircleShape sh = shapes[num];
		sh.setFillColor(colors[numcolor]);
		return sh;
	}
	
	
};
void gameBaseMechanic();
void menu()
{
	RenderWindow window(VideoMode(700, 600), "Game Menu");

	Clock clock;
	Time timer;


	Texture Background;

	Sprite bg;

	srand(time(NULL));

	Background.loadFromFile("menu.png");
	bg.setTexture(Background);

	

	while (window.isOpen())
	{
		Event e;
		window.draw(bg);
		window.pollEvent(e);
		switch (e.type)
		{
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				gameBaseMechanic();
				window.close();
			}
		case Event::Closed:
			window.close();
			break;
		default:
			break;
		}

		window.display();
	}

}



void gameBaseMechanic()
{
	RenderWindow window;
	window.create(VideoMode(WIDTH, HEIGHT), "Matshape");
	window.setFramerateLimit(60);
	Clock clock;
	Time time;
	Font MyFont;

	
	Music music;
	music.openFromFile("Thunder.wav");
	music.setVolume(80);
	music.play();
	Event e;
	shape s1;
	auto sh1 = s1.getshape(sha1, cl1r);
	auto sh2 = s1.getshape(sha1,cl1r); 
	auto sh3 = s1.getshape(sha1, cl1r);
	auto sh4 = s1.getshape(sha1, cl1r);
	auto fsh = s1.getshape(fshr, fclr);
	
	sh1.setPosition(0, 455);
	sh2.setPosition(150, 455);
	sh3.setPosition(310, 455);
    sh4.setPosition(460, 455);
	
	while (window.isOpen())
	{
		
		window.clear();
		window.pollEvent(e);
	    time = clock.getElapsedTime();
		
		if (time.asSeconds() >= 2)
		{
			fsh = s1.getshape(Arrsh[rand() % 4], Arrsh[rand() % 5]);
			fsh.setPosition(ArrXpos[rand() % 4], 0);
			window.draw(fsh);
			
			if (time.asSeconds() > 2.1)
				clock.restart();
		}
		fsh.move(0, 5);
		if (ypos <= 455)
		{
			ypos += 5;		//cout << ypos << endl;
		}
		else 
		{
			
			if (fshr != sha1 && fshr != cl1r)
			{
				cout << "Not Match" << endl;
				//break;
			}
		    if (fshr == sha1 && fshr == cl1r )
			{
				score += 100;
				cout << score << endl;
				//break;
			}

		}
		Text text;
		stringstream s;
		s << score;
		text.setString(s.str().c_str());
		window.draw(text);

		switch (e.type)
		{
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				if (sha1 < 3)
				{
					sha1++;
				}
				else if (sha1 == 3)
				{
					sha1 = 0;
				}
					if (Keyboard::isKeyPressed(Keyboard::H))
					{
						sh1 = s1.getshape(sha1, red);
					}
					if (Keyboard::isKeyPressed(Keyboard::J))
					{
						sh1 = s1.getshape(sha1, green);
					}if (Keyboard::isKeyPressed(Keyboard::K))
					{
						sh1 = s1.getshape(sha1, blue);
					}if (Keyboard::isKeyPressed(Keyboard::L))
					{
						sh1 = s1.getshape(sha1, yellow);
					}
				sh1.setPosition(0, 455);
				window.draw(sh1);
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				if (sha1 < 3)
				{
					sha1++;
				}
				else if (sha1 == 3)
				{
					sha1 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::H))
				{
					sh2 = s1.getshape(sha1, red);
				}
				if (Keyboard::isKeyPressed(Keyboard::J))
				{
					sh2 = s1.getshape(sha1, green);
				}if (Keyboard::isKeyPressed(Keyboard::K))
				{
					sh2 = s1.getshape(sha1, blue);
				}if (Keyboard::isKeyPressed(Keyboard::L))
				{
					sh2 = s1.getshape(sha1, yellow);
				}				sh2.setPosition(150, 455);
				window.draw(sh2);
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{

				if (sha1 < 3)
				{
					sha1++;
				}
				else if (sha1 == 3)
				{
					sha1 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::H))
				{
					sh3 = s1.getshape(sha1, red);
				}
				if (Keyboard::isKeyPressed(Keyboard::J))
				{
					sh3 = s1.getshape(sha1, green);
				}if (Keyboard::isKeyPressed(Keyboard::K))
				{
					sh3 = s1.getshape(sha1, blue);
				}if (Keyboard::isKeyPressed(Keyboard::L))
				{
					sh3 = s1.getshape(sha1, yellow);
				}	sh3.setPosition(310, 455);
				window.draw(sh3);
			}
			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				if (sha1 < 3)
				{
					sha1++;
				}
				else if (sha1 == 3)
				{
					sha1 = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::H))
				{
					sh4 = s1.getshape(sha1, red);
				}
				if (Keyboard::isKeyPressed(Keyboard::J))
				{
					sh4 = s1.getshape(sha1, green);
				}if (Keyboard::isKeyPressed(Keyboard::K))
				{
					sh4 = s1.getshape(sha1 ,blue);
				}if (Keyboard::isKeyPressed(Keyboard::L))
				{
					sh4 = s1.getshape(sha1, yellow);
				}sh4.setPosition(460, 455);
				window.draw(sh4);
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				menu();
				window.close();
			}
			break;
		case Event::Closed:
			window.close();
			break;
		default:
			break;
		}
		window.draw(sh1); window.draw(sh2); window.draw(sh3); window.draw(sh4); window.draw(fsh);
		window.display();
	}
}
void main()
{
	
	menu();
}
