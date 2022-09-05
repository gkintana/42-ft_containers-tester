/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_04_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/05 11:31:22 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

// https://stackoverflow.com/questions/30835980/c-error-deduced-conflicting-types-for-parameter-t-string-vs-const-char
template < typename T >
struct identity {
	typedef T type;
};

template < typename T >
static void resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
                             typename identity<T>::type value, bool add_newline) {
	ft.resize(new_size, value);
	std.resize(new_size, value);
	compareVectors(ft, std, add_newline);
}

template < typename T >
static void checkResizeExceptions(ft::vector<T> &ft,std::vector<T> &std,
                                 size_t new_size, bool add_newline) {
	bool ft_exception = false,
	     std_exception = false;

	try {
		ft.resize(new_size);
	} catch (std::exception &e) {
		ft_exception = true;
	}

	try {
		std.resize(new_size);
	} catch (std::exception &e) {
		std_exception = true;
	}

	if (ft_exception == std_exception) {
		std::cout << test_no++ << "." GREEN "EXCEPTION OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "EXCEPTION KO " DEFAULT;
	}
	compareVectors(ft, std, add_newline);
}

/*----------------------------------------------------------------------------*/

static void resizeTests();
static void resizeExceptionTests();
// static void reserveTests();
// static void reserveExceptionTests();

int main() {
	std::cout << PURPLE "Resize Tests" DEFAULT << std::endl;
	resizeTests();

	std::cout << PURPLE "Resize Exception Tests" DEFAULT << std::endl;
	resizeExceptionTests();
	
	return 0;
}

/*----------------------------------------------------------------------------*/

static void resizeTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		// test no. 1 - 5
		resizeAndCompare(ft_vec, std_vec, 7, 1234567890, false);
		// test no. 6 - 10
		resizeAndCompare(ft_vec, std_vec, 12, 42, false);
		// test no. 11 - 15
		resizeAndCompare(ft_vec, std_vec, 0, INT_MAX, false);
		// test no. 15 - 20
		resizeAndCompare(ft_vec, std_vec, 25, 25, false);
		// test no. 21 - 25
		resizeAndCompare(ft_vec, std_vec, 5, 123, false);
		// test no. 26 - 30
		resizeAndCompare(ft_vec, std_vec, 8, 456, false);
		// test no. 31 - 35
		resizeAndCompare(ft_vec, std_vec, 12, 789789789, true);
	}

	resetTestCount("String Vector: ");
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;

		// test no. 1 - 5
		resizeAndCompare(ft_vec, std_vec, 7, "Lorem ipsum dolor sit amet", false);
		// test no. 6 - 10
		resizeAndCompare(ft_vec, std_vec, 12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex", false);
		// test no. 11 - 15
		resizeAndCompare(ft_vec, std_vec, 0, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt", false);
		// test no. 15 - 20
		resizeAndCompare(ft_vec, std_vec, 25, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur", false);
		// test no. 21 - 25
		resizeAndCompare(ft_vec, std_vec, 5, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt", false);
		// test no. 26 - 30
		resizeAndCompare(ft_vec, std_vec, 8, "Hello World!", false);
		// test no. 31 - 35
		resizeAndCompare(ft_vec, std_vec, 12, "0123456789012345678901234567890123456789", true);
	}
}

static void resizeExceptionTests() {
	resetTestCount("");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		// test no. 1 - 6
		checkResizeExceptions(ft_vec, std_vec, +0, false);
		// test no. 7 - 12
		checkResizeExceptions(ft_vec, std_vec, -0, false);
		// test no. 13 - 18
		checkResizeExceptions(ft_vec, std_vec, CHAR_BIT, false);
		// test no. 19 - 24
		checkResizeExceptions(ft_vec, std_vec, CHAR_MIN, false);
		// test no. 25 - 30
		checkResizeExceptions(ft_vec, std_vec, CHAR_MAX, false);
		// test no. 31 - 36
		checkResizeExceptions(ft_vec, std_vec, SCHAR_MIN, false);
		// test no. 37 - 42
		checkResizeExceptions(ft_vec, std_vec, SCHAR_MAX, false);
		// test no. 43 - 48
		checkResizeExceptions(ft_vec, std_vec, INT_MIN, false);
		// test no. 49 - 54
		checkResizeExceptions(ft_vec, std_vec, SHRT_MIN, false);
		// test no. 55 - 60
		checkResizeExceptions(ft_vec, std_vec, SHRT_MAX, false);
		// test no. 61 - 66
		checkResizeExceptions(ft_vec, std_vec, USHRT_MAX, false);
		// test no. 67 - 72
		checkResizeExceptions(ft_vec, std_vec, LONG_MIN, false);
		// test no. 73 - 78
		checkResizeExceptions(ft_vec, std_vec, LONG_MAX, false);
		// test no. 79 - 84
		checkResizeExceptions(ft_vec, std_vec, ULONG_MAX, true);

		// the following cases gets stuck or a SIGKILL on campus macs, so I disabled them
		// checkResizeExceptions(ft_vec, std_vec, INT_MAX, true);
		// checkResizeExceptions(ft_vec, std_vec, UINT_MAX, true);
	}
}