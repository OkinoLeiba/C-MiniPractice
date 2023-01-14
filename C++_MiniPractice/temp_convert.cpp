//tenp_convertor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Project Practice: convert temperature from celesuis to fahrenheit 
//https://www.cprogramming.com/challenges/celsius_converter_table.html



/*Temperature Converter Challenge
Credit: Denis Meyer

In this challenge, write a program that takes in three arguments, a start temperature (in Celsius), an end temperature (in Celsius) and a step size. Print out a
table that goes from the start temperature to the end temperature, in steps of the step size; you do not actually need to print the final end temperature if the
step size does not exactly match. You should perform input validation: do not accept start temperatures less than a lower limit (which your code should specify as
a constant) or higher than an upper limit (which your code should also specify). You should not allow a step size greater than the difference in temperatures.
(This exercise was based on a problem from C Programming Language).



Sample run:

  Please give in a lower limit, limit >= 0: 10
  Please give in a higher limit, 10 > limit <= 50000: 20
  Please give in a step, 0 < step <= 10: 4

  Celsius         Fahrenheit
  -------         ----------
  10.000000       50.000000
  14.000000       57.200000
  18.000000       64.400000
  */


/*
Celsius to Kelvin: K = C + 273.15
Kelvin to Celcius: C = K - 273.15
Fahrenheit to Celcius: C = (F-32) (5/9)
Celsius to Fahrenheit: F = C(9/5) + 32
Fahrenheit to Kelvin: K = (F-32) (5/9) + 273.15
Kelvin to Fahrenheit: F = (K-273.15) (9/5) + 32
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
//#include "simp_win.cpp"
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>



#define KELVIN_CELSIUS 273.15
#define FAHRENHEIT_CELSIUS 32
#define CONVERT_FRACTION 5/9
#define FRACTION_CONVERT 9/5
#define LOWER_LIMIT 0
#define HIGHER_LIMIT 5000
#define STEP_LIMIT 10
#define MAX_CHAR 20
#define KELVIN "Kelvin"
#define CELSIUS "Celsius"
#define FAHRENHEIT "Fahrenheit"

using namespace std;




class Temp_Convert {


	static struct Temp_Data {
		signed int start_temp = NULL;
		signed int end_temp = NULL;
		signed int step = NULL;

		signed int celsius = NULL;
		signed int fahreneit = NULL;
		signed int kelvin = NULL;

		char current_temp[MAX_CHAR];
		char convert_temp[MAX_CHAR];
		string test_string;

		
	};

public:
	void print_statements() {
		signed int local_start_temp = NULL;
		signed int local_end_temp = NULL;
		signed int local_step = NULL;

		char local_current_temp[MAX_CHAR];
		char local_convert_temp[MAX_CHAR];

		struct Temp_Data temp_data;


		do {
				//initial print statements
				//prompt: current temp unit prompt and get value 
				printf("Type in Current Unit of Temparature. \n");
				printf("Celsuis \n");
				printf("Kelvin \n");
				printf("Fahrenheit \n");
				//cin.getline(temp_data.current_temp, MAX_CHAR);
				//scanf_s("%10s",temp_data.test_string);
				//cin >> temp_data.current_temp;
				cin.getline(temp_data.current_temp, MAX_CHAR);


				//prompt: convert temperature unit and get value 
				printf("Type in Temperature to Convert. \n");
				printf("Celsuis \n");
				printf("Kelvin \n");
				printf("Fahrenheit \n");
				//cin.getline(temp_data.current_temp, MAX_CHAR);
				//cin.getline(loc_convert_temp, MAX_CHAR);


				//validation: same temperature unit
				do {
					//cin >> temp_data.convert_temp;
					//scanf_s(loc_convert_temp, '%c');
					//fgets(loc_convert_temp, MAX_CHAR, stdin);
					cin.getline(local_convert_temp, MAX_CHAR);
					if (strncmp(local_convert_temp, temp_data.current_temp, strlen(temp_data.current_temp)) == 0) {
						printf("Type in Temperature to Convert other then %s \n", local_convert_temp);

					}
				} while (strncmp(temp_data.current_temp, local_convert_temp, strlen(temp_data.current_temp)) == 0);

		//validation: check for other values other than three temp units
		} while ((strncmp(temp_data.current_temp, KELVIN, strlen(temp_data.current_temp)) +
			strncmp(temp_data.current_temp, CELSIUS, strlen(temp_data.current_temp)) +
			strncmp(temp_data.current_temp, FAHRENHEIT, strlen(temp_data.current_temp))==0) &&

			(strncmp(local_convert_temp, KELVIN, strlen(local_convert_temp)) +
			strncmp(local_convert_temp, CELSIUS, strlen(local_convert_temp)) +
			strncmp(local_convert_temp, FAHRENHEIT, strlen(local_convert_temp)) == 0));


		//prompt: temperature to convert
		//validaiton: numerical range 	
		printf("Please give a lower limit >= 0: \n", &local_start_temp);
		//unsigned int int_start_temp = stol(&local_start_temp, nullptr, 0);
		do {
			//cin.getline(temp_data.start_temp, 10);
			//cin >> temp_data.start_temp;
			//atol(local_start_temp);
			cin >> local_start_temp;
			if (local_start_temp < LOWER_LIMIT) {
				printf("Please give a lower limit that is greater than or equal to 0 other than %i \n", local_start_temp);
			}
		} while (local_start_temp < LOWER_LIMIT);

		printf("Please give a higher limit, 10 > limit <= 50000: \n");
		do {
			//cin.getline(temp_data.end_temp, 10);
			//cin >> temp_data.end_temp;
			cin >> local_end_temp;
			if (local_end_temp < STEP_LIMIT || local_end_temp >= HIGHER_LIMIT) {
				printf("Please give a lower limit that is greater than 10 or less than 5000 other than %i \n", local_end_temp);
			}
		} while (local_end_temp < STEP_LIMIT || local_end_temp >= HIGHER_LIMIT);

		//TODO:you should not allow a step size greater than the difference in temperatures???
		printf("Please give a step, 0 > step <= 10: \n");
		do {
			//cin.getline(temp_data.step, 10);
			cin >> local_step;
			if (local_step < LOWER_LIMIT || local_step > STEP_LIMIT) {
				printf("Please give a step limit that is greater than 0 or less than 10 other than %i \n",  local_step);
			}
		} while (local_step < LOWER_LIMIT || local_step > STEP_LIMIT);

			
		/*char *convert_temp = temp_data.convert_temp;
		char *current_temp = temp_data.current_temp;
		cout << convert_temp;
		cout << &convert_temp;
		cout << *convert_temp;*/

	
		Temp_Convert::temp_convert(local_start_temp, local_end_temp, local_step, local_convert_temp, temp_data.current_temp);

		
		
	}

public:
	signed int temp_convert(signed int start_temp, signed int end_temp, signed int step, char* convert_temp, char* current_temp) {
		struct Temp_Data temp_data;
		


		/*for (int i = 0; i <= sizeof(convert_temp); ++i) {
			char temp_convert = NULL;
			temp_convert += convert_temp[i];
		}
*/
		if (strncmp(current_temp, CELSIUS, strlen(current_temp)) + strncmp(convert_temp, KELVIN, strlen(convert_temp)) == 0) {
			temp_data.kelvin = start_temp + KELVIN_CELSIUS;
		}
		else if (strncmp(current_temp, KELVIN, strlen(current_temp)) + strncmp(temp_data.convert_temp, CELSIUS, strlen(temp_data.convert_temp)) == 0) {
			temp_data.celsius = start_temp - KELVIN_CELSIUS;
		}
		else if (strncmp(current_temp, FAHRENHEIT, strlen(current_temp)) + strncmp(convert_temp, CELSIUS, strlen(convert_temp)) == 0) {
			temp_data.celsius = (start_temp - FAHRENHEIT_CELSIUS) * CONVERT_FRACTION;
		}
		else if (strncmp(current_temp, CELSIUS, strlen(current_temp)) + strncmp(convert_temp, FAHRENHEIT, strlen(convert_temp)) == 0 ){
			temp_data.fahreneit = (start_temp * FRACTION_CONVERT) + FAHRENHEIT_CELSIUS;
		}
		else if (strncmp(current_temp, FAHRENHEIT, strlen(current_temp)) + strncmp(convert_temp, KELVIN, strlen(convert_temp)) == 0) {
			temp_data.kelvin = ((start_temp - FAHRENHEIT_CELSIUS) * CONVERT_FRACTION) + KELVIN_CELSIUS;
		}
		else if (strncmp(current_temp, KELVIN, strlen(current_temp)) + strncmp(convert_temp, FAHRENHEIT, strlen(convert_temp)) == 0) {
			temp_data.fahreneit = (start_temp - KELVIN_CELSIUS) * FRACTION_CONVERT + FAHRENHEIT_CELSIUS;
		}
		else {
			printf("Danger, Will Robinson");
		}
/*
		switch (current_temp, convert_temp)
		{
		case current_temp == "Celsuis" && convert_temp == "Kelvin":
			temp_data.kelvin = start_temp + KELVIN_CELSIUS;
			break;
		case temp_data.current_temp == "Kelvin" && temp_data.convert_temp == "Celsuis":
			celsius = temp_data.start_temp - KELVIN_CELSIUS;
			break;
		case current_temp == "Celsuis" && convert_temp == "Fahrenheit":
			temp_data.fahreneit = (start_temp * FRACTION_CONVERT) + FAHRENHEIT_CELSIUS;
			break;
		case current_temp == "Fahrenheit" && convert_temp == "Kelvin":
			temp_data.kelvin = ((start_temp - FAHRENHEIT_CELSIUS) * CONVERT_FRACTION) + KELVIN_CELSIUS;
			break;
		case current_temp == "Fahrenheit" && convert_temp == "Kelvin":
			temp_data.fahreneit = (kelvin - KELVIN_CELSIUS) * FRACTION_CONVERT + FAHRENHEIT_CELSIUS;
			break;
		default:
			printf("Danger Will Robinson");
			break;
		}
*/
		end_temp = temp_data.kelvin = temp_data.fahreneit = temp_data.celsius;
		printf("The Temperature Converstion is: %i ", end_temp);
		return end_temp;
	}

};

void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void gotoxy(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



int main() {

	Temp_Convert temp_convert;


	
	temp_convert.print_statements();
	//fullscreen();
	//wWinMain();

	
	return 0;

}
