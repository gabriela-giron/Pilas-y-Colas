#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<thread>
#include<time.h>

using namespace std;

int num;

void caja1();
void caja2();
void caja3();
void caja4();

struct Nodo {
	int num;
	Nodo* siguiente;
};

void* procesoSeparado(void* data) {
	char* texto = (char*)data;
	struct timespec tiempo = { 1,0 };
	while (1) {
		printf("%s\n", texto);
		thread_delay_np(tiempo);
	}
}

void Add(Nodo*&, int);
void Remove(Nodo*&);

void insertarPila(Nodo*&, int);
void sacarPila(Nodo*&);
bool cola_vacia(Nodo*);
Nodo* frente = NULL;
Nodo* fin = NULL;

int main(void) {
	int opc;

	cout << "Elija entre las opciones " << endl;
	cout << "1) caja 1" << endl;
	cout << "2) caja 2" << endl;
	cout << "3) caja 3" << endl;
	cout << "4) caja 4" << endl;
	cout << "0) salir" << endl;

	switch (opc) {
	case 1:
		caja1();
		break;
	case 2:
		caja2();
		break;
	case 3:
		caja3();
		break;
	case 4:
		caja4();
		break;
	case 0:
		break;
	}
	

	system("pause");
	return 0;
}

void caja1() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	thread_t proceso1;
	thread_t proceso2;
	thread_create(&proceso1, NULL, &procesoSeparado);
	thread_create(&proceso1, NULL, &num_random);
	thread_join(proceso1, NULL);
	thread_join(proceso2, NULL);
	

	cout << "[" << num << "]: ";
	insertarPila(pila, num);
	

	cout << "---------------------------peek--------------------------" << pila->num<<endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "---------------------------peek--------------------------" << pila->num << endl;
			}
		}

	} while ((s=='s'));
}

void caja2() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	thread_t proceso1;
	thread_t proceso2;
	thread_create(&proceso1, NULL, &procesoSeparado);
	thread_create(&proceso1, NULL, &num_random);
	thread_join(proceso1, NULL);
	thread_join(proceso2, NULL);

	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "---------------------------peek--------------------------" << pila->num << endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "---------------------------peek--------------------------" << pila->num << endl;
			}
		}

	} while ((s == 's'));
}
void caja3() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	thread_t proceso1;
	thread_t proceso2;
	thread_create(&proceso1, NULL, &procesoSeparado);
	thread_create(&proceso1, NULL, &num_random);
	thread_join(proceso1, NULL);
	thread_join(proceso2, NULL);

	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "---------------------------peek--------------------------" << pila->num << endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "---------------------------peek--------------------------" << pila->num << endl;
			}
		}

	} while ((s == 's'));
 }

void caja4() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	thread_t proceso1;
	thread_t proceso2;
	thread_create(&proceso1, NULL, &procesoSeparado);
	thread_create(&proceso1, NULL, &num_random);
	thread_join(proceso1, NULL);
	thread_join(proceso2, NULL);

	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "---------------------------peek--------------------------" << pila->num << endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "---------------------------peek--------------------------" << pila->num << endl;
			}
		}

	} while ((s == 's'));
}

void insertarPila(Nodo*& pila, int n) {
	Nodo* push = new Nodo;
	push->num = n;
	push->siguiente = pila;
	pila = push;

	cout << "Elemento agregado a la pila" << endl;
}

void sacarPila(Nodo*& pila) {
	int n;
	Nodo* pop = pila;
	n = pop->num;
	pila = pop->siguiente;
	delete pop;
}

void Add(Nodo*& inicio, int n) {
	Nodo* add = new Nodo();
	add->num = n;
	add->siguiente = NULL;

	if (cola_vacia(frente)) {
		frente = add;
	}
	else {
		fin->siguiente = add;
	}
	fin = add;
	cout << "elemento insertado a la cola" << endl;
}

bool cola_vacia(Nodo *frente) {
	return (frente == NULL) ? true : false;
}

void Remove(Nodo *&frente) {
	int n;
	n = frente->num;
	Nodo* cola = frente;
	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->siguiente;
	}
	delete cola;
}

void num_random(int num) {
	int num;
	srand(time(NULL));

	for (int c = 1; c <= 200; c++) {
		num = 1 + rand() % (91 - 1);
		cout << num << " ";
	}
}




