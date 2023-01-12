#define OLC_PGE_APPLICATION
#include "E.h"
#include <fstream>
#include <stdlib.h>
#include <filesystem>

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

public:

std::string b;
    bool button(int x, int y, int scaleX, int scaleY, std::string text, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2, unsigned char R3, unsigned char G3, unsigned char B3, unsigned char Tscale){
		int x2 = x;
		int y2 = y;
		FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(0, 0, 0));
		DrawRect(x, y, scaleX, scaleY, olc::Pixel(R, G, B));
		FillRect(x + 1, y + 1, scaleX - 2, scaleY - 2, olc::Pixel(R2, G2, B2));
		DrawString(x + 4, y + 4, text, olc::Pixel(R3, G3, B3), Tscale);
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scaleX && mx > x && my < y + scaleY && my > y){
			FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(R3 - 50, G3 - 50, B3 - 50));
			DrawRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(0, 0, 0));
			DrawString(x + 8, y + 8, text, olc::Pixel(R3, G3, B3), Tscale);
			return true;
		}
		else{
			return false;
		}
	}
	bool Sbutton(int x, int y, int scaleX, int scaleY, std::string spr, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2, unsigned char R3, unsigned char G3, unsigned char B3, unsigned char Sscale){
		int x2 = x;
		int y2 = y;
		FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(0, 0, 0));
		DrawRect(x, y, scaleX, scaleY, olc::Pixel(R, G, B));
		FillRect(x + 1, y + 1, scaleX - 2, scaleY - 2, olc::Pixel(R2, G2, B2));
		olc::Sprite *bt;
		bt = new olc::Sprite(""+spr);
		DrawSprite(x, y, bt, Sscale);
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scaleX && mx > x && my < y + scaleY && my > y){
			FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(R3 - 50, G3 - 50, B3 - 50));
			DrawRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(0, 0, 0));
			DrawSprite(x + 2, y + 2, bt, Sscale);
			return true;
		}
		else{
			return false;
		}
	}
	bool cheakBox(int x, int y, short scale, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2){
		int x2 = x;
		int y2 = y;
		DrawRect(x, y, scale, scale, olc::Pixel(R, G, B));
		FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(200, 200, 200));
		bool state = false;
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scale && mx > x && my < y + scale && my > y && state == false){
			//FillRect(x + 4, y + 4, scale - 4, scale - 4, olc::Pixel(0, 0, 180));
			state = true;
		}
		else if (GetMouse(0).bHeld && mx < x + scale && mx > x && my < y + scale && my > y && state == true){
			state = false;
			//DrawRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(0, 0, 0));
			//FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(0, 0, 0));
		}
		if(state == true){
			FillRect(x + 4, y + 4, scale - 4, scale - 4, olc::Pixel(0, 0, 180));
			state = true;
		}
		else{
			FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(200, 200, 200));
		}
		return state;
	}
	bool pannel(int x, int y, int scaleX, int scaleY, unsigned char R, unsigned char G, unsigned char B, bool fill, short bwidth, unsigned char R2, unsigned char G2, unsigned char B2){
		int bwidth2 =  bwidth;
		int x2 = x;
		int y2 = y;
		int scaleX2 = scaleX;
		int scaleY2 = scaleY;
		while(bwidth2 > 0){
			DrawRect(x2, y2, scaleX2, scaleY2, olc::Pixel(R, G, B));
			x2 = x2 + 1;
			y2 = y2 + 1;
			scaleX2 = scaleX2 - 1;
			scaleY2 = scaleY2 - 1;
			bwidth2 = bwidth2 - 2; 
		}
		if(fill == true){
			FillRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(R2, G2, B2));
		}
		return true;
	}
	std::string dir = "lol.jpg";
	unsigned short strokeINC;
	short strokeX[2056];
	short strokeY[2056];
	bool OnUserCreate() override{
		// Create a text string, which is used to output the text file
		std::string myText;

		// Read from the text file
		std::ifstream MyReadFile("first.txt");

		// Use a while loop together with the getline() function to read the file line by line
		while (getline (MyReadFile, myText)) {
		// Output the text from the file
			if(myText == "0"){
				system("fistTime.rtf");
				MyReadFile.close();
				std::ofstream MyFile("first.txt");
				MyFile << "1";
				system("dep.bat");
			}
			else{

			}
		}

		// Close the file
		MyReadFile.close(); 

		Clear(olc::Pixel(244, 244, 244));
		pannel(280, 10, 800, 680, 200, 200, 200, true, 2, 254, 254, 254);
		olc::Sprite *pic;
		pic = new olc::Sprite(""+dir);
		DrawSprite(280, 10, pic, 1);

		return true;
	}
	char rgb[3] = {0, 0, 0};
	char size = 1;
	
	unsigned short lineCoordX[2];
	unsigned short lineCoordY[2];
	bool pen = true;
	bool line = false;
	bool rect = false;
	bool elipse = false;
	bool brush1 = false;
	bool brush2 = false;
	bool brush3 = false;
	bool brush4 = false;
	bool brush5 = false;
	bool brush6 = false;
	bool redINC = false;
	bool greenINC = false;
	bool blueINC = false;
	bool E = false;
	bool n = false;
	bool incSize = false;
	bool decSize = false;
	bool brush9 = false;
	int inc = 2;
	bool o = false;
	bool grad = false;
	int RButton[2] = {10, 10};
	int GButton[2] = {100, 10};
	int BBotton[2] = {180, 10};
	int colorPannel[2];
	int sizeButton[2];
	int clear[2];
	int lineButton[2];
	int openButton[2];
	int saveButton[2];
	int b0Button[2];
	int ResetButton[2];
	int b1Button[2];
	int b2Button[2];
	int b3Button[2];
	int b4Button[2];
	int b5Button[2];
	int b6Button[2];
	int eraseButton[2];
	int pannelXY[2] = {10, 10};
	char inc2222 = 0;
	short lineXY[2];
	

	bool OnUserUpdate(float fElapsedTime) override{
		std::string msxy;
		msxy = std::to_string(GetMouseX()) + ", " + std::to_string(GetMouseY());

		//data
		pannel(270, 689 + 1, 1280, 100, 244, 244, 244, true, 2, 244, 244, 244);
		pannel(270, 0, 1280, 10, 244, 244, 244, true, 2, 244, 244, 244);
		pannel(100, 0, 180, 720, 244, 244, 244, true, 2, 244, 244, 244);
		pannel(1080, 0, 200, 720, 244, 244, 244, true, 2, 244, 244, 244);
		pannel(10, 10, 250, 680, 254, 254, 254, true, 2, 190, 190, 190);
		pannel(280, 10, 800, 680, 200, 200, 200, false, 2, 254, 254, 254);
		bool redm = button(RButton[0] + pannelXY[0], RButton[1] + pannelXY[1], 20, 20, "<", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		FillRect(30 + pannelXY[0], 10 + pannelXY[1], 20, 20, olc::Pixel(rgb[0], 0, 0));
		bool redp = button(RButton[0] + pannelXY[0] + 40, RButton[1] + pannelXY[1], 20, 20, ">", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		bool grenm = button(100, 20, 20, 20, "<", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		FillRect(120, 20, 20, 20, olc::Pixel(0, rgb[1], 0));
		bool grenp = button(140, 20, 20, 20, ">", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		bool bluem = button(180, 20, 20, 20, "<", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		FillRect(200, 20, 20, 20, olc::Pixel(0, 0, rgb[2]));
		bool bluep = button(220, 20, 20, 20, ">", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		FillRect(20, 60, 220, 40, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		FillCircle(125, 200, size, olc::Pixel(0, 0, 0));

		bool sm = button(10, 200, 20, 20, "<", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool sp = button(220, 200, 20, 20, ">", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		bool CE = button(20, 240, 40, 40, "CE", 254, 254, 254, 200, 200, 200, 0, 0, 0, 2);
		bool ln = button(100, 240, 40, 40, "/", 254, 254, 254, 200, 200, 200, 0, 0, 0, 4);
		bool open = button(180, 240, 40, 40, "O", 254, 254, 254, 200, 200, 200, 0, 0, 0, 4);
		bool save = button(20, 300, 40, 40, "S", 254, 254, 254, 200, 200, 200, 0, 0, 0, 4);
		bool n2 = button(100, 300, 40, 40, ".", 254, 254, 254, 200, 200, 200, 0, 0, 0, 2);
		bool reset = button(180, 300, 40, 40, "R", 254, 254, 254, 200, 200, 200, 0, 0, 0, 4);

		bool B1 = button(20, 360, 66, 16, "brush1", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B2 = button(100, 360, 66, 16, "brush2", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B3 = button(180, 360, 66, 16, "brush3", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
	    bool B4 = button(20, 390, 66, 16, "brush4", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B5 = button(100, 390, 66, 16, "brush5", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B6 = button(180, 390, 66, 16, "brush6", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B7 = button(12, 420, 80, 16, "inc size", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B8 = button(95, 420, 80, 16, "dec size", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool B9 = button(180, 420, 80, 16, "Textur", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		bool RI = button(20, 450, 66, 16, "gradR", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool GI = button(100, 450, 66, 16, "gradG", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);
		bool BI = button(180, 450, 66, 16, "gradB", 254, 254, 254, 200, 200, 200, 0, 0, 0, 1);

		bool erase = button(20, 480, 220, 60, " E", 254, 254, 254, 200, 200, 200, 0, 0, 0, 8);


		if(n2 == true){
			n = true;
			pen = false;
		}
		if(B4 == true){
			brush4 = true;
			pen = false;
		}
		if(B5 == true){
			brush5 = true;
			pen = false;
		}
		if(B6 == true){
			brush6 = true;
			pen = false;
		}
		if(B7 == true){
			incSize = true;
			pen = false;
		}
		if(B8 == true){
			decSize = true;
			pen = false;
		}
		if(B9 == true){
			brush9 = true;
			pen = false;
			system("python tpaint.py");
		}
		if(RI == true){
			redINC = true;
		}
		if(GI == true){
			greenINC = true;
		}
		if(BI == true){
			blueINC = true;
		}
		if(open == true){
			o = true;
		}
		if(erase == true){
			E = true;
		}
		if(B1 == true){
			brush1 = true;
			pen = false;
		}
		if(B2 == true){
			brush2 = true;
			pen = false;
		}
		if(B3 == true){
			brush3 = true;
			pen = false;
		}
		if(reset == true){
			pen = true;
			n = false;
			brush1 = false;
			brush2 = false;
			brush3 = false;
			brush4 = false;
			brush5 = false;
			brush6  = false;
			incSize = false;
			decSize = false;
			brush9 = false;
			line = false;
			E = false;
			redINC = false;
			greenINC = false;
			blueINC = false;
			rgb[0] = 0;
			rgb[1] = 0;
			rgb[2] = 0;
			size = 1;
		}
		//std::cout << std::to_string(olc::Pixel(0, 0, 0));
		if(redp == true){
			rgb[0] = rgb[0] + 1;
		}
		if(redm == true){
			rgb[0] = rgb[0] - 1;
		}
		if(grenm == true){
			rgb[1] = rgb[1] - 1;
		}
		if(grenp == true){
			rgb[1] = rgb[1] + 1;
		}
		if(bluep == true){
			rgb[2] = rgb[2] + 1;
		}
		if(bluem == true){
			rgb[2] = rgb[2] - 1;
		}
		if(sp == true){
			size = size + 1;
		}
		if(sm == true){
			size = size - 1;
		}
		if(save == true){
			system("python savefile.py");
		}
		if(CE == true){
			Clear(olc::Pixel(244, 244, 244));
		    pannel(280, 10, 800, 680, 200, 200, 200, true, 2, 254, 254, 254);
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && pen == true){
			char w = size;
			while(w > 0){
				DrawLine(lineXY[0] + w, lineXY[1] + w, GetMouseX() + w, GetMouseY() + w, olc::Pixel(rgb[0], rgb[1], rgb[2]));
				w = w -1;
			}
			lineXY[0] = GetMouseX();
			lineXY[1] = GetMouseY();
			strokeX[strokeINC] = lineXY[0];
			strokeY[strokeINC] = lineXY[1];
			
			//std::cout << std::to_string(strokeINC) + "\n" + std::to_string(strokeX[strokeINC]) + "\n" + std::to_string(strokeY[strokeINC]) + "\n";
			strokeINC = strokeINC + 1;
		}
		
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && redINC == true){
			rgb[0] = rgb[0] + 1;
			
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && greenINC == true){
			rgb[1] = rgb[1] + 1;
			
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && blueINC == true){
			rgb[2] = rgb[2] + 1;
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && n == true){
			FillCircle(float(GetMouseX()), float(GetMouseY()), size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush4 == true){
			DrawLine(int(GetMouseX()) + size / 3, int(GetMouseY()) + size / 2, int(GetMouseX()) + size / 3, int(GetMouseY()) - size / 2, olc::Pixel(rgb[0], rgb[1], rgb[2]));
			DrawLine(int(GetMouseX()) + size / 2, int(GetMouseY()) + size / 2, int(GetMouseX()), int(GetMouseY()), olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush5 == true){
			DrawRect(int(GetMouseX()) - size / 2, int(GetMouseY()) - size / 2, size, size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush6 == true){
			DrawCircle(int(GetMouseX()) - size / 2, int(GetMouseY()) - size / 2, size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && E == true){
			FillCircle(float(GetMouseX()), float(GetMouseY()), size, olc::Pixel(254, 254, 254));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush1 == true){
			FillRect(int(GetMouseX()) - size / 2, int(GetMouseY()) - size / 2, size, size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush2 == true){
			FillTriangle(GetMouseX() - size / 2, GetMouseY() - size / 2, GetMouseX(), GetMouseY() + size, GetMouseX() + size, GetMouseY() + size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush3 == true){
			DrawTriangle(GetMouseX() - size / 2, GetMouseY() - size / 2, GetMouseX(), GetMouseY() + size, GetMouseX() + size, GetMouseY() + size, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && incSize == true){
			size = size + 1;
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && decSize == true){
			size = size - 1;
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10 && brush9 == true){
			olc::Sprite *pic1;
			pic1 = new olc::Sprite("C:\\Users\\Public\\Pictures\\pic.png");
		    DrawSprite(GetMouseX(), GetMouseY(), pic1, 1);

		}


		if(ln == true){
			line = true;
		}
		if(open == true){
			system("python openfile.py");
			olc::Sprite *pic;
			pic = new olc::Sprite("C:\\Users\\Public\\Pictures\\pic.png");
		    DrawSprite(280, 10, pic, 1);
		}
		if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10  && line == true){
			short x = 321;
			short y = 567;
			short xs = 706;
			short ys = 432;
					if(GetMouse(0).bHeld && float(GetMouseX()) < 800 + 280 && float(GetMouseX()) > 280 && float(GetMouseY()) < 680 + 10 && float(GetMouseY()) > 10  && line == true){
						DrawLine(int(GetMouseX()), int(GetMouseY()), x, y, olc::Pixel(rgb[0], rgb[1], rgb[2]));
					}
			DrawLine(float(GetMouseX()), float(GetMouseY()), xs, ys, olc::Pixel(rgb[0], rgb[1], rgb[2]));
		}
		if(size > 100 || size < 0){
			size = 0;
		}
		/*if(strokeINC > 2055){
			std::string myText;
			std::ifstream MyReadFile("tmp/tmp.txt");
			while (getline (MyReadFile, myText)) {
				//std::cout << myText;
			}
			MyReadFile.close(); 
			std::ofstream MyFile("tmp/tmp.txt");
			strokeINC = 0;
			while(strokeINC < 2056){
				myText = myText + std::to_string(strokeX[strokeINC]) + "," + std::to_string(strokeY[strokeINC]) + ",";
				strokeINC = strokeINC + 1;
			}
			MyFile << myText;
			strokeINC = 0;
			MyFile.close();
		}*/
		DrawRect(280, 690, 345, 704, olc::Pixel(0, 0, 0));
		DrawString(280, 695, msxy, olc::Pixel(0, 0, 0), 1);
		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();

	return 0;
}