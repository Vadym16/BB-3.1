#include <iostream>
#include <string>


using namespace std;

class Word {
public:

	Word() {

	}

	string word_get() {
		return word;
	}
	int num_get() {
		return num_page[0];
	}
	int count_get() {
		return count_page;
	}

	void word_set(string& word) {
		this->word = word;
	}
	void num_set(int page[], int size) {
		count_set(size);
		for (int i = 0; i < size; i++) {
			num_page[i] = page[i];
		}
	}
	void count_set(int count) {
		if (count > 0 and count < 10) {
			count_page = count;
		}
		else cout << "Помилка вводу кількості сторінок" << endl;

	}

	void show() {
		cout << "Славо: " << word << " Кількість сторінок: " << count_page << " Номер сторінки: ";
		show_page();
	}
	void show_page() {
		for (int i = 0; i < count_page; i++) {
			cout << num_page[i] << " ";
		}
		cout << endl;
	}

	bool more_N(int N) {
		return count_page > N;
	}
	
private:
	string word;
	int num_page[10];
	int count_page;
};



void more_N(Word words[], int size, int N);
void sort(Word words[], int size);
void Sreach(Word words[], int size, string& sreach);




int main()
{
	setlocale(LC_ALL, "ukr");

	Word words[3];
	int N;
	string srech;

	string w1 = "arr";
	int page1[3] = { 1,4,6 };
	words[0].word_set(w1);
	words[0].num_set(page1, 3);

	string w2 = "my";
	int page2[5] = { 1,4,6, 7, 2};
	words[1].word_set(w2);
	words[1].num_set(page2, 5);

	string w3 = "i`m";
	int page3[2] = { 1,4 };
	words[2].word_set(w3);
	words[2].num_set(page3, 2);

	for (int i = 0; i < 3; i++) {
		words[i].show();
	}

	cout << "Введіть число N: "; cin >> N;
	more_N(words, 3, N);
	sort(words, 3);
	cout << "Введіть шукане слово: "; cin>>srech;
	Sreach(words, 3, srech);

}

void more_N(Word words[], int size, int N) {
	cout << "Слова яких більше ніж на " << N << " сторінках" << endl;
	for (int i = 0; i < size; i++) {
		if (words[i].more_N(N)) {
			words[i].show();
		}
	}
}
void sort(Word words[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (words[j].word_get() > words[j + 1].word_get()) {
				Word temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp;
			}
		}
	}
	cout << "Слова за абеткою: " << endl;
	for (int i = 0; i < size; i++) {
		words[i].show();
	}
}

void Sreach(Word words[], int size,  string& sreach) {
	bool f = false;
	cout << "Кількість сторінок в шуканому слові: " << endl;
	for (int i = 0; i < size; i++) {
		if (words[i].word_get() == sreach) {
			words[i].show_page();
			f = true;
		}
	}
	if (!f) {
		cout << "Вашого слова немає в наших книгах" << endl;
	}
}