/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/17 17:54:35 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/17 18:18:21 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
Array<T>::Array(): _array(0), _aSize(0) {}

template <typename T>
Array<T>::Array(unsigned int size): _array(new T[size]()), _aSize(size) {}

template <typename T>
Array<T>::Array(const Array<T>& copy): _array(new T[copy._aSize]), _aSize(copy._aSize) {
	for (unsigned int i = 0; i < _aSize; ++i)
		_array[i] = copy._array[i];
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src){
	if (this != &src){
		delete[] _array;
		_aSize = src._aSize;
		_array = new T[_aSize];
		for (unsigned int i = 0; i < _aSize; ++i)
			_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _aSize)
		throw std::out_of_range("index out of bounds");
	
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _aSize)
		throw std::out_of_range("Index out of bounds");
	
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const{
	return _aSize;
}