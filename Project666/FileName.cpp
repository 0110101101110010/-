#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include <sstream>

using namespace std;

class Car
{
public:

	string manufacturer;
	string model;
	string color;
	int capysity = 0;
	double maxspeed = 0;
	int quantity = 0;
	int numbercar = 0;
	double hieght = 0;
	double width = 0;
	double length = 0;

	string str;

	fstream fs;

	void finCar(string manufacturer, string model, string color, int capysity, double maxspeed, int quantity, double height, double width, double length)
	{
		fs.open("Car.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла!";
		}
		else
		{
			fs << manufacturer << " " << model << " " << color << " " << capysity << " " << maxspeed << " " << quantity << " " << height << " " << width << " " << length << "\n";

		}
		fs.close();

	}

	void foutCar()
	{
		fs.open("Car.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла!";
		}
		else
		{
			str = " ";
			numbercar = 0;

			while (!fs.eof())
			{
				numbercar++;
				cin.ignore();
				getline(fs, str);
				cout << numbercar << " " << str;
			}

		}
		fs.close();
	}

	void delCar(int delstr)
	{
		fstream file("Car.txt", ios::in | ios::out);

		if (file.is_open()) {
			ofstream temp("temp.txt");

			string line;
			int delstrtest = 0;
			while (getline(file, line)) 
			{
				delstrtest++;
				if (delstr != delstrtest) {
					temp << line << endl;
				}
			}

			file.close();
			temp.close();

			remove("Car.txt");
			rename("temp.txt", "Car.txt");

			cout << "Line removed from file." << endl;
		}
		else 
		{
			cout << "Unable to open file." << endl;
		}
	}
	
	//Вывод отсортированного тхт файла
	void foutSortCar()
	{
		fs.open("sorted_data.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла!";
		}
		else
		{
			str = " ";
			numbercar = 0;

			while (!fs.eof())
			{
				numbercar++;
				cin.ignore();
				getline(fs, str);
				cout << numbercar << " " << str;
			}

		}
		fs.close();
	}

//Ввод в файл отсортированного списка
	void outsortcar(vector<string> lines)
	{
		ofstream outputFile("sorted_data.txt");
		for (const auto& line : lines)
		{
			outputFile << line << endl;
		}
		outputFile.close();
	}
};

// Функция для разбиения строки на отдельные значения
std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

// Функция-компаратор для сравнения значений в нужном столбце
bool compareColumns(const std::string& str1, const std::string& str2, int column) {
	std::vector<std::string> values1 = split(str1, ' ');
	std::vector<std::string> values2 = split(str2, ' ');
	if (values1.size() <= column || values2.size() <= column) {
		return false; // Некорректные данные
	}
	return values1[column] < values2[column];
}


int main()
{
	setlocale(0, "");
	srand(time (NULL));
	
	
	Car testCar;

	int switch_1 = 0;
	bool while_1 = true;
	bool is_valid = false;

	string manufacturer;
	string model;
	string color;
	int capysity = 0;
	double maxspeed = 0;
	int quantity = 0;
	double hieght = 0;
	double width = 0;
	double length = 0;

	int delstr = 0;


	ifstream inputFile("Car.txt");
	vector<std::string> lines;
	string line;

	int columnToSort = 0; // Столбец, по которому будем сортировать


	while (while_1)
	{


		cout << endl;
		cout << "1. Ввести автомобиль\n";
		cout << "2. Вывести все автомобили\n";
		cout << "3. Удалить автомобиль\n";
		cout << "4. Сортировка списка\n";
		cout << "0. выход\n";

		cin >> switch_1;

		switch (switch_1)
		{
		case 1:

			
				cout << "file is open!\n";

				do
				{
					cout << "Введите производителя автомобиля: ";
					cin >> manufacturer;
					is_valid = true;
					for (char c : manufacturer) {
						if (!isalpha(c)) {
							cout << "Ошибка! производитель может содержать только буквы латинсого алфавита." << endl;
							is_valid = false;
							break;
						}
					}
				} while (!is_valid);

				cout << "Введите модель автомобиля: ";
				cin >> model;

				do
				{
					cout << "Введите цвет автомобиля: ";
					cin >> color;
					is_valid = true;
					for (char c : color) {
						if (!isalpha(c)) {
							cout << "Ошибка! цвет может содержать только буквы латинсого алфавита." << endl;
							is_valid = false;
							break;
						}
					}
				} while (!is_valid);

				do
				{
					cout << "введите людей: ";
					cin >> capysity;

					is_valid = true;

					if (cin.fail()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "люди исчесляются в цифрах." << endl;
						is_valid = true;
					}
					else {
						is_valid = false;
					}
				} while (is_valid);


				do
				{
					cout << "Введите максимальную скорость : ";
					cin >> maxspeed;

					is_valid = true;

					if (cin.fail()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "максимальная скорость может исчесляться в цислах." << endl;
						is_valid = true;
					}
					else {
						is_valid = false;
					}
				} while (is_valid);

				do
				{
					cout << "Введите высоту автомобиля : ";
					cin >> hieght;

					is_valid = true;

					if (cin.fail()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "высота может исчесляться в цислах." << endl;
						is_valid = true;
					}
					else {
						is_valid = false;
					}
				} while (is_valid);

				do
				{
					cout << "Введите ширину автомобиля : ";
					cin >> width;

					is_valid = true;

					if (cin.fail()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "максимальная скорость может исчесляться в цислах." << endl;
						is_valid = true;
					}
					else {
						is_valid = false;
					}
				} while (is_valid);

				do
				{
					cout << "Введите длинну автомобиля : ";
					cin >> length;

					is_valid = true;

					if (cin.fail()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "максимальная скорость может исчесляться в цислах." << endl;
						is_valid = true;
					}
					else {
						is_valid = false;
					}
				} while (is_valid);



				quantity = 1+rand() % 15;

				testCar.finCar(manufacturer, model, color, capysity, maxspeed, quantity, hieght, width, length);
			


			break;
		case 2:

			testCar.foutCar();

			break;

		case 3:
			cout << "Введите удаляемую строку: ";
			cin >> delstr;
			testCar.delCar(delstr);

			break;
		case 4:
			cout << "Введите по кокому столбцу будет выполнена сортировка: ";
			cin >> columnToSort;
			columnToSort = columnToSort - 1;

			while (getline(inputFile, line)) 
			{
				lines.push_back(line);
			}
			inputFile.close();

			
			sort(lines.begin(), lines.end(), [columnToSort](const std::string& str1, const std::string& str2) 
			{
					return compareColumns(str1, str2, columnToSort);
			});

			testCar.outsortcar(lines);

			testCar.foutSortCar();

			break;
		case 0:

			cout << "Выход!\n";

			while_1 = false;

			break;
		default:
			cout << "Введите коректное значение!\n";
			break;
		}

	}
}