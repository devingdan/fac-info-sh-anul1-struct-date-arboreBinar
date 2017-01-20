/* Aceasta aplicatie este scrisa in C++
Rolul aplicatiei este sa realizeze initializarea unui arbore binar,
si de a oferi verificarea unui numar introdus de utilizator
daca acesta se regaseste in structura tip arbore binar.
*/

#include<iostream>
using namespace std;
//Definirea structurii de date tip nod a arborelui binar
struct NodArbore {
	int data; //data nodului
	NodArbore* stanga; //adresa nodului din stanga (cu valoare mai mica)
	NodArbore* dreapta;//adresa nodului din dreapta (cu valoare mai mare)
};

NodArbore* obtineNod(int data) { // functia obtineNod va crea un nod nou;
	NodArbore* nodNou = new NodArbore();
	nodNou->data = data;
	nodNou->stanga = nodNou->dreapta = NULL;
	return nodNou;
}

// pentru a introduce variabila data in arbore, returneaza adresa radacinii
NodArbore* Insert(NodArbore* radacina,int data) {
	if(radacina == NULL) { // cazul in care arborele este gol
		radacina = obtineNod(data);
	}
	else if(data <= radacina->data) { // daca data ce este introdusa este mai mica, introdu-o in subarborele stanga
		radacina->stanga = Insert(radacina->stanga,data);
	}

	else { // altfel, introduce data in subarborele din dreapta.
		radacina->dreapta = Insert(radacina->dreapta,data);
	}
	return radacina;
}
//Pt cautare element in arbore, returneaza "A fost gasit" daca este adevarat
bool Search(NodArbore* radacina,int data) {
	if(radacina == NULL) {
		return false;
	}
	else if(radacina->data == data) {
		return true;
	}
	else if(data <= radacina->data) {
		return Search(radacina->stanga,data);
	}
	else {
		return Search(radacina->dreapta,data);
	}
}
int main() {
	NodArbore* radacina = NULL;  // Creare arbore gol
	radacina = Insert(radacina,15);
	radacina = Insert(radacina,10);
	radacina = Insert(radacina,20);
	radacina = Insert(radacina,25);
	radacina = Insert(radacina,8);
	radacina = Insert(radacina,12);
	radacina = Insert(radacina,14);
	// Cere utilizatorului o valoare
	int number;
	cout<<"Introduceti un numar pentru a fi analizat\n";
	cin>>number;
	//daca a fost gasit, afiseaza acest lucru
	if(Search(radacina,number) == true) cout<<"A fost gasit\n";
	else cout<<"Nu a fost gasit\n";
}
