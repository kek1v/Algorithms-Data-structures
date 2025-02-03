#include <iostream>
#include <string>
#include <fstream>

class Point {
private:
	int x;
	int y;
	int z;
public:
	Point() {
		x = y = z = 0;
	}

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std::istream& is, Point& point);
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << point.x << " " << point.y << " " << point.z;// запись данных в файл
	return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
	is >> point.x >> point.y >> point.z;// чтение данных из файла
	return is;
}

int main() {
	setlocale(LC_ALL, "ru");

	Point point(32, 16, 88);
	std::string path = "Coordinates.txt";

	std::ofstream fout;
	std::ifstream fin;

	fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try {
		std::cout << "Попытка открыть файл для записи\n";
		fout.open(path);
		std::cout << "Файл открыт успешно для записи!\n";
		fout << point;// запись данных в файл
		fout.close();
		std::cout << "Данные записаны успешно!\n";
	} catch (const std::ofstream::failure& ex) {
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		std::cout << "Не удалось открыть файл для записи!";
	}

	try {
		std::cout << "Попытка открыть файл для чтения\n";
		fin.open(path);
		std::cout << "Файл открыт успешно для чтения!\n";
		Point readPoint;
		fin >> readPoint;
		std::cout << "Данные прочитаны успешно: " << readPoint << std::endl;
		fin.close();
	} catch (const std::ifstream::failure& ex) {
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		std::cout << "Не удалось открыть файл для чтения!";
	}

	return 0;
}
