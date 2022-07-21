#include <iostream>
#ifndef __Map_H__
#define __Map_H__

using namespace std;

//n-name, v-value
template <class N, class V> class Map{
private:
	struct node{
		node * next;
		N name;
		V value;
		node(N name, V value, node* next){
			this->name = name;
			this->value = value;
			this->next = next;
		}
		node(N name,V value){
			this->name = name;
			this->value = value;
			this->next = NULL;
		}
		~node(){}
	};
	node* head;
	void clear(){
		while(head){
			node * t = head -> next;
			delete head;
			head = t;
		}
	}
public:
	Map(){
		head = NULL;
	}
	~Map(){
		clear();
	}
	Map(const Map& m){
		node * t = m.head;
		head = NULL;
		while(t){
			node * tmp = new node((t->name), (t->value), head);
			this->head = tmp;
			t = t->next;
		}
	}
	void add(N name,V value){
		node * tmp = new node(name, value, head);
		this->head = tmp;
	}
	V* find(N name){
		node * t = head;
		while(t){
			if ((t->name) == name){
				return &(t->value);
			}
			t = t->next;
		}
		return NULL;
	}
	Map& operator=(const Map& m){
		if(&m == this)
		{
			return *this;
		}
		node * t = m.head;
		clear();
		while(t){
			node * tmp = new node((t->name), (t->value), head);
			this->head = tmp;
			t= t->next;
		}
		return *this;
	}
	friend ostream& operator << (ostream&o, Map& m){
		node * t = m.head;
		while(t){
			o << (t->name) << " : " << (t->value) << endl;
			t = t->next;
		}
		return o;
	}
};



#endif /* __MAP_H__ */
