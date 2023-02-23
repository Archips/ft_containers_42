/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/23 17:02:04 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "../includes/map.hpp"

# define NAMESPACE ft

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	pair<int, string>			my_pair(8, "salut");
	map<int, string>			test;
	map<int, string>::iterator	it;

	test.insert(my_pair);
	test.insert(pair<int, string>(-4, "bar"));
	test.insert(pair<int, string>(2, "machin"));
	/* test.insert(pair<int, string>(3, "foo")); */
	/* test.insert(pair<int, string>(746, "Marcel")); */
	/* test.insert(pair<int, string>(1, "truc")); */
	it = test.begin();
	cout << '\n';
	test.get_rbt().print_prefix(test.get_rbt().root(), 0);
	/* while (it != test.end()) */
	/* { */
	/* 	cout << "start of while\n"; */
	/* 	cout << it->first << ", " << it->second << '\n'; */
	/* 	it++; */
 		/* cout << "iterator incremented\n"; */

// #ifndef STD
// 		cout << it.getPointer() << '\n';
// 		cout << test.end().getPointer() << '\n';
// #endif

	/* } */
	cout << "End of display loop\n";
}
