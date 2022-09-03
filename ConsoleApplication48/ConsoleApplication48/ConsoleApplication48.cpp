#define USER_DATA_FILE "users.dat"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;

class User {

private:
	bool isAdmin, access;
	string login, salt;
	long passwordHash;

public:
	static long hash(string str) {
		long result = 17;
		for (char symbol : str) {
			result *= symbol * 31;
		}
		return result;
	}

	static string generateSalt(int length) {
		string result;
		for (int i = 0; i < length; i++) {
			result += (char)(rand() % 26 + 65);
		}
		return result;
	}

	User(string login, long passwordHash, string salt, bool isAdmin, bool access) {
		this->login = login;
		this->isAdmin = isAdmin;
		this->access = access;
		this->salt = salt;
		this->passwordHash = passwordHash;
	}

	User(string login, string password, bool isAdmin, bool access) {
		this->login = login;
		this->isAdmin = isAdmin;
		string salt = User::generateSalt(6);
		this->passwordHash = User::hash(salt + password);
		this->access = access;
		this->salt = salt;
	}

	string getLogin() { return login; }

	void setLogin(string login) { this->login = login; }

	bool checkPassword(string password) {
		return User::hash(salt + password) == passwordHash;
	}

	long getPasswordHash() { return passwordHash; }

	string getSalt() { return salt; }

	void setPassword(string password) {
		passwordHash = User::hash(salt + password);
	}

	void setRole(bool isAdmin) { this->isAdmin = isAdmin; }

	bool getRole() { return isAdmin; }

	void setAccess(bool access) { this->access = access; }

	bool getAccess() { return access; }

};

string hiddenInput() {
	string result; char ch;
	while (true) {
		ch = _getch();
		if (ch == '\r') break;
		if (ch == '\b') {
			cout << "\b \b";
			result.pop_back();
			continue;
		}
		result += ch;
		cout << '*';
	}
	cout << "\n";
	return result;
}

template<typename T>
T input() {
	T result; cin >> result;
	while (cin.fail()) {
		cout << "Некорректный ввод." << endl;
		cin.clear();
		while (cin.get() != '\n');
		cin >> result;
	}
	return result;
}

int getConsoleWidth() {
	HANDLE hWndConsole = GetStdHandle(-12);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo);
	return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

void accentPrint(string text) {
	system("cls");
	cout << " ====== " << text << " ";
	for (int i = 11 + text.size(); i < getConsoleWidth(); i++)
		cout << '=';
	cout << endl;
}

vector<User> firstRun() {
	accentPrint("Первый запуск");
	cout << "Вы впервые запустили программу.\n"
		"Сейчас пройдет процедура регистрации учетной записи администратора.\n\n"
		"Введите логин администратора: ";
	string login; cin >> login;

	cout << "Введите пароль администратора: ";
	string password; password = hiddenInput();

	string salt = User::generateSalt(6);
	return { User(login, User::hash(salt + password), salt, true, true) };
}

vector<User> loadUsers(string path) {
	ifstream fin(path);
	if (!fin.is_open()) { return firstRun(); }

	vector<User> users;
	int count; fin >> count;
	for (int i = 0; i < count; i++) {
		string login, salt;
		long passwordHash;
		bool isAdmin, access;
		fin >> login >> passwordHash >> salt >> isAdmin >> access;
		if (fin.fail()) {
			cout << "Файл с данными пользователей повреждён. Прочесть не удалось." << endl;
			exit(1);
		}
		users.emplace_back(login, passwordHash, salt, isAdmin, access);
	}
	fin.close();

	return users;
}

void saveUsers(string path, vector<User> & users) {
	ofstream fout(path);
	fout << users.size() << endl;
	for (auto user : users) {
		fout << user.getLogin() << " " << user.getPasswordHash() << " "
			<< user.getSalt() << " " << user.getRole() << " " << user.getAccess() << endl;
	}
	fout.close();
}

User login(vector<User> & users) {
	accentPrint("Вход");
	cout << "Введите ваш логин: ";
	string login; User * currentUser = nullptr;

	while (currentUser == nullptr) {
		cin >> login;
		for (auto & user : users) {
			if (user.getLogin() == login) {
				currentUser = &user;
				break;
			}
		}
		if (currentUser == nullptr) {
			cout << "Такого пользователя не существует. Попробуйте ещё раз: ";
		}
	}

	int tries = 0; string password;
	cout << "Введите ваш пароль: ";
	while (!currentUser->checkPassword(password)) {
		if (tries == 3) {
			cout << endl << "Три попытки неверного ввода. Аккаунт заблокирован." << endl;
			currentUser->setAccess(false);
			saveUsers(USER_DATA_FILE, users);
			exit(0);
		}
		password = hiddenInput();
		if (!currentUser->checkPassword(password)) {
			cout << "Пароль неверный. Осталось " << 2 - tries << " попытки: ";
			tries++;
		}
	}

	if (!currentUser->getAccess()) {
		cout << "Ваш аккаунт заблокирован. Обратитесь к администратору." << endl;
		exit(0);
	}

	return *currentUser;
}

void reg(vector<User> & users, bool byAdmin = false) {
	accentPrint("Регистрация");
	cout << "Введите логин: ";
	bool alreadyExists = true;
	string login;

	while (alreadyExists) {
		cin >> login;
		alreadyExists = false;
		for (auto& user : users) {
			if (user.getLogin() == login) {
				alreadyExists = true;
				break;
			}
		}
		if (alreadyExists) {
			cout << "Пользователь с таким логином уже существует." << endl
				<< "Попробуйте ещё раз: ";
		}
	}

	string password = "1", password2 = "2";

	while (password != password2) {
		cout << "Введите пароль: ";
		password = hiddenInput();
		cout << "Подтвердите пароль: ";
		password2 = hiddenInput();
		if (password != password2) {
			cout << "Пароли не совпадают. Попробуйте ещё раз." << endl;
		}
	}

	cout << "Поздравляем. Аккаунт зарегистрирован." << endl;
	if (!byAdmin) {
		cout << "После подтверждения вашей регистрации администратором, вы сможете начать работу." << endl;
		users.emplace_back(login, password, 0, 0);
		saveUsers(USER_DATA_FILE, users);
		exit(0);
	}
	users.emplace_back(login, password, 0, 1);
	system("pause");
}

User welcomePrompt(vector<User> & users) {
	accentPrint("Добро пожаловать в систему покупки билетов!");
	cout << "Вы хотите войти или зарегистрироваться?\n"
		"\t1 - Войти\n"
		"\t2 - Зарегистрироваться\n"
		"Ваш выбор: ";
	int mode = 0;
	while (mode != 1 && mode != 2) {
		mode = input<int>();
		if (mode != 1 && mode != 2)
			cout << "Вы выбрали несуществующий вариант. Попробуйте ещё раз: ";
	}
	if (mode == 1) return login(users);
	reg(users);
}

void error(string text) {
	accentPrint("Ошибка");
	cout << endl << text << endl << endl;
	system("pause");
}

void listUsers(vector<User> & users) {
	accentPrint("Список пользователей");
	cout << endl;
	int i = 0;
	for (auto & user : users) {
		cout << ++i << ". " << user.getLogin() << ", "
			 << (user.getRole() ? "администратор, " : "клиент, ")
			 << (user.getAccess() ? "активен" : "заблокирован") << endl;
 	}
	cout << endl;
	system("pause");
}

void edit(vector<User> & users) {
	accentPrint("Меню редактирования пользователей");
	cout << "Введите логин пользователя, которого вы желаете отредактировать: ";
	system("pause");
}

void adminPanel(User currentUser, vector<User> & users) {
	string command = "";
	while (command != "quit") {
		accentPrint("Панель администратора");
		cout << endl << "Вам доступы следующие команды:" << endl
			<< "\tlist - вывести список всех учётных записей" << endl
			<< "\tadd - добавить новую учётную запись" << endl
			<< "\tedit - редактировать учётную запись" << endl
			<< "\tquit - выход из панели администратора" << endl << endl;
		cout << currentUser.getLogin() << " > ";
		cin >> command;

		if (command == "quit") { }
		else if (command == "add") {
			reg(users, true);
		}
		else if (command == "list") {
			listUsers(users);
		}
		else if (command == "edit") {
			edit(users);
		}
		else {
			error("Такой команды не существует.");
		}
	}
}

void menu(User currentUser, vector<User> & users) {
	string command = "";
	while (command != "quit") {
		accentPrint("Система покупки билетов");
		cout << endl << "Вам доступы следующие команды:" << endl
			<< "\tquit - выход" << endl << endl;
		if (currentUser.getRole()) {
			cout << "\tadmin - переход в панель администратора" << endl << endl;
		}
		cout << currentUser.getLogin() << " > ";
		cin >> command;
		
		if (command == "quit") {
			cout << "Хорошего вам дня." << endl;
		}
		else if (command == "admin") {
			if (currentUser.getRole()) {
				adminPanel(currentUser, users);
			}
			else {
				cout << "Вы не имеете доступа к данной команде." << endl;
			}
		}
		else {
			error("Такой команды не существует.");
		}
	}

}

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	vector<User> users = loadUsers(USER_DATA_FILE);
	User currentUser = welcomePrompt(users);
	menu(currentUser, users);
	for (auto user : users) {

	}
	saveUsers(USER_DATA_FILE, users);
	return 0;
}
