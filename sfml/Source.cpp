#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>

using namespace sf;

const int W = 1000;
const int H = 500;

//класс волка
class Player {
public:
	//картинка волка
	Sprite sprite;
	//направление волка(лево, право)
	bool left;

	//картинка рук волка
	Sprite arm;
	//руки по y
	int army = 0;
	// положение рук (верх,низ)
	bool up;

	//на какую группу яиц направлен волк
	int direction = 0;

	Player(Texture& p, Texture& p2) {
		sprite.setTexture(p);
		arm.setTexture(p2);
		//руки крутятся вокруг точки
		arm.setOrigin(54, 47);
	}

	//смена направления волка, рук
	void update() {
		if (left) {
			sprite.setTextureRect(IntRect(0, 0, 134, 201));
			sprite.setPosition(360, 200);
			//руки если волк смотри влево
			if (up) {
				arm.setRotation(0);
				army = 0;
			}
			else {
				arm.setRotation(-30);
				army = 50;
			}
			arm.setTextureRect(IntRect(0, 0, 108, 93));
			arm.setPosition(280 + 54, 200 + 47 + army);
		}
		else {
			sprite.setTextureRect(IntRect(134, 0, -134, 201));
			sprite.setPosition(510, 200);
			//руки если вправо
			if (up) {
				arm.setRotation(0);
				army = 0;
			}
			else {
				arm.setRotation(30);
				army = 50;
			}
			arm.setTextureRect(IntRect(108, 0, -108, 93));
			arm.setPosition(610 + 54, 200 + 47 + army);
		}

		
		//устанавливаем направление
		if (left && up)
			direction = 0;
		else if (left && !up)
			direction = 1;
		else if (!left && up)
			direction = 2;
		else if (!left && !up)
			direction = 3;
	}
};

//вызов следующей анимации яйца
bool newAnimation = false;

//класс яйца(группы)
class Egg {
public:
	//картинки яйца(5 фреймов)
	Sprite sprite[5];
	//координаты (5 положений)
	FloatRect rect[5];
	//видимость яйца
	bool vision[5];
	//время анимации и обрабатываемое яйцо
	int time = 1000, next = 0;

	//задаём координаты и поворачиваем рисунок
	void set(Texture& image, int& num) {
		vision[0] = true;
		for (int i = 1; i < 5; i++)
			vision[i] = false;

		for (int i = 0; i < 5; i++) {
			//группа левоверх
			if (num == 1) {
				rect[i].left = 191 + 10 + i * 25;
				rect[i].top = 181 - 10 + i * 13;
			}
			//группа левониз
			else if (num == 2) {
				rect[i].left = 181 + 10 + i * 25;
				rect[i].top = 271 - 10 + i * 13;
			}
			//группа правоверх
			else if (num == 3) {
				rect[i].left = 811 - (10 + i * 25);
				rect[i].top = 185 - 10 + i * 13;
			}
			//группа правониз
			else if (num == 4) {
				rect[i].left = 811 - (10 + i * 25);
				rect[i].top = 275 - 10 + i * 13;
			}
		}

		for (int i = 0; i < 5; i++) {
			sprite[i].setTexture(image);
			sprite[i].setOrigin(11, 9);

			if (num < 3)
				sprite[i].setRotation(30 * i);
			else
				sprite[i].setRotation(-30 * i);

			sprite[i].setPosition(rect[i].left, rect[i].top);
		}
	}

	//анимация яйца
	void update() {
		time--;

		//стираем видимое яйцо
		if (time == 0) {
			vision[next] = false;
			next++;
			if (next < 5)
				vision[next] = true;
			else
				newAnimation = true;
			time = 1000;
		}
	}
};

//класс счётчика пойманных яиц
class Score {
public:
	Sprite sprite[2];
	//значение числа
	int count;
	//число на экране
	int s[2];

	Score(Texture& image) {

		for (int i = 0; i < 2; i++) {
			sprite[i].setTexture(image);
			sprite[i].setPosition(670 + 30 * i, 70);
			s[i] = 0;
		}
		count = 0;
	}

	//вывод числа на экран
	void update() {
		if (count < 10)
			s[1] = count;
		else {
			s[0] = count / 10;
			s[1] = count % 10;
		}
		//картинка 250 на 46 пикселей, 10 чисел
		for (int i = 0; i < 2; i++)
			sprite[i].setTextureRect(IntRect(25 * s[i], 0, 25, 46));
	}
};

//падение яйца
class Fall {

public:
	Sprite sprite;
	//отображение анимации
	bool vision;
	//anim - кадр анимации(всего 5)
	int anim = 1, time = 1000;

	void set(Texture& image) {
		sprite.setTexture(image);
		vision = false;
	}

	//анимация падения яйца (право, лево)
	void update(bool right) {
		time--;
		if (time == 0) {
			anim++;
			time = 1000;
		}

		//первый кадр и т.д.
		if (anim == 1) {
			if (right) {
				sprite.setTextureRect(IntRect(0, 0, 52, 66));
				sprite.setPosition(650, 350);
			}
			else {
				sprite.setTextureRect(IntRect(52, 0, -52, 66));
				sprite.setPosition(300, 350);
			}
		}
		if (anim == 2) {
			if (right) {
				sprite.setTextureRect(IntRect(0, 0, 87, 66));
				sprite.setPosition(650, 350);
			}
			else {
				sprite.setTextureRect(IntRect(87, 0, -87, 66));
				sprite.setPosition(265, 350);
			}
		}
		if (anim == 3) {
			if (right) {
				sprite.setTextureRect(IntRect(87, 0, 22, 66));
				sprite.setPosition(750, 350);
			}
			else {
				sprite.setTextureRect(IntRect(109, 0, -22, 66));
				sprite.setPosition(230, 350);
			}
		}
		if (anim == 4) {
			if (right) {
				sprite.setTextureRect(IntRect(109, 0, 22, 66));
				sprite.setPosition(780, 350);
			}
			else {
				sprite.setTextureRect(IntRect(131, 0, -22, 66));
				sprite.setPosition(195, 350);
			}
		}
		if (anim == 5) {
			if (right) {
				sprite.setTextureRect(IntRect(131, 0, 22, 66));
				sprite.setPosition(802, 350);
			}
			else {
				sprite.setTextureRect(IntRect(153, 0, -22, 66));
				sprite.setPosition(160, 350);
			}
		}
	}
};



int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(W, H), "Well, wait!");

	//картинка фона
	Texture f;
	f.loadFromFile("fon.png");
	Sprite fon(f);

	//волк и руки
	Texture p, r;
	p.loadFromFile("player.png");
	r.loadFromFile("arms.png");
	Player player(p, r);

	//картинка яйца
	Texture eg;
	eg.loadFromFile("egg.png");
	int num[4];
	Egg egg[4];
	for (int i = 0; i < 4; i++) {
		num[i] = i + 1;
		egg[i].set(eg, num[i]);
	}

	//выбор случайной группы яиц
	int group = rand() % 4;

	//картинка с цифрами для счётчика
	Texture s;
	s.loadFromFile("score.png");
	Score score(s);

	//картинка с падением яйца
	Texture up;
	up.loadFromFile("fall.png");
	Fall fall;
	fall.set(up);

	//направление (право,лево) в котором должна проигрываться анимация падения яйца
	bool right = true;

	//пауза (0)
	bool game = true;

	//картинка разбитого яйца
	Texture l;
	l.loadFromFile("lose.png");
	Sprite lose[3];
	for (int i = 0; i < 3; i++) {
		lose[i].setTexture(l);
		lose[i].setPosition(400 + 70 * i, 70);
	}

	//кол-во разбитых яиц
	int broken = 0;

	//надпись - конец игры
	Texture end;
	end.loadFromFile("gameover.png");
	Sprite gameover(end);
	gameover.setPosition(380, 120);

	//игра окончена
	bool endgame = false;

	//основной цикл
	while (window.isOpen())
	{
		//определение координат курсора
		Vector2i pos = Mouse::getPosition(window);
		//закрытие окна
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//определение направления волка
		if (pos.x < 500)
			player.left = true;
		else
			player.left = false;

		//определение местоположения рук
		if (pos.y > 250)
			player.up = false;
		else
			player.up = true;

		//вызов следующей анимации
		if (newAnimation) {
			//волк поймал яйцо
			if (group == player.direction) {
				score.count++;
			}
			//пауза для проигрывания анимации падения яйца
			else {
				fall.vision = true;
				game = false;

				//определяем сторону проигрывания анимации падения яйца
				if (group > 1)
					right = true;
				else
					right = false;
			}

			//генерация группы в которой будет вызвана анимация
			group = rand() % 4;

			//обнуляем номер обрабатываемого яйца перед слудующей анимацией
			for (int i = 0; i < 4; i++)
				egg[i].next = 0;

			newAnimation = false;
		}

		//продолжение игры после завершения анимации падения яйца
		if (!game and fall.anim == 6 and !endgame) {
			broken++;
			//если 3 яйца разбилось - конец игры(пауза + вывод надписи + прекращение анимации яйца)
			if (broken != 3) {
				game = true;
				fall.anim = true;
			}
			else
				endgame = true;
		}

		//отрисовка
		if (game) {
			player.update();
			for (int i = 0; i < 4; i++)
				if (group == i)
					egg[i].update();
		}
		else
			fall.update(right);
		score.update();
		window.clear(Color::White);
		window.draw(fon);
		//волк
		window.draw(player.sprite);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 4; j++)
				if (egg[j].vision[i] && group == j)
					window.draw(egg[j].sprite[i]);
		window.draw(player.arm);
		//счёт
		for (int i = 0; i < 2; i++)
			window.draw(score.sprite[i]);
		//разбитые яйца
		for (int i = 0; i < broken; i++) {
			window.draw(lose[i]);
		}
		//анимация падение яйца
		if (fall.vision and !game)
			window.draw(fall.sprite);
		//конец игры
		if (endgame) {
			window.draw(gameover);
			while (window.pollEvent(event))
			{
					window.close();
					main();
			}
			
		}
		window.display();
	}
}