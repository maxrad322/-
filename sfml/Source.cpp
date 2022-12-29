#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>

using namespace sf;

const int W = 1000;
const int H = 500;

//����� �����
class Player {
public:
	//�������� �����
	Sprite sprite;
	//����������� �����(����, �����)
	bool left;

	//�������� ��� �����
	Sprite arm;
	//���� �� y
	int army = 0;
	// ��������� ��� (����,���)
	bool up;

	//�� ����� ������ ��� ��������� ����
	int direction = 0;

	Player(Texture& p, Texture& p2) {
		sprite.setTexture(p);
		arm.setTexture(p2);
		//���� �������� ������ �����
		arm.setOrigin(54, 47);
	}

	//����� ����������� �����, ���
	void update() {
		if (left) {
			sprite.setTextureRect(IntRect(0, 0, 134, 201));
			sprite.setPosition(360, 200);
			//���� ���� ���� ������ �����
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
			//���� ���� ������
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

		
		//������������� �����������
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

//����� ��������� �������� ����
bool newAnimation = false;

//����� ����(������)
class Egg {
public:
	//�������� ����(5 �������)
	Sprite sprite[5];
	//���������� (5 ���������)
	FloatRect rect[5];
	//��������� ����
	bool vision[5];
	//����� �������� � �������������� ����
	int time = 1000, next = 0;

	//����� ���������� � ������������ �������
	void set(Texture& image, int& num) {
		vision[0] = true;
		for (int i = 1; i < 5; i++)
			vision[i] = false;

		for (int i = 0; i < 5; i++) {
			//������ ��������
			if (num == 1) {
				rect[i].left = 191 + 10 + i * 25;
				rect[i].top = 181 - 10 + i * 13;
			}
			//������ �������
			else if (num == 2) {
				rect[i].left = 181 + 10 + i * 25;
				rect[i].top = 271 - 10 + i * 13;
			}
			//������ ���������
			else if (num == 3) {
				rect[i].left = 811 - (10 + i * 25);
				rect[i].top = 185 - 10 + i * 13;
			}
			//������ ��������
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

	//�������� ����
	void update() {
		time--;

		//������� ������� ����
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

//����� �������� ��������� ���
class Score {
public:
	Sprite sprite[2];
	//�������� �����
	int count;
	//����� �� ������
	int s[2];

	Score(Texture& image) {

		for (int i = 0; i < 2; i++) {
			sprite[i].setTexture(image);
			sprite[i].setPosition(670 + 30 * i, 70);
			s[i] = 0;
		}
		count = 0;
	}

	//����� ����� �� �����
	void update() {
		if (count < 10)
			s[1] = count;
		else {
			s[0] = count / 10;
			s[1] = count % 10;
		}
		//�������� 250 �� 46 ��������, 10 �����
		for (int i = 0; i < 2; i++)
			sprite[i].setTextureRect(IntRect(25 * s[i], 0, 25, 46));
	}
};

//������� ����
class Fall {

public:
	Sprite sprite;
	//����������� ��������
	bool vision;
	//anim - ���� ��������(����� 5)
	int anim = 1, time = 1000;

	void set(Texture& image) {
		sprite.setTexture(image);
		vision = false;
	}

	//�������� ������� ���� (�����, ����)
	void update(bool right) {
		time--;
		if (time == 0) {
			anim++;
			time = 1000;
		}

		//������ ���� � �.�.
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

	//�������� ����
	Texture f;
	f.loadFromFile("fon.png");
	Sprite fon(f);

	//���� � ����
	Texture p, r;
	p.loadFromFile("player.png");
	r.loadFromFile("arms.png");
	Player player(p, r);

	//�������� ����
	Texture eg;
	eg.loadFromFile("egg.png");
	int num[4];
	Egg egg[4];
	for (int i = 0; i < 4; i++) {
		num[i] = i + 1;
		egg[i].set(eg, num[i]);
	}

	//����� ��������� ������ ���
	int group = rand() % 4;

	//�������� � ������� ��� ��������
	Texture s;
	s.loadFromFile("score.png");
	Score score(s);

	//�������� � �������� ����
	Texture up;
	up.loadFromFile("fall.png");
	Fall fall;
	fall.set(up);

	//����������� (�����,����) � ������� ������ ������������� �������� ������� ����
	bool right = true;

	//����� (0)
	bool game = true;

	//�������� ��������� ����
	Texture l;
	l.loadFromFile("lose.png");
	Sprite lose[3];
	for (int i = 0; i < 3; i++) {
		lose[i].setTexture(l);
		lose[i].setPosition(400 + 70 * i, 70);
	}

	//���-�� �������� ���
	int broken = 0;

	//������� - ����� ����
	Texture end;
	end.loadFromFile("gameover.png");
	Sprite gameover(end);
	gameover.setPosition(380, 120);

	//���� ��������
	bool endgame = false;

	//�������� ����
	while (window.isOpen())
	{
		//����������� ��������� �������
		Vector2i pos = Mouse::getPosition(window);
		//�������� ����
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//����������� ����������� �����
		if (pos.x < 500)
			player.left = true;
		else
			player.left = false;

		//����������� �������������� ���
		if (pos.y > 250)
			player.up = false;
		else
			player.up = true;

		//����� ��������� ��������
		if (newAnimation) {
			//���� ������ ����
			if (group == player.direction) {
				score.count++;
			}
			//����� ��� ������������ �������� ������� ����
			else {
				fall.vision = true;
				game = false;

				//���������� ������� ������������ �������� ������� ����
				if (group > 1)
					right = true;
				else
					right = false;
			}

			//��������� ������ � ������� ����� ������� ��������
			group = rand() % 4;

			//�������� ����� ��������������� ���� ����� ��������� ���������
			for (int i = 0; i < 4; i++)
				egg[i].next = 0;

			newAnimation = false;
		}

		//����������� ���� ����� ���������� �������� ������� ����
		if (!game and fall.anim == 6 and !endgame) {
			broken++;
			//���� 3 ���� ��������� - ����� ����(����� + ����� ������� + ����������� �������� ����)
			if (broken != 3) {
				game = true;
				fall.anim = true;
			}
			else
				endgame = true;
		}

		//���������
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
		//����
		window.draw(player.sprite);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 4; j++)
				if (egg[j].vision[i] && group == j)
					window.draw(egg[j].sprite[i]);
		window.draw(player.arm);
		//����
		for (int i = 0; i < 2; i++)
			window.draw(score.sprite[i]);
		//�������� ����
		for (int i = 0; i < broken; i++) {
			window.draw(lose[i]);
		}
		//�������� ������� ����
		if (fall.vision and !game)
			window.draw(fall.sprite);
		//����� ����
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