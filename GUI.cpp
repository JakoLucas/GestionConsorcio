# include<iostream>
# include "GUI.h"

using namespace std;


GUI::GUI();
void GUI::ubicacion(int x, int y){
  rlutil::locate(x,y);
}
