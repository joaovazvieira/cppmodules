/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 11:34:04 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/07 12:30:50 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>{
public:
	using iterator = typename Container::iterator;
	using const_iterator = typename Container::const_iterator;
	using reverse_iterator = typename Container::reverse_iterator;
	using const_reverse_iterator = typename Container::const_reverse_iterator;

	//for non constant iterators
	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}

	//for constant iterator
	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}

	//for non constant reverse iterator
	reverse_iterator rbegin() {return this->c.rbegin();}
	reverse_iterator rend() {return this->c.rend();}
	
	//for constant reverse iterator
	const_reverse_iterator rbegin() const {return this->c.rbegin();}
	const_reverse_iterator rend() const {return this->c.rend();}
};


#endif