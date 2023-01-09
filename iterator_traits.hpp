/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:22:53 by athirion          #+#    #+#             */
/*   Updated: 2023/01/09 10:26:28 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

namespace ft {

    template< class Iter >
    struct iterator_traits {

		typedef typename 	Iter::difference_type				difference_type;
		typedef typename	Iter::value_type					value_type;
		typedef typename 	Iter::pointer						pointer;
		typedef typename 	Iter::reference						reference;
		typedef typename 	Iter::iterator_category				iterator_category;
	};

    template< class T >
    struct iterator_traits<T*> {

		typedef typename	std::ptrdiff_t						difference_type;
		typedef 			T									value_type;
		typedef				T*									pointer;
		typedef				T&									reference;
		typedef typename	std::random_access_iterator_tag		iterator_category;
	};

    template< class T >
    struct iterator_traits<const T*> {

		typedef typename	std::ptrdiff_t						difference_value;
		typedef				T									value_type;
		typedef				const T*							pointer;
		typedef				const T&							reference;
		typedef typename	std::random_access_iterator_tag		iterator_category;
	};

}

#endif
