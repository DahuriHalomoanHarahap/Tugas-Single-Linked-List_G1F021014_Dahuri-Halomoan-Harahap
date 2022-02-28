#include <iostream>
using namespace std;

struct Buku{
	string judul, pengarang;
	int terbit;
	
	Buku *next;
};

	Buku *head, *tail, *cur, *newNode, *del, *before;
	
	//create Single Linked List
	void createSingleLinkedList(string judul, string pengarang, int terbit) {
		head = new Buku();
		head->judul=judul;
		head->pengarang=pengarang;
		head->terbit=terbit;
		head->next=NULL;
		tail = head;
	}
	
	//menghitung berapa banyak data yang ada
	int countSingleLinkedList() {
		cur = head;
		int jumlah = 0;
		while (cur != NULL) {
			jumlah++;
			cur= cur->next;
		}
		return jumlah;
	}
	
	//add first Single Linked List
	void addfirst(string judul, string pengarang, int terbit) {
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->next=head;
		head=newNode;
	}
	
	//add last Single Linked List
	void addlast(string judul, string pengarang, int terbit) {
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
	}
	
	//add middle Single Linked List
	void addmiddle(string judul, string pengarang, int terbit, int posisi) {
		if (posisi < 1 || posisi > countSingleLinkedList() ) {
			cout<<"Posisi diluar jangkauan"<<endl;
		} else if (posisi == 1 || posisi == countSingleLinkedList() ) {
			cout<<"Posisi bukan posisi tengah"<<endl;
		} else {
			newNode = new Buku();
			newNode->judul=judul;
			newNode->pengarang=pengarang;
			newNode->terbit=terbit;
			
			//tranversing
			cur = head;
			int nomor = 1;
			while (nomor < posisi -1) {
				cur = cur->next;
				nomor++;
			}
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
	
	
	//delete first
	void deletefirst() {
		del=head;
		head=head->next;
		delete del;
	}
	
	//delete last
	void deletelast() {
		del=tail;
		cur=head;
		while(cur->next != tail) {
			cur = cur->next;
		}
		tail=cur;
		tail->next=NULL;
		delete del;
	}
	
	//delete middle
	void deletemiddle(int posisi) {
		if (posisi < 1 || posisi > countSingleLinkedList() ) {
			cout<<"Posisi diluar jangkauan"<<endl;
		} else if (posisi == 1 || posisi == countSingleLinkedList() ) {
			cout<<"Posisi bukan posisi tengah"<<endl;
		} else {
			int nomor = 1;
			cur = head;
			while (nomor <= posisi) {
				if (nomor == posisi-1) {
					before = cur;
				}
				if(nomor == posisi) {
					del = cur;
				}
				cur = cur->next;
				nomor++;
			}
			before->next = cur;
			delete del;	
		}
	}
	
	
	
	//print Single Link List
	void printSingleLinkedList() {
		cout<<"Jumlah data ada : "<< countSingleLinkedList()<<endl;
		cur = head;
		while (cur != NULL) {
			cout << "Judul Buku   : "<< cur->judul<<endl;
			cout << "Pengarang    : "<< cur->pengarang<<endl;
			cout << "Tahun Terbit : "<< cur->terbit<<endl;
			
			cur= cur->next;
		}
	}
int main() {
	
	createSingleLinkedList("Matematika", "Erlangga", 2009);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	addfirst("Kimia", "Suryadi", 2012);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	addlast("Bahasa Indonesia", "Suryono", 2018);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	addmiddle("Biologi", "Siswanto", 2008, 2); //menambahakan data baru di posisi ke-2
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	/*deletefirst();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deletelast();
	printSingleLinkedList();
	cout<<"\n\n"<<endl; 
	
	deletemiddle(3); //menghapus data pada posisi ke-3
	printSingleLinkedList();
	cout<<"\n\n"<<endl; */
	
	
	
	return 0;	
}
