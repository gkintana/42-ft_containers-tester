/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_templates.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:11:47 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/06 09:37:20 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEMPLATES_HPP
#define MAP_TEMPLATES_HPP

#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <map>
#include "map.hpp"

template <typename key, typename value>
void printContent(NAMESPACE::map<key, value> &map) {
	std::cout << "map::empty() = " << std::boolalpha << map.empty() << std::endl
	          << "map::size() = " << map.size() << std::endl
	          << "Contents:" << std::endl;
	for (typename NAMESPACE::map<key, value>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

#define INSERT_BY_PAIR         1
#define INSERT_BY_MAKE_PAIR    2
#define INSERT_BY_OPERATOR     3

template <typename key, typename value>
void insertValue(NAMESPACE::map<key, value> &map, int insert_style,
                 typename NAMESPACE::map<key, value>::key_type first,
                 typename NAMESPACE::map<key, value>::mapped_type second) {
	if (insert_style == INSERT_BY_PAIR) {
		map.insert(NAMESPACE::pair<key, value>(first, second));
	} else if (insert_style == INSERT_BY_MAKE_PAIR) {
		map.insert(NAMESPACE::make_pair(first, second));
	} else if (insert_style == INSERT_BY_OPERATOR) {
		map[first] = second;
	} else {
		throw std::out_of_range("Incorrect insert style");
	}
}

template <typename key, typename value>
void insertValue(NAMESPACE::map<key, value> &map,
                 typename NAMESPACE::map<key, value>::iterator position,
                 typename NAMESPACE::map<key, value>::key_type first,
                 typename NAMESPACE::map<key, value>::mapped_type second) {
	map.insert(position, NAMESPACE::make_pair(first, second));
}

#endif