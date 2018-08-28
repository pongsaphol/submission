#include "tetris.h"
#include <bits/stdc++.h>
using namespace std;

int state;

void init(int n) {
	state = 0;
}

int position;
int rotation;

void new_figure(int figure_type) {
	if(figure_type == 1) {
		position = 0, rotation = 0;
	} else if(figure_type == 2) {
		if(state == 0) position = 0, rotation = 0, state = 4;
		else if(state == 1) position = 1, rotation = 0, state = 0;
		else if(state == 2) position = 0, rotation = 1, state = 1;
		else if(state == 3) position = 0, rotation = 0, state = 0;
		else if(state == 4) position = 2, rotation = 1, state = 3;
		else if(state == 5) position = 1, rotation = 0, state = 4;
	} else if(figure_type == 3) {
		if(state == 0) position = 0, rotation = 0, state = 5;
		else if(state == 1) position = 1, rotation = 1, state = 3;
		else if(state == 2) position = 0, rotation = 3, state = 4;
		else if(state == 3) position = 0, rotation = 0, state = 1;
		else if(state == 4) position = 1, rotation = 2, state = 2;
		else if(state == 5) position = 1, rotation = 2, state = 0;
	}
}

int get_position() {
	return position;
}

int get_rotation() {
	return rotation;
}

