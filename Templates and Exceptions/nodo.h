#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

template <class TDATO>
class nodo_t{
private:
	nodo_t* next_;
	nodo_t* prev_;
	TDATO dato_;
public:
	nodo_t(TDATO dato);
	~nodo_t(void);
	void set_next (nodo_t* next);
	nodo_t* get_next (void);
	void set_prev (nodo_t* prev);
	nodo_t* get_prev (void);
	void set_dato (TDATO dato);
	TDATO get_dato (void);
	void write (ostream& os);
};


template <class TDATO>
nodo_t<TDATO>::nodo_t(TDATO dato):
next_(NULL),
prev_(NULL),
dato_(dato){}

template <class TDATO>
nodo_t<TDATO>::~nodo_t (void){}

template <class TDATO>
void nodo_t<TDATO>::set_next (nodo_t* x){
	next_ = x;
}

template <class TDATO>
nodo_t<TDATO>* nodo_t<TDATO>::get_next (void){
	return next_;
}

template <class TDATO>
void nodo_t<TDATO>::set_prev (nodo_t* x){
	prev_ = x;
}

template <class TDATO>
nodo_t<TDATO>* nodo_t<TDATO>::get_prev (void){
	return prev_;
}

template <class TDATO>
void nodo_t<TDATO>::set_dato (TDATO x){
	dato_ = x;
}

template <class TDATO>
TDATO nodo_t<TDATO>::get_dato (void){
	return dato_;
}

template <class TDATO>
void nodo_t<TDATO>::write (ostream& os){
	os << dato_;
}